/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is delivered "as is" and shows the usage of other software 
* components. It is provided as an example software which is intended to be 
* modified and extended according to particular requirements.
* 
* TARA Systems hereby disclaims all warranties and conditions with regard to the
* software, including all implied warranties and conditions of merchantability 
* and non-infringement of any third party IPR or other rights which may result 
* from the use or the inability to use the software.
*
* This file was generated automatically by Embedded Wizard Studio.
*
* Please do not make any modifications of this file! The modifications are lost
* when the file is generated again by Embedded Wizard Studio!
*
* Version  : 10.0
* Date     : 17.02.2021  8:00:50
* Profile  : iMX_RT
* Platform : NXP.iMX_RT_VGLite.RGB565
*
*******************************************************************************/

/* Bitmap resource : 'Oximeter::Battery' */
EW_DEFINE_BITMAP_RES( OximeterBattery )
  EW_BITMAP_FRAMES( OximeterBattery, Default, EW_DRIVER_VARIANT_ALPHA8, 24, 45, 750 )
    EW_BITMAP_FRAME( 0, 7, 1, 34, 0x00000000, 0x00000000 ),
    EW_BITMAP_FRAME( 5, 37, 14, 3, 0x00000160, 0x00000000 ),
    EW_BITMAP_FRAME( 5, 29, 14, 3, 0x00000314, 0x00000000 ),
    EW_BITMAP_FRAME( 5, 22, 14, 3, 0x00000514, 0x00000000 ),
    EW_BITMAP_FRAME( 5, 16, 14, 3, 0x00000750, 0x00000000 ),
    EW_BITMAP_FRAME( 5, 8, 14, 3, 0x000009C8, 0x00000000 )
    EW_BITMAP_MAPPING( OximeterBattery, Default )

  EW_BITMAP_PIXEL_R90( OximeterBattery, Default )               /* ratio 48.70 % */
    0x59801700, 0xC19FEEF6, 0x2A130883, 0x9F10A85C, 0x0C2442B8, 0x24F00000, 0xF77B3B13,
    0xC8DBCDE4, 0x8FC7A3B1, 0x9C69E51B, 0x3CE45227, 0xD19CFA7A, 0x17D130A9, 0x48BF7D3A,
    0xB345128D, 0x389BCDA6, 0x25228D45, 0x524F2773, 0xFB91629F, 0xC4C6CDD7, 0xF582F97A,
    0x83A260A8, 0xA3500D86, 0x552A9D4A, 0x26140843, 0x81308042, 0x0D09C4E2, 0x5BA8FE31,
    0x80006517, 0x7158F97F, 0xADB6C898, 0xE170B7DB, 0x0D127032, 0x6703961E, 0x1182B5ED,
    0xB7DFAFB7, 0x592C3E03, 0xC48AEF16, 0xBD5CF77F, 0xAFD8CBF8, 0x9A4E0F80, 0xC0C2DBC5,
    0x8DC56200, 0xEC7DBF33, 0x5C3FD844, 0x5E5D2294, 0x0034B9AC, 0x2612BACE, 0x333A6D26,
    0x5B98D56A, 0x1A9C86BB, 0xB3D96AE1, 0x783ED49D, 0xD7E3371B, 0x76FB63B6, 0xEB361B4C,
    0xF38171E1, 0xAE1C8E16, 0x9BBD8372, 0xCC4C873B, 0x8041AB1F, 0x0E4F4B46, 0x233B59F9,
    0xE5E9FF13, 0x60B01DBB, 0x14A8F066, 0x6D769B38, 0xA373B7F9, 0x0092D3C5, 0x4CA55200,
    0x4FDD529D, 0xAD562AD5, 0x9605795C, 0xE5996458, 0xE5324C12, 0x3E4E60A4, 0x4F13E28D,
    0x5432C09E, 0x81351351, 0x811945C9, 0x2686A1A4, 0x3CD25491, 0xCCF3F0F6, 0x51496C4A,
    0xA50C3C4C, 0xFB42E2A8, 0x04C79388, 0x10100166, 0x294C0100, 0xC19FEF16, 0x2A130883,
    0x1F50A85C, 0x06133C38, 0x24F00000, 0xF37B3B13, 0xE8DBB1D6, 0x8FBCDE2E, 0x948A4320,
    0xC7E49247, 0x35F32692, 0xA26153A3, 0x80FA742F, 0xAAA54A9D, 0xA2522A26, 0xB9DCEA72,
    0x9FA91473, 0x04F9473F, 0xB91629FA, 0x4C6CDD7F, 0x582F97AC, 0x984E140F, 0x34F24934,
    0x58AB86C3, 0x10D55EB3, 0xAF89C502, 0x30804226, 0x8684F5E1, 0xADD47F18, 0x1FF1228B,
    0x861D563E, 0x4A04E298, 0x13121992, 0xCBDDEAF3, 0x27032FB7, 0x3961E0D1, 0x3CDFE000,
    0x1D1A3957, 0x490BD7AC, 0x2790C7DF, 0x64B0F80E, 0x062BBC59, 0x757BD30A, 0x7A41D163,
    0x1E4488B6, 0x07C057BD, 0x6DE2CD27, 0xDFE06061, 0x0D9E1B66, 0x8435ABCE, 0xA6006DB4,
    0x87FB089D, 0xD724528B, 0x9C1F60AF, 0xE8F6FB5D, 0xBE12BADC, 0xB6986D8E, 0x93A7E3F1,
    0xDC3E5C23, 0xC8C873F9, 0x4E670795, 0xE8F63AFC, 0xB6CB85DA, 0xF66F9DEE, 0x17ABDBE9,
    0x3C1A5F2F, 0xD7CDF17A, 0xFE7BCFB3, 0xF2F1FA73, 0x6F76E3E7, 0xFD777E1F, 0x8C469DF4,
    0x020CAC3F, 0x7D9D7008, 0x01801A16, 0x3B4CF13A, 0x18644C46, 0xC4198A62, 0x020C6398,
    0xCC12D930, 0x014543C0, 0xD715BD85, 0x95DD755C, 0x457F44E1, 0x09168F13, 0x5394C000,
    0x15454950, 0x6569560A, 0x9D655723, 0x6558D610, 0x5AD6959D, 0xD314BD12, 0x72A9354C,
    0xEA484F13, 0x42501434, 0x278A4501, 0xD4951CB0, 0x72604D44, 0xB11B4651, 0x5C4891D3,
    0x3C928486, 0x8F349527, 0xC33CFC3D, 0x10525E52, 0x6C9AD0C4, 0x388FB42E, 0x51344479,
    0x00000040, 0x294C0100, 0xC19FEF16, 0x2A130883, 0x1F50A85C, 0x06133C38, 0x24F00000,
    0xF37B3B13, 0xF8DBB1D6, 0x8DBBDE0E, 0x1BC9E71C, 0x489E7249, 0xA24CF292, 0x19AF994C,
    0x7D130A9D, 0xEC07D3A1, 0x38552A54, 0x853A994F, 0x53AAD553, 0x250A82A4, 0x50D46A25,
    0x0A8CA352, 0xDC8B14FD, 0x26366EBF, 0xAC17CBD6, 0x4C270A07, 0x41D9209A, 0x26920763,
    0x00DC9C4C, 0x89C4C241, 0x704A2813, 0xECE28100, 0x40211309, 0x427B6898, 0xEA3F8C43,
    0xF89145D6, 0x0EAB1F0F, 0x02714C43, 0x920BE905, 0x7140902F, 0xA2653532, 0x2390C7E3,
    0x24E06003, 0x072C3C1A, 0xE79BFC00, 0x83A3472A, 0x7A455EF2, 0xA660EF25, 0x3B539288,
    0xC961F01E, 0x0C5778B2, 0xEAF7A668, 0xF183A2C6, 0x554A2152, 0x08A620D0, 0x16AB5402,
    0xB349C1F0, 0x18185B78, 0xC6DB47F8, 0x4EF1836D, 0xFBD53A19, 0xC2E0EFDF, 0x22771325,
    0x4A2E1FEC, 0x72BF9891, 0xF53A5B8E, 0x6BB3D783, 0x612BAE2F, 0xA2FFE7F3, 0x5E9EAF4F,
    0xEDEDE43D, 0x3F2FBE11, 0xFB703D1F, 0xDEE7B1F7, 0x77C9F078, 0x01FF6F9E, 0x037E18E8,
    0x799D0792, 0x20A825F4, 0x47EA0C00, 0x5A077F20, 0x1582A127, 0x83DFB41E, 0xDD8821FD,
    0xF41A1D84, 0xFA107C61, 0x02872237, 0x8A20E85A, 0x22B86A21, 0xE311DB80, 0x00832B0F,
    0xB86D9E22, 0x8A9BC6E9, 0xDDB44E13, 0x3118ED33, 0x7D9D66D1, 0xA3685066, 0x69D06695,
    0xDAC90512, 0x43C0CC12, 0xF99A0145, 0x84609805, 0x62988619, 0x18F9058C, 0xA3C4D165,
    0x4C000245, 0x5955D555, 0x57D5D56D, 0xD6558D61, 0x45AD6959, 0xCD715BD7, 0x785D9675,
    0x4C9125E9, 0x93D4D934, 0xF4E13C4E, 0x154151D3, 0x43525475, 0x538B0279, 0x04D44D50,
    0x04651726, 0x5D1F4752, 0x2A4A127A, 0x4A69BA71, 0xCCF3F0F6, 0x41498E4B, 0xA6A84310,
    0xE23ED0BA, 0x001A81E4, 0x00000101, 0x294C0100, 0xC19FEF16, 0x2A130883, 0x1F50A85C,
    0x06133C38, 0x24F00000, 0xF37B3B13, 0xF8DBB1D6, 0x8DBBDE0E, 0x6BBDE51C, 0x3B5D71B7,
    0xA9E4F379, 0xE52F3954, 0x9AF9944A, 0xD130A9D1, 0xC07D3A17, 0xC552A54E, 0x53A994F3,
    0x3AAD553C, 0xCF274A45, 0x8946A955, 0xE994C522, 0x494D51A8, 0xEE458A7D, 0x131B375F,
    0xD60BE5EB, 0x26138503, 0xA0EC904D, 0x134903B1, 0x946A4E26, 0xC98491E0, 0x42442812,
    0xA2714074, 0x201089AE, 0xA13DD04C, 0x751FC621, 0xFC48A2EB, 0x87558F87, 0x8138A621,
    0xC905F482, 0x38A04817, 0x61225A99, 0x9B4EA48C, 0x30B21150, 0xCF67B3B1, 0x83449C0C,
    0x8000E587, 0xE55CF37F, 0xDE507468, 0xE4AF48AB, 0x43B45C1D, 0xDB83BED7, 0x0DDE7C48,
    0x2587C060, 0x315DE2CB, 0xABDE9A70, 0xC60E8B1B, 0x5528854B, 0x6E8B8341, 0x5B87AAC4,
    0x02CF6F37, 0x1669383E, 0x03030B6F, 0x48DB8CFF, 0x29DE306E, 0xFF9EA743, 0x15E3645B,
    0xB1D7EABD, 0x0FF6176B, 0xE148A517, 0x7E578D5F, 0xF6ECFD3E, 0x5B9419EF, 0xE7659D7C,
    0x89092E84, 0xE63FDE47, 0x7B1EA7A1, 0x2047C1EE, 0x88220600, 0x39FC8290, 0x02845FF8,
    0x8560475A, 0x60B7EA09, 0x0741FE83, 0x6A1F84A0, 0x1841E167, 0x83DFD796, 0x21387627,
    0xB8862A85, 0x9A1A8B9F, 0x033FE1C8, 0x85E2084E, 0xE2586622, 0xE8F2317A, 0xB23F7C61,
    0x438E2418, 0x91A01842, 0x50692633, 0xB8BE0C8B, 0xA63D93E1, 0xFE3104E8, 0x200832B0,
    0x1CA721F9, 0x26CDCE73, 0xFA32751D, 0xED33DDA8, 0x6A113118, 0x9066B1AA, 0x06C9B06B,
    0xA5B76D5D, 0x4B6FA049, 0x150F0330, 0xD8569C05, 0xD62D8961, 0x4D9163D8, 0x9965D956,
    0x0023366D, 0x8F1345A1, 0xA0000916, 0x815E5715, 0x66591625, 0x5B16A5A1, 0xD725C16E,
    0x95DC275E, 0xFD7D5ED7, 0x36449815, 0x4F5464E1, 0x5435053F, 0x95093B51, 0x3D5152D4,
    0xB0279515, 0x44D57554, 0x5172604D, 0xF4752046, 0x9122B151, 0x28498EC4, 0x4B9284BD,
    0xCFC3D92C, 0x26753333, 0x650C4105, 0xFB42EDAB, 0x44479388, 0x00040513, 0x294C0100,
    0xC19FEF16, 0x2A130883, 0x1F50A85C, 0x06133C38, 0x24F00000, 0xF37B3B13, 0xF8DBB1D6,
    0x8DBBDE0E, 0x6BBDE51C, 0xBB5D71B7, 0x6E34F079, 0x9E6F176C, 0xE72F97BC, 0xA7466BE5,
    0xE85F44C2, 0x953B01F4, 0x53CF954A, 0x54F94EA6, 0x2914EAB5, 0xA5573E9E, 0xD56A5512,
    0x46A554D0, 0xEA4A9A91, 0xFF722C53, 0x5898D9BA, 0x1EB05F2F, 0x69309C28, 0x8D076482,
    0x309A481D, 0x04A35271, 0x964C248F, 0xE1E21940, 0x4C2613C5, 0xD1791894, 0x138A04A1,
    0xF8C43427, 0x145D6EA3, 0xB1F0FF89, 0x14C430EA, 0xBE905027, 0x0902F920, 0x4B532714,
    0xD4918C24, 0x412A1369, 0xEA9C7E08, 0x2192E9D4, 0x0353131C, 0x1A24E060, 0x00072C3C,
    0x2AE79BFC, 0xF283A347, 0x257A455E, 0x1DA2E0EF, 0xBC1DF6BA, 0xC1CD00E6, 0xA8D0F07E,
    0xC3E03006, 0xAEF16592, 0xEF4D9018, 0x07458DD5, 0x9442A5E3, 0x45C1A0AA, 0x1BD56237,
    0xBF20FC5E, 0x0B966273, 0x59A4E0F8, 0x0C0C2DBC, 0x036EABFC, 0xA778C1BB, 0xFEF29D0C,
    0x578D916F, 0x9C6790F4, 0x1394FB41, 0x09EC7A86, 0x942E0FF3, 0x2BDF3244, 0xDF9765F5,
    0x17FDBE7E, 0x0DC441A0, 0x07814FF8, 0x139EB6AA, 0x9F4424BA, 0xA7E0FF7D, 0x01FE7F1F,
    0x1C41E028, 0x88A20822, 0x22689210, 0xB859DF85, 0xBA068122, 0x23422218, 0x8562784A,
    0x1E58622A, 0xF6A61D8E, 0xF5078EE1, 0x2884DF78, 0x86A428DA, 0x1EC87A2D, 0x59290692,
    0x5E409322, 0x2C864FF8, 0x8BE528E6, 0x23E8C63C, 0xB939FD8D, 0x7A1B90E5, 0x3094E469,
    0x8FE4B846, 0x26790635, 0x744E6A94, 0x62329B64, 0x5C96A719, 0x3122E912, 0x0832B0FE,
    0x975E0F20, 0xF9DD76DD, 0x4F78DE16, 0x8B9E879A, 0xC463B4CF, 0x76D5B344, 0xEDB9419B,
    0xC077DBD6, 0x41A8D709, 0x5AA729C8, 0x03304B73, 0xC805150F, 0x8E6318A6, 0x65192641,
    0x19A66196, 0x26819E67, 0xA1A6691A, 0xD16B1CB6, 0x0245A3C4, 0x55F57400, 0x75956358,
    0xB56B5A56, 0x735C56F5, 0x5E5775D5, 0x57F5F57B, 0x76158360, 0xE9380018, 0x414FD484,
    0x51D4550D, 0x54B5113D, 0x45454F53, 0xC09E2915, 0x13569582, 0x45C98135, 0xD1D48119,
    0x448AF247, 0xA1263B12, 0x2C3B12A4, 0x3CD304B9, 0x4CF3F0F6, 0x4149A94D, 0x27084310,
    0xE23ED0BC, 0x44D111E4, 0x00000101, 0x294C0100, 0xC19FEF16, 0x2A130883, 0x1F50A85C,
    0x06133C38, 0x24F00000, 0xF37B3B13, 0xF8DBB1D6, 0x8DBBDE0E, 0x6BBDE51C, 0xBB5D71B7,
    0x6E34F079, 0x1E0F0774, 0xF0F295C9, 0x6153A335, 0xFA742FA2, 0xA54A9D80, 0x5329E7AA,
    0x5AAA7AA7, 0xCED48A75, 0x8952AB9E, 0x684AB52A, 0x78A5532A, 0x8B2514F6, 0x366EBFDC,
    0x17CBD626, 0x270A07AC, 0xD9209A4C, 0x92076341, 0xD49C4C26, 0x0923C128, 0x86502593,
    0x84F17878, 0x45251309, 0xE238C068, 0x19934964, 0x5BA5003A, 0x3FE24517, 0x0C3AAC7C,
    0x1409C531, 0xBE482FA4, 0xC9C50240, 0x630912D4, 0x84DA7524, 0x1F82104A, 0xB2753AA7,
    0x0F090824, 0x8D38A445, 0x4A82E30A, 0x0E587833, 0xCF37F800, 0x07468E55, 0xF48ABDE5,
    0x45C1DE4A, 0x3BED743B, 0x9A01CD78, 0x45CEFB83, 0xA0EE83BA, 0x86542DAD, 0x6062BBC5,
    0x3757BD36, 0x978C1D16, 0x82AA510A, 0x88DD1706, 0xF1B88F55, 0x21BCFA83, 0xE0DCD3A2,
    0x08562BAC, 0xE060616E, 0xDA1B75DF, 0x653BC60D, 0x7FF814E8, 0x0AF0D88B, 0x671DE63D,
    0x18DC3E90, 0xFF7B4732, 0x158562CC, 0x0B83FCBB, 0xF7D89125, 0xF1DB7E0A, 0x026FDFE7,
    0x71506812, 0xA083FE06, 0x683A0C82, 0xDD092CC5, 0xFB3FDF97, 0x805FF7F5, 0x5E881603,
    0x641E0B82, 0xA9088A22, 0x1C8BA198, 0x79E1F8C6, 0xE258D207, 0xA41E3883, 0xBE1A7EA3,
    0x418CA1D8, 0x91236892, 0x62B85E29, 0xB7861B8B, 0x8E218FE4, 0x507BA358, 0x8EE528E6,
    0xE5780255, 0xE8CE203F, 0x46279724, 0x3C922189, 0x9923E95A, 0xE4288A40, 0xB97A6993,
    0xF6498B26, 0x599C21E8, 0x916689CE, 0x67891D06, 0x59BE629B, 0x365B9366, 0xFE2F20F8,
    0x200832B0, 0x5DB76616, 0x36FDDF77, 0xA258795E, 0x367B1EA7, 0x3B4C77C2, 0x9B444C46,
    0xA419B86D, 0x85BE6F1B, 0x9970DC17, 0x72DC941A, 0x05473E0C, 0x5150F031, 0x29886CC0,
    0x906398C6, 0x65994649, 0x99C66998, 0x4689A067, 0xA9A8699A, 0xF16B9AC6, 0x00009168,
    0x55F5755B, 0x75956358, 0xB56B5A56, 0x735C56F5, 0x5E5775D5, 0x57F5F57B, 0x06158360,
    0x1D394DC0, 0x425013E5, 0x54946511, 0x54D52D49, 0x25454F4F, 0x61565514, 0x98135135,
    0x4811945C, 0xB0047D1D, 0x84992F48, 0xB0EC4A92, 0xF4C012E4, 0x4D0CE3EC, 0xC5400113,
    0x6431FF31, 0xED08C5F1, 0x161ECE33, 0x40400448, 0x00000000

  EW_BITMAP_CLUT_EMPTY( OximeterBattery, Default )

  EW_BITMAPS_TABLE( OximeterBattery )
    EW_BITMAP( OximeterBattery, Default )
EW_END_OF_BITMAP_RES( OximeterBattery )

/* Embedded Wizard */
