/****************************************************************************** 
* 
* Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved. 
* 
* This program is free software; you can redistribute it and/or modify it 
* under the terms of version 2 of the GNU General Public License as 
* published by the Free Software Foundation. 
* 
* This program is distributed in the hope that it will be useful, but WITHOUT 
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
* more details. 
* 
* You should have received a copy of the GNU General Public License along with 
* this program; if not, write to the Free Software Foundation, Inc., 
* 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA 
* 
* 
******************************************************************************/

#include "../odm_precomp.h"

#if (RTL8192E_SUPPORT == 1)
static BOOLEAN
CheckCondition(
    const u4Byte  Condition,
    const u4Byte  Hex
    )
{
    u4Byte _board     = (Hex & 0x000000FF);
    u4Byte _interface = (Hex & 0x0000FF00) >> 8;
    u4Byte _platform  = (Hex & 0x00FF0000) >> 16;
    u4Byte cond = Condition;

    if ( Condition == 0xCDCDCDCD )
        return TRUE;

    cond = Condition & 0x000000FF;
    if ( (_board != cond) && (cond != 0xFF) )
        return FALSE;

    cond = Condition & 0x0000FF00;
    cond = cond >> 8;
    if ( ((_interface & cond) == 0) && (cond != 0x07) )
        return FALSE;

    cond = Condition & 0x00FF0000;
    cond = cond >> 16;
    if ( ((_platform & cond) == 0) && (cond != 0x0F) )
        return FALSE;
    return TRUE;
}


/******************************************************************************
*                           RadioA.TXT
******************************************************************************/

u4Byte Array_MP_8192E_RadioA[] = { 
		0x07F, 0x00000082,
		0x081, 0x0003FC00,
		0x000, 0x00030000,
		0x008, 0x00008400,
		0x018, 0x00000407,
		0x019, 0x00000012,
		0x01B, 0x00000064,
		0x01E, 0x00080009,
		0x01F, 0x00000880,
		0x02F, 0x0001A060,
		0x03F, 0x00000000,
		0x042, 0x000060C0,
		0x057, 0x000D0000,
		0x058, 0x000BE180,
		0x067, 0x00001552,
		0x083, 0x00000000,
		0x0B0, 0x000FF9F1,
		0x0B1, 0x00055418,
		0x0B2, 0x0008CC00,
		0x0B4, 0x00043083,
		0x0B5, 0x00008166,
		0x0B6, 0x0000803E,
		0x0B7, 0x0001C69F,
		0x0B8, 0x0000407F,
		0x0B9, 0x00080001,
		0x0BA, 0x00040001,
		0x0BB, 0x00000400,
		0x0BF, 0x000C0000,
		0x0C2, 0x00002400,
		0x0C3, 0x00000009,
		0x0C4, 0x00040C91,
		0x0C5, 0x00099999,
		0x0C6, 0x000000A3,
		0x0C7, 0x00088820,
		0x0C8, 0x00076C06,
		0x0C9, 0x00000000,
		0x0CA, 0x00080000,
		0x0DF, 0x00000180,
		0x0EF, 0x000001A0,
		0x051, 0x00069545,
		0x052, 0x0007E45E,
		0x053, 0x00000071,
		0x056, 0x00051FF3,
		0x035, 0x000000A8,
		0x035, 0x000001E0,
		0x035, 0x000002A8,
		0x036, 0x00001C24,
		0x036, 0x00009C24,
		0x036, 0x00011C24,
		0x036, 0x00019C24,
		0x018, 0x00000C07,
		0x05A, 0x00048000,
		0x019, 0x000739D0,
	0xFF010718, 0xABCD,
		0x034, 0x0000A093,
		0x034, 0x0000908F,
		0x034, 0x0000808C,
		0x034, 0x0000704F,
		0x034, 0x0000604C,
		0x034, 0x00005049,
		0x034, 0x0000400C,
		0x034, 0x00003009,
		0x034, 0x00002006,
		0x034, 0x00001003,
		0x034, 0x00000000,
	0xCDCDCDCD, 0xCDCD,
		0x034, 0x0000ADD7,
		0x034, 0x00009DD4,
		0x034, 0x00008DD1,
		0x034, 0x00007DCE,
		0x034, 0x00006DCB,
		0x034, 0x000054D2,
		0x034, 0x000044CF,
		0x034, 0x000034CC,
		0x034, 0x0000244F,
		0x034, 0x0000144C,
		0x034, 0x00000051,
	0xFF010718, 0xDEAD,
		0x000, 0x00030159,
		0x084, 0x00068180,
		0x086, 0x0000014E,
		0x087, 0x00048E00,
		0x08E, 0x00065540,
		0x08F, 0x00088000,
		0x0EF, 0x000020A0,
		0x03B, 0x000F82B0,
		0x03B, 0x000EF7B0,
		0x03B, 0x000D4FB0,
		0x03B, 0x000CF060,
		0x03B, 0x000B0090,
		0x03B, 0x000A0080,
		0x03B, 0x00090080,
		0x03B, 0x0008F780,
		0x03B, 0x0007C730,
		0x03B, 0x00060FB0,
		0x03B, 0x0005FFA0,
		0x03B, 0x00040620,
		0x03B, 0x00030090,
		0x03B, 0x00020080,
		0x03B, 0x0001F060,
		0x03B, 0x0000FFB0,
		0x0EF, 0x000000A0,
		0x0FE, 0x00000000,	
		0x018, 0x0000FC07,
		0x0FE, 0x00000000,
		0x0FE, 0x00000000,
		0x0FE, 0x00000000,
		0x0FE, 0x00000000,	
		0x01E, 0x00000001,
		0x01F, 0x00080000,
		0x000, 0x00033E70,

};

