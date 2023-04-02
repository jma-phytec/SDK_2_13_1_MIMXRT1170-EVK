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
		{ 0x3d00, 0x043e },
		{ 0x3d02, 0x4760 },
		{ 0x3d04, 0xffff },
		{ 0x3d06, 0xffff },
		{ 0x3d08, 0x8000 },
		{ 0x3d0a, 0x0510 },
		{ 0x3d0c, 0xaf08 },
		{ 0x3d0e, 0x0252 },
		{ 0x3d10, 0x486f },
		{ 0x3d12, 0x5d5d },
		{ 0x3d14, 0x8056 },
		{ 0x3d16, 0x8313 },
		{ 0x3d18, 0x0087 },
		{ 0x3d1a, 0x6a48 },
		{ 0x3d1c, 0x6982 },
		{ 0x3d1e, 0x0280 },
		{ 0x3d20, 0x8359 },
		{ 0x3d22, 0x8d02 },
		{ 0x3d24, 0x8020 },
		{ 0x3d26, 0x4882 },
		{ 0x3d28, 0x4269 },
		{ 0x3d2a, 0x6a95 },
		{ 0x3d2c, 0x5988 },
		{ 0x3d2e, 0x5a83 },
		{ 0x3d30, 0x5885 },
		{ 0x3d32, 0x6280 },
		{ 0x3d34, 0x6289 },
		{ 0x3d36, 0x6097 },
		{ 0x3d38, 0x5782 },
		{ 0x3d3a, 0x605c },
		{ 0x3d3c, 0xbf18 },
		{ 0x3d3e, 0x0961 },
		{ 0x3d40, 0x5080 },
		{ 0x3d42, 0x2090 },
		{ 0x3d44, 0x4390 },
		{ 0x3d46, 0x4382 },
		{ 0x3d48, 0x5f8a },
		{ 0x3d4a, 0x5d5d },
		{ 0x3d4c, 0x9c63 },
		{ 0x3d4e, 0x8063 },
		{ 0x3d50, 0xa960 },
		{ 0x3d52, 0x9757 },
		{ 0x3d54, 0x8260 },
		{ 0x3d56, 0x5cff },
		{ 0x3d58, 0xbf10 },
		{ 0x3d5a, 0x1681 },
		{ 0x3d5c, 0x0802 },
		{ 0x3d5e, 0x8000 },
		{ 0x3d60, 0x141c },
		{ 0x3d62, 0x6000 },
		{ 0x3d64, 0x6022 },
		{ 0x3d66, 0x4d80 },
		{ 0x3d68, 0x5c97 },
		{ 0x3d6a, 0x6a69 },
		{ 0x3d6c, 0xac6f },
		{ 0x3d6e, 0x4645 },
		{ 0x3d70, 0x4400 },
		{ 0x3d72, 0x0513 },
		{ 0x3d74, 0x8069 },
		{ 0x3d76, 0x6ac6 },
		{ 0x3d78, 0x5f95 },
		{ 0x3d7a, 0x5f70 },
		{ 0x3d7c, 0x8040 },
		{ 0x3d7e, 0x4a81 },
		{ 0x3d80, 0x0300 },
		{ 0x3d82, 0xe703 },
		{ 0x3d84, 0x0088 },
		{ 0x3d86, 0x4a83 },
		{ 0x3d88, 0x40ff },
		{ 0x3d8a, 0xffff },
		{ 0x3d8c, 0xfd70 },
		{ 0x3d8e, 0x8040 },
		{ 0x3d90, 0x4a85 },
		{ 0x3d92, 0x4fa8 },
		{ 0x3d94, 0x4f8c },
		{ 0x3d96, 0x0070 },
		{ 0x3d98, 0xbe47 },
		{ 0x3d9a, 0x8847 },
		{ 0x3d9c, 0xbc78 },
		{ 0x3d9e, 0x6b89 },
		{ 0x3da0, 0x6a80 },
		{ 0x3da2, 0x6986 },
		{ 0x3da4, 0x6b8e },
		{ 0x3da6, 0x6b80 },
		{ 0x3da8, 0x6980 },
		{ 0x3daa, 0x6a88 },
		{ 0x3dac, 0x7c9f },
		{ 0x3dae, 0x866b },
		{ 0x3db0, 0x8765 },
		{ 0x3db2, 0x46ff },
		{ 0x3db4, 0xe365 },
		{ 0x3db6, 0xa679 },
		{ 0x3db8, 0x4a40 },
		{ 0x3dba, 0x4580 },
		{ 0x3dbc, 0x44bc },
		{ 0x3dbe, 0x7000 },
		{ 0x3dc0, 0x8040 },
		{ 0x3dc2, 0x0802 },
		{ 0x3dc4, 0x10ef },
		{ 0x3dc6, 0x0104 },
		{ 0x3dc8, 0x3860 },
		{ 0x3dca, 0x5d5d },
		{ 0x3dcc, 0x5682 },
		{ 0x3dce, 0x1300 },
		{ 0x3dd0, 0x8648 },
		{ 0x3dd2, 0x8202 },
		{ 0x3dd4, 0x8082 },
		{ 0x3dd6, 0x598a },
		{ 0x3dd8, 0x0280 },
		{ 0x3dda, 0x2048 },
		{ 0x3ddc, 0x3060 },
		{ 0x3dde, 0x8042 },
		{ 0x3de0, 0x9259 },
		{ 0x3de2, 0x865a },
		{ 0x3de4, 0x8258 },
		{ 0x3de6, 0x8562 },
		{ 0x3de8, 0x8062 },
		{ 0x3dea, 0x8560 },
		{ 0x3dec, 0x9257 },
		{ 0x3dee, 0x8221 },
		{ 0x3df0, 0x10ff },
		{ 0x3df2, 0xb757 },
		{ 0x3df4, 0x9361 },
		{ 0x3df6, 0x1019 },
		{ 0x3df8, 0x8020 },
		{ 0x3dfa, 0x9043 },
		{ 0x3dfc, 0x8b43 },
		{ 0x3dfe, 0x875f },
		{ 0x3e00, 0x835d },
		{ 0x3e02, 0x805d },
		{ 0x3e04, 0x8163 },
		{ 0x3e06, 0x8063 },
		{ 0x3e08, 0xa060 },
		{ 0x3e0a, 0x9157 },
		{ 0x3e0c, 0x8260 },
		{ 0x3e0e, 0x5cff },
		{ 0x3e10, 0xffff },
		{ 0x3e12, 0xffe5 },
		{ 0x3e14, 0x1016 },
		{ 0x3e16, 0x2048 },
		{ 0x3e18, 0x0802 },
		{ 0x3e1a, 0x1c60 },
		{ 0x3e1c, 0x0014 },
		{ 0x3e1e, 0x0060 },
		{ 0x3e20, 0x2205 },
		{ 0x3e22, 0x8120 },
		{ 0x3e24, 0x908f },
		{ 0x3e26, 0x6a80 },
		{ 0x3e28, 0x6982 },
		{ 0x3e2a, 0x5f9f },
		{ 0x3e2c, 0x6f46 },
		{ 0x3e2e, 0x4544 },
		{ 0x3e30, 0x0005 },
		{ 0x3e32, 0x8013 },
		{ 0x3e34, 0x8069 },
		{ 0x3e36, 0x6a80 },
		{ 0x3e38, 0x7000 },
		{ 0x3e3a, 0x0000 },
		{ 0x3e3c, 0x0000 },
		{ 0x3e3e, 0x0000 },
		{ 0x3e40, 0x0000 },
		{ 0x3e42, 0x0000 },
		{ 0x3e44, 0x0000 },
		{ 0x3e46, 0x0000 },
		{ 0x3e48, 0x0000 },
		{ 0x3e4a, 0x0000 },
		{ 0x3e4c, 0x0000 },
		{ 0x3e4e, 0x0000 },
		{ 0x3e50, 0x0000 },
		{ 0x3e52, 0x0000 },
		{ 0x3e54, 0x0000 },
		{ 0x3e56, 0x0000 },
		{ 0x3e58, 0x0000 },
		{ 0x3e5a, 0x0000 },
		{ 0x3e5c, 0x0000 },
		{ 0x3e5e, 0x0000 },
		{ 0x3e60, 0x0000 },
		{ 0x3e62, 0x0000 },
		{ 0x3e64, 0x0000 },
		{ 0x3e66, 0x0000 },
		{ 0x3e68, 0x0000 },
		{ 0x3e6a, 0x0000 },
		{ 0x3e6c, 0x0000 },
		{ 0x3e6e, 0x0000 },
		{ 0x3e70, 0x0000 },
		{ 0x3e72, 0x0000 },
		{ 0x3e74, 0x0000 },
		{ 0x3e76, 0x0000 },
		{ 0x3e78, 0x0000 },
		{ 0x3e7a, 0x0000 },
		{ 0x3e7c, 0x0000 },
		{ 0x3e7e, 0x0000 },
		{ 0x3e80, 0x0000 },
		{ 0x3e82, 0x0000 },
		{ 0x3e84, 0x0000 },
		{ 0x3e86, 0x0000 },
		{ 0x3e88, 0x0000 },
		{ 0x3e8a, 0x0000 },
		{ 0x3e8c, 0x0000 },
		{ 0x3e8e, 0x0000 },
		{ 0x3e90, 0x0000 },
		{ 0x3e92, 0x0000 },
		{ 0x3e94, 0x0000 },
		{ 0x3e96, 0x0000 },
		{ 0x3e98, 0x0000 },
		{ 0x3e9a, 0x0000 },
		{ 0x3e9c, 0x0000 },
		{ 0x3e9e, 0x0000 },
		{ 0x3ea0, 0x0000 },
		{ 0x3ea2, 0x0000 },
		{ 0x3ea4, 0x0000 },
		{ 0x3ea6, 0x0000 },
		{ 0x3ea8, 0x0000 },
		{ 0x3eaa, 0x0000 },
		{ 0x3eac, 0x0000 },
		{ 0x3eae, 0x0000 },
		{ 0x3eb0, 0x0000 },
		{ 0x3eb2, 0x0000 },
		{ 0x3eb4, 0x0000 },
};

