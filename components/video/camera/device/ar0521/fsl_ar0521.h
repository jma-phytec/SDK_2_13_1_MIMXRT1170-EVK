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
#define	AR0521_FRAME_LENGTH_LINES		0x300a
#define	AR0521_LINE_LENGTH_PCK			0x300c
#define	AR0521_RESET_REGISTER			0x301a
#define		BIT_GROUPED_PARAM_HOLD		BIT(15)
#define		BIT_GAIN_INSERT_ALL		BIT(14)
#define		BIT_SMIA_SER_DIS		BIT(12)
#define		BIT_FORCED_PLL_ON		BIT(11)
#define		BIT_RESTART_BAD			BIT(10)
#define		BIT_MASK_BAD			BIT(9)
#define		BIT_GPI_EN			BIT(8)
#define		BIT_LOCK_REG			BIT(3)
#define		BIT_STREAM			BIT(2)
#define		BIT_RESTART			BIT(1)
#define		BIT_RESET			BIT(0)
#define	AR0521_FRAME_STATUS			0x303c
#define		BIT_PLL_LOCKED			BIT(3)
#define		BIT_FRAME_START_DURING_GPH	BIT(2)
#define		BIT_STANDBY_STATUS		BIT(1)
#define		BIT_FRAMESYNC			BIT(0)
#define	AR0521_SER_CTRL_STAT			0x31c6
#define		BIT_FRAMER_TEST_MODE		BIT(7)
#define	AR0521_SERIAL_TEST			0x3066
#define AR0521_TEST_LANE_0		(0x1 << 6)
#define AR0521_TEST_LANE_1		(0x2 << 6)
#define AR0521_TEST_LANE_2		(0x4 << 6)
#define AR0521_TEST_LANE_3		(0x8 << 6)
#define AR0521_TEST_MODE_LP11		(0x1 << 2)
#define	AR0521_VT_PIX_CLK_DIV			0x0300
#define	AR0521_VT_SYS_CLK_DIV			0x0302
#define	AR0521_PRE_PLL_CLK_DIV			0x0304
#define		BIT_PLL_DIV2(n)			((n) << 8)
#define		BIT_PLL_DIV1(n)			(n)
#define	AR0521_PLL_MUL				0x0306
#define		BIT_PLL_MUL2(n)			((n) << 8)
#define		BIT_PLL_MUL1(n)			(n)
#define	AR0521_OP_PIX_CLK_DIV			0x0308
#define	AR0521_OP_SYS_CLK_DIV			0x030a
#define	AR0521_X_ADDR_START			0x0344
#define	AR0521_Y_ADDR_START			0x0346
#define	AR0521_X_ADRR_END			0x0348
#define	AR0521_Y_ADRR_END			0x034a
#define	AR0521_X_OUTPUT_SIZE			0x034c
#define	AR0521_Y_OUTPUT_SIZE			0x034e
#define	AR0521_X_ODD_INC			0x30a2
#define	AR0521_Y_ODD_INC			0x30a6

#define	AR0521_DATA_FORMAT_BITS			0x0112
#define		BIT_DATA_FMT_IN(n)		((n) << 8)
#define		BIT_DATA_FMT_OUT(n)		(n)
#define	AR0521_SERIAL_FORMAT			0x31ae
#define		BIT_TYPE(n)			((n) << 8)
#define		BIT_LANES(n)			(n)
#define AR0521_MIPI_CNTRL			0x3354
#define	AR0521_MIPI_TIMING_0			0x31b4
#define		BIT_HS_PREP(n)			((n) << 12)
#define		BIT_HS_ZERO(n)			((n) << 6)
#define		BIT_HS_TRAIL(n)			((n) << 1)
#define	AR0521_MIPI_TIMING_1			0x31b6
#define		BIT_CLK_PREP(n)			((n) << 12)
#define		BIT_CLK_ZERO(n)			((n) << 5)
#define		BIT_CLK_TRAIL(n)		(n)
#define	AR0521_MIPI_TIMING_2			0x31b8
#define		BIT_BGAP(n)			((n) << 10)
#define		BIT_CLK_PRE(n)			((n) << 4)
#define		BIT_CLK_POST_MSBS(n)		(n)
#define	AR0521_MIPI_TIMING_3			0x31ba
#define		BIT_LPX(n)			((n) << 10)
#define		BIT_WAKEUP(n)			((n) << 3)
#define		BIT_CLK_POST(n)			(n)
#define	AR0521_MIPI_TIMING_4			0x31bc
#define		BIT_CONT_TX_CLK			BIT(15)
#define		BIT_VREG_MODE			BIT(13)
#define		BIT_HS_EXIT(n)			((n) << 7)
#define		BIT_INIT(n)			(n)