void
ODM_ReadAndConfig_MP_8192E_RadioA(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	#define READ_NEXT_PAIR(v1, v2, i) do { i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)

	u4Byte     hex         = 0;
	u4Byte     i           = 0;
	u2Byte     count       = 0;
	pu4Byte    ptr_array   = NULL;
	u1Byte     platform    = pDM_Odm->SupportPlatform;
	u1Byte     _interface   = pDM_Odm->SupportInterface;
	u1Byte     board       = pDM_Odm->BoardType;  
	u4Byte     ArrayLen    = sizeof(Array_MP_8192E_RadioA)/sizeof(u4Byte);
	pu4Byte    Array       = Array_MP_8192E_RadioA;


	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_8192E_RadioA, hex = 0x%X\n", hex));

	for (i = 0; i < ArrayLen; i += 2 )
	{
	    u4Byte v1 = Array[i];
	    u4Byte v2 = Array[i+1];
	
	    // This (offset, data) pair meets the condition.
	    if ( v1 < 0xCDCDCDCD )
	    {
		    odm_ConfigRF_RadioA_8192E(pDM_Odm, v1, v2);
		    continue;
	 	}
		else
		{ // This line is the start line of branch.
		    if ( !CheckCondition(Array[i], hex) )
		    { // Discard the following (offset, data) pairs.
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        i -= 2; // prevent from for-loop += 2
		    }
		    else // Configure matched pairs and skip to end of if-else.
		    {
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		    		odm_ConfigRF_RadioA_8192E(pDM_Odm, v1, v2);
		            READ_NEXT_PAIR(v1, v2, i);
		        }

		        while (v2 != 0xDEAD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        
		    }
		}	
	}

}

/******************************************************************************
*                           RadioB.TXT
******************************************************************************/

