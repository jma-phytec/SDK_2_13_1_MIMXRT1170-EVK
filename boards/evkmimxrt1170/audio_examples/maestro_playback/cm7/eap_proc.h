/*
 * Copyright 2020-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _EAP_PROC_H_
#define _EAP_PROC_H_

#ifdef MULTICHANNEL_EXAMPLE
#include "EAP32.h" // EAP library
#else
#include "EAP16.h" // EAP library
#endif
#include "eap_att.h"
#include "app_definitions.h"

#define LVM_FRAME_SIZE_MS (10)

#ifndef MAX_SAMPLE_SIZE
#define MAX_SAMPLE_SIZE (1024)
#endif

#define NUM_OUT_BUFFERS (2)

/* Define for the full output range of the EAP crossover options when applied to a stereo audio input file */
// #define XO_USE_FULL_STEREO
#if (defined(XO_USE_FULL_STEREO) && (DEMO_CODEC_CS42448 != 1))
#error "When full stereo mode is enabled, the CS42448 codec must also be enabled"
#endif

int EAP_Init(void *arg);
int EAP_Execute(void *arg, void *inputBuffer, int size);
int EAP_Deinit();

eap_att_code_t register_post_process(void *streamer);

#endif
