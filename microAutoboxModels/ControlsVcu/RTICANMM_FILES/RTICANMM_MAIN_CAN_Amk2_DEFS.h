/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Amk2_DEFS */
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


/*********
 *  AMK0_ActualValues1 - 1
 *     AMK0_ActualValues1.AMK_bSystemReady - 1
 *     AMK0_ActualValues1.AMK_bError - 2
 *     AMK0_ActualValues1.AMK_bWarn - 3
 *     AMK0_ActualValues1.AMK_bQuitDcOn - 4
 *     AMK0_ActualValues1.AMK_bDcOn - 5
 *     AMK0_ActualValues1.AMK_bQuitInverterOn - 6
 *     AMK0_ActualValues1.AMK_bInverterOn - 7
 *     AMK0_ActualValues1.AMK_bDerating - 8
 *     AMK0_ActualValues1.AMK_ActualVelocity - 9
 *     AMK0_ActualValues1.AMK_TorqueCurrent - 10
 *     AMK0_ActualValues1.AMK_MagnetizingCurrent - 11
 */

/*********
 *  AMK0_ActualValues2 - 2
 *     AMK0_ActualValues2.AMK_TempMotor - 1
 *     AMK0_ActualValues2.AMK_TempInverter - 2
 *     AMK0_ActualValues2.AMK_ErrorInfo - 3
 *     AMK0_ActualValues2.AMK_TempIGBT - 4
 */

/*********
 *  AMK0_SetPoints1 - 3
 *     AMK0_SetPoints1.AMK_bInverterOn - 1
 *     AMK0_SetPoints1.AMK_bDcOn - 2
 *     AMK0_SetPoints1.AMK_bEnable - 3
 *     AMK0_SetPoints1.AMK_bErrorReset - 4
 *     AMK0_SetPoints1.AMK_TargetVelocity - 5
 *     AMK0_SetPoints1.AMK_TorqueLimitPositiv - 6
 *     AMK0_SetPoints1.AMK_TorqueLimitNegativ - 7
 */

/*********
 *  AMK1_ActualValues1 - 4
 *     AMK1_ActualValues1.AMK_bSystemReady - 1
 *     AMK1_ActualValues1.AMK_bError - 2
 *     AMK1_ActualValues1.AMK_bWarn - 3
 *     AMK1_ActualValues1.AMK_bQuitDcOn - 4
 *     AMK1_ActualValues1.AMK_bDcOn - 5
 *     AMK1_ActualValues1.AMK_bQuitInverterOn - 6
 *     AMK1_ActualValues1.AMK_bInverterOn - 7
 *     AMK1_ActualValues1.AMK_bDerating - 8
 *     AMK1_ActualValues1.AMK_ActualVelocity - 9
 *     AMK1_ActualValues1.AMK_TorqueCurrent - 10
 *     AMK1_ActualValues1.AMK_MagnetizingCurrent - 11
 */

/*********
 *  AMK1_ActualValues2 - 5
 *     AMK1_ActualValues2.AMK_TempMotor - 1
 *     AMK1_ActualValues2.AMK_TempInverter - 2
 *     AMK1_ActualValues2.AMK_ErrorInfo - 3
 *     AMK1_ActualValues2.AMK_TempIGBT - 4
 */

/*********
 *  AMK1_SetPoints1 - 6
 *     AMK1_SetPoints1.AMK_bInverterOn - 1
 *     AMK1_SetPoints1.AMK_bDcOn - 2
 *     AMK1_SetPoints1.AMK_bEnable - 3
 *     AMK1_SetPoints1.AMK_bErrorReset - 4
 *     AMK1_SetPoints1.AMK_TargetVelocity - 5
 *     AMK1_SetPoints1.AMK_TorqueLimitPositiv - 6
 *     AMK1_SetPoints1.AMK_TorqueLimitNegativ - 7
 */
volatile uint8_T CANMMCAN_Amk2_RTVE;
volatile boolean_T CANMMCAN_Amk2_TRAFFIC;
volatile int32_T CANMMCAN_Amk2_MAXMSGPERSTEP;

