// Process Image File
// Generated by CANopen Architect Professional 9.10.5971 on 10/16/2020 1:02:39 AM
// Generated from project
// E:\ESA_new\MicroCANopenPlus\trunk\MCO_CiA401_IMXRT_MCUX_SDK\Example-Config\EDS-FD\CANopenFD_NXP_SDK_Device.cax
// Generated from EDS 'CANopenFD_NXP_SDK_CiA401-BF' 10-16-2020 01:01AM by Pf
// Use with MicroCANopen Plus CANopen stack
// For more information visit www.esacademy.com and www.microcanopen.com

// Check for warnings below before using this file

#ifndef _PIMGH_
#define _PIMGH_

// EDS configuration usage
// 1 = configuration was used when this file was generated
#define EDSCONFIGURATION_ALL_ENTRIES 1

// EDS group usage
// 1 = group was used when this file was generated

// set to 1 to use this stack config
#define AUTO_GENERATED_STACK_CONFIG 1

#if (AUTO_GENERATED_STACK_CONFIG == 1)
// stack configuration

// if no stack version defined then assume version 5.xx
#ifndef _MCOPVERSION_
#define _MCOPVERSION_ 5
#endif

// Maximum number of receive PDOs
#define NR_OF_RPDOS 2

// Maximum number of transmit PDOs
#define NR_OF_TPDOS 2

// Default Node ID of this node
#if _MCOPVERSION_ >= 6
#define NODEID_DCF         0x03
#define DEFAULT_EMCY_COBID 0x00000080L + NODEID_DCF
#else
#define NODE_ID            0x03
#define DEFAULT_EMCY_COBID 0x00000080L + NODE_ID
#endif

// device type entry is an array therefore OD_1000H_LIST is used instead of this define
#define OD_DEVICE_TYPE 0xFFFFFFFFL

// Identity Object data [1018]
// Note: the values in Device -> Information are not used for this piece of code,
// only the values in [1018] are used
#define OD_VENDOR_ID     0xAF0002DCL
#define OD_PRODUCT_CODE  0xC0DE0020L
#define OD_REVISION      0x20201014L
#define OD_SERIAL_NUMBER 0x00000000L

// Specify the default heartbeat here
#define DEFAULT_HEARTBEAT 1000

// Defines the maximum number of heartbeat consumers
#define NR_OF_HB_CONSUMER 3

// Defines the maximum number of emergency consumers
#define NR_OF_EMCY_CONSUMERS 0

// Defines the emergency inhibit time (x100us)
#define EMCY_INHIBIT_TIME 100

#endif // AUTO_GENERATED_STACK_CONFIG == 1

