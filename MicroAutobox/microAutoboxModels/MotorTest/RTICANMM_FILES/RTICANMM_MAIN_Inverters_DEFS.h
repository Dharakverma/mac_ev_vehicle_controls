/*****************************************************************************************************************************/
/* RTICANMM_MAIN_Inverters_DEFS */
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
volatile uint8_T CANMMInverters_RTVE;
volatile boolean_T CANMMInverters_TRAFFIC;
volatile int32_T CANMMInverters_MAXMSGPERSTEP;

volatile uint8_T CANMMInverters_TVAR8;

volatile uint8_T CANMMInverters_TVAR8_2;

volatile uint32_T CANMMInverters_TVAR32;

volatile uint8_T CANMMInverters_TVAR8A[8];

volatile double CANMMInverters_TVARD;
volatile double CANMMInverters_TVARD2;

/* Globale Enable */
volatile boolean_T CANMMInverters_GEIN;
#define CANMMInverters_GE CANMMInverters_GEIN

/* Reset */
#define CANMMInverters_RE 1


/* Feedthrough debug variable*/
volatile uint8_T CANMMInverters_FTD;

/* Globale Enable TX */
volatile boolean_T CANMMInverters_TXGEIN;
#define CANMMInverters_TXGE CANMMInverters_TXGEIN
                               
                               
/* ECU ENABLE */               
volatile boolean_T CANMMInverters_TXEEIE[1] = {1};     
volatile boolean_T CANMMInverters_TXEEIEOLD[1] = {1};     
volatile boolean_T CANMMInverters_TXECUEN_VCU = 1;   
                            
                            

/* Message would be sent */
volatile uint8_T CANMMInverters_WBS[NUM_TX_MSG];
volatile boolean_T CANMMInverters_BYKICK[NUM_TX_MSG];

/* Message enable */
volatile boolean_T CANMMInverters_TXENIE[NUM_TX_MSG];
volatile boolean_T CANMMInverters_TXEIN[NUM_TX_MSG];
#define CANMMInverters_TXEN(X) (CANMMInverters_TXENIE[X])
#define USE_LOCAL_ENABLE

/* Cyclic triggering */
volatile boolean_T CANMMInverters_TXCIE[NUM_TX_MSG];
volatile boolean_T CANMMInverters_TXCIN[NUM_TX_MSG];
#define CANMMInverters_TXC(X) (CANMMInverters_TXCIE[X])

/* Message kickout */
volatile boolean_T CANMMInverters_TXKIEX[NUM_TX_MSG];
volatile boolean_T CANMMInverters_TXKIN[NUM_TX_MSG];
volatile boolean_T CANMMInverters_TXKIEXC[NUM_TX_MSG];
#define CANMMInverters_TXKOUT(X) (CANMMInverters_TXKIEX[X])
#undef MESSAGETIMEOUT


#define ID_Table_RX(X) (int)(CANMMInverters_MIDRX[X])
#define ID_Table_TX(X) (int)(CANMMInverters_MIDTX[X])
uint8_T CANMMInverters_MIDTXSW[NUM_RX_MSG];
uint32_T CANMMInverters_MIDTXIN[NUM_RX_MSG];
uint32_T CANMMInverters_MIDTXS[NUM_RX_MSG];
uint32_T CANMMInverters_MIDRX[NUM_RX_MSG];
uint8_T CANMMInverters_MIDFRX[NUM_RX_MSG];
uint8_T CANMMInverters_MIDFTXIN[NUM_RX_MSG];
uint8_T CANMMInverters_MIDFTXS[NUM_RX_MSG];
uint8_T CANMMInverters_MIDFTX[NUM_RX_MSG];
uint8_T CANMMInverters_RXMT[NUM_RX_MSG];
 

volatile real_T CANMMInverters_RXt[NUM_RX_MSG];
volatile real_T CANMMInverters_RXdt[NUM_RX_MSG];
volatile boolean_T CANMMInverters_RXsta[NUM_RX_MSG];
volatile uint8_T CANMMInverters_RXerr[NUM_RX_MSG];
volatile real_T CANMMInverters_RXCTMIN[NUM_RX_MSG];
volatile real_T CANMMInverters_RXCTMAX[NUM_RX_MSG];
volatile uint8_T CANMMInverters_RXLEN[NUM_RX_MSG];
volatile uint32_T CANMMInverters_RXCNT[NUM_RX_MSG];
uint32_T CANMMInverters_MIDTX[NUM_TX_MSG];
volatile real_T CANMMInverters_TXCT[NUM_TX_MSG];
volatile real_T CANMMInverters_TXDT[NUM_TX_MSG];
volatile uint8_T CANMMInverters_TXcraw[NUM_TX_MSG];
volatile boolean_T CANMMInverters_TXsta[NUM_TX_MSG];
volatile uint8_T CANMMInverters_TXRBUF[NUM_TX_MSG];
volatile uint8_T CANMMInverters_TXRXBUF[NUM_TX_MSG];
volatile uint8_T CANMMInverters_TXusrm[NUM_TX_MSG];
volatile uint8_T CANMMInverters_TXLEN[NUM_TX_MSG];



