/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Driver_DEFS */
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
 *  CoolingLoopModes - 1
 *     CoolingLoopModes.InverterLoopFanMode - 1
 *     CoolingLoopModes.InverterLoopPumpMode - 2
 *     CoolingLoopModes.SpeakerRequest - 3
 *     CoolingLoopModes.MotorLoopFanMode - 4
 *     CoolingLoopModes.MotorLoopPumpMode - 5
 */

/*********
 *  CoolingLoopsData - 2
 *     CoolingLoopsData.InverterLoopFluidTemp - 1
 *     CoolingLoopsData.MotorLoopFluidTemp - 2
 *     CoolingLoopsData.InverterLoopPressure - 3
 *     CoolingLoopsData.MotorLoopPressure - 4
 *     CoolingLoopsData.InverterLoopTempSensorStatus - 5
 *     CoolingLoopsData.MotorLoopTempSensorStatus - 6
 *     CoolingLoopsData.InverterLoopPressureSensorStatus - 7
 *     CoolingLoopsData.MotorLoopPressureSensorStatus - 8
 *     CoolingLoopsData.MC_CoolingLoopsData - 9
 */

/*********
 *  PedalPositions - 3
 *     PedalPositions.BrakePedalPosition0 - 1
 *     PedalPositions.BrakePedalPosition1 - 2
 *     PedalPositions.AcceleratorPedalPosition1 - 3
 *     PedalPositions.AcceleratorPedalPosition0 - 4
 *     PedalPositions.DriveButton - 5
 *     PedalPositions.Bpps0Status - 6
 *     PedalPositions.Bpps1Status - 7
 *     PedalPositions.Apps0Status - 8
 *     PedalPositions.Apps1Status - 9
 *     PedalPositions.BspdFault - 10
 *     PedalPositions.MC_PedalPosition - 11
 */

/*********
 *  TemperatureInfo - 4
 *     TemperatureInfo.LeftFrontMotorTemperature - 1
 *     TemperatureInfo.LeftRearMotorTemperature - 2
 *     TemperatureInfo.RightFrontMotorTemperature - 3
 *     TemperatureInfo.RightRearMotorTemperature - 4
 *     TemperatureInfo.BatteryTemperature - 5
 */

/*********
 *  VehicleInfo - 5
 *     VehicleInfo.MaximumPowerAvailablePercentage - 1
 *     VehicleInfo.SocPercentage - 2
 *     VehicleInfo.VcuErrors - 3
 *     VehicleInfo.VehicleSpeed - 4
 *     VehicleInfo.VehicleStatus - 5
 */
volatile uint8_T CANMMCAN_Driver_RTVE;
volatile boolean_T CANMMCAN_Driver_TRAFFIC;
volatile int32_T CANMMCAN_Driver_MAXMSGPERSTEP;

volatile uint8_T CANMMCAN_Driver_TVAR8;

volatile uint8_T CANMMCAN_Driver_TVAR8_2;

volatile uint32_T CANMMCAN_Driver_TVAR32;

volatile uint8_T CANMMCAN_Driver_TVAR8A[8];

volatile double CANMMCAN_Driver_TVARD;
volatile double CANMMCAN_Driver_TVARD2;

/* Globale Enable */
volatile boolean_T CANMMCAN_Driver_GEIN;
#define CANMMCAN_Driver_GE CANMMCAN_Driver_GEIN

/* Reset */
#define CANMMCAN_Driver_RE 1


/* Feedthrough debug variable*/
volatile uint8_T CANMMCAN_Driver_FTD;

/* Globale Enable TX */
volatile boolean_T CANMMCAN_Driver_TXGEIN;
#define CANMMCAN_Driver_TXGE CANMMCAN_Driver_TXGEIN
                               
                               
/* ECU ENABLE */               
volatile boolean_T CANMMCAN_Driver_TXEEIE[1] = {1};     
volatile boolean_T CANMMCAN_Driver_TXEEIEOLD[1] = {1};     
volatile boolean_T CANMMCAN_Driver_TXECUEN_VCU = 1;   
                            
                            