u4Byte Array_MP_8192E_RadioB[] = { 
		0x07F, 0x00000082,
		0x081, 0x0003FC00,
		0x000, 0x00030000,
		0x008, 0x00008400,
		0x018, 0x00000407,
		0x019, 0x00000012,
		0x01B, 0x00000064,
		0x01E, 0x00080009,
		0x01F, 0x00000880,
		0x02F, 0x0001A060,
		0x03F, 0x00000000,
		0x042, 0x000060C0,
		0x057, 0x000D0000,
		0x058, 0x000BE180,
		0x067, 0x00001552,
		0x07F, 0x00000082,
		0x081, 0x0003F000,
		0x083, 0x00000000,
		0x0DF, 0x00000180,
		0x0EF, 0x000001A0,
		0x051, 0x00069545,
		0x052, 0x0007E42E,
		0x053, 0x00000071,
		0x056, 0x00051FF3,
		0x035, 0x000000A8,
		0x035, 0x000001E0,
		0x035, 0x000002A8,
		0x036, 0x00001CA8,
		0x036, 0x00009C24,
		0x036, 0x00011C24,
		0x036, 0x00019C24,
		0x018, 0x00000C07,
		0x05A, 0x00048000,
		0x019, 0x000739D0,
	0xFF010718, 0xABCD,
		0x034, 0x0000A093,
		0x034, 0x0000908F,
		0x034, 0x0000808C,
		0x034, 0x0000704F,
		0x034, 0x0000604C,
		0x034, 0x00005049,
		0x034, 0x0000400C,
		0x034, 0x00003009,
		0x034, 0x00002006,
		0x034, 0x00001003,
		0x034, 0x00000000,
	0xCDCDCDCD, 0xCDCD,
		0x034, 0x0000ADD7,
		0x034, 0x00009DD4,
		0x034, 0x00008DD1,
		0x034, 0x00007DCE,
		0x034, 0x00006DCB,
		0x034, 0x000054D2,
		0x034, 0x000044CF,
		0x034, 0x000034CC,
		0x034, 0x0000244F,
		0x034, 0x0000144C,
		0x034, 0x00000051,
	0xFF010718, 0xDEAD,
		0x000, 0x00030159,
		0x084, 0x00068180,
		0x086, 0x000000CE,
		0x087, 0x00048A00,
		0x08E, 0x00065540,
		0x08F, 0x00088000,
		0x0EF, 0x000020A0,
		0x03B, 0x000F82B0,
		0x03B, 0x000EF7B0,
		0x03B, 0x000D4FB0,
		0x03B, 0x000CF060,
		0x03B, 0x000B0090,
		0x03B, 0x000A0080,
		0x03B, 0x00090080,
		0x03B, 0x0008F780,
		0x03B, 0x0007C730,
		0x03B, 0x00060FB0,
		0x03B, 0x0005FFA0,
		0x03B, 0x00040620,
		0x03B, 0x00030090,
		0x03B, 0x00020080,
		0x03B, 0x0001F060,
		0x03B, 0x0000FFB0,
		0x0EF, 0x000000A0,
		0x000, 0x00010159,
		0x0FE, 0x00000000,
		0x0FE, 0x00000000,
		0x0FE, 0x00000000,
		0x0FE, 0x00000000,
		0x01E, 0x00000001,
		0x01F, 0x00080000,
		0x000, 0x00033E70,

};

void
ODM_ReadAndConfig_MP_8192E_RadioB(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	#define READ_NEXT_PAIR(v1, v2, i) do { i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)

	u4Byte     hex         = 0;
	u4Byte     i           = 0;
	u2Byte     count       = 0;
	pu4Byte    ptr_array   = NULL;
	u1Byte     platform    = pDM_Odm->SupportPlatform;
	u1Byte     _interface   = pDM_Odm->SupportInterface;
	u1Byte     board       = pDM_Odm->BoardType;  
	u4Byte     ArrayLen    = sizeof(Array_MP_8192E_RadioB)/sizeof(u4Byte);
	pu4Byte    Array       = Array_MP_8192E_RadioB;


	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_8192E_RadioB, hex = 0x%X\n", hex));

	for (i = 0; i < ArrayLen; i += 2 )
	{
	    u4Byte v1 = Array[i];
	    u4Byte v2 = Array[i+1];
	
	    // This (offset, data) pair meets the condition.
	    if ( v1 < 0xCDCDCDCD )
	    {
		    odm_ConfigRF_RadioB_8192E(pDM_Odm, v1, v2);
		    continue;
	 	}
		else
		{ // This line is the start line of branch.
		    if ( !CheckCondition(Array[i], hex) )
		    { // Discard the following (offset, data) pairs.
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        i -= 2; // prevent from for-loop += 2
		    }
		    else // Configure matched pairs and skip to end of if-else.
		    {
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		    		odm_ConfigRF_RadioB_8192E(pDM_Odm, v1, v2);
		            READ_NEXT_PAIR(v1, v2, i);
		        }

		        while (v2 != 0xDEAD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        
		    }
		}	
	}

}

/******************************************************************************
*                           TxPowerTrack_AP.TXT
******************************************************************************/