/* Define RX/TX structure */

volatile real_T CANMMInverters_RXCT1;
UInt8 CANMMInverters_RX_Msg_1_Sgn_1;
UInt8 CANMMInverters_RX_Msg_1_Sgn_2;
UInt8 CANMMInverters_RX_Msg_1_Sgn_3;
UInt8 CANMMInverters_RX_Msg_1_Sgn_4;
UInt8 CANMMInverters_RX_Msg_1_Sgn_5;
UInt8 CANMMInverters_RX_Msg_1_Sgn_6;
UInt8 CANMMInverters_RX_Msg_1_Sgn_7;
UInt8 CANMMInverters_RX_Msg_1_Sgn_8;
Int16 CANMMInverters_RX_Msg_1_Sgn_9;
Int16 CANMMInverters_RX_Msg_1_Sgn_10;
Int16 CANMMInverters_RX_Msg_1_Sgn_11;
volatile real_T CANMMInverters_RXCT2;
double CANMMInverters_RX_Msg_2_Sgn_1;
double CANMMInverters_RX_Msg_2_Sgn_2;
UInt16 CANMMInverters_RX_Msg_2_Sgn_3;
double CANMMInverters_RX_Msg_2_Sgn_4;
UInt8 CANMMInverters_RX_Msg_3_Sgn_1;
UInt8 CANMMInverters_TX_Msg_3_Sgn_1;
UInt8 CANMMInverters_TX_Msg_3_Sgn_1_constant;
UInt8 CANMMInverters_TX_Msg_3_Sgn_1_DynValue;
UInt8 CANMMInverters_TX_Msg_3_Sgn_1_error;
UInt8 CANMMInverters_RX_Msg_3_Sgn_2;
UInt8 CANMMInverters_TX_Msg_3_Sgn_2;
UInt8 CANMMInverters_TX_Msg_3_Sgn_2_constant;
UInt8 CANMMInverters_TX_Msg_3_Sgn_2_DynValue;
UInt8 CANMMInverters_TX_Msg_3_Sgn_2_error;
UInt8 CANMMInverters_RX_Msg_3_Sgn_3;
UInt8 CANMMInverters_TX_Msg_3_Sgn_3;
UInt8 CANMMInverters_TX_Msg_3_Sgn_3_constant;
UInt8 CANMMInverters_TX_Msg_3_Sgn_3_DynValue;
UInt8 CANMMInverters_TX_Msg_3_Sgn_3_error;
UInt8 CANMMInverters_RX_Msg_3_Sgn_4;
UInt8 CANMMInverters_TX_Msg_3_Sgn_4;
UInt8 CANMMInverters_TX_Msg_3_Sgn_4_constant;
UInt8 CANMMInverters_TX_Msg_3_Sgn_4_DynValue;
UInt8 CANMMInverters_TX_Msg_3_Sgn_4_error;
Int16 CANMMInverters_RX_Msg_3_Sgn_5;
Int16 CANMMInverters_TX_Msg_3_Sgn_5;
Int16 CANMMInverters_TX_Msg_3_Sgn_5_constant;
Int16 CANMMInverters_TX_Msg_3_Sgn_5_DynValue;
Int16 CANMMInverters_TX_Msg_3_Sgn_5_error;
Int16 CANMMInverters_RX_Msg_3_Sgn_6;
Int16 CANMMInverters_TX_Msg_3_Sgn_6;
Int16 CANMMInverters_TX_Msg_3_Sgn_6_constant;
Int16 CANMMInverters_TX_Msg_3_Sgn_6_DynValue;
Int16 CANMMInverters_TX_Msg_3_Sgn_6_error;
Int16 CANMMInverters_RX_Msg_3_Sgn_7;
Int16 CANMMInverters_TX_Msg_3_Sgn_7;
Int16 CANMMInverters_TX_Msg_3_Sgn_7_constant;
Int16 CANMMInverters_TX_Msg_3_Sgn_7_DynValue;
Int16 CANMMInverters_TX_Msg_3_Sgn_7_error;
volatile real_T CANMMInverters_RXCT4;
UInt8 CANMMInverters_RX_Msg_4_Sgn_1;
UInt8 CANMMInverters_RX_Msg_4_Sgn_2;
UInt8 CANMMInverters_RX_Msg_4_Sgn_3;
UInt8 CANMMInverters_RX_Msg_4_Sgn_4;
UInt8 CANMMInverters_RX_Msg_4_Sgn_5;
UInt8 CANMMInverters_RX_Msg_4_Sgn_6;
UInt8 CANMMInverters_RX_Msg_4_Sgn_7;
UInt8 CANMMInverters_RX_Msg_4_Sgn_8;
Int16 CANMMInverters_RX_Msg_4_Sgn_9;
Int16 CANMMInverters_RX_Msg_4_Sgn_10;
Int16 CANMMInverters_RX_Msg_4_Sgn_11;
volatile real_T CANMMInverters_RXCT5;
double CANMMInverters_RX_Msg_5_Sgn_1;
double CANMMInverters_RX_Msg_5_Sgn_2;
UInt16 CANMMInverters_RX_Msg_5_Sgn_3;
double CANMMInverters_RX_Msg_5_Sgn_4;
UInt8 CANMMInverters_RX_Msg_6_Sgn_1;
UInt8 CANMMInverters_TX_Msg_6_Sgn_1;
UInt8 CANMMInverters_TX_Msg_6_Sgn_1_constant;
UInt8 CANMMInverters_TX_Msg_6_Sgn_1_DynValue;
UInt8 CANMMInverters_TX_Msg_6_Sgn_1_error;
UInt8 CANMMInverters_RX_Msg_6_Sgn_2;
UInt8 CANMMInverters_TX_Msg_6_Sgn_2;
UInt8 CANMMInverters_TX_Msg_6_Sgn_2_constant;
UInt8 CANMMInverters_TX_Msg_6_Sgn_2_DynValue;
UInt8 CANMMInverters_TX_Msg_6_Sgn_2_error;
UInt8 CANMMInverters_RX_Msg_6_Sgn_3;
UInt8 CANMMInverters_TX_Msg_6_Sgn_3;
UInt8 CANMMInverters_TX_Msg_6_Sgn_3_constant;
UInt8 CANMMInverters_TX_Msg_6_Sgn_3_DynValue;
UInt8 CANMMInverters_TX_Msg_6_Sgn_3_error;
UInt8 CANMMInverters_RX_Msg_6_Sgn_4;
UInt8 CANMMInverters_TX_Msg_6_Sgn_4;
UInt8 CANMMInverters_TX_Msg_6_Sgn_4_constant;
UInt8 CANMMInverters_TX_Msg_6_Sgn_4_DynValue;
UInt8 CANMMInverters_TX_Msg_6_Sgn_4_error;
Int16 CANMMInverters_RX_Msg_6_Sgn_5;
Int16 CANMMInverters_TX_Msg_6_Sgn_5;
Int16 CANMMInverters_TX_Msg_6_Sgn_5_constant;
Int16 CANMMInverters_TX_Msg_6_Sgn_5_DynValue;
Int16 CANMMInverters_TX_Msg_6_Sgn_5_error;
Int16 CANMMInverters_RX_Msg_6_Sgn_6;
Int16 CANMMInverters_TX_Msg_6_Sgn_6;
Int16 CANMMInverters_TX_Msg_6_Sgn_6_constant;
Int16 CANMMInverters_TX_Msg_6_Sgn_6_DynValue;
Int16 CANMMInverters_TX_Msg_6_Sgn_6_error;
Int16 CANMMInverters_RX_Msg_6_Sgn_7;
Int16 CANMMInverters_TX_Msg_6_Sgn_7;
Int16 CANMMInverters_TX_Msg_6_Sgn_7_constant;
Int16 CANMMInverters_TX_Msg_6_Sgn_7_DynValue;
Int16 CANMMInverters_TX_Msg_6_Sgn_7_error;






volatile uint8_T CANMMInverters_TXs[14];
volatile uint8_T CANMMInverters_TXm[14];
volatile uint8_T CANMMInverters_TXGWs[14];
volatile uint32_T CANMMInverters_TXcdo[14];
