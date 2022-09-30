/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Ams_RX_PORT */
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

/* ELP_CurrentInfo.ELP_DischargeCurrentMax_A */ 
ssSetOutputPortDataType(S, 0, SS_UINT16); 
ssSetOutputPortWidth(S, 0, 1); 
/* ELP_CurrentInfo.ELP_ChargeCurrentMax_A */ 
ssSetOutputPortDataType(S, 1, SS_UINT16); 
ssSetOutputPortWidth(S, 1, 1); 
/* ELP_CurrentInfo.ELP_PackCurrent_A */ 
ssSetOutputPortDataType(S, 2, SS_INT16); 
ssSetOutputPortWidth(S, 2, 1); 
/* ELP_SOCInfo.ELP_SOH_pc */ 
ssSetOutputPortDataType(S, 3, SS_INT8); 
ssSetOutputPortWidth(S, 3, 1); 
/* ELP_SOCInfo.ELP_SOC2_pc */ 
ssSetOutputPortDataType(S, 4, SS_INT8); 
ssSetOutputPortWidth(S, 4, 1); 
/* ELP_SOCInfo.ELP_Capacity_Ah */ 
ssSetOutputPortDataType(S, 5, SS_UINT16); 
ssSetOutputPortWidth(S, 5, 1); 
/* ELP_SOCInfo.ELP_DOD_Ah */ 
ssSetOutputPortDataType(S, 6, SS_UINT16); 
ssSetOutputPortWidth(S, 6, 1); 
/* ELP_SOCInfo.ELP_SOC_pc */ 
ssSetOutputPortDataType(S, 7, SS_UINT8); 
ssSetOutputPortWidth(S, 7, 1); 
/* ELP_StateInfo.ELP_WarningFlags */ 
ssSetOutputPortDataType(S, 8, SS_UINT8); 
ssSetOutputPortWidth(S, 8, 1); 
/* ELP_StateInfo.ELP_LevelFaultFlags */ 
ssSetOutputPortDataType(S, 9, SS_UINT8); 
ssSetOutputPortWidth(S, 9, 1); 
/* ELP_StateInfo.ELP_FltCodeStored_uint8 */ 
ssSetOutputPortDataType(S, 10, SS_UINT8); 
ssSetOutputPortWidth(S, 10, 1); 
/* ELP_StateInfo.ELP_Flags_uint8 */ 
ssSetOutputPortDataType(S, 11, SS_UINT8); 
ssSetOutputPortWidth(S, 11, 1); 
/* ELP_StateInfo.ELP_CountdownTm_s */ 
ssSetOutputPortDataType(S, 12, SS_UINT16); 
ssSetOutputPortWidth(S, 12, 1); 
/* ELP_StateInfo.ELP_BmsFault */ 
ssSetOutputPortDataType(S, 13, SS_BOOLEAN); 
ssSetOutputPortWidth(S, 13, 1); 
/* ELP_StateInfo.ELP_ContactorK1 */ 
ssSetOutputPortDataType(S, 14, SS_BOOLEAN); 
ssSetOutputPortWidth(S, 14, 1); 
/* ELP_StateInfo.ELP_ContactorK2 */ 
ssSetOutputPortDataType(S, 15, SS_BOOLEAN); 
ssSetOutputPortWidth(S, 15, 1); 
/* ELP_StateInfo.ELP_ContactorK3 */ 
ssSetOutputPortDataType(S, 16, SS_BOOLEAN); 
ssSetOutputPortWidth(S, 16, 1); 
/* ELP_StateInfo.ELP_RelayFault */ 
ssSetOutputPortDataType(S, 17, SS_BOOLEAN); 
ssSetOutputPortWidth(S, 17, 1); 
/* ELP_TemperatureInfo.ELP_CellIdTempMax_num */ 
ssSetOutputPortDataType(S, 18, SS_UINT8); 
ssSetOutputPortWidth(S, 18, 1); 
/* ELP_TemperatureInfo.ELP_SensorTempMax_degC */ 
ssSetOutputPortDataType(S, 19, SS_INT8); 
ssSetOutputPortWidth(S, 19, 1); 
/* ELP_TemperatureInfo.ELP_CellIdMinTemp_num */ 
ssSetOutputPortDataType(S, 20, SS_UINT8); 
ssSetOutputPortWidth(S, 20, 1); 
/* ELP_TemperatureInfo.ELP_SensorTempMin_degC */ 
ssSetOutputPortDataType(S, 21, SS_INT8); 
ssSetOutputPortWidth(S, 21, 1); 
/* ELP_TemperatureInfo.ELP_PackAvgTemp_degC */ 
ssSetOutputPortDataType(S, 22, SS_INT8); 
ssSetOutputPortWidth(S, 22, 1); 
/* ELP_VoltageInfo.ELP_CellIdVoltageMax_num */ 
ssSetOutputPortDataType(S, 23, SS_UINT8); 
ssSetOutputPortWidth(S, 23, 1); 
/* ELP_VoltageInfo.ELP_CellVoltageMax_V */ 
ssSetOutputPortDataType(S, 24, SS_DOUBLE); 
ssSetOutputPortWidth(S, 24, 1); 
/* ELP_VoltageInfo.ELP_CellIdVoltageMin_num */ 
ssSetOutputPortDataType(S, 25, SS_UINT8); 
ssSetOutputPortWidth(S, 25, 1); 
/* ELP_VoltageInfo.ELP_CellVoltageMin_V */ 
ssSetOutputPortDataType(S, 26, SS_DOUBLE); 
ssSetOutputPortWidth(S, 26, 1); 
/* ELP_VoltageInfo.ELP_PackVoltage_V */ 
ssSetOutputPortDataType(S, 27, SS_UINT16); 
ssSetOutputPortWidth(S, 27, 1); 