u1Byte gDeltaSwingTableIdx_MP_5GB_N_TxPowerTrack_AP_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 5, 6,  6,  7,  7,  8,  8,  9,  9, 10, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
};
u1Byte gDeltaSwingTableIdx_MP_5GB_P_TxPowerTrack_AP_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 17, 17, 18, 19, 20, 20, 20},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 19, 20, 20, 20},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 21, 21, 21},
};
u1Byte gDeltaSwingTableIdx_MP_5GA_N_TxPowerTrack_AP_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 2, 3, 3, 4, 4, 5, 5, 6,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 6,  7,  7,  8,  8,  9, 10, 11, 11, 12, 13, 13, 14, 15, 16, 16, 16, 16, 16, 16, 16},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 10, 11, 11, 12, 13, 14, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16},
};
u1Byte gDeltaSwingTableIdx_MP_5GA_P_TxPowerTrack_AP_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 21, 21, 21},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 21, 21, 21},
};
u1Byte gDeltaSwingTableIdx_MP_2GB_N_TxPowerTrack_AP_8192E[]    = {0, 0, 1, 2, 2, 2, 3, 3, 3, 4,  5,  5,  6,  6,  6,  6,  7,  7,  7,  8,  8,  9,  9, 10, 10, 11, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GB_P_TxPowerTrack_AP_8192E[]    = {0, 0, 1, 2, 2, 2, 3, 3, 3, 4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9,  9, 10, 10, 11, 11, 12, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GA_N_TxPowerTrack_AP_8192E[]    = {0, 0, 1, 2, 2, 2, 3, 3, 3, 4,  5,  5,  6,  6,  6,  6,  7,  7,  7,  8,  8,  9,  9, 10, 10, 11, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GA_P_TxPowerTrack_AP_8192E[]    = {0, 0, 1, 2, 2, 2, 3, 3, 3, 4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9,  9, 10, 10, 11, 11, 12, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GCCKB_N_TxPowerTrack_AP_8192E[] = {0, 0, 1, 2, 2, 3, 3, 4, 4, 5,  6,  6,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10, 10, 11, 11, 12, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GCCKB_P_TxPowerTrack_AP_8192E[] = {0, 0, 0, 0, 1, 1, 1, 3, 3, 4,  4,  4,  4,  6,  6,  6,  6,  7,  7,  7,  9, 10, 10, 11, 11, 12, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GCCKA_N_TxPowerTrack_AP_8192E[] = {0, 0, 1, 2, 2, 3, 3, 4, 4, 5,  6,  6,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10, 10, 11, 11, 12, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GCCKA_P_TxPowerTrack_AP_8192E[] = {0, 0, 0, 0, 1, 1, 1, 3, 3, 4,  4,  4,  4,  6,  6,  6,  6,  7,  7,  7,  9, 10, 10, 11, 11, 12, 12, 13, 14, 15};

void
ODM_ReadAndConfig_MP_8192E_TxPowerTrack_AP(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	PODM_RF_CAL_T  pRFCalibrateInfo = &(pDM_Odm->RFCalibrateInfo);

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_8192E_TxPowerTrack_AP\n"));


	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GA_P, gDeltaSwingTableIdx_MP_2GA_P_TxPowerTrack_AP_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GA_N, gDeltaSwingTableIdx_MP_2GA_N_TxPowerTrack_AP_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GB_P, gDeltaSwingTableIdx_MP_2GB_P_TxPowerTrack_AP_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GB_N, gDeltaSwingTableIdx_MP_2GB_N_TxPowerTrack_AP_8192E, DELTA_SWINGIDX_SIZE);

	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_P, gDeltaSwingTableIdx_MP_2GCCKA_P_TxPowerTrack_AP_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_N, gDeltaSwingTableIdx_MP_2GCCKA_N_TxPowerTrack_AP_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_P, gDeltaSwingTableIdx_MP_2GCCKB_P_TxPowerTrack_AP_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_N, gDeltaSwingTableIdx_MP_2GCCKB_N_TxPowerTrack_AP_8192E, DELTA_SWINGIDX_SIZE);

	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GA_P, gDeltaSwingTableIdx_MP_5GA_P_TxPowerTrack_AP_8192E, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GA_N, gDeltaSwingTableIdx_MP_5GA_N_TxPowerTrack_AP_8192E, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GB_P, gDeltaSwingTableIdx_MP_5GB_P_TxPowerTrack_AP_8192E, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GB_N, gDeltaSwingTableIdx_MP_5GB_N_TxPowerTrack_AP_8192E, DELTA_SWINGIDX_SIZE*3);
}

/******************************************************************************
*                           TxPowerTrack_PCIE.TXT
******************************************************************************/

u1Byte gDeltaSwingTableIdx_MP_5GB_N_TxPowerTrack_PCIE_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 5, 6,  6,  7,  7,  8,  8,  9,  9, 10, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
};
u1Byte gDeltaSwingTableIdx_MP_5GB_P_TxPowerTrack_PCIE_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 17, 17, 18, 19, 20, 20, 20},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 19, 20, 20, 20},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 21, 21, 21},
};
u1Byte gDeltaSwingTableIdx_MP_5GA_N_TxPowerTrack_PCIE_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 2, 3, 3, 4, 4, 5, 5, 6,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 6,  7,  7,  8,  8,  9, 10, 11, 11, 12, 13, 13, 14, 15, 16, 16, 16, 16, 16, 16, 16},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 10, 11, 11, 12, 13, 14, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16},
};
u1Byte gDeltaSwingTableIdx_MP_5GA_P_TxPowerTrack_PCIE_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 21, 21, 21},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 21, 21, 21},
};
u1Byte gDeltaSwingTableIdx_MP_2GB_N_TxPowerTrack_PCIE_8192E[]    = {0, 0, 1, 2, 2, 2, 3, 3, 3, 4,  5,  5,  6,  6,  6,  6,  7,  7,  7,  8,  8,  9,  9, 10, 10, 11, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GB_P_TxPowerTrack_PCIE_8192E[]    = {0, 0, 1, 2, 2, 2, 3, 3, 3, 4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9,  9, 10, 10, 11, 11, 12, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GA_N_TxPowerTrack_PCIE_8192E[]    = {0, 0, 1, 2, 2, 2, 3, 3, 3, 4,  5,  5,  6,  6,  6,  6,  7,  7,  7,  8,  8,  9,  9, 10, 10, 11, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GA_P_TxPowerTrack_PCIE_8192E[]    = {0, 0, 1, 2, 2, 2, 3, 3, 3, 4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9,  9, 10, 10, 11, 11, 12, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GCCKB_N_TxPowerTrack_PCIE_8192E[] = {0, 0, 1, 2, 2, 3, 3, 4, 4, 5,  6,  6,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10, 10, 11, 11, 12, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GCCKB_P_TxPowerTrack_PCIE_8192E[] = {0, 0, 0, 0, 1, 1, 1, 3, 3, 4,  4,  4,  4,  6,  6,  6,  6,  7,  7,  7,  9, 10, 10, 11, 11, 12, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GCCKA_N_TxPowerTrack_PCIE_8192E[] = {0, 0, 1, 2, 2, 3, 3, 4, 4, 5,  6,  6,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10, 10, 11, 11, 12, 12, 13, 14, 15};
u1Byte gDeltaSwingTableIdx_MP_2GCCKA_P_TxPowerTrack_PCIE_8192E[] = {0, 0, 0, 0, 1, 1, 1, 3, 3, 4,  4,  4,  4,  6,  6,  6,  6,  7,  7,  7,  9, 10, 10, 11, 11, 12, 12, 13, 14, 15};

void
ODM_ReadAndConfig_MP_8192E_TxPowerTrack_PCIE(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	PODM_RF_CAL_T  pRFCalibrateInfo = &(pDM_Odm->RFCalibrateInfo);

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_MP_8192E\n"));


	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GA_P, gDeltaSwingTableIdx_MP_2GA_P_TxPowerTrack_PCIE_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GA_N, gDeltaSwingTableIdx_MP_2GA_N_TxPowerTrack_PCIE_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GB_P, gDeltaSwingTableIdx_MP_2GB_P_TxPowerTrack_PCIE_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GB_N, gDeltaSwingTableIdx_MP_2GB_N_TxPowerTrack_PCIE_8192E, DELTA_SWINGIDX_SIZE);

	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_P, gDeltaSwingTableIdx_MP_2GCCKA_P_TxPowerTrack_PCIE_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_N, gDeltaSwingTableIdx_MP_2GCCKA_N_TxPowerTrack_PCIE_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_P, gDeltaSwingTableIdx_MP_2GCCKB_P_TxPowerTrack_PCIE_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_N, gDeltaSwingTableIdx_MP_2GCCKB_N_TxPowerTrack_PCIE_8192E, DELTA_SWINGIDX_SIZE);

	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GA_P, gDeltaSwingTableIdx_MP_5GA_P_TxPowerTrack_PCIE_8192E, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GA_N, gDeltaSwingTableIdx_MP_5GA_N_TxPowerTrack_PCIE_8192E, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GB_P, gDeltaSwingTableIdx_MP_5GB_P_TxPowerTrack_PCIE_8192E, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GB_N, gDeltaSwingTableIdx_MP_5GB_N_TxPowerTrack_PCIE_8192E, DELTA_SWINGIDX_SIZE*3);
}

/******************************************************************************
*                           TxPowerTrack_SDIO.TXT
******************************************************************************/

u1Byte gDeltaSwingTableIdx_MP_5GB_N_TxPowerTrack_SDIO_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 5, 6,  6,  7,  7,  8,  8,  9,  9, 10, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
};
u1Byte gDeltaSwingTableIdx_MP_5GB_P_TxPowerTrack_SDIO_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 17, 17, 18, 19, 20, 20, 20},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 19, 20, 20, 20},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 21, 21, 21},
};
u1Byte gDeltaSwingTableIdx_MP_5GA_N_TxPowerTrack_SDIO_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 2, 3, 3, 4, 4, 5, 5, 6,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 6,  7,  7,  8,  8,  9, 10, 11, 11, 12, 13, 13, 14, 15, 16, 16, 16, 16, 16, 16, 16},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 10, 11, 11, 12, 13, 14, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16},
};
u1Byte gDeltaSwingTableIdx_MP_5GA_P_TxPowerTrack_SDIO_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 5, 6,  7,  8,  8,  9, 10, 11, 11, 12, 13, 14, 14, 15, 15, 16, 16, 17, 18, 19, 19, 19},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 21, 21, 21},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 21, 21, 21},
};
u1Byte gDeltaSwingTableIdx_MP_2GB_N_TxPowerTrack_SDIO_8192E[]    = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 23, 23, 23, 23, 23, 23};
u1Byte gDeltaSwingTableIdx_MP_2GB_P_TxPowerTrack_SDIO_8192E[]    = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
u1Byte gDeltaSwingTableIdx_MP_2GA_N_TxPowerTrack_SDIO_8192E[]    = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 23, 23, 23, 23, 23, 23};
u1Byte gDeltaSwingTableIdx_MP_2GA_P_TxPowerTrack_SDIO_8192E[]    = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
u1Byte gDeltaSwingTableIdx_MP_2GCCKB_N_TxPowerTrack_SDIO_8192E[] = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 23, 23, 23, 23, 23, 23};
u1Byte gDeltaSwingTableIdx_MP_2GCCKB_P_TxPowerTrack_SDIO_8192E[] = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
u1Byte gDeltaSwingTableIdx_MP_2GCCKA_N_TxPowerTrack_SDIO_8192E[] = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 23, 23, 23, 23, 23, 23};
u1Byte gDeltaSwingTableIdx_MP_2GCCKA_P_TxPowerTrack_SDIO_8192E[] = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