volatile uint8_T CANMMCAN_Amk2_TVAR8;

volatile uint8_T CANMMCAN_Amk2_TVAR8_2;

volatile uint32_T CANMMCAN_Amk2_TVAR32;

volatile uint8_T CANMMCAN_Amk2_TVAR8A[8];

volatile double CANMMCAN_Amk2_TVARD;
volatile double CANMMCAN_Amk2_TVARD2;

/* Globale Enable */
volatile boolean_T CANMMCAN_Amk2_GEIN;
#define CANMMCAN_Amk2_GE CANMMCAN_Amk2_GEIN

/* Reset */
#define CANMMCAN_Amk2_RE 1


/* Feedthrough debug variable*/
volatile uint8_T CANMMCAN_Amk2_FTD;

/* Globale Enable TX */
volatile boolean_T CANMMCAN_Amk2_TXGEIN;
#define CANMMCAN_Amk2_TXGE CANMMCAN_Amk2_TXGEIN
                               
                               
/* ECU ENABLE */               
volatile boolean_T CANMMCAN_Amk2_TXEEIE[1] = {1};     
volatile boolean_T CANMMCAN_Amk2_TXEEIEOLD[1] = {1};     
volatile boolean_T CANMMCAN_Amk2_TXECUEN_VCU_02 = 1;   
                            
                            

