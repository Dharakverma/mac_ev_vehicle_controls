/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Ams_DEFS */
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
 *  ELP_ContactorRequest - 1
 *     ELP_ContactorRequest.ELP_Contactor - 1
 */

/*********
 *  ELP_CurrentInfo - 2
 *     ELP_CurrentInfo.ELP_DischargeCurrentMax_A - 1
 *     ELP_CurrentInfo.ELP_ChargeCurrentMax_A - 2
 *     ELP_CurrentInfo.ELP_PackCurrent_A - 3
 */

/*********
 *  ELP_SOCInfo - 3
 *     ELP_SOCInfo.ELP_SOH_pc - 1
 *     ELP_SOCInfo.ELP_SOC2_pc - 2
 *     ELP_SOCInfo.ELP_Capacity_Ah - 3
 *     ELP_SOCInfo.ELP_DOD_Ah - 4
 *     ELP_SOCInfo.ELP_SOC_pc - 5
 */

/*********
 *  ELP_StateInfo - 4
 *     ELP_StateInfo.ELP_WarningFlags - 1
 *     ELP_StateInfo.ELP_LevelFaultFlags - 2
 *     ELP_StateInfo.ELP_FltCodeStored_uint8 - 3
 *     ELP_StateInfo.ELP_Flags_uint8 - 4
 *     ELP_StateInfo.ELP_CountdownTm_s - 5
 *     ELP_StateInfo.ELP_BmsFault - 6
 *     ELP_StateInfo.ELP_ContactorK1 - 7
 *     ELP_StateInfo.ELP_ContactorK2 - 8
 *     ELP_StateInfo.ELP_ContactorK3 - 9
 *     ELP_StateInfo.ELP_RelayFault - 10
 */

/*********
 *  ELP_TemperatureInfo - 5
 *     ELP_TemperatureInfo.ELP_CellIdTempMax_num - 1
 *     ELP_TemperatureInfo.ELP_SensorTempMax_degC - 2
 *     ELP_TemperatureInfo.ELP_CellIdMinTemp_num - 3
 *     ELP_TemperatureInfo.ELP_SensorTempMin_degC - 4
 *     ELP_TemperatureInfo.ELP_PackAvgTemp_degC - 5
 */

/*********
 *  ELP_VoltageInfo - 6
 *     ELP_VoltageInfo.ELP_CellIdVoltageMax_num - 1
 *     ELP_VoltageInfo.ELP_CellVoltageMax_V - 2
 *     ELP_VoltageInfo.ELP_CellIdVoltageMin_num - 3
 *     ELP_VoltageInfo.ELP_CellVoltageMin_V - 4
 *     ELP_VoltageInfo.ELP_PackVoltage_V - 5
 */
volatile uint8_T CANMMCAN_Ams_RTVE;
volatile boolean_T CANMMCAN_Ams_TRAFFIC;
volatile int32_T CANMMCAN_Ams_MAXMSGPERSTEP;

volatile uint8_T CANMMCAN_Ams_TVAR8;

volatile uint8_T CANMMCAN_Ams_TVAR8_2;

volatile uint32_T CANMMCAN_Ams_TVAR32;

volatile uint8_T CANMMCAN_Ams_TVAR8A[8];

volatile double CANMMCAN_Ams_TVARD;
volatile double CANMMCAN_Ams_TVARD2;

/* Globale Enable */
volatile boolean_T CANMMCAN_Ams_GEIN;
#define CANMMCAN_Ams_GE CANMMCAN_Ams_GEIN

/* Reset */
#define CANMMCAN_Ams_RE 1


/* Feedthrough debug variable*/
volatile uint8_T CANMMCAN_Ams_FTD;

/* Globale Enable TX */
volatile boolean_T CANMMCAN_Ams_TXGEIN;
#define CANMMCAN_Ams_TXGE CANMMCAN_Ams_TXGEIN
                               
                               
/* ECU ENABLE */               
volatile boolean_T CANMMCAN_Ams_TXEEIE[1] = {1};     
volatile boolean_T CANMMCAN_Ams_TXEEIEOLD[1] = {1};     
volatile boolean_T CANMMCAN_Ams_TXECUEN_VCU_03 = 1;   
                            
                            