void
ODM_ReadAndConfig_MP_8192E_TxPowerTrack_SDIO(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	PODM_RF_CAL_T  pRFCalibrateInfo = &(pDM_Odm->RFCalibrateInfo);

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_MP_8192E\n"));


	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GA_P, gDeltaSwingTableIdx_MP_2GA_P_TxPowerTrack_SDIO_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GA_N, gDeltaSwingTableIdx_MP_2GA_N_TxPowerTrack_SDIO_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GB_P, gDeltaSwingTableIdx_MP_2GB_P_TxPowerTrack_SDIO_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GB_N, gDeltaSwingTableIdx_MP_2GB_N_TxPowerTrack_SDIO_8192E, DELTA_SWINGIDX_SIZE);

	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_P, gDeltaSwingTableIdx_MP_2GCCKA_P_TxPowerTrack_SDIO_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_N, gDeltaSwingTableIdx_MP_2GCCKA_N_TxPowerTrack_SDIO_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_P, gDeltaSwingTableIdx_MP_2GCCKB_P_TxPowerTrack_SDIO_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_N, gDeltaSwingTableIdx_MP_2GCCKB_N_TxPowerTrack_SDIO_8192E, DELTA_SWINGIDX_SIZE);

	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GA_P, gDeltaSwingTableIdx_MP_5GA_P_TxPowerTrack_SDIO_8192E, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GA_N, gDeltaSwingTableIdx_MP_5GA_N_TxPowerTrack_SDIO_8192E, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GB_P, gDeltaSwingTableIdx_MP_5GB_P_TxPowerTrack_SDIO_8192E, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GB_N, gDeltaSwingTableIdx_MP_5GB_N_TxPowerTrack_SDIO_8192E, DELTA_SWINGIDX_SIZE*3);
}