// [6200,01] Unsigned8
#define P620001_DigOutput8_1 0x00000000
#define PDigOutput8_1_620001 P620001_DigOutput8_1
#define P620001              P620001_DigOutput8_1
#define P0x62000x01          P620001_DigOutput8_1
// The uppercase versions are deprecated
#define P620001_DIGOUTPUT8_1 P620001_DigOutput8_1
#define PDIGOUTPUT8_1_620001 P620001_DigOutput8_1
// [6200,02] Unsigned8
#define P620002_DigOutput8_2 0x00000001
#define PDigOutput8_2_620002 P620002_DigOutput8_2
#define P620002              P620002_DigOutput8_2
#define P0x62000x02          P620002_DigOutput8_2
// The uppercase versions are deprecated
#define P620002_DIGOUTPUT8_2 P620002_DigOutput8_2
#define PDIGOUTPUT8_2_620002 P620002_DigOutput8_2
// [6200,03] Unsigned8
#define P620003_DigOutput8_3 0x00000002
#define PDigOutput8_3_620003 P620003_DigOutput8_3
#define P620003              P620003_DigOutput8_3
#define P0x62000x03          P620003_DigOutput8_3
// The uppercase versions are deprecated
#define P620003_DIGOUTPUT8_3 P620003_DigOutput8_3
#define PDIGOUTPUT8_3_620003 P620003_DigOutput8_3
// [6200,04] Unsigned8
#define P620004_DigOutput8_4 0x00000003
#define PDigOutput8_4_620004 P620004_DigOutput8_4
#define P620004              P620004_DigOutput8_4
#define P0x62000x04          P620004_DigOutput8_4
// The uppercase versions are deprecated
#define P620004_DIGOUTPUT8_4 P620004_DigOutput8_4
#define PDIGOUTPUT8_4_620004 P620004_DigOutput8_4
// [6411,01] Integer16
#define P641101_AnalogOutput16_1 0x00000004
#define PAnalogOutput16_1_641101 P641101_AnalogOutput16_1
#define P641101                  P641101_AnalogOutput16_1
#define P0x64110x01              P641101_AnalogOutput16_1
// The uppercase versions are deprecated
#define P641101_ANALOGOUTPUT16_1 P641101_AnalogOutput16_1
#define PANALOGOUTPUT16_1_641101 P641101_AnalogOutput16_1
// [6411,02] Integer16
#define P641102_AnalogOutput16_2 0x00000006
#define PAnalogOutput16_2_641102 P641102_AnalogOutput16_2
#define P641102                  P641102_AnalogOutput16_2
#define P0x64110x02              P641102_AnalogOutput16_2
// The uppercase versions are deprecated
#define P641102_ANALOGOUTPUT16_2 P641102_AnalogOutput16_2
#define PANALOGOUTPUT16_2_641102 P641102_AnalogOutput16_2
// [6000,01] Unsigned8
#define P600001_DigInput8_1 0x00000008
#define PDigInput8_1_600001 P600001_DigInput8_1
#define P600001             P600001_DigInput8_1
#define P0x60000x01         P600001_DigInput8_1
// The uppercase versions are deprecated
#define P600001_DIGINPUT8_1 P600001_DigInput8_1
#define PDIGINPUT8_1_600001 P600001_DigInput8_1
// [6000,02] Unsigned8
#define P600002_DigInput8_2 0x00000009
#define PDigInput8_2_600002 P600002_DigInput8_2
#define P600002             P600002_DigInput8_2
#define P0x60000x02         P600002_DigInput8_2
// The uppercase versions are deprecated
#define P600002_DIGINPUT8_2 P600002_DigInput8_2
#define PDIGINPUT8_2_600002 P600002_DigInput8_2
// [6000,03] Unsigned8
#define P600003_DigInput8_3 0x0000000A
#define PDigInput8_3_600003 P600003_DigInput8_3
#define P600003             P600003_DigInput8_3
#define P0x60000x03         P600003_DigInput8_3
// The uppercase versions are deprecated
#define P600003_DIGINPUT8_3 P600003_DigInput8_3
#define PDIGINPUT8_3_600003 P600003_DigInput8_3
// [6000,04] Unsigned8
#define P600004_DigInput8_4 0x0000000B
#define PDigInput8_4_600004 P600004_DigInput8_4
#define P600004             P600004_DigInput8_4
#define P0x60000x04         P600004_DigInput8_4
// The uppercase versions are deprecated
#define P600004_DIGINPUT8_4 P600004_DigInput8_4
#define PDIGINPUT8_4_600004 P600004_DigInput8_4
// [6401,01] Integer16
#define P640101_AnalogInput16_1 0x0000000C
#define PAnalogInput16_1_640101 P640101_AnalogInput16_1
#define P640101                 P640101_AnalogInput16_1
#define P0x64010x01             P640101_AnalogInput16_1
// The uppercase versions are deprecated
#define P640101_ANALOGINPUT16_1 P640101_AnalogInput16_1
#define PANALOGINPUT16_1_640101 P640101_AnalogInput16_1
// [6401,02] Integer16
#define P640102_AnalogInput16_2 0x0000000E
#define PAnalogInput16_2_640102 P640102_AnalogInput16_2
#define P640102                 P640102_AnalogInput16_2
#define P0x64010x02             P640102_AnalogInput16_2
// The uppercase versions are deprecated
#define P640102_ANALOGINPUT16_2 P640102_AnalogInput16_2
#define PANALOGINPUT16_2_640102 P640102_AnalogInput16_2
// [6401,03] Integer16
#define P640103_AnalogInput16_3 0x00000010
#define PAnalogInput16_3_640103 P640103_AnalogInput16_3
#define P640103                 P640103_AnalogInput16_3
#define P0x64010x03             P640103_AnalogInput16_3
// The uppercase versions are deprecated
#define P640103_ANALOGINPUT16_3 P640103_AnalogInput16_3
#define PANALOGINPUT16_3_640103 P640103_AnalogInput16_3
// [6401,04] Integer16
#define P640104_AnalogInput16_4 0x00000012
#define PAnalogInput16_4_640104 P640104_AnalogInput16_4
#define P640104                 P640104_AnalogInput16_4
#define P0x64010x04             P640104_AnalogInput16_4
// The uppercase versions are deprecated
#define P640104_ANALOGINPUT16_4 P640104_AnalogInput16_4
#define PANALOGINPUT16_4_640104 P640104_AnalogInput16_4
// [6401,05] Integer16
#define P640105_AnalogInput16_5 0x00000014
#define PAnalogInput16_5_640105 P640105_AnalogInput16_5
#define P640105                 P640105_AnalogInput16_5
#define P0x64010x05             P640105_AnalogInput16_5
// The uppercase versions are deprecated
#define P640105_ANALOGINPUT16_5 P640105_AnalogInput16_5
#define PANALOGINPUT16_5_640105 P640105_AnalogInput16_5
// [6401,06] Integer16
#define P640106_AnalogInput16_6 0x00000016
#define PAnalogInput16_6_640106 P640106_AnalogInput16_6
#define P640106                 P640106_AnalogInput16_6
#define P0x64010x06             P640106_AnalogInput16_6
// The uppercase versions are deprecated
#define P640106_ANALOGINPUT16_6 P640106_AnalogInput16_6
#define PANALOGINPUT16_6_640106 P640106_AnalogInput16_6
// [6401,07] Integer16
#define P640107_AnalogInput16_7 0x00000018
#define PAnalogInput16_7_640107 P640107_AnalogInput16_7
#define P640107                 P640107_AnalogInput16_7
#define P0x64010x07             P640107_AnalogInput16_7
// The uppercase versions are deprecated
#define P640107_ANALOGINPUT16_7 P640107_AnalogInput16_7
#define PANALOGINPUT16_7_640107 P640107_AnalogInput16_7
// [6401,08] Integer16
#define P640108_AnalogInput16_8 0x0000001A
#define PAnalogInput16_8_640108 P640108_AnalogInput16_8
#define P640108                 P640108_AnalogInput16_8
#define P0x64010x08             P640108_AnalogInput16_8
// The uppercase versions are deprecated
#define P640108_ANALOGINPUT16_8 P640108_AnalogInput16_8
#define PANALOGINPUT16_8_640108 P640108_AnalogInput16_8
// [1000,00] Unsigned8
#define P100000_Highest_Subindex 0x0000001C
#define PHighest_Subindex_100000 P100000_Highest_Subindex
#define P100000                  P100000_Highest_Subindex
#define P0x10000x00              P100000_Highest_Subindex
// The uppercase versions are deprecated
#define P100000_HIGHEST_SUBINDEX P100000_Highest_Subindex
#define PHIGHEST_SUBINDEX_100000 P100000_Highest_Subindex
// [1000,01] Unsigned32
#define P100001_Device_Type_1 0x0000001D
#define PDevice_Type_1_100001 P100001_Device_Type_1
#define P100001               P100001_Device_Type_1
#define P0x10000x01           P100001_Device_Type_1
// The uppercase versions are deprecated
#define P100001_DEVICE_TYPE_1 P100001_Device_Type_1
#define PDEVICE_TYPE_1_100001 P100001_Device_Type_1
// [1002,00] Unsigned32
#define P100200_Manufacturer_Status_Register 0x00000021
#define PManufacturer_Status_Register_100200 P100200_Manufacturer_Status_Register
#define P100200                              P100200_Manufacturer_Status_Register
#define P0x10020x00                          P100200_Manufacturer_Status_Register
// The uppercase versions are deprecated
#define P100200_MANUFACTURER_STATUS_REGISTER P100200_Manufacturer_Status_Register
#define PMANUFACTURER_STATUS_REGISTER_100200 P100200_Manufacturer_Status_Register
// [1008,00] VisibleString
#define P100800_Manufacturer_Device_Name 0x00000025
#define PManufacturer_Device_Name_100800 P100800_Manufacturer_Device_Name
#define P100800                          P100800_Manufacturer_Device_Name
#define P0x10080x00                      P100800_Manufacturer_Device_Name
// The uppercase versions are deprecated
#define P100800_MANUFACTURER_DEVICE_NAME P100800_Manufacturer_Device_Name
#define PMANUFACTURER_DEVICE_NAME_100800 P100800_Manufacturer_Device_Name
// [1009,00] VisibleString
#define P100900_Manufacturer_Hardware_Version 0x00000048
#define PManufacturer_Hardware_Version_100900 P100900_Manufacturer_Hardware_Version
#define P100900                               P100900_Manufacturer_Hardware_Version
#define P0x10090x00                           P100900_Manufacturer_Hardware_Version
// The uppercase versions are deprecated
#define P100900_MANUFACTURER_HARDWARE_VERSION P100900_Manufacturer_Hardware_Version
#define PMANUFACTURER_HARDWARE_VERSION_100900 P100900_Manufacturer_Hardware_Version
// [100A,00] VisibleString
#define P100A00_Manufacturer_Software_Version 0x0000005A
#define PManufacturer_Software_Version_100A00 P100A00_Manufacturer_Software_Version
#define P100A00                               P100A00_Manufacturer_Software_Version
#define P0x100A0x00                           P100A00_Manufacturer_Software_Version
// The uppercase versions are deprecated
#define P100A00_MANUFACTURER_SOFTWARE_VERSION P100A00_Manufacturer_Software_Version
#define PMANUFACTURER_SOFTWARE_VERSION_100A00 P100A00_Manufacturer_Software_Version
// [1030,00] Unsigned8
#define P103000_Highest_Subindex 0x00000073
#define PHighest_Subindex_103000 P103000_Highest_Subindex
#define P103000                  P103000_Highest_Subindex
#define P0x10300x00              P103000_Highest_Subindex
// The uppercase versions are deprecated
#define P103000_HIGHEST_SUBINDEX P103000_Highest_Subindex
#define PHIGHEST_SUBINDEX_103000 P103000_Highest_Subindex
// [1030,01] Unsigned32
#define P103001_Version_Information_1 0x00000074
#define PVersion_Information_1_103001 P103001_Version_Information_1
#define P103001                       P103001_Version_Information_1
#define P0x10300x01                   P103001_Version_Information_1
// The uppercase versions are deprecated
#define P103001_VERSION_INFORMATION_1 P103001_Version_Information_1
#define PVERSION_INFORMATION_1_103001 P103001_Version_Information_1
// [1030,02] Unsigned32
#define P103002_Version_Information_2 0x00000078
#define PVersion_Information_2_103002 P103002_Version_Information_2
#define P103002                       P103002_Version_Information_2
#define P0x10300x02                   P103002_Version_Information_2
// The uppercase versions are deprecated
#define P103002_VERSION_INFORMATION_2 P103002_Version_Information_2
#define PVERSION_INFORMATION_2_103002 P103002_Version_Information_2
// [1031,00] Unsigned8
#define P103100_Highest_Subindex 0x0000007C
#define PHighest_Subindex_103100 P103100_Highest_Subindex
#define P103100                  P103100_Highest_Subindex
#define P0x10310x00              P103100_Highest_Subindex
// The uppercase versions are deprecated
#define P103100_HIGHEST_SUBINDEX P103100_Highest_Subindex
#define PHIGHEST_SUBINDEX_103100 P103100_Highest_Subindex
// [1031,01] Unsigned32
#define P103101_Error_History_Status 0x0000007D
#define PError_History_Status_103101 P103101_Error_History_Status
#define P103101                      P103101_Error_History_Status
#define P0x10310x01                  P103101_Error_History_Status
// The uppercase versions are deprecated
#define P103101_ERROR_HISTORY_STATUS P103101_Error_History_Status
#define PERROR_HISTORY_STATUS_103101 P103101_Error_History_Status
// [1031,02] Unsigned16
#define P103102_Error_History_Command 0x00000081
#define PError_History_Command_103102 P103102_Error_History_Command
#define P103102                       P103102_Error_History_Command
#define P0x10310x02                   P103102_Error_History_Command
// The uppercase versions are deprecated
#define P103102_ERROR_HISTORY_COMMAND P103102_Error_History_Command
#define PERROR_HISTORY_COMMAND_103102 P103102_Error_History_Command
// [1031,03] Unsigned16
#define P103103_Error_History_Command_Input 0x00000083
#define PError_History_Command_Input_103103 P103103_Error_History_Command_Input
#define P103103                             P103103_Error_History_Command_Input
#define P0x10310x03                         P103103_Error_History_Command_Input
// The uppercase versions are deprecated
#define P103103_ERROR_HISTORY_COMMAND_INPUT P103103_Error_History_Command_Input
#define PERROR_HISTORY_COMMAND_INPUT_103103 P103103_Error_History_Command_Input
// [1031,05] Unsigned32
#define P103105_Error_History_Processing 0x00000085
#define PError_History_Processing_103105 P103105_Error_History_Processing
#define P103105                          P103105_Error_History_Processing
#define P0x10310x05                      P103105_Error_History_Processing
// The uppercase versions are deprecated
#define P103105_ERROR_HISTORY_PROCESSING P103105_Error_History_Processing
#define PERROR_HISTORY_PROCESSING_103105 P103105_Error_History_Processing
// [1032,00] Unsigned8
#define P103200_Highest_Subindex 0x00000089
#define PHighest_Subindex_103200 P103200_Highest_Subindex
#define P103200                  P103200_Highest_Subindex
#define P0x10320x00              P103200_Highest_Subindex
// The uppercase versions are deprecated
#define P103200_HIGHEST_SUBINDEX P103200_Highest_Subindex
#define PHIGHEST_SUBINDEX_103200 P103200_Highest_Subindex
// [1032,01] Unsigned32
#define P103201_Error_Event_1 0x0000008A
#define PError_Event_1_103201 P103201_Error_Event_1
#define P103201               P103201_Error_Event_1
#define P0x10320x01           P103201_Error_Event_1
// The uppercase versions are deprecated
#define P103201_ERROR_EVENT_1 P103201_Error_Event_1
#define PERROR_EVENT_1_103201 P103201_Error_Event_1
// [1032,02] Unsigned32
#define P103202_Error_Event_2 0x0000008E
#define PError_Event_2_103202 P103202_Error_Event_2
#define P103202               P103202_Error_Event_2
#define P0x10320x02           P103202_Error_Event_2
// The uppercase versions are deprecated
#define P103202_ERROR_EVENT_2 P103202_Error_Event_2
#define PERROR_EVENT_2_103202 P103202_Error_Event_2
// [1032,03] Unsigned32
#define P103203_Error_Event_3 0x00000092
#define PError_Event_3_103203 P103203_Error_Event_3
#define P103203               P103203_Error_Event_3
#define P0x10320x03           P103203_Error_Event_3
// The uppercase versions are deprecated
#define P103203_ERROR_EVENT_3 P103203_Error_Event_3
#define PERROR_EVENT_3_103203 P103203_Error_Event_3
// [1032,04] Unsigned32
#define P103204_Error_Event_4 0x00000096
#define PError_Event_4_103204 P103204_Error_Event_4
#define P103204               P103204_Error_Event_4
#define P0x10320x04           P103204_Error_Event_4
// The uppercase versions are deprecated
#define P103204_ERROR_EVENT_4 P103204_Error_Event_4
#define PERROR_EVENT_4_103204 P103204_Error_Event_4
// [2010,00] VisibleString
#define P201000_128byte_Buffer_Segmentation_Test 0x0000009A
#define P128byte_Buffer_Segmentation_Test_201000 P201000_128byte_Buffer_Segmentation_Test
#define P201000                                  P201000_128byte_Buffer_Segmentation_Test
#define P0x20100x00                              P201000_128byte_Buffer_Segmentation_Test
// The uppercase versions are deprecated
#define P201000_128BYTE_BUFFER_SEGMENTATION_TEST P201000_128byte_Buffer_Segmentation_Test
#define P128BYTE_BUFFER_SEGMENTATION_TEST_201000 P201000_128byte_Buffer_Segmentation_Test
// [5FFF,00] VisibleString
#define P5FFF00_EmSA 0x0000011A
#define PEmSA_5FFF00 P5FFF00_EmSA
#define P5FFF00      P5FFF00_EmSA
#define P0x5FFF0x00  P5FFF00_EmSA
// The uppercase versions are deprecated
#define P5FFF00_EMSA P5FFF00_EmSA
#define PEMSA_5FFF00 P5FFF00_EmSA

