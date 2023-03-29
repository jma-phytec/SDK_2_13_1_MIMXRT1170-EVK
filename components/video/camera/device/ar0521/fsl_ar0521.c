/*
 * Copyright 2017-2018, 2020 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_video_common.h"
#include "fsl_camera.h"
#include "fsl_camera_device.h"
#include "fsl_ar0521.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define AR0521_DelayMs VIDEO_DelayMs

#define AR0521_DEBUG

#ifdef AR0521_DEBUG
#include "fsl_debug_console.h"
#endif

#define AR0521_SCCB_ADDR            0x36U
#define AR0521_RESOLUTION_PARAM_NUM 0x16U

#define AR0521_CHECK_RET(x)            \
    do                                 \
    {                                  \
        status = (x);                  \
        if (kStatus_Success != status) \
        {                              \
            return status;             \
        }                              \
    } while (false)

typedef struct _ar0521_reg_val
{
    uint16_t regAddr; /*!< Register address. */
    uint16_t regVal;   /*!<Register value. */
} ar0521_reg_val_t;

typedef struct _ar0521_resolution_param
{
    uint32_t resolution; /*!< Resolution, see @ref video_resolution_t and @ref FSL_VIDEO_RESOLUTION. */
    uint8_t param[AR0521_RESOLUTION_PARAM_NUM]; /*!< Parameter 0x3800 to 0x3813. */
} ar0521_resolution_param_t;

typedef struct
{
    uint32_t resolution;
    uint8_t framePerSec;
    uint8_t pllCtrl1;
    uint8_t pllCtrl2;
    uint8_t vfifoCtrl0C;
    uint8_t pclkDiv;
    uint8_t pclkPeriod;
} ar0521_clock_config_t;

typedef status_t (*ar0521_cmd_func_t)(camera_device_handle_t *handle, int32_t arg);

typedef struct
{
    camera_device_cmd_t cmd;
    ar0521_cmd_func_t func;
} ar0521_cmd_func_map_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
status_t AR0521_Init(camera_device_handle_t *handle, const camera_config_t *config);

status_t AR0521_Deinit(camera_device_handle_t *handle);

status_t AR0521_Control(camera_device_handle_t *handle, camera_device_cmd_t cmd, int32_t arg);

status_t AR0521_Start(camera_device_handle_t *handle);

status_t AR0521_Stop(camera_device_handle_t *handle);

status_t AR0521_InitExt(camera_device_handle_t *handle, const camera_config_t *config, const void *specialConfig);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static const ar0521_reg_val_t ar0521InitParam[] = {
};

const camera_device_operations_t ar0521_ops = {
    .init     = AR0521_Init,
    .deinit   = AR0521_Deinit,
    .start    = AR0521_Start,
    .stop     = AR0521_Stop,
    .control  = AR0521_Control,
    .init_ext = AR0521_InitExt,
};

/*******************************************************************************
 * Code
 ******************************************************************************/

static status_t AR0521_WriteReg16(camera_device_handle_t *handle, uint32_t reg, uint16_t val)
{
	status_t status;
	uint8_t write_buf[2];

	write_buf[0] = (val >> 8) & 0xff;
	write_buf[1] = val & 0xff;

    status = SCCB_WriteMultiRegs(AR0521_SCCB_ADDR, kSCCB_RegAddr16Bit, (reg), (uint8_t *)write_buf, 2,
                        ((ar0521_resource_t *)((handle)->resource))->i2cSendFunc);
    return status;

}

static status_t AR0521_ReadReg16(camera_device_handle_t *handle, uint32_t reg, uint16_t *val)
{
	status_t status;
	uint8_t read_buf[2];

    status = SCCB_ReadMultiRegs(AR0521_SCCB_ADDR, kSCCB_RegAddr16Bit, (reg), (uint8_t *)read_buf, 2,
                 ((ar0521_resource_t *)((handle)->resource))->i2cReceiveFunc);

	//val[0] = read_buf[1];
    //val[1] = read_buf[0];

    *val = (read_buf[0] << 8) + read_buf[1];

    return status;
}

static status_t AR0521_ModifyReg16(camera_device_handle_t *handle, uint32_t reg, uint32_t clrMask, uint16_t val)
{
	status_t status;
	uint16_t RegVal;

    status = AR0521_ReadReg16(handle, reg, &RegVal);

    if (kStatus_Success != status)
    {
        return status;
    }


    RegVal = (uint16_t)(RegVal & ~((uint16_t)clrMask)) | (val & clrMask);

    status = AR0521_WriteReg16(handle, reg, RegVal);
    if (kStatus_Success != status)
    {
        return status;
    }

    return status;
}

static status_t AR0521_CheckChipID(camera_device_handle_t *handle)
{
	status_t status;
	uint16_t model_id, customer_rev;

	status = AR0521_ReadReg16(handle, AR0521_MODEL_ID, &model_id);

	if (model_id != AR0521_CHIP_ID)
	{
#ifdef AR0521_DEBUG
	    PRINTF("Wrong chip version: 0x%04x <-> 0x%04x\r\n",
			model_id, AR0521_CHIP_ID);
#endif
		return status;
	}

	AR0521_CHECK_RET(AR0521_ReadReg16(handle, AR0521_CUSTOMER_REV, &customer_rev));
#ifdef AR0521_DEBUG
	PRINTF("Device ID: 0x%04x customer rev: 0x%04x\r\n", model_id, customer_rev);
#endif
	return kStatus_Success;
}

static status_t AR0521_LoadRegVal(camera_device_handle_t *handle, const ar0521_reg_val_t regVal[], uint32_t num)
{
    uint32_t i;
    status_t status;

    for (i = 0; i < num; i++)
    {
        status = AR0521_WriteReg16(handle, regVal[i].regAddr, regVal[i].regVal);

        if (kStatus_Success != status)
        {
            return status;
        }
    }

    return kStatus_Success;
}

static status_t AR0521_SoftwareReset(camera_device_handle_t *handle)
{
	return AR0521_ModifyReg16(handle, AR0521_RESET_REGISTER, (uint8_t)BIT_RESET, (uint8_t)1U << 0);
}

status_t AR0521_Init(camera_device_handle_t *handle, const camera_config_t *config)
{
    status_t status;

    AR0521_CHECK_RET(AR0521_SoftwareReset(handle));

    /* Delay 20ms. */
    AR0521_DelayMs(20);

    AR0521_CHECK_RET(AR0521_CheckChipID(handle));

    /* Delay 5ms. */
    AR0521_DelayMs(5);

    /* Initialize. */
    status = AR0521_LoadRegVal(handle, ar0521InitParam, ARRAY_SIZE(ar0521InitParam));
    if (kStatus_Success != status)
    {
        return status;
    }


    return kStatus_Success;
}

status_t AR0521_Deinit(camera_device_handle_t *handle)
{
    return kStatus_Success;
}

status_t AR0521_Control(camera_device_handle_t *handle, camera_device_cmd_t cmd, int32_t arg)
{
    return kStatus_InvalidArgument;
}

status_t AR0521_Start(camera_device_handle_t *handle)
{
    return kStatus_Success;
}

status_t AR0521_Stop(camera_device_handle_t *handle)
{
    return kStatus_Success;
}

status_t AR0521_InitExt(camera_device_handle_t *handle, const camera_config_t *config, const void *specialConfig)
{
    return AR0521_Init(handle, config);
}