/******************************************************************************
*                           TxPowerTrack_USB.TXT
******************************************************************************/

u1Byte gDeltaSwingTableIdx_MP_5GB_N_TxPowerTrack_USB_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 5, 6,  6,  7,  7,  8,  8,  9,  9, 10, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
};
u1Byte gDeltaSwingTableIdx_MP_5GB_P_TxPowerTrack_USB_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 17, 17, 18, 19, 20, 20, 20},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 19, 20, 20, 20},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 21, 21, 21},
};
u1Byte gDeltaSwingTableIdx_MP_5GA_N_TxPowerTrack_USB_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 2, 3, 3, 4, 4, 5, 5, 6,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 14},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 6,  7,  7,  8,  8,  9, 10, 11, 11, 12, 13, 13, 14, 15, 16, 16, 16, 16, 16, 16, 16},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 10, 11, 11, 12, 13, 14, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16},
};
u1Byte gDeltaSwingTableIdx_MP_5GA_P_TxPowerTrack_USB_8192E[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 5, 6,  7,  8,  8,  9, 10, 11, 11, 12, 13, 14, 14, 15, 15, 16, 16, 17, 18, 19, 19, 19},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 21, 21, 21},
	{0, 1, 2, 3, 3, 4, 5, 6, 6, 7,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 21, 21, 21},
};
u1Byte gDeltaSwingTableIdx_MP_2GB_N_TxPowerTrack_USB_8192E[]    = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 23, 23, 23, 23, 23, 23};
u1Byte gDeltaSwingTableIdx_MP_2GB_P_TxPowerTrack_USB_8192E[]    = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
u1Byte gDeltaSwingTableIdx_MP_2GA_N_TxPowerTrack_USB_8192E[]    = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 23, 23, 23, 23, 23, 23};
u1Byte gDeltaSwingTableIdx_MP_2GA_P_TxPowerTrack_USB_8192E[]    = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
u1Byte gDeltaSwingTableIdx_MP_2GCCKB_N_TxPowerTrack_USB_8192E[] = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 23, 23, 23, 23, 23, 23};
u1Byte gDeltaSwingTableIdx_MP_2GCCKB_P_TxPowerTrack_USB_8192E[] = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
u1Byte gDeltaSwingTableIdx_MP_2GCCKA_N_TxPowerTrack_USB_8192E[] = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 23, 23, 23, 23, 23, 23};
u1Byte gDeltaSwingTableIdx_MP_2GCCKA_P_TxPowerTrack_USB_8192E[] = {0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

void
ODM_ReadAndConfig_MP_8192E_TxPowerTrack_USB(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	PODM_RF_CAL_T  pRFCalibrateInfo = &(pDM_Odm->RFCalibrateInfo);

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_MP_8192E\n"));


	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GA_P, gDeltaSwingTableIdx_MP_2GA_P_TxPowerTrack_USB_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GA_N, gDeltaSwingTableIdx_MP_2GA_N_TxPowerTrack_USB_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GB_P, gDeltaSwingTableIdx_MP_2GB_P_TxPowerTrack_USB_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GB_N, gDeltaSwingTableIdx_MP_2GB_N_TxPowerTrack_USB_8192E, DELTA_SWINGIDX_SIZE);

	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_P, gDeltaSwingTableIdx_MP_2GCCKA_P_TxPowerTrack_USB_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_N, gDeltaSwingTableIdx_MP_2GCCKA_N_TxPowerTrack_USB_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_P, gDeltaSwingTableIdx_MP_2GCCKB_P_TxPowerTrack_USB_8192E, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_N, gDeltaSwingTableIdx_MP_2GCCKB_N_TxPowerTrack_USB_8192E, DELTA_SWINGIDX_SIZE);

	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GA_P, gDeltaSwingTableIdx_MP_5GA_P_TxPowerTrack_USB_8192E, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GA_N, gDeltaSwingTableIdx_MP_5GA_N_TxPowerTrack_USB_8192E, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GB_P, gDeltaSwingTableIdx_MP_5GB_P_TxPowerTrack_USB_8192E, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GB_N, gDeltaSwingTableIdx_MP_5GB_N_TxPowerTrack_USB_8192E, DELTA_SWINGIDX_SIZE*3);
}

#endif // end of HWIMG_SUPPORT