// last byte used in process image
#define PIMGEND 0x00000143

// sizes for entries in the process image in bytes
#define SIZEOF_6200_01_DIGOUTPUT8_1                     1
#define SIZEOF_6200_02_DIGOUTPUT8_2                     1
#define SIZEOF_6200_03_DIGOUTPUT8_3                     1
#define SIZEOF_6200_04_DIGOUTPUT8_4                     1
#define SIZEOF_6411_01_ANALOGOUTPUT16_1                 2
#define SIZEOF_6411_02_ANALOGOUTPUT16_2                 2
#define SIZEOF_6000_01_DIGINPUT8_1                      1
#define SIZEOF_6000_02_DIGINPUT8_2                      1
#define SIZEOF_6000_03_DIGINPUT8_3                      1
#define SIZEOF_6000_04_DIGINPUT8_4                      1
#define SIZEOF_6401_01_ANALOGINPUT16_1                  2
#define SIZEOF_6401_02_ANALOGINPUT16_2                  2
#define SIZEOF_6401_03_ANALOGINPUT16_3                  2
#define SIZEOF_6401_04_ANALOGINPUT16_4                  2
#define SIZEOF_6401_05_ANALOGINPUT16_5                  2
#define SIZEOF_6401_06_ANALOGINPUT16_6                  2
#define SIZEOF_6401_07_ANALOGINPUT16_7                  2
#define SIZEOF_6401_08_ANALOGINPUT16_8                  2
#define SIZEOF_1000_00_HIGHEST_SUBINDEX                 1
#define SIZEOF_1000_01_DEVICE_TYPE_1                    4
#define SIZEOF_1002_00_MANUFACTURER_STATUS_REGISTER     4
#define SIZEOF_1008_00_MANUFACTURER_DEVICE_NAME         35
#define SIZEOF_1009_00_MANUFACTURER_HARDWARE_VERSION    18
#define SIZEOF_100A_00_MANUFACTURER_SOFTWARE_VERSION    25
#define SIZEOF_1030_00_HIGHEST_SUBINDEX                 1
#define SIZEOF_1030_01_VERSION_INFORMATION_1            4
#define SIZEOF_1030_02_VERSION_INFORMATION_2            4
#define SIZEOF_1031_00_HIGHEST_SUBINDEX                 1
#define SIZEOF_1031_01_ERROR_HISTORY_STATUS             4
#define SIZEOF_1031_02_ERROR_HISTORY_COMMAND            2
#define SIZEOF_1031_03_ERROR_HISTORY_COMMAND_INPUT      2
#define SIZEOF_1031_05_ERROR_HISTORY_PROCESSING         4
#define SIZEOF_1032_00_HIGHEST_SUBINDEX                 1
#define SIZEOF_1032_01_ERROR_EVENT_1                    4
#define SIZEOF_1032_02_ERROR_EVENT_2                    4
#define SIZEOF_1032_03_ERROR_EVENT_3                    4
#define SIZEOF_1032_04_ERROR_EVENT_4                    4
#define SIZEOF_2010_00_128BYTE_BUFFER_SEGMENTATION_TEST 128
#define SIZEOF_5FFF_00_EMSA                             42

