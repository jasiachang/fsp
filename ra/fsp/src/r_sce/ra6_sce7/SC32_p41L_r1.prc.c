/////////////////////////////////////////////////////////////////////////

// <SC32#2 Generate hidden key for AES-128bit>                         //
// Procedure number: 41                                                //
// File name      : SC32_p41L_r1.prc                                   //
// State Diagram  : main(FSM1)                                         //
// Start State    : main03                                             //
// End State      : main03                                             //
// Input Data     : void                                               //
// Output Data    : OutData_KeyIndex[9]                                //
// Return Value   : Pass or Resource_Conflict                          //
// ---------------------------------------------------------------------//
// total cycle    : polling + write access + read access               //
// polling        : 336 cycle                                          //
// polling access :  37 times                                          //
// write access   : 110 times                                          //
// read  access   :  10 times                                          //
/////////////////////////////////////////////////////////////////////////

#include "SCE_ProcCommon.h"
#include "hw_sce_aes_private.h"

fsp_err_t HW_SCE_AES_128CreateEncryptedKey (uint32_t * OutData_KeyIndex)
{
    if (RD1_MASK(REG_1BCH, 0x0000001f) != 0x0000000)
    {
        // Busy now then retry later;
        // Because  1_xxxx other processing box is in duty.
        // x_1xxx resource D is in duty,then retry after you released D.
        // x_x1xx resource C is in duty,then retry after you released C.
        // x_xx1x resource B is in duty,then retry after you released B.
        // x_xxx1 resource A is in duty,then retry after you released A.

        // A,B,C,D: see Primitive Level Procedures datasheet
        return FSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_84H, 0x00004101);
    WR1_PROG(REG_108H, 0x00000000);

    WR1_PROG(REG_1C0H, 0x00010001);

    SC32_function001(0x5f01d4b5, 0x81c43310, 0xc6483dfc, 0x124c856d);

    WR1_PROG(REG_104H, 0x00000252);
    WR1_PROG(REG_C4H, 0x01003774);
    WAIT_STS(REG_104H, 31, 1);
    WR1_PROG(REG_100H, 0x00000000);

    WR1_PROG(REG_C4H, 0x010037f4);
    WAIT_STS(REG_104H, 31, 1);
    WR1_PROG(REG_100H, 0x00000000);

    WR1_PROG(REG_C4H, 0x010037f4);
    WAIT_STS(REG_104H, 31, 1);
    WR1_PROG(REG_100H, 0x00000000);

    WR1_PROG(REG_C4H, 0x00060805);
    WR1_PROG(REG_00H, 0x00002213);
    WAIT_STS(REG_00H, 25, 0);
    WR1_PROG(REG_1CH, 0x00001800);

    WR1_PROG(REG_104H, 0x00000052);
    WR1_PROG(REG_C4H, 0x01073644);
    WAIT_STS(REG_104H, 31, 1);
    WR1_PROG(REG_100H, 0x00000000);

    WR1_PROG(REG_C4H, 0x000b0805);
    WR1_PROG(REG_00H, 0x00002213);
    WAIT_STS(REG_00H, 25, 0);
    WR1_PROG(REG_1CH, 0x00001800);
    WR1_PROG(REG_104H, 0x00000052);
    WR1_PROG(REG_C4H, 0x01000c84);
    WAIT_STS(REG_104H, 31, 1);
    WR1_PROG(REG_100H, 0x00000000);

    WR1_PROG(REG_E0H, 0x80040000);
    WR1_PROG(REG_1D0H, 0x00000000);
    WR1_PROG(REG_00H, 0x00008213);
    WAIT_STS(REG_00H, 25, 0);
    WR1_PROG(REG_1CH, 0x00001800);

    SC32_function001(0xd88b3379, 0xfb1d1b4b, 0x09c69343, 0x573d61a0);
    WR1_PROG(REG_E0H, 0x81010000);
    WR1_PROG(REG_1D0H, 0x00000000);
    WR1_PROG(REG_A4H, 0x00000884);
    WR1_PROG(REG_00H, 0x00001807);
    WAIT_STS(REG_00H, 25, 0);
    WR1_PROG(REG_1CH, 0x00001800);
    WR1_PROG(REG_04H, 0x00000107);
    WAIT_STS(REG_04H, 30, 1);
    RD1_ADDR(REG_A0H, &OutData_KeyIndex[0]);
    WR1_PROG(REG_00H, 0x0000010f);
    WAIT_STS(REG_00H, 25, 0);
    WR1_PROG(REG_1CH, 0x00001800);

    WR1_PROG(REG_A4H, 0x200c3b0c);
    WR1_PROG(REG_E0H, 0x81010000);
    WR1_PROG(REG_1D0H, 0x00000000);
    WR1_PROG(REG_00H, 0x00001807);
    WAIT_STS(REG_00H, 25, 0);
    WR1_PROG(REG_1CH, 0x00001800);

    WR1_PROG(REG_A4H, 0x000c0b0c);
    WAIT_STS(REG_104H, 31, 1);
    WR1_PROG(REG_100H, 0x4e2279db);

    SC32_function001(0x0e4132ff, 0xf413a02a, 0xd6afb0ce, 0x51262bd9);

    WR1_PROG(REG_104H, 0x00000252);
    WR1_PROG(REG_C4H, 0x01003774);
    WAIT_STS(REG_104H, 31, 1);
    WR1_PROG(REG_100H, 0x00000000);

    WR1_PROG(REG_C4H, 0x010037f4);
    WAIT_STS(REG_104H, 31, 1);
    WR1_PROG(REG_100H, 0x00000000);

    WR1_PROG(REG_C4H, 0x010037f4);
    WAIT_STS(REG_104H, 31, 1);
    WR1_PROG(REG_100H, 0x00000000);

    WR1_PROG(REG_C4H, 0x00060805);
    WR1_PROG(REG_00H, 0x00002213);
    WAIT_STS(REG_00H, 25, 0);
    WR1_PROG(REG_1CH, 0x00001800);

    WR1_PROG(REG_104H, 0x00000052);
    WR1_PROG(REG_C4H, 0x01073644);
    WAIT_STS(REG_104H, 31, 1);
    WR1_PROG(REG_100H, 0x00000000);

    WR1_PROG(REG_C4H, 0x000b0805);
    WR1_PROG(REG_00H, 0x00002213);
    WAIT_STS(REG_00H, 25, 0);
    WR1_PROG(REG_1CH, 0x00001800);
    WR1_PROG(REG_104H, 0x00000052);
    WR1_PROG(REG_C4H, 0x01000c84);
    WAIT_STS(REG_104H, 31, 1);
    WR1_PROG(REG_100H, 0x00000000);

    WR1_PROG(REG_A4H, 0x02e407bd);
    WR1_PROG(REG_00H, 0x00001213);
    WAIT_STS(REG_00H, 25, 0);
    WR1_PROG(REG_1CH, 0x00001800);

    SC32_function001(0xccd8f2d7, 0x211d4ead, 0xe593e8f0, 0xd46d025e);
    WR1_PROG(REG_104H, 0x00000351);
    WR1_PROG(REG_A4H, 0x000009cd);
    WAIT_STS(REG_104H, 31, 1);
    WR4_PROG(REG_100H, 0x00000000, 0x00000000, 0x00000000, 0x00000001);

    WR1_PROG(REG_04H, 0x00000123);
    WAIT_STS(REG_04H, 30, 1);
    RD4_ADDR(REG_A0H, &OutData_KeyIndex[1]);
    WAIT_STS(REG_04H, 30, 1);
    RD4_ADDR(REG_A0H, &OutData_KeyIndex[5]);

    WR1_PROG(REG_1C0H, 0x00010000);

    SC32_function003(0x45492d30, 0xb795806d, 0x16b841fe, 0x71537bf2);
    WR1_PROG(REG_1BCH, 0x00000040);
    WAIT_STS(REG_18H, 12, 0);

    return FSP_SUCCESS;
}
