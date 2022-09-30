/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Driver_TX_PORT */
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

/* CoolingLoopModes.InverterLoopFanMode */ 
ssSetInputPortDataType(S, 0, SS_UINT8); 
ssSetInputPortWidth(S, 0, 1);
/* CoolingLoopModes.InverterLoopPumpMode */ 
ssSetInputPortDataType(S, 1, SS_UINT8); 
ssSetInputPortWidth(S, 1, 1);
/* CoolingLoopModes.SpeakerRequest */ 
ssSetInputPortDataType(S, 2, SS_BOOLEAN); 
ssSetInputPortWidth(S, 2, 1);
/* CoolingLoopModes.MotorLoopFanMode */ 
ssSetInputPortDataType(S, 3, SS_UINT8); 
ssSetInputPortWidth(S, 3, 1);
/* CoolingLoopModes.MotorLoopPumpMode */ 
ssSetInputPortDataType(S, 4, SS_UINT8); 
ssSetInputPortWidth(S, 4, 1);
/* TemperatureInfo.LeftFrontMotorTemperature */ 
ssSetInputPortDataType(S, 5, SS_INT16); 
ssSetInputPortWidth(S, 5, 1);
/* TemperatureInfo.LeftRearMotorTemperature */ 
ssSetInputPortDataType(S, 6, SS_INT16); 
ssSetInputPortWidth(S, 6, 1);
/* TemperatureInfo.RightFrontMotorTemperature */ 
ssSetInputPortDataType(S, 7, SS_INT16); 
ssSetInputPortWidth(S, 7, 1);
/* TemperatureInfo.RightRearMotorTemperature */ 
ssSetInputPortDataType(S, 8, SS_INT16); 
ssSetInputPortWidth(S, 8, 1);
/* TemperatureInfo.BatteryTemperature */ 
ssSetInputPortDataType(S, 9, SS_INT16); 
ssSetInputPortWidth(S, 9, 1);
/* VehicleInfo.MaximumPowerAvailablePercentage */ 
ssSetInputPortDataType(S, 10, SS_UINT8); 
ssSetInputPortWidth(S, 10, 1);
/* VehicleInfo.SocPercentage */ 
ssSetInputPortDataType(S, 11, SS_UINT8); 
ssSetInputPortWidth(S, 11, 1);
/* VehicleInfo.VcuErrors */ 
ssSetInputPortDataType(S, 12, SS_UINT8); 
ssSetInputPortWidth(S, 12, 1);
/* VehicleInfo.VehicleSpeed */ 
ssSetInputPortDataType(S, 13, SS_UINT8); 
ssSetInputPortWidth(S, 13, 1);
/* VehicleInfo.VehicleStatus */ 
ssSetInputPortDataType(S, 14, SS_UINT8); 
ssSetInputPortWidth(S, 14, 1);