const camera_device_operations_t ar0521_ops = {
    .init     = AR0521_Init,
    .deinit   = AR0521_Deinit,
    .start    = AR0521_Start,
    .stop     = AR0521_Stop,
    .control  = AR0521_Control,
    .init_ext = AR0521_InitExt,
};

struct ar0521 ar0521_sensor;
struct ar0521 *sensor = &ar0521_sensor;

/*******************************************************************************
 * Code
 ******************************************************************************/

static inline int bpp_to_index(unsigned int bpp)
{
	return (bpp - 8) / 2;
}

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
	if (sensor->model == AR0521_MODEL_UNKNOWN)
	{
		if (customer_rev & BIT(4))
			sensor->model = AR0521_MODEL_COLOR;
		else
			sensor->model = AR0521_MODEL_MONOCHROME;
	}

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

static const struct ar0521_format ar0521_mono_formats[] = {
	{
		.code	= MEDIA_BUS_FMT_Y8_1X8,
		.bpp	= 8,
	}, {
		.code	= MEDIA_BUS_FMT_Y10_1X10,
		.bpp	= 10,
	}, {
		.code	= MEDIA_BUS_FMT_Y12_1X12,
		.bpp	= 12,
	},
};

static const struct ar0521_format ar0521_col_formats[] = {
	{
		.code	= MEDIA_BUS_FMT_SGRBG8_1X8,
		.bpp	= 8,
	}, {
		.code	= MEDIA_BUS_FMT_SGRBG10_1X10,
		.bpp	= 10,
	}, {
		.code	= MEDIA_BUS_FMT_SGRBG12_1X12,
		.bpp	= 12,
	},
};

