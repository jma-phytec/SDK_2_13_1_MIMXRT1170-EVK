/*
 * Copyright 2017-2018, 2020 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_AR0521_H_
#define _FSL_AR0521_H_

#include "fsl_common.h"
#include "fsl_sccb.h"

/*
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BIT(nr)			((1) << (nr))

#define	AR0521_MODEL_ID				0x3000
#define	AR0521_RESET_REGISTER			0x301a
#define		BIT_RESET			BIT(0)


#define AR0521_CHIP_ID			0x0457
#define	AR0521_CUSTOMER_REV			0x31fe


/*!
 * @brief AR0521 resource.
 *
 * Before initialize the AR0521, the resource must be initialized that the SCCB
 * I2C could start to work.
 */
typedef struct _ar0521_resource
{
    sccb_i2c_send_func_t i2cSendFunc;       /*!< I2C send function. */
    sccb_i2c_receive_func_t i2cReceiveFunc; /*!< I2C receive function. */
} ar0521_resource_t;

/*! @brief AR0521 operation functions. */
extern const camera_device_operations_t ar0521_ops;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif /* _FSL_AR0521_H_ */
