/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Driver_ID_TABLE */
/*                                                                                                                           */
/*   AUTHOR(S):                                                                                                              */
/*      U. Homann                                                                                                              */
/*      M. Eikermann                                                                                                              */
/*                                                                                                                           */
/*                                                                                                                           */
/*   RTICANMM Date: 07-Apr-2020 08:38:10                                                                                     */
/*   RTICANMM Version: 5.4.737888.359837963                                                                                     */
/*                                                                                                                           */
/*  Copyright 2020, dSPACE GmbH. All rights reserved.                                                                    */
/*      Brand names or product names are trademarks or registered trademarks of their respective companies or organizations. */
/*                                                                                                                           */
/* ***************************************************************************************************************************/




/* PedalPositions */
((UInt32*) IDPTR_MEM_R)[0] = (UInt32) RTICANMM_MAIN_CAN_Driver_copy_PedalPositions;
CANMMCAN_Driver_MIDTXSW[0] = 0;
CANMMCAN_Driver_RXCNT[0] = 0;
CANMMCAN_Driver_MIDRX[0] = 0x101;
CANMMCAN_Driver_MIDTXS[0] = 0x101;
CANMMCAN_Driver_RXMT[0] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Driver_MIDFRX[0] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Driver_MIDFTXS[0] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Driver_MIDFTX[0] = 0;  /* 0: standard, 1:extended */ 



/* CoolingLoopsData */
((UInt32*) IDPTR_MEM_R)[1] = (UInt32) RTICANMM_MAIN_CAN_Driver_copy_CoolingLoopsData;
CANMMCAN_Driver_MIDTXSW[1] = 0;
CANMMCAN_Driver_RXCNT[1] = 0;
CANMMCAN_Driver_MIDRX[1] = 0x201;
CANMMCAN_Driver_MIDTXS[1] = 0x201;
CANMMCAN_Driver_RXMT[1] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Driver_MIDFRX[1] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Driver_MIDFTXS[1] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Driver_MIDFTX[1] = 0;  /* 0: standard, 1:extended */ 



/* CoolingLoopModes */
((UInt32*) IDPTR_MEM_R)[2] = (UInt32) RTICANMM_MAIN_CAN_Driver_copy_CoolingLoopModes;
CANMMCAN_Driver_MIDTXSW[2] = 0;
CANMMCAN_Driver_RXCNT[2] = 0;
CANMMCAN_Driver_MIDRX[2] = 0x202;
CANMMCAN_Driver_MIDTXS[2] = 0x202;
CANMMCAN_Driver_RXMT[2] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Driver_MIDFRX[2] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Driver_MIDFTXS[2] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Driver_MIDFTX[2] = 0;  /* 0: standard, 1:extended */ 



/* TemperatureInfo */
((UInt32*) IDPTR_MEM_R)[3] = (UInt32) RTICANMM_MAIN_CAN_Driver_copy_TemperatureInfo;
CANMMCAN_Driver_MIDTXSW[3] = 0;
CANMMCAN_Driver_RXCNT[3] = 0;
CANMMCAN_Driver_MIDRX[3] = 0x502;
CANMMCAN_Driver_MIDTXS[3] = 0x502;
CANMMCAN_Driver_RXMT[3] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Driver_MIDFRX[3] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Driver_MIDFTXS[3] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Driver_MIDFTX[3] = 0;  /* 0: standard, 1:extended */ 



/* VehicleInfo */
((UInt32*) IDPTR_MEM_R)[4] = (UInt32) RTICANMM_MAIN_CAN_Driver_copy_VehicleInfo;
CANMMCAN_Driver_MIDTXSW[4] = 0;
CANMMCAN_Driver_RXCNT[4] = 0;
CANMMCAN_Driver_MIDRX[4] = 0x503;
CANMMCAN_Driver_MIDTXS[4] = 0x503;
CANMMCAN_Driver_RXMT[4] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Driver_MIDFRX[4] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Driver_MIDFTXS[4] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Driver_MIDFTX[4] = 0;  /* 0: standard, 1:extended */ 
 
 


/* CoolingLoopModes */
CANMMCAN_Driver_MIDTX[0] = 2; 
((UInt32*) IDPTR_MEM_T)[0] = (UInt32) RTICANMM_MAIN_CAN_Driver_copy_CoolingLoopModes;



/* TemperatureInfo */
CANMMCAN_Driver_MIDTX[1] = 3; 
((UInt32*) IDPTR_MEM_T)[1] = (UInt32) RTICANMM_MAIN_CAN_Driver_copy_TemperatureInfo;



/* VehicleInfo */
CANMMCAN_Driver_MIDTX[2] = 4; 
((UInt32*) IDPTR_MEM_T)[2] = (UInt32) RTICANMM_MAIN_CAN_Driver_copy_VehicleInfo;