static void ar0521_set_defaults(void)
{
	sensor->limits = (struct ar0521_sensor_limits) {
					/* min		max	 */
		.x 			= {0        ,	2603      },
		.y 			= {0        ,	1955      },
		.hlen 			= {3080     ,	65532     },
		.vlen 			= {48       ,	65535     },
		.hblank 		= {240      ,	65535     },
		.vblank 		= {28       ,	65535     },
		.ext_clk 		= {5000000  ,	64000000  },
	};

	sensor->crop.left = 4;
	sensor->crop.top = 4;
	sensor->crop.width = AR0521_DEF_WIDTH;
	sensor->crop.height = AR0521_DEF_HEIGHT;

	sensor->fmt.width = AR0521_DEF_WIDTH;
	sensor->fmt.height = AR0521_DEF_HEIGHT;
	sensor->fmt.field = V4L2_FIELD_NONE;
	sensor->fmt.colorspace = V4L2_COLORSPACE_RAW;

	if (sensor->model == AR0521_MODEL_MONOCHROME) {
		sensor->formats = ar0521_mono_formats;
		sensor->num_fmts = ARRAY_SIZE(ar0521_mono_formats);
	} else {
		sensor->formats = ar0521_col_formats;
		sensor->num_fmts = ARRAY_SIZE(ar0521_col_formats);
	}

	sensor->fmt.code = sensor->formats[sensor->num_fmts - 1].code;
	sensor->bpp = sensor->formats[sensor->num_fmts - 1].bpp;

	sensor->w_scale = 1;
	sensor->h_scale = 1;
	sensor->hblank = sensor->limits.hblank.min;
	sensor->vblank = sensor->limits.vblank.min;
	sensor->hlen = sensor->limits.hlen.min;
	sensor->vlen = sensor->fmt.height + sensor->vblank;
	sensor->gains.red = 1000;
	sensor->gains.greenr = 1000;
	sensor->gains.greenb = 1000;
	sensor->gains.blue = 1000;
	sensor->gains.min_ref = 1000;

	return;
}