#define AR0521_CHIP_ID			0x0457
#define	AR0521_CUSTOMER_REV			0x31fe
#define AR0521_DEF_WIDTH		2592
#define AR0521_DEF_HEIGHT		1944

#define AR0521_CSI2_DT_RAW8		0x2a
#define AR0521_CSI2_DT_RAW10		0x2b
#define AR0521_CSI2_DT_RAW12		0x2c
#define AR0521_TYPE_MIPI		2


/* YUV (including grey) - next is	0x202e */
#define MEDIA_BUS_FMT_Y8_1X8			0x2001
#define MEDIA_BUS_FMT_UV8_1X8			0x2015
#define MEDIA_BUS_FMT_UYVY8_1_5X8		0x2002
#define MEDIA_BUS_FMT_VYUY8_1_5X8		0x2003
#define MEDIA_BUS_FMT_YUYV8_1_5X8		0x2004
#define MEDIA_BUS_FMT_YVYU8_1_5X8		0x2005
#define MEDIA_BUS_FMT_UYVY8_2X8			0x2006
#define MEDIA_BUS_FMT_VYUY8_2X8			0x2007
#define MEDIA_BUS_FMT_YUYV8_2X8			0x2008
#define MEDIA_BUS_FMT_YVYU8_2X8			0x2009
#define MEDIA_BUS_FMT_Y10_1X10			0x200a
#define MEDIA_BUS_FMT_Y10_2X8_PADHI_LE		0x202c
#define MEDIA_BUS_FMT_UYVY10_2X10		0x2018
#define MEDIA_BUS_FMT_VYUY10_2X10		0x2019
#define MEDIA_BUS_FMT_YUYV10_2X10		0x200b
#define MEDIA_BUS_FMT_YVYU10_2X10		0x200c
#define MEDIA_BUS_FMT_Y12_1X12			0x2013
#define MEDIA_BUS_FMT_UYVY12_2X12		0x201c
#define MEDIA_BUS_FMT_VYUY12_2X12		0x201d
#define MEDIA_BUS_FMT_YUYV12_2X12		0x201e
#define MEDIA_BUS_FMT_YVYU12_2X12		0x201f
#define MEDIA_BUS_FMT_Y14_1X14			0x202d
#define MEDIA_BUS_FMT_UYVY8_1X16		0x200f
#define MEDIA_BUS_FMT_VYUY8_1X16		0x2010
#define MEDIA_BUS_FMT_YUYV8_1X16		0x2011
#define MEDIA_BUS_FMT_YVYU8_1X16		0x2012
#define MEDIA_BUS_FMT_YDYUYDYV8_1X16		0x2014
#define MEDIA_BUS_FMT_UYVY10_1X20		0x201a
#define MEDIA_BUS_FMT_VYUY10_1X20		0x201b
#define MEDIA_BUS_FMT_YUYV10_1X20		0x200d
#define MEDIA_BUS_FMT_YVYU10_1X20		0x200e
#define MEDIA_BUS_FMT_VUY8_1X24			0x2024
#define MEDIA_BUS_FMT_YUV8_1X24			0x2025
#define MEDIA_BUS_FMT_UYYVYY8_0_5X24		0x2026
#define MEDIA_BUS_FMT_UYVY12_1X24		0x2020
#define MEDIA_BUS_FMT_VYUY12_1X24		0x2021
#define MEDIA_BUS_FMT_YUYV12_1X24		0x2022
#define MEDIA_BUS_FMT_YVYU12_1X24		0x2023
#define MEDIA_BUS_FMT_YUV10_1X30		0x2016
#define MEDIA_BUS_FMT_UYYVYY10_0_5X30		0x2027
#define MEDIA_BUS_FMT_AYUV8_1X32		0x2017
#define MEDIA_BUS_FMT_UYYVYY12_0_5X36		0x2028
#define MEDIA_BUS_FMT_YUV12_1X36		0x2029
#define MEDIA_BUS_FMT_YUV16_1X48		0x202a
#define MEDIA_BUS_FMT_UYYVYY16_0_5X48		0x202b