// default values for process image
#define PIMGDEFAULTS                                                                                                  \
    {                                                                                                                 \
        /*[6200,01]*/ 0x00, /*[6200,02]*/ 0x00, /*[6200,03]*/ 0x00, /*[6200,04]*/ 0x00, /*[6411,01]*/ 0x00, 0x00,     \
            /*[6411,02]*/ 0x00, 0x00, /*[6000,01]*/ 0x12, /*[6000,02]*/ 0x23, /*[6000,03]*/ 0x34, /*[6000,04]*/ 0x45, \
            /*[6401,01]*/ 0x34, 0x12, /*[6401,02]*/ 0x45, 0x23, /*[6401,03]*/ 0x56, 0x34, /*[6401,04]*/ 0x67, 0x45,   \
            /*[6401,05]*/ 0x78, 0x56, /*[6401,06]*/ 0x89, 0x67, /*[6401,07]*/ 0x9A, 0x78, /*[6401,08]*/ 0xAB, 0x89,   \
            /*[1000,00]*/ 0x01, /*[1000,01]*/ 0x91, 0x01, 0x0F, 0x00, /*[1002,00]*/ 0x00, 0x00, 0x00, 0x00,           \
            /*[1008,00]*/ 0x43, 0x41, 0x4E, 0x6F, 0x70, 0x65, 0x6E, 0x4C, 0x69, 0x62, 0x4E, 0x58, 0x50, 0x53, 0x44,   \
            0x4B, 0x20, 0x43, 0x69, 0x41, 0x34, 0x30, 0x31, 0x2D, 0x42, 0x2F, 0x46, 0x20, 0x45, 0x78, 0x61, 0x6D,     \
            0x70, 0x6C, 0x65, /*[1009,00]*/ 0x53, 0x6F, 0x6D, 0x65, 0x20, 0x4E, 0x58, 0x50, 0x20, 0x45, 0x76, 0x61,   \
            0x6C, 0x62, 0x6F, 0x61, 0x72, 0x64, /*[100A,00]*/ 0x45, 0x6D, 0x53, 0x41, 0x20, 0x4D, 0x43, 0x4F, 0x50,   \
            0x20, 0x37, 0x2E, 0x31, 0x30, 0x20, 0x32, 0x30, 0x32, 0x30, 0x2D, 0x31, 0x30, 0x2D, 0x31, 0x34,           \
            /*[1030,00]*/ 0x02, /*[1030,01]*/ 0x00, 0x01, 0x50, 0x51, /*[1030,02]*/ 0x00, 0x03, 0x10, 0x19,           \
            /*[1031,00]*/ 0x05, /*[1031,01]*/ 0x00, 0x00, 0x00, 0x00, /*[1031,02]*/ 0x00, 0x00, /*[1031,03]*/ 0x00,   \
            0x00, /*[1031,05]*/ 0x00, 0x00, 0x00, 0x00, /*[1032,00]*/ 0x00, /*[1032,01]*/ 0x00, 0x00, 0x00, 0x00,     \
            /*[1032,02]*/ 0x00, 0x00, 0x00, 0x00, /*[1032,03]*/ 0x00, 0x00, 0x00, 0x00, /*[1032,04]*/ 0x00, 0x00,     \
            0x00, 0x00, /*[2010,00]*/ 0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 0x31, 0x32, 0x38,   \
            0x20, 0x62, 0x79, 0x74, 0x65, 0x20, 0x6C, 0x6F, 0x6E, 0x67, 0x20, 0x74, 0x65, 0x73, 0x74, 0x20, 0x73,     \
            0x74, 0x72, 0x69, 0x6E, 0x67, 0x20, 0x66, 0x6F, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x4E, 0x58, 0x50,     \
            0x20, 0x4D, 0x43, 0x55, 0x58, 0x70, 0x72, 0x65, 0x73, 0x73, 0x6F, 0x20, 0x53, 0x44, 0x4B, 0x20, 0x4D,     \
            0x69, 0x63, 0x72, 0x6F, 0x20, 0x43, 0x41, 0x4E, 0x6F, 0x70, 0x65, 0x6E, 0x20, 0x46, 0x44, 0x20, 0x64,     \
            0x65, 0x6D, 0x6F, 0x20, 0x62, 0x79, 0x20, 0x45, 0x6D, 0x62, 0x65, 0x64, 0x64, 0x65, 0x64, 0x20, 0x53,     \
            0x79, 0x73, 0x74, 0x65, 0x6D, 0x73, 0x20, 0x41, 0x63, 0x61, 0x64, 0x65, 0x6D, 0x79, 0x20, 0x28, 0x77,     \
            0x77, 0x77, 0x2E, 0x65, 0x6D, 0x2D, 0x73, 0x61, 0x2E, 0x63, 0x6F, 0x6D, 0x29, /*[5FFF,00]*/ 0x45, 0x6D,   \
            0x53, 0x41, 0x20, 0x77, 0x77, 0x77, 0x2E, 0x65, 0x6D, 0x2D, 0x73, 0x61, 0x2E, 0x63, 0x6F, 0x6D, 0x2C,     \
            0x20, 0x43, 0x41, 0x4E, 0x6F, 0x70, 0x65, 0x6E, 0x20, 0x41, 0x72, 0x63, 0x68, 0x69, 0x74, 0x65, 0x63,     \
            0x74, 0x20, 0x4D, 0x69, 0x6E, 0x69,                                                                       \
    }