static int ar0521_mipi_enter_lp11(camera_device_handle_t *handle)
{
	int ret;

	AR0521_WriteReg16(handle, AR0521_SERIAL_TEST,
			   AR0521_TEST_MODE_LP11 |
			   AR0521_TEST_LANE_0 | AR0521_TEST_LANE_1 |
			   AR0521_TEST_LANE_2 | AR0521_TEST_LANE_3);

	AR0521_ModifyReg16(handle, AR0521_SER_CTRL_STAT, BIT_FRAMER_TEST_MODE, 1);

	AR0521_ModifyReg16(handle, AR0521_RESET_REGISTER, BIT_STREAM, 1);
	AR0521_ModifyReg16(handle, AR0521_RESET_REGISTER, BIT_SMIA_SER_DIS, 0);

	return ret;
}

static int ar0521_enter_standby(camera_device_handle_t *handle)
{
	uint16_t timeout = 1000;
	int ret;
	uint16_t val;

	AR0521_ModifyReg16(handle, AR0521_RESET_REGISTER, BIT_STREAM, 0);

	while(timeout)
	{
		AR0521_ReadReg16(handle, AR0521_FRAME_STATUS, &val);

		if (val & BIT_STANDBY_STATUS)
		{
			break;
		}
		timeout--;
		AR0521_DelayMs(5);
	}

	AR0521_DelayMs(5);

	AR0521_ModifyReg16(handle, AR0521_RESET_REGISTER, BIT_SMIA_SER_DIS, 1);

	AR0521_ModifyReg16(handle, AR0521_SER_CTRL_STAT, BIT_FRAMER_TEST_MODE, 0);

	return 0;
}