/* Bayer - next is	0x3021 */
#define MEDIA_BUS_FMT_SBGGR8_1X8		0x3001
#define MEDIA_BUS_FMT_SGBRG8_1X8		0x3013
#define MEDIA_BUS_FMT_SGRBG8_1X8		0x3002
#define MEDIA_BUS_FMT_SRGGB8_1X8		0x3014
#define MEDIA_BUS_FMT_SBGGR10_ALAW8_1X8		0x3015
#define MEDIA_BUS_FMT_SGBRG10_ALAW8_1X8		0x3016
#define MEDIA_BUS_FMT_SGRBG10_ALAW8_1X8		0x3017
#define MEDIA_BUS_FMT_SRGGB10_ALAW8_1X8		0x3018
#define MEDIA_BUS_FMT_SBGGR10_DPCM8_1X8		0x300b
#define MEDIA_BUS_FMT_SGBRG10_DPCM8_1X8		0x300c
#define MEDIA_BUS_FMT_SGRBG10_DPCM8_1X8		0x3009
#define MEDIA_BUS_FMT_SRGGB10_DPCM8_1X8		0x300d
#define MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_BE	0x3003
#define MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_LE	0x3004
#define MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_BE	0x3005
#define MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_LE	0x3006
#define MEDIA_BUS_FMT_SBGGR10_1X10		0x3007
#define MEDIA_BUS_FMT_SGBRG10_1X10		0x300e
#define MEDIA_BUS_FMT_SGRBG10_1X10		0x300a
#define MEDIA_BUS_FMT_SRGGB10_1X10		0x300f
#define MEDIA_BUS_FMT_SBGGR12_1X12		0x3008
#define MEDIA_BUS_FMT_SGBRG12_1X12		0x3010
#define MEDIA_BUS_FMT_SGRBG12_1X12		0x3011
#define MEDIA_BUS_FMT_SRGGB12_1X12		0x3012
#define MEDIA_BUS_FMT_SBGGR14_1X14		0x3019
#define MEDIA_BUS_FMT_SGBRG14_1X14		0x301a
#define MEDIA_BUS_FMT_SGRBG14_1X14		0x301b
#define MEDIA_BUS_FMT_SRGGB14_1X14		0x301c
#define MEDIA_BUS_FMT_SBGGR16_1X16		0x301d
#define MEDIA_BUS_FMT_SGBRG16_1X16		0x301e
#define MEDIA_BUS_FMT_SGRBG16_1X16		0x301f
#define MEDIA_BUS_FMT_SRGGB16_1X16		0x3020

/* Serial flags */
/* CSI-2 D-PHY number of data lanes. */
#define V4L2_MBUS_CSI2_1_LANE			BIT(0)
#define V4L2_MBUS_CSI2_2_LANE			BIT(1)
#define V4L2_MBUS_CSI2_3_LANE			BIT(2)
#define V4L2_MBUS_CSI2_4_LANE			BIT(3)
/* CSI-2 Virtual Channel identifiers. */
#define V4L2_MBUS_CSI2_CHANNEL_0		BIT(4)
#define V4L2_MBUS_CSI2_CHANNEL_1		BIT(5)
#define V4L2_MBUS_CSI2_CHANNEL_2		BIT(6)
#define V4L2_MBUS_CSI2_CHANNEL_3		BIT(7)
/* Clock non-continuous mode support. */
#define V4L2_MBUS_CSI2_CONTINUOUS_CLOCK		BIT(8)
#define V4L2_MBUS_CSI2_NONCONTINUOUS_CLOCK	BIT(9)

