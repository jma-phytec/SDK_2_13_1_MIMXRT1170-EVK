# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 3.10.0)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})
SET(LIBRARY_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})


project(lvgl_guider_bm_cm4)

set(MCUX_BUILD_TYPES flexspi_nor_sdram_debug flexspi_nor_sdram_release)

set(MCUX_SDK_PROJECT_NAME lvgl_guider_bm_cm4.elf)

if (NOT DEFINED SdkRootDirPath)
    SET(SdkRootDirPath ${ProjDirPath}/../../../../../..)
endif()

include(${ProjDirPath}/flags.cmake)

include(${ProjDirPath}/config.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${ProjDirPath}/../display_support.h"
"${ProjDirPath}/../display_support.c"
"${ProjDirPath}/../lvgl_guider_bm.c"
"${ProjDirPath}/../lv_conf.h"
"${ProjDirPath}/../pin_mux.c"
"${ProjDirPath}/../pin_mux.h"
"${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_guider_bm/generated/images/images.c"
"${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_guider_bm/generated/guider_fonts/guider_fonts.h"
"${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_guider_bm/generated/guider_customer_fonts/guider_customer_fonts.h"
"${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_guider_bm/generated/gui_guider.c"
"${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_guider_bm/generated/gui_guider.h"
"${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_guider_bm/generated/events_init.c"
"${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_guider_bm/generated/events_init.h"
"${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_guider_bm/custom/custom.c"
"${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_guider_bm/custom/custom.h"
"${ProjDirPath}/../board.c"
"${ProjDirPath}/../board.h"
"${ProjDirPath}/../clock_config.c"
"${ProjDirPath}/../clock_config.h"
"${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_support.h"
"${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_support.c"
"${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_demo_utils.h"
"${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_demo_utils.c"
"${ProjDirPath}/../dcd.c"
"${ProjDirPath}/../dcd.h"
"${ProjDirPath}/../evkmimxrt1170_connect_cm4_cm4side_sdram.jlinkscript"
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${ProjDirPath}/..
    ${SdkRootDirPath}/boards/evkmimxrt1170
    ${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_guider_bm/generated
    ${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_guider_bm/custom
    ${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_guider_bm/generated/guider_customer_fonts
    ${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples/lvgl_guider_bm/generated/guider_fonts
    ${SdkRootDirPath}/boards/evkmimxrt1170/lvgl_examples
)

set(CMAKE_MODULE_PATH
    ${SdkRootDirPath}/components/video
    ${SdkRootDirPath}/components/video/display
    ${SdkRootDirPath}/components/video/display/rm68191
    ${SdkRootDirPath}/devices/MIMXRT1176/drivers
    ${SdkRootDirPath}/components/video/display/mipi_dsi_cmd
    ${SdkRootDirPath}/components/video/display/rm68200
    ${SdkRootDirPath}/components/video/display/dc/lcdifv2
    ${SdkRootDirPath}/components/gt911
    ${SdkRootDirPath}/components/video/display/dc/elcdif
    ${SdkRootDirPath}/components/video/display/hx8394
    ${SdkRootDirPath}/middleware/lvgl
    ${SdkRootDirPath}/devices/MIMXRT1176
    ${SdkRootDirPath}/devices/MIMXRT1176/utilities
    ${SdkRootDirPath}/components/uart
    ${SdkRootDirPath}/components/serial_manager
    ${SdkRootDirPath}/components/lists
    ${SdkRootDirPath}/devices/MIMXRT1176/xip
    ${SdkRootDirPath}/boards/evkmimxrt1170/xip
    ${SdkRootDirPath}/devices/MIMXRT1176/drivers/cm4
    ${SdkRootDirPath}/boards/evkmimxrt1170/xmcd
    ${SdkRootDirPath}/CMSIS/Core/Include
    ${SdkRootDirPath}/components/video/display/dc
)

# include modules
include(driver_video-common_MIMXRT1176_cm4)

include(driver_display-common_MIMXRT1176_cm4)

include(driver_display-rm68191_MIMXRT1176_cm4)

include(driver_mipi_dsi_split_MIMXRT1176_cm4)

include(driver_display-mipi-dsi-cmd_MIMXRT1176_cm4)

include(driver_common_MIMXRT1176_cm4)

include(driver_display-rm68200_MIMXRT1176_cm4)

include(driver_dc-fb-lcdifv2_MIMXRT1176_cm4)

include(driver_gt911_MIMXRT1176_cm4)

include(driver_lpi2c_MIMXRT1176_cm4)

include(driver_soc_src_MIMXRT1176_cm4)

include(driver_pxp_MIMXRT1176_cm4)

include(driver_elcdif_MIMXRT1176_cm4)

include(driver_dc-fb-elcdif_MIMXRT1176_cm4)

include(driver_display-hx8394_MIMXRT1176_cm4)

include(driver_clock_MIMXRT1176_cm4)

include(middleware_lvgl_MIMXRT1176_cm4)

include(device_MIMXRT1176_CMSIS_MIMXRT1176_cm4)

include(utility_debug_console_MIMXRT1176_cm4)

include(component_lpuart_adapter_MIMXRT1176_cm4)

include(component_serial_manager_MIMXRT1176_cm4)

include(component_lists_MIMXRT1176_cm4)

include(component_serial_manager_uart_MIMXRT1176_cm4)

include(driver_lpuart_MIMXRT1176_cm4)

include(device_MIMXRT1176_startup_MIMXRT1176_cm4)

include(driver_iomuxc_MIMXRT1176_cm4)

include(utility_assert_MIMXRT1176_cm4)

include(driver_igpio_MIMXRT1176_cm4)

include(driver_xip_device_MIMXRT1176_cm4)

include(driver_xip_board_evkmimxrt1170_MIMXRT1176_cm4)

include(driver_pmu_1_MIMXRT1176_cm4)

include(driver_dcdc_soc_MIMXRT1176_cm4)

include(driver_cache_lmem_MIMXRT1176_cm4)

include(driver_xmcd_evkmimxrt1170_MIMXRT1176_cm4)

include(driver_anatop_ai_MIMXRT1176_cm4)

include(CMSIS_Include_core_cm_MIMXRT1176_cm4)

include(driver_soc_mipi_csi2rx_MIMXRT1176_cm4)

include(driver_dc-fb-common_MIMXRT1176_cm4)

include(driver_lcdifv2_MIMXRT1176_cm4)

include(driver_memory_MIMXRT1176_cm4)

include(utilities_misc_utilities_MIMXRT1176_cm4)

include(device_MIMXRT1176_system_MIMXRT1176_cm4)


IF(NOT DEFINED TARGET_LINK_SYSTEM_LIBRARIES)  
    SET(TARGET_LINK_SYSTEM_LIBRARIES "-lm -lc -lgcc -lnosys")  
ENDIF()  

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${TARGET_LINK_SYSTEM_LIBRARIES})

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)