static int ar0521_s_power(camera_device_handle_t *handle, int on)
{
	int ret = 0;

	if(on)
	{
		/* Enable MIPI LP-11 test mode as required by e.g. i.MX 6 */
		if(!sensor->is_streaming)
		{
			ret = ar0521_mipi_enter_lp11(handle);
		}
	}
	else
	{
		ar0521_enter_standby(handle);
	}

	return ret;
}

static int ar0521_config_pll(camera_device_handle_t *handle)
{
	int index;
	int ret;

	index = bpp_to_index(sensor->bpp);

	AR0521_WriteReg16(handle, AR0521_VT_PIX_CLK_DIV, sensor->pll[index].vt_pix_div);

	AR0521_WriteReg16(handle, AR0521_VT_SYS_CLK_DIV, sensor->pll[index].vt_sys_div);

	AR0521_WriteReg16(handle, AR0521_PRE_PLL_CLK_DIV,
			   BIT_PLL_DIV2(sensor->pll[index].pll2_div) |
			   BIT_PLL_DIV1(sensor->pll[index].pll_div));

	AR0521_WriteReg16(handle, AR0521_PLL_MUL,
			   BIT_PLL_MUL2(sensor->pll[index].pll2_mul) |
			   BIT_PLL_MUL1(sensor->pll[index].pll_mul));

	AR0521_WriteReg16(handle, AR0521_OP_PIX_CLK_DIV,
			   sensor->pll[index].op_pix_div);

	AR0521_WriteReg16(handle, AR0521_OP_SYS_CLK_DIV,
			   sensor->pll[index].op_sys_div);

    AR0521_DelayMs(5);

	return 0;
}

static int ar0521_config_frame(camera_device_handle_t *handle)
{
	unsigned int height = sensor->fmt.height * sensor->h_scale;
	unsigned int width = sensor->fmt.width * sensor->w_scale;
	int ret;
	uint16_t x_end, y_end;

	AR0521_WriteReg16(handle, AR0521_Y_ADDR_START, sensor->crop.top);

	AR0521_WriteReg16(handle, AR0521_X_ADDR_START, sensor->crop.left);

	y_end = sensor->crop.top + height - 1;
	AR0521_WriteReg16(handle, AR0521_Y_ADRR_END, y_end);

	x_end = sensor->crop.left + width - 1;
	AR0521_WriteReg16(handle, AR0521_X_ADRR_END, x_end);

	AR0521_WriteReg16(handle, AR0521_FRAME_LENGTH_LINES, sensor->vlen);

	AR0521_WriteReg16(handle, AR0521_LINE_LENGTH_PCK, sensor->hlen);

	AR0521_WriteReg16(handle, AR0521_X_OUTPUT_SIZE, sensor->fmt.width);

	AR0521_WriteReg16(handle, AR0521_Y_OUTPUT_SIZE, sensor->fmt.height);

	AR0521_WriteReg16(handle, AR0521_X_ODD_INC, (sensor->w_scale << 1) - 1);

	AR0521_WriteReg16(handle, AR0521_Y_ODD_INC, (sensor->h_scale << 1) - 1);

	return ret;
}