#define V4L2_MBUS_CSI2_LANES		(V4L2_MBUS_CSI2_1_LANE | \
					 V4L2_MBUS_CSI2_2_LANE | \
					 V4L2_MBUS_CSI2_3_LANE | \
					 V4L2_MBUS_CSI2_4_LANE)
#define V4L2_MBUS_CSI2_CHANNELS		(V4L2_MBUS_CSI2_CHANNEL_0 | \
					 V4L2_MBUS_CSI2_CHANNEL_1 | \
					 V4L2_MBUS_CSI2_CHANNEL_2 | \
					 V4L2_MBUS_CSI2_CHANNEL_3)

#define AR0521_FREQ_MENU_8BIT		0
#define AR0521_FREQ_MENU_10BIT		1
#define AR0521_FREQ_MENU_12BIT		2


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

/**
 * enum v4l2_mbus_type - media bus type
 * @V4L2_MBUS_UNKNOWN:	unknown bus type, no V4L2 mediabus configuration
 * @V4L2_MBUS_PARALLEL:	parallel interface with hsync and vsync
 * @V4L2_MBUS_BT656:	parallel interface with embedded synchronisation, can
 *			also be used for BT.1120
 * @V4L2_MBUS_CSI1:	MIPI CSI-1 serial interface
 * @V4L2_MBUS_CCP2:	CCP2 (Compact Camera Port 2)
 * @V4L2_MBUS_CSI2_DPHY: MIPI CSI-2 serial interface, with D-PHY
 * @V4L2_MBUS_CSI2_CPHY: MIPI CSI-2 serial interface, with C-PHY
 * @V4L2_MBUS_INVALID:	invalid bus type (keep as last)
 */
enum v4l2_mbus_type {
	V4L2_MBUS_UNKNOWN,
	V4L2_MBUS_PARALLEL,
	V4L2_MBUS_BT656,
	V4L2_MBUS_CSI1,
	V4L2_MBUS_CCP2,
	V4L2_MBUS_CSI2_DPHY,
	V4L2_MBUS_CSI2_CPHY,
	V4L2_MBUS_INVALID,
};


enum ar0521_model {
	AR0521_MODEL_UNKNOWN,
	AR0521_MODEL_COLOR,
	AR0521_MODEL_MONOCHROME,
};

enum v4l2_field {
	V4L2_FIELD_ANY           = 0, /* driver can choose from none,
					 top, bottom, interlaced
					 depending on whatever it thinks
					 is approximate ... */
	V4L2_FIELD_NONE          = 1, /* this device has no fields ... */
	V4L2_FIELD_TOP           = 2, /* top field only */
	V4L2_FIELD_BOTTOM        = 3, /* bottom field only */
	V4L2_FIELD_INTERLACED    = 4, /* both fields interlaced */
	V4L2_FIELD_SEQ_TB        = 5, /* both fields sequential into one
					 buffer, top-bottom order */
	V4L2_FIELD_SEQ_BT        = 6, /* same as above + bottom-top order */
	V4L2_FIELD_ALTERNATE     = 7, /* both fields alternating into
					 separate buffers */
	V4L2_FIELD_INTERLACED_TB = 8, /* both fields interlaced, top field
					 first and the top field is
					 transmitted first */
	V4L2_FIELD_INTERLACED_BT = 9, /* both fields interlaced, top field
					 first and the bottom field is
					 transmitted first */
};

enum v4l2_colorspace {
	/*
	 * Default colorspace, i.e. let the driver figure it out.
	 * Can only be used with video capture.
	 */
	V4L2_COLORSPACE_DEFAULT       = 0,

	/* SMPTE 170M: used for broadcast NTSC/PAL SDTV */
	V4L2_COLORSPACE_SMPTE170M     = 1,

	/* Obsolete pre-1998 SMPTE 240M HDTV standard, superseded by Rec 709 */
	V4L2_COLORSPACE_SMPTE240M     = 2,

	/* Rec.709: used for HDTV */
	V4L2_COLORSPACE_REC709        = 3,

	/*
	 * Deprecated, do not use. No driver will ever return this. This was
	 * based on a misunderstanding of the bt878 datasheet.
	 */
	V4L2_COLORSPACE_BT878         = 4,

