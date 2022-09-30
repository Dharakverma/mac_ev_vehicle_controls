/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Driver_RX_PORT */
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

/* CoolingLoopsData.InverterLoopFluidTemp */ 
ssSetOutputPortDataType(S, 0, SS_INT16); 
ssSetOutputPortWidth(S, 0, 1); 
/* CoolingLoopsData.MotorLoopFluidTemp */ 
ssSetOutputPortDataType(S, 1, SS_INT16); 
ssSetOutputPortWidth(S, 1, 1); 
/* CoolingLoopsData.InverterLoopPressure */ 
ssSetOutputPortDataType(S, 2, SS_UINT8); 
ssSetOutputPortWidth(S, 2, 1); 
/* CoolingLoopsData.MotorLoopPressure */ 
ssSetOutputPortDataType(S, 3, SS_UINT8); 
ssSetOutputPortWidth(S, 3, 1); 
/* CoolingLoopsData.InverterLoopTempSensorStatus */ 
ssSetOutputPortDataType(S, 4, SS_UINT8); 
ssSetOutputPortWidth(S, 4, 1); 
/* CoolingLoopsData.MotorLoopTempSensorStatus */ 
ssSetOutputPortDataType(S, 5, SS_UINT8); 
ssSetOutputPortWidth(S, 5, 1); 
/* CoolingLoopsData.InverterLoopPressureSensorStatus */ 
ssSetOutputPortDataType(S, 6, SS_UINT8); 
ssSetOutputPortWidth(S, 6, 1); 
/* CoolingLoopsData.MotorLoopPressureSensorStatus */ 
ssSetOutputPortDataType(S, 7, SS_UINT8); 
ssSetOutputPortWidth(S, 7, 1); 
/* CoolingLoopsData.MC_CoolingLoopsData */ 
ssSetOutputPortDataType(S, 8, SS_UINT8); 
ssSetOutputPortWidth(S, 8, 1); 
/* PedalPositions.BrakePedalPosition0 */ 
ssSetOutputPortDataType(S, 9, SS_UINT8); 
ssSetOutputPortWidth(S, 9, 1); 
/* PedalPositions.BrakePedalPosition1 */ 
ssSetOutputPortDataType(S, 10, SS_UINT8); 
ssSetOutputPortWidth(S, 10, 1); 
/* PedalPositions.AcceleratorPedalPosition1 */ 
ssSetOutputPortDataType(S, 11, SS_UINT8); 
ssSetOutputPortWidth(S, 11, 1); 
/* PedalPositions.AcceleratorPedalPosition0 */ 
ssSetOutputPortDataType(S, 12, SS_UINT8); 
ssSetOutputPortWidth(S, 12, 1); 
/* PedalPositions.DriveButton */ 
ssSetOutputPortDataType(S, 13, SS_UINT8); 
ssSetOutputPortWidth(S, 13, 1); 
/* PedalPositions.Bpps0Status */ 
ssSetOutputPortDataType(S, 14, SS_UINT8); 
ssSetOutputPortWidth(S, 14, 1); 
/* PedalPositions.Bpps1Status */ 
ssSetOutputPortDataType(S, 15, SS_UINT8); 
ssSetOutputPortWidth(S, 15, 1); 
/* PedalPositions.Apps0Status */ 
ssSetOutputPortDataType(S, 16, SS_UINT8); 
ssSetOutputPortWidth(S, 16, 1); 
/* PedalPositions.Apps1Status */ 
ssSetOutputPortDataType(S, 17, SS_UINT8); 
ssSetOutputPortWidth(S, 17, 1); 
/* PedalPositions.BspdFault */ 
ssSetOutputPortDataType(S, 18, SS_BOOLEAN); 
ssSetOutputPortWidth(S, 18, 1); 
/* PedalPositions.MC_PedalPosition */ 
ssSetOutputPortDataType(S, 19, SS_UINT8); 
ssSetOutputPortWidth(S, 19, 1); 