static int ar0521_config_mipi(camera_device_handle_t *handle)
{
	int ret;
	uint16_t val;

	switch (sensor->bpp) {
	case 8:
		val = AR0521_CSI2_DT_RAW8;
		break;
	case 10:
		val = AR0521_CSI2_DT_RAW10;
		break;
	case 12:
		val = AR0521_CSI2_DT_RAW12;
		break;
	}

	AR0521_WriteReg16(handle, AR0521_MIPI_CNTRL, val);

	AR0521_WriteReg16(handle, AR0521_MIPI_TIMING_0,
			   BIT_HS_PREP(sensor->info.t_hs_prep) |
			   BIT_HS_ZERO(sensor->info.t_hs_zero) |
			   BIT_HS_TRAIL(sensor->info.t_hs_trail));

	AR0521_WriteReg16(handle, AR0521_MIPI_TIMING_1,
			   BIT_CLK_PREP(sensor->info.t_clk_prep) |
			   BIT_CLK_ZERO(sensor->info.t_clk_zero) |
			   BIT_CLK_TRAIL(sensor->info.t_clk_trail));

	AR0521_WriteReg16(handle, AR0521_MIPI_TIMING_2,
			   BIT_BGAP(sensor->info.t_bgap) |
			   BIT_CLK_PRE(sensor->info.t_clk_pre) |
			   BIT_CLK_POST_MSBS(sensor->info.t_clk_post_msbs));

	AR0521_WriteReg16(handle, AR0521_MIPI_TIMING_3,
			   BIT_LPX(sensor->info.t_lpx) |
			   BIT_WAKEUP(sensor->info.t_wakeup) |
			   BIT_CLK_POST(sensor->info.t_clk_post));

	AR0521_WriteReg16(handle, AR0521_MIPI_TIMING_4,
			   (sensor->info.cont_tx_clk ? BIT_CONT_TX_CLK : 0) |
			   (sensor->info.vreg_mode ? BIT_VREG_MODE : 0) |
			   BIT_HS_EXIT(sensor->info.t_hs_exit) |
			   BIT_INIT(sensor->info.t_init));

	AR0521_WriteReg16(handle, AR0521_DATA_FORMAT_BITS,
			   BIT_DATA_FMT_IN(sensor->bpp) |
			   BIT_DATA_FMT_OUT(sensor->bpp));

	AR0521_WriteReg16(handle, AR0521_SERIAL_FORMAT,
			   BIT_TYPE(AR0521_TYPE_MIPI) |
			   BIT_LANES(sensor->info.num_lanes));

	AR0521_ModifyReg16(handle, AR0521_RESET_REGISTER, BIT_STREAM, 1);
	AR0521_ModifyReg16(handle, AR0521_RESET_REGISTER, BIT_MASK_BAD, 1);

	AR0521_ModifyReg16(handle, AR0521_RESET_REGISTER, BIT_SMIA_SER_DIS, 0);

	AR0521_ModifyReg16(handle, 0x3f20, BIT(3), 0);

	return ret;
}

static int ar0521_stream_on(camera_device_handle_t *handle)
{
	int ret;

	ret = ar0521_enter_standby(handle);

	ret = ar0521_config_pll(handle);

	ret = ar0521_config_frame(handle);

	ret = ar0521_config_mipi(handle);

	sensor->is_streaming = true;
	return 0;
}

static int ar0521_stream_off(camera_device_handle_t *handle)
{
	int ret;

	ret = ar0521_enter_standby(handle);

	sensor->is_streaming = false;
	return ret;
}


static int ar0521_s_stream(camera_device_handle_t *handle, int enable)
{
	int ret = 0;

	if(enable && sensor->is_streaming)
	{
		return -1;
	}

	if(!enable && !sensor->is_streaming)
		return 0;

	if(enable)
	{
		ret = ar0521_stream_on(handle);
	}
	else
	{
		ret = ar0521_stream_off(handle);
	}

	return ret;
}

static uint32_t ar0521_clk_mul_div(uint32_t freq, uint16_t mul, uint16_t div)
{
	uint32_t result;

	result = freq;
	result *= mul;
	result = (result/div);

	return result;
}