/* Message would be sent */
volatile uint8_T CANMMCAN_Ams_WBS[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Ams_BYKICK[NUM_TX_MSG];

/* Message enable */
volatile boolean_T CANMMCAN_Ams_TXENIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Ams_TXEIN[NUM_TX_MSG];
#define CANMMCAN_Ams_TXEN(X) (CANMMCAN_Ams_TXENIE[X])
#define USE_LOCAL_ENABLE

/* Cyclic triggering */
volatile boolean_T CANMMCAN_Ams_TXCIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Ams_TXCIN[NUM_TX_MSG];
#define CANMMCAN_Ams_TXC(X) (CANMMCAN_Ams_TXCIE[X])

/* Message kickout */
volatile boolean_T CANMMCAN_Ams_TXKIEX[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Ams_TXKIN[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Ams_TXKIEXC[NUM_TX_MSG];
#define CANMMCAN_Ams_TXKOUT(X) (CANMMCAN_Ams_TXKIEX[X])
#undef MESSAGETIMEOUT


#define ID_Table_RX(X) (int)(CANMMCAN_Ams_MIDRX[X])
#define ID_Table_TX(X) (int)(CANMMCAN_Ams_MIDTX[X])
uint8_T CANMMCAN_Ams_MIDTXSW[NUM_RX_MSG];
uint32_T CANMMCAN_Ams_MIDTXIN[NUM_RX_MSG];
uint32_T CANMMCAN_Ams_MIDTXS[NUM_RX_MSG];
uint32_T CANMMCAN_Ams_MIDRX[NUM_RX_MSG];
uint8_T CANMMCAN_Ams_MIDFRX[NUM_RX_MSG];
uint8_T CANMMCAN_Ams_MIDFTXIN[NUM_RX_MSG];
uint8_T CANMMCAN_Ams_MIDFTXS[NUM_RX_MSG];
uint8_T CANMMCAN_Ams_MIDFTX[NUM_RX_MSG];
uint8_T CANMMCAN_Ams_RXMT[NUM_RX_MSG];
 

volatile real_T CANMMCAN_Ams_RXt[NUM_RX_MSG];
volatile real_T CANMMCAN_Ams_RXdt[NUM_RX_MSG];
volatile boolean_T CANMMCAN_Ams_RXsta[NUM_RX_MSG];
volatile uint8_T CANMMCAN_Ams_RXerr[NUM_RX_MSG];
volatile real_T CANMMCAN_Ams_RXCTMIN[NUM_RX_MSG];
volatile real_T CANMMCAN_Ams_RXCTMAX[NUM_RX_MSG];
volatile uint8_T CANMMCAN_Ams_RXLEN[NUM_RX_MSG];
volatile uint32_T CANMMCAN_Ams_RXCNT[NUM_RX_MSG];
uint32_T CANMMCAN_Ams_MIDTX[NUM_TX_MSG];
volatile real_T CANMMCAN_Ams_TXCT[NUM_TX_MSG];
volatile real_T CANMMCAN_Ams_TXDT[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Ams_TXcraw[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Ams_TXsta[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Ams_TXRBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Ams_TXRXBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Ams_TXusrm[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Ams_TXLEN[NUM_TX_MSG];



/* Define RX/TX structure */

UInt8 CANMMCAN_Ams_RX_Msg_1_Sgn_1;
UInt8 CANMMCAN_Ams_TX_Msg_1_Sgn_1;
UInt8 CANMMCAN_Ams_TX_Msg_1_Sgn_1_constant;
UInt8 CANMMCAN_Ams_TX_Msg_1_Sgn_1_DynValue;
UInt8 CANMMCAN_Ams_TX_Msg_1_Sgn_1_error;
volatile real_T CANMMCAN_Ams_RXCT2;
UInt16 CANMMCAN_Ams_RX_Msg_2_Sgn_1;
UInt16 CANMMCAN_Ams_RX_Msg_2_Sgn_2;
Int16 CANMMCAN_Ams_RX_Msg_2_Sgn_3;
volatile real_T CANMMCAN_Ams_RXCT3;
Int8 CANMMCAN_Ams_RX_Msg_3_Sgn_1;
Int8 CANMMCAN_Ams_RX_Msg_3_Sgn_2;
UInt16 CANMMCAN_Ams_RX_Msg_3_Sgn_3;
UInt16 CANMMCAN_Ams_RX_Msg_3_Sgn_4;
UInt8 CANMMCAN_Ams_RX_Msg_3_Sgn_5;
volatile real_T CANMMCAN_Ams_RXCT4;
UInt8 CANMMCAN_Ams_RX_Msg_4_Sgn_1;
UInt8 CANMMCAN_Ams_RX_Msg_4_Sgn_2;
UInt8 CANMMCAN_Ams_RX_Msg_4_Sgn_3;
UInt8 CANMMCAN_Ams_RX_Msg_4_Sgn_4;
UInt16 CANMMCAN_Ams_RX_Msg_4_Sgn_5;
UInt8 CANMMCAN_Ams_RX_Msg_4_Sgn_6;
UInt8 CANMMCAN_Ams_RX_Msg_4_Sgn_7;
UInt8 CANMMCAN_Ams_RX_Msg_4_Sgn_8;
UInt8 CANMMCAN_Ams_RX_Msg_4_Sgn_9;
UInt8 CANMMCAN_Ams_RX_Msg_4_Sgn_10;
volatile real_T CANMMCAN_Ams_RXCT5;
UInt8 CANMMCAN_Ams_RX_Msg_5_Sgn_1;
Int8 CANMMCAN_Ams_RX_Msg_5_Sgn_2;
UInt8 CANMMCAN_Ams_RX_Msg_5_Sgn_3;
Int8 CANMMCAN_Ams_RX_Msg_5_Sgn_4;
Int8 CANMMCAN_Ams_RX_Msg_5_Sgn_5;
volatile real_T CANMMCAN_Ams_RXCT6;
UInt8 CANMMCAN_Ams_RX_Msg_6_Sgn_1;
double CANMMCAN_Ams_RX_Msg_6_Sgn_2;
UInt8 CANMMCAN_Ams_RX_Msg_6_Sgn_3;
double CANMMCAN_Ams_RX_Msg_6_Sgn_4;
UInt16 CANMMCAN_Ams_RX_Msg_6_Sgn_5;






volatile uint8_T CANMMCAN_Ams_TXs[1];
volatile uint8_T CANMMCAN_Ams_TXm[1];
volatile uint8_T CANMMCAN_Ams_TXGWs[1];
volatile uint32_T CANMMCAN_Ams_TXcdo[1];
