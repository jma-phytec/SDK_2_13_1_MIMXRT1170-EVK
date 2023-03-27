IF(NOT DEFINED FPU)  
    SET(FPU "-mfloat-abi=hard -mfpu=fpv5-d16")  
ENDIF()  

IF(NOT DEFINED SPECS)  
    SET(SPECS "--specs=nano.specs --specs=nosys.specs")  
ENDIF()  

IF(NOT DEFINED DEBUG_CONSOLE_CONFIG)  
    SET(DEBUG_CONSOLE_CONFIG "-DSDK_DEBUGCONSOLE_UART")  
ENDIF()  

SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG " \
    ${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} \
    -D__STARTUP_CLEAR_BSS \
    -D__STARTUP_INITIALIZE_RAMFUNCTION \
    -DDEBUG \
    -D__STARTUP_INITIALIZE_NONCACHEDATA \
    -mcpu=cortex-m7 \
    -mthumb \
    ${FPU} \
")
SET(CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE " \
    ${CMAKE_ASM_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} \
    -D__STARTUP_CLEAR_BSS \
    -D__STARTUP_INITIALIZE_RAMFUNCTION \
    -DNDEBUG \
    -D__STARTUP_INITIALIZE_NONCACHEDATA \
    -mcpu=cortex-m7 \
    -mthumb \
    ${FPU} \
")
SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG " \
    ${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} \
    -DXIP_EXTERNAL_FLASH=1 \
    -DXIP_BOOT_HEADER_ENABLE=1 \
    -DXIP_BOOT_HEADER_DCD_ENABLE=0 \
    -DXIP_BOOT_HEADER_XMCD_ENABLE=1 \
    -DUSE_SDRAM \
    -DDATA_SECTION_IS_CACHEABLE=1 \
    -DDEBUG \
    -DCORE1_IMAGE_COPY_TO_RAM \
    -DXIP_BOOT_HEADER_DCD_ENABLE=1 \
    -DXIP_BOOT_HEADER_XMCD_ENABLE=0 \
    -DCPU_MIMXRT1176DVMAA_cm7 \
    -DARM_MATH_CM7 \
    -D__FPU_PRESENT=1 \
    -DSDK_I2C_BASED_COMPONENT_USED=1 \
    -DSDK_I2C_BASED_COMPONENT_USED=1 \
    -DEIQ_GUI_PRINTF \
    -DTF_LITE_STATIC_MEMORY \
    -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 \
    -DCMSIS_NN \
    -DMCUXPRESSO_SDK \
    -g \
    -O0 \
    -Wall \
    -Wno-strict-aliasing \
    -mcpu=cortex-m7 \
    -mthumb \
    -MMD \
    -MP \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -mapcs \
    -std=gnu99 \
    ${FPU} \
    ${DEBUG_CONSOLE_CONFIG} \
")
SET(CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE " \
    ${CMAKE_C_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} \
    -DXIP_EXTERNAL_FLASH=1 \
    -DXIP_BOOT_HEADER_ENABLE=1 \
    -DXIP_BOOT_HEADER_DCD_ENABLE=0 \
    -DXIP_BOOT_HEADER_XMCD_ENABLE=1 \
    -DUSE_SDRAM \
    -DDATA_SECTION_IS_CACHEABLE=1 \
    -DNDEBUG \
    -DCORE1_IMAGE_COPY_TO_RAM \
    -DXIP_BOOT_HEADER_DCD_ENABLE=1 \
    -DXIP_BOOT_HEADER_XMCD_ENABLE=0 \
    -DCPU_MIMXRT1176DVMAA_cm7 \
    -DARM_MATH_CM7 \
    -D__FPU_PRESENT=1 \
    -DSDK_I2C_BASED_COMPONENT_USED=1 \
    -DSDK_I2C_BASED_COMPONENT_USED=1 \
    -DEIQ_GUI_PRINTF \
    -DTF_LITE_STATIC_MEMORY \
    -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 \
    -DCMSIS_NN \
    -DMCUXPRESSO_SDK \
    -O3 \
    -Wall \
    -Wno-strict-aliasing \
    -mcpu=cortex-m7 \
    -mthumb \
    -MMD \
    -MP \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -mapcs \
    -std=gnu99 \
    ${FPU} \
    ${DEBUG_CONSOLE_CONFIG} \
")
SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG " \
    ${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} \
    -DDEBUG \
    -DCPU_MIMXRT1176DVMAA_cm7 \
    -DARM_MATH_CM7 \
    -D__FPU_PRESENT=1 \
    -DSDK_I2C_BASED_COMPONENT_USED=1 \
    -DEIQ_GUI_PRINTF \
    -DTF_LITE_STATIC_MEMORY \
    -DCMSIS_NN \
    -DMCUXPRESSO_SDK \
    -g \
    -O0 \
    -Wall \
    -fno-rtti \
    -fno-exceptions \
    -Wno-sign-compare \
    -Wno-strict-aliasing \
    -mcpu=cortex-m7 \
    -mthumb \
    -MMD \
    -MP \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -mapcs \
    ${FPU} \
    ${DEBUG_CONSOLE_CONFIG} \
")
SET(CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE " \
    ${CMAKE_CXX_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} \
    -DNDEBUG \
    -DCPU_MIMXRT1176DVMAA_cm7 \
    -DARM_MATH_CM7 \
    -D__FPU_PRESENT=1 \
    -DSDK_I2C_BASED_COMPONENT_USED=1 \
    -DEIQ_GUI_PRINTF \
    -DTF_LITE_STATIC_MEMORY \
    -DCMSIS_NN \
    -DMCUXPRESSO_SDK \
    -O3 \
    -Wall \
    -fno-rtti \
    -fno-exceptions \
    -Wno-sign-compare \
    -Wno-strict-aliasing \
    -mcpu=cortex-m7 \
    -mthumb \
    -MMD \
    -MP \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -mapcs \
    ${FPU} \
    ${DEBUG_CONSOLE_CONFIG} \
")
SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG " \
    ${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_DEBUG} \
    -g \
    -mcpu=cortex-m7 \
    -Wall \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -ffreestanding \
    -fno-builtin \
    -mthumb \
    -mapcs \
    -Xlinker \
    --gc-sections \
    -Xlinker \
    -static \
    -Xlinker \
    -z \
    -Xlinker \
    muldefs \
    -Xlinker \
    -Map=output.map \
    -Wl,--print-memory-usage \
    -Xlinker \
    --defsym=__heap_size__=0x80000 \
    -Xlinker \
    --defsym=__stack_size__=0x2000 \
    ${FPU} \
    ${SPECS} \
    -T${ProjDirPath}/MIMXRT1176xxxxx_cm7_flexspi_nor_sdram.ld -static \
")
SET(CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE " \
    ${CMAKE_EXE_LINKER_FLAGS_FLEXSPI_NOR_SDRAM_RELEASE} \
    -mcpu=cortex-m7 \
    -Wall \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -ffreestanding \
    -fno-builtin \
    -mthumb \
    -mapcs \
    -Xlinker \
    --gc-sections \
    -Xlinker \
    -static \
    -Xlinker \
    -z \
    -Xlinker \
    muldefs \
    -Xlinker \
    -Map=output.map \
    -Wl,--print-memory-usage \
    -Xlinker \
    --defsym=__heap_size__=0x80000 \
    -Xlinker \
    --defsym=__stack_size__=0x2000 \
    ${FPU} \
    ${SPECS} \
    -T${ProjDirPath}/MIMXRT1176xxxxx_cm7_flexspi_nor_sdram.ld -static \
")