static int ar0521_calculate_pll(struct ar0521_pll_config *pll,
				unsigned long ext_freq,
				uint32_t link_freq,
				uint16_t bpp,
				uint16_t lanes)
{
	unsigned long op_clk;
	unsigned long vco;
	unsigned long pix_clk;
	unsigned long pix_clk_target;
	unsigned long diff, diff_old;
	unsigned int div, mul;
	const struct limit_range div_lim = {.min = 1, .max = 63};
	const struct limit_range mul_lim = {.min = 32, .max = 254};
	const struct limit_range pix_lim = {.min = 84000000, .max = 207000000};
	const struct limit_range vco_lim = {
		.min = 320000000,
		.max = 1280000000
	};

	pix_clk_target = ar0521_clk_mul_div(link_freq, 2 * lanes, bpp);
	diff_old = pix_clk_target;

	pll->pll_div = 3;
	pll->pll_mul = 89;
	pll->pll2_div = 1;
	pll->pll2_mul = 0;
	pll->op_sys_div = 1;
	pll->op_pix_div = 2;
	pll->vt_sys_div = 1;
	pll->vt_pix_div = bpp / 2;

	div = div_lim.min;
	mul = mul_lim.min;

	while (div <= div_lim.max) {
		if (mul % 2 != 0)
			mul++;

		if (mul > mul_lim.max) {
			mul = mul_lim.min;
			div++;
			if (div > div_lim.max)
				break;
		}

		vco = ar0521_clk_mul_div(ext_freq, mul, div);

		if (vco < vco_lim.min || vco > vco_lim.max) {
			mul++;
			continue;
		}

		pix_clk = ar0521_clk_mul_div(vco, 2, pll->vt_pix_div);
		op_clk = ar0521_clk_mul_div(pix_clk, 1, 4);

		if (pix_clk < (2 * pix_lim.min) ||
		    pix_clk > (2 * pix_lim.max)) {
			mul++;
			continue;
		}

		if (pix_clk > pix_clk_target) {
			mul++;
			continue;
		}

		diff = pix_clk_target - pix_clk;
		if (diff >= diff_old) {
			mul++;
			continue;
		}

		diff_old = diff;

		pll->pll2_div = div;
		pll->pll2_mul = mul;
		pll->vco_freq = vco;
		pll->pix_freq = pix_clk;
		pll->ser_freq = ar0521_clk_mul_div(pix_clk, bpp, 2 * lanes);

		mul++;
	}

	return 0;
}

static int ar0521_parse_endpoint(void)
{
	uint32_t *link_freqs;
	uint32_t ext_freq = 27000000;
	uint16_t tmp;
	int i;
	int ret;

	sensor->info.num_lanes = 2;
	sensor->info.flags |= V4L2_MBUS_CSI2_CONTINUOUS_CLOCK;
	sensor->info.flags |= V4L2_MBUS_CSI2_CHANNEL_0;
	switch (sensor->info.num_lanes) {
	case 2:
		sensor->info.flags |= V4L2_MBUS_CSI2_2_LANE;
		break;
	case 4:
		sensor->info.flags |= V4L2_MBUS_CSI2_4_LANE;
		break;
	default:
		break;
	}

	for (i = 0; i < 3; i++) {
		ret = ar0521_calculate_pll(&sensor->pll[i], ext_freq,
					   50400000,
					   (i*2+8),
					   sensor->info.num_lanes);
		link_freqs[i] = sensor->pll[i].ser_freq;
	}

	sensor->info.link_freqs = link_freqs;
	sensor->pll[3] = sensor->pll[AR0521_FREQ_MENU_12BIT];
	sensor->info.t_hs_prep = 2;
	sensor->info.t_hs_zero = 15;
	sensor->info.t_hs_trail = 9;
	sensor->info.t_clk_prep = 2;
	sensor->info.t_clk_zero = 34;
	sensor->info.t_clk_trail = 10;
	sensor->info.t_bgap = 10;
	sensor->info.t_clk_pre = 1;
	sensor->info.t_clk_post_msbs = 3;
	sensor->info.t_lpx = 7;
	sensor->info.t_wakeup = 15;
	sensor->info.t_clk_post = 1;
	sensor->info.cont_tx_clk = true;
	sensor->info.vreg_mode = false;
	sensor->info.t_hs_exit = 13;
	sensor->info.t_init = 12;

	return ret;
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

	ar0521_set_defaults();

    /* Initialize. */
    status = AR0521_LoadRegVal(handle, ar0521InitParam, ARRAY_SIZE(ar0521InitParam));
    if (kStatus_Success != status)
    {
        return status;
    }

    ar0521_parse_endpoint();

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
	ar0521_s_power(handle, 1);

	ar0521_s_stream(handle, 1);

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