/* Message would be sent */
volatile uint8_T CANMMCAN_Driver_WBS[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Driver_BYKICK[NUM_TX_MSG];

/* Message enable */
volatile boolean_T CANMMCAN_Driver_TXENIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Driver_TXEIN[NUM_TX_MSG];
#define CANMMCAN_Driver_TXEN(X) (CANMMCAN_Driver_TXENIE[X])
#define USE_LOCAL_ENABLE

/* Cyclic triggering */
volatile boolean_T CANMMCAN_Driver_TXCIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Driver_TXCIN[NUM_TX_MSG];
#define CANMMCAN_Driver_TXC(X) (CANMMCAN_Driver_TXCIE[X])

/* Message kickout */
volatile boolean_T CANMMCAN_Driver_TXKIEX[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Driver_TXKIN[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Driver_TXKIEXC[NUM_TX_MSG];
#define CANMMCAN_Driver_TXKOUT(X) (CANMMCAN_Driver_TXKIEX[X])
#undef MESSAGETIMEOUT


#define ID_Table_RX(X) (int)(CANMMCAN_Driver_MIDRX[X])
#define ID_Table_TX(X) (int)(CANMMCAN_Driver_MIDTX[X])
uint8_T CANMMCAN_Driver_MIDTXSW[NUM_RX_MSG];
uint32_T CANMMCAN_Driver_MIDTXIN[NUM_RX_MSG];
uint32_T CANMMCAN_Driver_MIDTXS[NUM_RX_MSG];
uint32_T CANMMCAN_Driver_MIDRX[NUM_RX_MSG];
uint8_T CANMMCAN_Driver_MIDFRX[NUM_RX_MSG];
uint8_T CANMMCAN_Driver_MIDFTXIN[NUM_RX_MSG];
uint8_T CANMMCAN_Driver_MIDFTXS[NUM_RX_MSG];
uint8_T CANMMCAN_Driver_MIDFTX[NUM_RX_MSG];
uint8_T CANMMCAN_Driver_RXMT[NUM_RX_MSG];
 

volatile real_T CANMMCAN_Driver_RXt[NUM_RX_MSG];
volatile real_T CANMMCAN_Driver_RXdt[NUM_RX_MSG];
volatile boolean_T CANMMCAN_Driver_RXsta[NUM_RX_MSG];
volatile uint8_T CANMMCAN_Driver_RXerr[NUM_RX_MSG];
volatile real_T CANMMCAN_Driver_RXCTMIN[NUM_RX_MSG];
volatile real_T CANMMCAN_Driver_RXCTMAX[NUM_RX_MSG];
volatile uint8_T CANMMCAN_Driver_RXLEN[NUM_RX_MSG];
volatile uint32_T CANMMCAN_Driver_RXCNT[NUM_RX_MSG];
uint32_T CANMMCAN_Driver_MIDTX[NUM_TX_MSG];
volatile real_T CANMMCAN_Driver_TXCT[NUM_TX_MSG];
volatile real_T CANMMCAN_Driver_TXDT[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Driver_TXcraw[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Driver_TXsta[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Driver_TXRBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Driver_TXRXBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Driver_TXusrm[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Driver_TXLEN[NUM_TX_MSG];



/* Define RX/TX structure */

UInt8 CANMMCAN_Driver_RX_Msg_1_Sgn_1;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_1;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_1_constant;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_1_DynValue;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_1_error;
UInt8 CANMMCAN_Driver_RX_Msg_1_Sgn_2;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_2;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_2_constant;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_2_DynValue;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_2_error;
UInt8 CANMMCAN_Driver_RX_Msg_1_Sgn_3;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_3;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_3_constant;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_3_DynValue;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_3_error;
UInt8 CANMMCAN_Driver_RX_Msg_1_Sgn_4;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_4;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_4_constant;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_4_DynValue;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_4_error;
UInt8 CANMMCAN_Driver_RX_Msg_1_Sgn_5;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_5;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_5_constant;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_5_DynValue;
UInt8 CANMMCAN_Driver_TX_Msg_1_Sgn_5_error;
volatile real_T CANMMCAN_Driver_RXCT2;
Int16 CANMMCAN_Driver_RX_Msg_2_Sgn_1;
Int16 CANMMCAN_Driver_RX_Msg_2_Sgn_2;
UInt8 CANMMCAN_Driver_RX_Msg_2_Sgn_3;
UInt8 CANMMCAN_Driver_RX_Msg_2_Sgn_4;
UInt8 CANMMCAN_Driver_RX_Msg_2_Sgn_5;
UInt8 CANMMCAN_Driver_RX_Msg_2_Sgn_6;
UInt8 CANMMCAN_Driver_RX_Msg_2_Sgn_7;
UInt8 CANMMCAN_Driver_RX_Msg_2_Sgn_8;
UInt8 CANMMCAN_Driver_RX_Msg_2_Sgn_9;
volatile real_T CANMMCAN_Driver_RXCT3;
UInt8 CANMMCAN_Driver_RX_Msg_3_Sgn_1;
UInt8 CANMMCAN_Driver_RX_Msg_3_Sgn_2;
UInt8 CANMMCAN_Driver_RX_Msg_3_Sgn_3;
UInt8 CANMMCAN_Driver_RX_Msg_3_Sgn_4;
UInt8 CANMMCAN_Driver_RX_Msg_3_Sgn_5;
UInt8 CANMMCAN_Driver_RX_Msg_3_Sgn_6;
UInt8 CANMMCAN_Driver_RX_Msg_3_Sgn_7;
UInt8 CANMMCAN_Driver_RX_Msg_3_Sgn_8;
UInt8 CANMMCAN_Driver_RX_Msg_3_Sgn_9;
UInt8 CANMMCAN_Driver_RX_Msg_3_Sgn_10;
UInt8 CANMMCAN_Driver_RX_Msg_3_Sgn_11;
Int16 CANMMCAN_Driver_RX_Msg_4_Sgn_1;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_1;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_1_constant;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_1_DynValue;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_1_error;
Int16 CANMMCAN_Driver_RX_Msg_4_Sgn_2;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_2;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_2_constant;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_2_DynValue;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_2_error;
Int16 CANMMCAN_Driver_RX_Msg_4_Sgn_3;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_3;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_3_constant;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_3_DynValue;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_3_error;
Int16 CANMMCAN_Driver_RX_Msg_4_Sgn_4;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_4;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_4_constant;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_4_DynValue;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_4_error;
Int16 CANMMCAN_Driver_RX_Msg_4_Sgn_5;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_5;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_5_constant;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_5_DynValue;
Int16 CANMMCAN_Driver_TX_Msg_4_Sgn_5_error;
UInt8 CANMMCAN_Driver_RX_Msg_5_Sgn_1;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_1;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_1_constant;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_1_DynValue;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_1_error;
UInt8 CANMMCAN_Driver_RX_Msg_5_Sgn_2;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_2;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_2_constant;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_2_DynValue;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_2_error;
UInt8 CANMMCAN_Driver_RX_Msg_5_Sgn_3;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_3;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_3_constant;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_3_DynValue;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_3_error;
UInt8 CANMMCAN_Driver_RX_Msg_5_Sgn_4;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_4;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_4_constant;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_4_DynValue;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_4_error;
UInt8 CANMMCAN_Driver_RX_Msg_5_Sgn_5;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_5;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_5_constant;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_5_DynValue;
UInt8 CANMMCAN_Driver_TX_Msg_5_Sgn_5_error;






volatile uint8_T CANMMCAN_Driver_TXs[15];
volatile uint8_T CANMMCAN_Driver_TXm[15];
volatile uint8_T CANMMCAN_Driver_TXGWs[15];
volatile uint32_T CANMMCAN_Driver_TXcdo[15];
