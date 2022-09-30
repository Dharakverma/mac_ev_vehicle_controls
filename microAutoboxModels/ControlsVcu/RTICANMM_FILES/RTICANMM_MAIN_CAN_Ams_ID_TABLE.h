/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Ams_ID_TABLE */
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




/* ELP_StateInfo */
((UInt32*) IDPTR_MEM_R)[0] = (UInt32) RTICANMM_MAIN_CAN_Ams_copy_ELP_StateInfo;
CANMMCAN_Ams_MIDTXSW[0] = 0;
CANMMCAN_Ams_RXCNT[0] = 0;
CANMMCAN_Ams_MIDRX[0] = 0x622;
CANMMCAN_Ams_MIDTXS[0] = 0x622;
CANMMCAN_Ams_RXMT[0] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Ams_MIDFRX[0] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Ams_MIDFTXS[0] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Ams_MIDFTX[0] = 0;  /* 0: standard, 1:extended */ 



/* ELP_VoltageInfo */
((UInt32*) IDPTR_MEM_R)[1] = (UInt32) RTICANMM_MAIN_CAN_Ams_copy_ELP_VoltageInfo;
CANMMCAN_Ams_MIDTXSW[1] = 0;
CANMMCAN_Ams_RXCNT[1] = 0;
CANMMCAN_Ams_MIDRX[1] = 0x623;
CANMMCAN_Ams_MIDTXS[1] = 0x623;
CANMMCAN_Ams_RXMT[1] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Ams_MIDFRX[1] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Ams_MIDFTXS[1] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Ams_MIDFTX[1] = 0;  /* 0: standard, 1:extended */ 



/* ELP_CurrentInfo */
((UInt32*) IDPTR_MEM_R)[2] = (UInt32) RTICANMM_MAIN_CAN_Ams_copy_ELP_CurrentInfo;
CANMMCAN_Ams_MIDTXSW[2] = 0;
CANMMCAN_Ams_RXCNT[2] = 0;
CANMMCAN_Ams_MIDRX[2] = 0x624;
CANMMCAN_Ams_MIDTXS[2] = 0x624;
CANMMCAN_Ams_RXMT[2] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Ams_MIDFRX[2] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Ams_MIDFTXS[2] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Ams_MIDFTX[2] = 0;  /* 0: standard, 1:extended */ 



/* ELP_SOCInfo */
((UInt32*) IDPTR_MEM_R)[3] = (UInt32) RTICANMM_MAIN_CAN_Ams_copy_ELP_SOCInfo;
CANMMCAN_Ams_MIDTXSW[3] = 0;
CANMMCAN_Ams_RXCNT[3] = 0;
CANMMCAN_Ams_MIDRX[3] = 0x626;
CANMMCAN_Ams_MIDTXS[3] = 0x626;
CANMMCAN_Ams_RXMT[3] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Ams_MIDFRX[3] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Ams_MIDFTXS[3] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Ams_MIDFTX[3] = 0;  /* 0: standard, 1:extended */ 



/* ELP_TemperatureInfo */
((UInt32*) IDPTR_MEM_R)[4] = (UInt32) RTICANMM_MAIN_CAN_Ams_copy_ELP_TemperatureInfo;
CANMMCAN_Ams_MIDTXSW[4] = 0;
CANMMCAN_Ams_RXCNT[4] = 0;
CANMMCAN_Ams_MIDRX[4] = 0x627;
CANMMCAN_Ams_MIDTXS[4] = 0x627;
CANMMCAN_Ams_RXMT[4] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Ams_MIDFRX[4] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Ams_MIDFTXS[4] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Ams_MIDFTX[4] = 0;  /* 0: standard, 1:extended */ 



/* ELP_ContactorRequest */
((UInt32*) IDPTR_MEM_R)[5] = (UInt32) RTICANMM_MAIN_CAN_Ams_copy_ELP_ContactorRequest;
CANMMCAN_Ams_MIDTXSW[5] = 0;
CANMMCAN_Ams_RXCNT[5] = 0;
CANMMCAN_Ams_MIDRX[5] = 0x632;
CANMMCAN_Ams_MIDTXS[5] = 0x632;
CANMMCAN_Ams_RXMT[5] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Ams_MIDFRX[5] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Ams_MIDFTXS[5] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Ams_MIDFTX[5] = 0;  /* 0: standard, 1:extended */ 
 
 


/* ELP_ContactorRequest */
CANMMCAN_Ams_MIDTX[0] = 5; 
((UInt32*) IDPTR_MEM_T)[0] = (UInt32) RTICANMM_MAIN_CAN_Ams_copy_ELP_ContactorRequest;



