include_guard()
message("middleware_iot_reference_mqtt_agent component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/mqtt_agent_task.c
)


target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)


include(middleware_freertos-kernel_MIMXRT1176_cm7)

include(middleware_freertos_backoffalgorithm_MIMXRT1176_cm7)

include(middleware_freertos_coremqtt-agent_MIMXRT1176_cm7)

include(middleware_freertos_corepkcs11_MIMXRT1176_cm7)

include(middleware_iot_reference_kvstore_MIMXRT1176_cm7)

include(middleware_iot_reference_mqtt_agent_interface_MIMXRT1176_cm7)