/* Message would be sent */
volatile uint8_T CANMMCAN_Amk2_WBS[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Amk2_BYKICK[NUM_TX_MSG];

/* Message enable */
volatile boolean_T CANMMCAN_Amk2_TXENIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Amk2_TXEIN[NUM_TX_MSG];
#define CANMMCAN_Amk2_TXEN(X) (CANMMCAN_Amk2_TXENIE[X])
#define USE_LOCAL_ENABLE

/* Cyclic triggering */
volatile boolean_T CANMMCAN_Amk2_TXCIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Amk2_TXCIN[NUM_TX_MSG];
#define CANMMCAN_Amk2_TXC(X) (CANMMCAN_Amk2_TXCIE[X])

/* Message kickout */
volatile boolean_T CANMMCAN_Amk2_TXKIEX[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Amk2_TXKIN[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Amk2_TXKIEXC[NUM_TX_MSG];
#define CANMMCAN_Amk2_TXKOUT(X) (CANMMCAN_Amk2_TXKIEX[X])
#undef MESSAGETIMEOUT


#define ID_Table_RX(X) (int)(CANMMCAN_Amk2_MIDRX[X])
#define ID_Table_TX(X) (int)(CANMMCAN_Amk2_MIDTX[X])
uint8_T CANMMCAN_Amk2_MIDTXSW[NUM_RX_MSG];
uint32_T CANMMCAN_Amk2_MIDTXIN[NUM_RX_MSG];
uint32_T CANMMCAN_Amk2_MIDTXS[NUM_RX_MSG];
uint32_T CANMMCAN_Amk2_MIDRX[NUM_RX_MSG];
uint8_T CANMMCAN_Amk2_MIDFRX[NUM_RX_MSG];
uint8_T CANMMCAN_Amk2_MIDFTXIN[NUM_RX_MSG];
uint8_T CANMMCAN_Amk2_MIDFTXS[NUM_RX_MSG];
uint8_T CANMMCAN_Amk2_MIDFTX[NUM_RX_MSG];
uint8_T CANMMCAN_Amk2_RXMT[NUM_RX_MSG];
 

volatile real_T CANMMCAN_Amk2_RXt[NUM_RX_MSG];
volatile real_T CANMMCAN_Amk2_RXdt[NUM_RX_MSG];
volatile boolean_T CANMMCAN_Amk2_RXsta[NUM_RX_MSG];
volatile uint8_T CANMMCAN_Amk2_RXerr[NUM_RX_MSG];
volatile real_T CANMMCAN_Amk2_RXCTMIN[NUM_RX_MSG];
volatile real_T CANMMCAN_Amk2_RXCTMAX[NUM_RX_MSG];
volatile uint8_T CANMMCAN_Amk2_RXLEN[NUM_RX_MSG];
volatile uint32_T CANMMCAN_Amk2_RXCNT[NUM_RX_MSG];
uint32_T CANMMCAN_Amk2_MIDTX[NUM_TX_MSG];
volatile real_T CANMMCAN_Amk2_TXCT[NUM_TX_MSG];
volatile real_T CANMMCAN_Amk2_TXDT[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Amk2_TXcraw[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Amk2_TXsta[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Amk2_TXRBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Amk2_TXRXBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Amk2_TXusrm[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Amk2_TXLEN[NUM_TX_MSG];



/* Define RX/TX structure */

volatile real_T CANMMCAN_Amk2_RXCT1;
UInt8 CANMMCAN_Amk2_RX_Msg_1_Sgn_1;
UInt8 CANMMCAN_Amk2_RX_Msg_1_Sgn_2;
UInt8 CANMMCAN_Amk2_RX_Msg_1_Sgn_3;
UInt8 CANMMCAN_Amk2_RX_Msg_1_Sgn_4;
UInt8 CANMMCAN_Amk2_RX_Msg_1_Sgn_5;
UInt8 CANMMCAN_Amk2_RX_Msg_1_Sgn_6;
UInt8 CANMMCAN_Amk2_RX_Msg_1_Sgn_7;
UInt8 CANMMCAN_Amk2_RX_Msg_1_Sgn_8;
Int16 CANMMCAN_Amk2_RX_Msg_1_Sgn_9;
Int16 CANMMCAN_Amk2_RX_Msg_1_Sgn_10;
Int16 CANMMCAN_Amk2_RX_Msg_1_Sgn_11;
volatile real_T CANMMCAN_Amk2_RXCT2;
double CANMMCAN_Amk2_RX_Msg_2_Sgn_1;
double CANMMCAN_Amk2_RX_Msg_2_Sgn_2;
double CANMMCAN_Amk2_RX_Msg_2_Sgn_3;
double CANMMCAN_Amk2_RX_Msg_2_Sgn_4;
UInt8 CANMMCAN_Amk2_RX_Msg_3_Sgn_1;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_1;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_1_constant;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_1_DynValue;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_1_error;
UInt8 CANMMCAN_Amk2_RX_Msg_3_Sgn_2;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_2;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_2_constant;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_2_DynValue;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_2_error;
UInt8 CANMMCAN_Amk2_RX_Msg_3_Sgn_3;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_3;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_3_constant;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_3_DynValue;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_3_error;
UInt8 CANMMCAN_Amk2_RX_Msg_3_Sgn_4;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_4;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_4_constant;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_4_DynValue;
UInt8 CANMMCAN_Amk2_TX_Msg_3_Sgn_4_error;
Int16 CANMMCAN_Amk2_RX_Msg_3_Sgn_5;
Int16 CANMMCAN_Amk2_TX_Msg_3_Sgn_5;
Int16 CANMMCAN_Amk2_TX_Msg_3_Sgn_5_constant;
Int16 CANMMCAN_Amk2_TX_Msg_3_Sgn_5_DynValue;
Int16 CANMMCAN_Amk2_TX_Msg_3_Sgn_5_error;
Int16 CANMMCAN_Amk2_RX_Msg_3_Sgn_6;
Int16 CANMMCAN_Amk2_TX_Msg_3_Sgn_6;
Int16 CANMMCAN_Amk2_TX_Msg_3_Sgn_6_constant;
Int16 CANMMCAN_Amk2_TX_Msg_3_Sgn_6_DynValue;
Int16 CANMMCAN_Amk2_TX_Msg_3_Sgn_6_error;
Int16 CANMMCAN_Amk2_RX_Msg_3_Sgn_7;
Int16 CANMMCAN_Amk2_TX_Msg_3_Sgn_7;
Int16 CANMMCAN_Amk2_TX_Msg_3_Sgn_7_constant;
Int16 CANMMCAN_Amk2_TX_Msg_3_Sgn_7_DynValue;
Int16 CANMMCAN_Amk2_TX_Msg_3_Sgn_7_error;
volatile real_T CANMMCAN_Amk2_RXCT4;
UInt8 CANMMCAN_Amk2_RX_Msg_4_Sgn_1;
UInt8 CANMMCAN_Amk2_RX_Msg_4_Sgn_2;
UInt8 CANMMCAN_Amk2_RX_Msg_4_Sgn_3;
UInt8 CANMMCAN_Amk2_RX_Msg_4_Sgn_4;
UInt8 CANMMCAN_Amk2_RX_Msg_4_Sgn_5;
UInt8 CANMMCAN_Amk2_RX_Msg_4_Sgn_6;
UInt8 CANMMCAN_Amk2_RX_Msg_4_Sgn_7;
UInt8 CANMMCAN_Amk2_RX_Msg_4_Sgn_8;
Int16 CANMMCAN_Amk2_RX_Msg_4_Sgn_9;
Int16 CANMMCAN_Amk2_RX_Msg_4_Sgn_10;
Int16 CANMMCAN_Amk2_RX_Msg_4_Sgn_11;
volatile real_T CANMMCAN_Amk2_RXCT5;
double CANMMCAN_Amk2_RX_Msg_5_Sgn_1;
double CANMMCAN_Amk2_RX_Msg_5_Sgn_2;
UInt16 CANMMCAN_Amk2_RX_Msg_5_Sgn_3;
double CANMMCAN_Amk2_RX_Msg_5_Sgn_4;
UInt8 CANMMCAN_Amk2_RX_Msg_6_Sgn_1;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_1;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_1_constant;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_1_DynValue;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_1_error;
UInt8 CANMMCAN_Amk2_RX_Msg_6_Sgn_2;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_2;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_2_constant;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_2_DynValue;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_2_error;
UInt8 CANMMCAN_Amk2_RX_Msg_6_Sgn_3;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_3;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_3_constant;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_3_DynValue;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_3_error;
UInt8 CANMMCAN_Amk2_RX_Msg_6_Sgn_4;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_4;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_4_constant;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_4_DynValue;
UInt8 CANMMCAN_Amk2_TX_Msg_6_Sgn_4_error;
Int16 CANMMCAN_Amk2_RX_Msg_6_Sgn_5;
Int16 CANMMCAN_Amk2_TX_Msg_6_Sgn_5;
Int16 CANMMCAN_Amk2_TX_Msg_6_Sgn_5_constant;
Int16 CANMMCAN_Amk2_TX_Msg_6_Sgn_5_DynValue;
Int16 CANMMCAN_Amk2_TX_Msg_6_Sgn_5_error;
Int16 CANMMCAN_Amk2_RX_Msg_6_Sgn_6;
Int16 CANMMCAN_Amk2_TX_Msg_6_Sgn_6;
Int16 CANMMCAN_Amk2_TX_Msg_6_Sgn_6_constant;
Int16 CANMMCAN_Amk2_TX_Msg_6_Sgn_6_DynValue;
Int16 CANMMCAN_Amk2_TX_Msg_6_Sgn_6_error;
Int16 CANMMCAN_Amk2_RX_Msg_6_Sgn_7;
Int16 CANMMCAN_Amk2_TX_Msg_6_Sgn_7;
Int16 CANMMCAN_Amk2_TX_Msg_6_Sgn_7_constant;
Int16 CANMMCAN_Amk2_TX_Msg_6_Sgn_7_DynValue;
Int16 CANMMCAN_Amk2_TX_Msg_6_Sgn_7_error;






volatile uint8_T CANMMCAN_Amk2_TXs[14];
volatile uint8_T CANMMCAN_Amk2_TXm[14];
volatile uint8_T CANMMCAN_Amk2_TXGWs[14];
volatile uint32_T CANMMCAN_Amk2_TXcdo[14];