	/*
	 * NTSC 1953 colorspace. This only makes sense when dealing with
	 * really, really old NTSC recordings. Superseded by SMPTE 170M.
	 */
	V4L2_COLORSPACE_470_SYSTEM_M  = 5,

	/*
	 * EBU Tech 3213 PAL/SECAM colorspace.
	 */
	V4L2_COLORSPACE_470_SYSTEM_BG = 6,

	/*
	 * Effectively shorthand for V4L2_COLORSPACE_SRGB, V4L2_YCBCR_ENC_601
	 * and V4L2_QUANTIZATION_FULL_RANGE. To be used for (Motion-)JPEG.
	 */
	V4L2_COLORSPACE_JPEG          = 7,

	/* For RGB colorspaces such as produces by most webcams. */
	V4L2_COLORSPACE_SRGB          = 8,

	/* opRGB colorspace */
	V4L2_COLORSPACE_OPRGB         = 9,

	/* BT.2020 colorspace, used for UHDTV. */
	V4L2_COLORSPACE_BT2020        = 10,

	/* Raw colorspace: for RAW unprocessed images */
	V4L2_COLORSPACE_RAW           = 11,

	/* DCI-P3 colorspace, used by cinema projectors */
	V4L2_COLORSPACE_DCI_P3        = 12,

	/* Generic film (colour filters using Illuminant C) */
	V4L2_COLORSPACE_GENERIC_FILM  = 13,

	/* SMPTE ST 428-1 */
	V4L2_COLORSPACE_ST428         = 14,
};


struct limit_range {
	uint32_t min;
	uint32_t max;
};

struct ar0521_sensor_limits {
	struct limit_range x;
	struct limit_range y;
	struct limit_range hlen;
	struct limit_range vlen;
	struct limit_range hblank;
	struct limit_range vblank;
	struct limit_range ext_clk;
};

struct v4l2_mbus_framefmt {
	uint32_t	width;
	uint32_t	height;
	uint32_t	code;
	uint32_t	field;
	uint32_t	colorspace;
};

struct v4l2_rect {
	uint32_t	left;
	uint32_t	top;
	uint32_t	width;
	uint32_t	height;
};

struct ar0521_gains {
	uint32_t	red;
	uint32_t	greenb;
	uint32_t	greenr;
	uint32_t	blue;
	uint32_t	min_ref;
};

struct ar0521_format {
	uint32_t	code;
	uint32_t	bpp;
};

struct ar0521_pll_config {
	uint32_t pll2_div;
	uint32_t pll2_mul;
	uint32_t pll_div;
	uint32_t pll_mul;
	uint32_t vt_sys_div;
	uint32_t vt_pix_div;
	uint32_t op_sys_div;
	uint32_t op_pix_div;
	uint32_t vco_freq;
	uint32_t pix_freq;
	uint32_t ser_freq;
};

struct ar0521_businfo {
	uint16_t num_lanes;
	uint16_t flags;
	const uint32_t  *link_freqs;

	uint16_t t_hs_prep;
	uint16_t t_hs_zero;
	uint16_t t_hs_trail;
	uint16_t t_clk_prep;
	uint16_t t_clk_zero;
	uint16_t t_clk_trail;
	uint16_t t_bgap;
	uint16_t t_clk_pre;
	uint16_t t_clk_post_msbs;
	uint16_t t_lpx;
	uint16_t t_wakeup;
	uint16_t t_clk_post;
	uint16_t t_hs_exit;
	uint16_t t_init;
	bool cont_tx_clk;
	bool vreg_mode;
};

struct ar0521 {
	struct v4l2_mbus_framefmt fmt;
	struct v4l2_rect crop;
	struct ar0521_sensor_limits limits;
	struct ar0521_businfo info;
	struct ar0521_pll_config pll[4];
	enum ar0521_model model;
	const struct ar0521_format *formats;
	uint32_t	num_fmts;
	uint32_t	bpp;
	uint32_t	w_scale;
	uint32_t	h_scale;
	uint32_t	vblank;
	uint32_t	hblank;
	uint32_t	hlen;
	uint32_t	vlen;
	struct ar0521_gains gains;
	bool is_streaming;
};

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