// 1 MACROS WERE GENERATED TO HOLD THE PROCESS IMAGE
// USE THE FOLLOWING INITIALIZER:
// PIMGDEFAULTS

// minimum values for process image
#define PIMGMINS                                                                                                      \
    {                                                                                                                 \
        /*[6200,01]*/ 0x00, /*[6200,02]*/ 0x00, /*[6200,03]*/ 0x00, /*[6200,04]*/ 0x00, /*[6411,01]*/ 0x00, 0x00,     \
            /*[6411,02]*/ 0x00, 0x00, /*[6000,01]*/ 0x00, /*[6000,02]*/ 0x00, /*[6000,03]*/ 0x00, /*[6000,04]*/ 0x00, \
            /*[6401,01]*/ 0x00, 0x00, /*[6401,02]*/ 0x00, 0x00, /*[6401,03]*/ 0x00, 0x00, /*[6401,04]*/ 0x00, 0x00,   \
            /*[6401,05]*/ 0x00, 0x00, /*[6401,06]*/ 0x00, 0x00, /*[6401,07]*/ 0x00, 0x00, /*[6401,08]*/ 0x00, 0x00,   \
            /*[1000,00]*/ 0x00, /*[1000,01]*/ 0x00, 0x00, 0x00, 0x00, /*[1002,00]*/ 0x00, 0x00, 0x00, 0x00,           \
            /*[1008,00]*/ 0x00, 0x00, 0x00, 0x00, /*[1009,00]*/ 0x00, 0x00, 0x00, 0x00, /*[100A,00]*/ 0x00, 0x00,     \
            0x00, 0x00, /*[1030,00]*/ 0x00, /*[1030,01]*/ 0x00, 0x00, 0x00, 0x00, /*[1030,02]*/ 0x00, 0x00, 0x00,     \
            0x00, /*[1031,00]*/ 0x00, /*[1031,01]*/ 0x00, 0x00, 0x00, 0x00, /*[1031,02]*/ 0x00, 0x00,                 \
            /*[1031,03]*/ 0x00, 0x00, /*[1031,05]*/ 0x00, 0x00, 0x00, 0x00, /*[1032,00]*/ 0x00, /*[1032,01]*/ 0x00,   \
            0x00, 0x00, 0x00, /*[1032,02]*/ 0x00, 0x00, 0x00, 0x00, /*[1032,03]*/ 0x00, 0x00, 0x00, 0x00,             \
            /*[1032,04]*/ 0x00, 0x00, 0x00, 0x00, /*[2010,00]*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            /*[5FFF,00]*/ 0x00, 0x00, 0x00, 0x00,                                                                     \
    }

// 1 MACROS WERE GENERATED TO HOLD THE PROCESS IMAGE
// USE THE FOLLOWING INITIALIZER:
// PIMGMINS

// maximum values for process image
#define PIMGMAXS                                                                                                      \
    {                                                                                                                 \
        /*[6200,01]*/ 0x00, /*[6200,02]*/ 0x00, /*[6200,03]*/ 0x00, /*[6200,04]*/ 0x00, /*[6411,01]*/ 0x00, 0x00,     \
            /*[6411,02]*/ 0x00, 0x00, /*[6000,01]*/ 0x00, /*[6000,02]*/ 0x00, /*[6000,03]*/ 0x00, /*[6000,04]*/ 0x00, \
            /*[6401,01]*/ 0x00, 0x00, /*[6401,02]*/ 0x00, 0x00, /*[6401,03]*/ 0x00, 0x00, /*[6401,04]*/ 0x00, 0x00,   \
            /*[6401,05]*/ 0x00, 0x00, /*[6401,06]*/ 0x00, 0x00, /*[6401,07]*/ 0x00, 0x00, /*[6401,08]*/ 0x00, 0x00,   \
            /*[1000,00]*/ 0x00, /*[1000,01]*/ 0x00, 0x00, 0x00, 0x00, /*[1002,00]*/ 0x00, 0x00, 0x00, 0x00,           \
            /*[1008,00]*/ 0x00, 0x00, 0x00, 0x00, /*[1009,00]*/ 0x00, 0x00, 0x00, 0x00, /*[100A,00]*/ 0x00, 0x00,     \
            0x00, 0x00, /*[1030,00]*/ 0x00, /*[1030,01]*/ 0x00, 0x00, 0x00, 0x00, /*[1030,02]*/ 0x00, 0x00, 0x00,     \
            0x00, /*[1031,00]*/ 0x00, /*[1031,01]*/ 0x00, 0x00, 0x00, 0x00, /*[1031,02]*/ 0x00, 0x00,                 \
            /*[1031,03]*/ 0x00, 0x00, /*[1031,05]*/ 0x00, 0x00, 0x00, 0x00, /*[1032,00]*/ 0x04, /*[1032,01]*/ 0x00,   \
            0x00, 0x00, 0x00, /*[1032,02]*/ 0x00, 0x00, 0x00, 0x00, /*[1032,03]*/ 0x00, 0x00, 0x00, 0x00,             \
            /*[1032,04]*/ 0x00, 0x00, 0x00, 0x00, /*[2010,00]*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     \
            /*[5FFF,00]*/ 0x00, 0x00, 0x00, 0x00,                                                                     \
    }

// 1 MACROS WERE GENERATED TO HOLD THE PROCESS IMAGE
// USE THE FOLLOWING INITIALIZER:
// PIMGMAXS

// Example usage: PIMG_OFFSET(0x1000, 0x00)
#define PIMG_OFFSET(index, subindex) P##index##subindex

#endif // _PIMGH_
