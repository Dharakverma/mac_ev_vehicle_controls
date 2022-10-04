/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Ams_MSG_DATA */
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

/* Global variables used for signal decoding */                               
#if defined(_DS1006) | defined(_DS1007) | defined(_DS2510) | defined(_DS1202) 
static volatile ULong64 ulong64Temp  = 0;                                     
static volatile Long64  long64Temp   = 0;                                     
static volatile Int32   signedTemp   = 0;                                     
static volatile UInt32  unsignedTemp = 0;                                     
static volatile Float32 floatTemp    = 0.0;                                   
static volatile double  doubleTemp   = 0.0;                                   
#else                                                                         
static ULong64 ulong64Temp  = 0;                                              
static Long64  long64Temp   = 0;                                              
static Int32   signedTemp   = 0;                                              
static UInt32  unsignedTemp = 0;                                              
static Float32 floatTemp    = 0.0;                                            
static double  doubleTemp   = 0.0;                                            
#endif                                                                        

static uint8_T canFdLen[7] = {12, 16, 20, 24, 32, 48, 64};                    


void RTICANMM_MAIN_CAN_Ams_copy_ELP_ContactorRequest(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Ams_copy_ELP_CurrentInfo(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Ams_copy_ELP_SOCInfo(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Ams_copy_ELP_StateInfo(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Ams_copy_ELP_TemperatureInfo(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Ams_copy_ELP_VoltageInfo(MainSetupMsgData* data, int direction, SimStruct *S);
                                           
/* Message for custom code manipulations */         
static RTICANMMMsgStruct custCodeMsg;               
                                                    
static void custCodeMsg2Data(RTICANMMMsgStruct *msg, MainSetupMsgData *data) {         
  int i = 0;                                        
  int rawBytes = 0;                                 
  data->CANMsg.Format  = (CanMM_Msg_Format) msg->idformat;
  data->CANMsg.Id      = msg->identifier;           
  data->CANMsg.Dlc     = msg->len;                  
  switch(data->CANMsg.Format) {                     
      case CANMM_MSG_FORMAT_FD_STD_SLOW:            
      case CANMM_MSG_FORMAT_FD_EXT_SLOW:            
      case CANMM_MSG_FORMAT_FD_STD_FAST:            
      case CANMM_MSG_FORMAT_FD_EXT_FAST:            
          rawBytes = (msg->len<8 ? 8 : msg->len);   
          break;                                    
      default:                                      
          rawBytes = 8;                             
          break;                                    
  }                                                 
  for (i=0; i<rawBytes && i<64; i++) {              
      data->pData[i] = msg->RAW_DATA[i];            
  }                                                 
  data->CANMsg.HwTime      = msg->HwTime;           
  data->DelayTime   = msg->DelayTime;               
  data->CycleTime   = msg->CycleTime;               
  data->Status      = msg->status;                  
  data->TXCounter   = msg->TX_counter;              
  data->RXCounter   = msg->RX_counter;              
}                                                   
                                                    
                                                    
/* CustomCode requires all data (TX path) */        
static void data2CustCodeMsg(MainSetupMsgData *data, RTICANMMMsgStruct *msg) {        
  int i = 0;                                        
  int rawBytes = 0;                                 
  msg->idformat    = (int)data->CANMsg.Format;      
  msg->identifier  = data->CANMsg.Id;               
  msg->HwTime      = data->CANMsg.HwTime;           
  msg->DelayTime   = data->DelayTime;               
  msg->CycleTime   = data->CycleTime;               
  msg->status      = data->Status;                  
  msg->TX_counter  = data->TXCounter;               
  msg->RX_counter  = data->RXCounter;               
                                                    
  msg->deltatime   = data->DeltaTime;               
  msg->time        = data->CANMsg.TimeStamp;        
                                                    
  msg->len         = data->CANMsg.Dlc;              
  switch(data->CANMsg.Format) {                     
      case CANMM_MSG_FORMAT_FD_STD_SLOW:            
      case CANMM_MSG_FORMAT_FD_EXT_SLOW:            
      case CANMM_MSG_FORMAT_FD_STD_FAST:            
      case CANMM_MSG_FORMAT_FD_EXT_FAST:            
          rawBytes = (data->CANMsg.Dlc<8 ? 8 : data->CANMsg.Dlc);     
          break;                                    
      default:                                      
          rawBytes = 8;                             
          break;                                    
  }                                                 
  for (i=0; i<rawBytes && i<64; i++) {              
      msg->RAW_DATA[i] = data->pData[i];            
  }                                                 
}                                                   
                                                    
/*----------------------------------------------------------------------------------------------*/
/* ----- ELP_ContactorRequest  -----*/  
void RTICANMM_MAIN_CAN_Ams_copy_ELP_ContactorRequest(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Ams_MIDFRX[5] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Ams_RXLEN[5] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Ams_RXLEN[5];                                   
                                                                                 
if(currentMsgLength >= 1) {
/* ELP_Contactor */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Ams_RX_Msg_1_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

}      
else {  /* TX ========================================================================================== */ 

  /* Init encode structure */                               
    *((UInt32*)(data->pData)) = INT32_TO_BE(0x00000000);        
    *((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);      

/* ELP_Contactor */
CANMMCAN_Ams_TX_Msg_1_Sgn_1 = ((uint8_T*)GetInputPortSignal(S,0))[0];
/* ELP_Contactor */ 
unsignedTemp = (CANMMCAN_Ams_TX_Msg_1_Sgn_1 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                         
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_BE(~(0xFF << 0))) | INT8_TO_BE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_Ams_TXLEN[0], (uint8_T)8, (uint8_T)0);

data->CANMsg.Id = CANMMCAN_Ams_MIDRX[5];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_Ams_MIDFTX[5];  
CANMMCAN_Ams_TXsta[0] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- ELP_CurrentInfo  -----*/  
void RTICANMM_MAIN_CAN_Ams_copy_ELP_CurrentInfo(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Ams_MIDFRX[2] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Ams_RXLEN[2] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Ams_RXLEN[2];                                   
                                                                                 
if(currentMsgLength >= 5) {
/* ELP_DischargeCurrentMax_A */ 
unsignedTemp = INT16_FROM_BE(*(UInt16*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  CANMMCAN_Ams_RX_Msg_2_Sgn_1 = (UInt16)1 * (UInt16)unsignedTemp + (UInt16)(0);                    

}

if(currentMsgLength >= 3) {
/* ELP_ChargeCurrentMax_A */ 
unsignedTemp = INT16_FROM_BE(*(UInt16*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  CANMMCAN_Ams_RX_Msg_2_Sgn_2 = (UInt16)1 * (UInt16)unsignedTemp + (UInt16)(0);                    

}

if(currentMsgLength >= 1) {
/* ELP_PackCurrent_A */ 
unsignedTemp = INT16_FROM_BE(*(UInt16*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Ams_RX_Msg_2_Sgn_3 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

}

((uint16_T*) ssGetOutputPortSignal(S, 0))[0] = CANMMCAN_Ams_RX_Msg_2_Sgn_1;
((uint16_T*) ssGetOutputPortSignal(S, 1))[0] = CANMMCAN_Ams_RX_Msg_2_Sgn_2;
((int16_T*) ssGetOutputPortSignal(S, 2))[0] = CANMMCAN_Ams_RX_Msg_2_Sgn_3;
}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- ELP_SOCInfo  -----*/  
void RTICANMM_MAIN_CAN_Ams_copy_ELP_SOCInfo(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Ams_MIDFRX[3] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Ams_RXLEN[3] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Ams_RXLEN[3];                                   
                                                                                 
if(currentMsgLength >= 7) {
/* ELP_SOH_pc */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (6)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  if (unsignedTemp & 0x80) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFFFF00;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Ams_RX_Msg_3_Sgn_1 = (Int8)1 * (Int8)signedTemp + (Int8)(0);                    

}

if(currentMsgLength >= 6) {
/* ELP_SOC2_pc */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (5)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  if (unsignedTemp & 0x80) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFFFF00;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Ams_RX_Msg_3_Sgn_2 = (Int8)1 * (Int8)signedTemp + (Int8)(0);                    

}

if(currentMsgLength >= 4) {
/* ELP_Capacity_Ah */ 
unsignedTemp = INT16_FROM_BE(*(UInt16*)(data->pData + (3)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  CANMMCAN_Ams_RX_Msg_3_Sgn_3 = (UInt16)1 * (UInt16)unsignedTemp + (UInt16)(0);                    

}

if(currentMsgLength >= 2) {
/* ELP_DOD_Ah */ 
unsignedTemp = INT16_FROM_BE(*(UInt16*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  CANMMCAN_Ams_RX_Msg_3_Sgn_4 = (UInt16)1 * (UInt16)unsignedTemp + (UInt16)(0);                    

}

if(currentMsgLength >= 1) {
/* ELP_SOC_pc */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Ams_RX_Msg_3_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

((int8_T*) ssGetOutputPortSignal(S, 3))[0] = CANMMCAN_Ams_RX_Msg_3_Sgn_1;
((int8_T*) ssGetOutputPortSignal(S, 4))[0] = CANMMCAN_Ams_RX_Msg_3_Sgn_2;
((uint16_T*) ssGetOutputPortSignal(S, 5))[0] = CANMMCAN_Ams_RX_Msg_3_Sgn_3;
((uint16_T*) ssGetOutputPortSignal(S, 6))[0] = CANMMCAN_Ams_RX_Msg_3_Sgn_4;
((uint8_T*) ssGetOutputPortSignal(S, 7))[0] = CANMMCAN_Ams_RX_Msg_3_Sgn_5;
}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- ELP_StateInfo  -----*/  
void RTICANMM_MAIN_CAN_Ams_copy_ELP_StateInfo(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Ams_MIDFRX[0] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Ams_RXLEN[0] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Ams_RXLEN[0];                                   
                                                                                 
if(currentMsgLength >= 7) {
/* ELP_WarningFlags */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (6)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Ams_RX_Msg_4_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 6) {
/* ELP_LevelFaultFlags */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (5)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Ams_RX_Msg_4_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 5) {
/* ELP_FltCodeStored_uint8 */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Ams_RX_Msg_4_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* ELP_Flags_uint8 */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (3)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Ams_RX_Msg_4_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* ELP_CountdownTm_s */ 
unsignedTemp = INT16_FROM_BE(*(UInt16*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  CANMMCAN_Ams_RX_Msg_4_Sgn_5 = (UInt16)1 * (UInt16)unsignedTemp + (UInt16)(0);                    

}

if(currentMsgLength >= 1) {
/* ELP_BmsFault */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Ams_RX_Msg_4_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* ELP_ContactorK1 */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 1;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Ams_RX_Msg_4_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* ELP_ContactorK2 */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 2;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Ams_RX_Msg_4_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* ELP_ContactorK3 */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 3;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Ams_RX_Msg_4_Sgn_9 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* ELP_RelayFault */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 4;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Ams_RX_Msg_4_Sgn_10 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

((uint8_T*) ssGetOutputPortSignal(S, 8))[0] = CANMMCAN_Ams_RX_Msg_4_Sgn_1;
((uint8_T*) ssGetOutputPortSignal(S, 9))[0] = CANMMCAN_Ams_RX_Msg_4_Sgn_2;
((uint8_T*) ssGetOutputPortSignal(S, 10))[0] = CANMMCAN_Ams_RX_Msg_4_Sgn_3;
((uint8_T*) ssGetOutputPortSignal(S, 11))[0] = CANMMCAN_Ams_RX_Msg_4_Sgn_4;
((uint16_T*) ssGetOutputPortSignal(S, 12))[0] = CANMMCAN_Ams_RX_Msg_4_Sgn_5;
((boolean_T*) ssGetOutputPortSignal(S, 13))[0] = CANMMCAN_Ams_RX_Msg_4_Sgn_6;
((boolean_T*) ssGetOutputPortSignal(S, 14))[0] = CANMMCAN_Ams_RX_Msg_4_Sgn_7;
((boolean_T*) ssGetOutputPortSignal(S, 15))[0] = CANMMCAN_Ams_RX_Msg_4_Sgn_8;
((boolean_T*) ssGetOutputPortSignal(S, 16))[0] = CANMMCAN_Ams_RX_Msg_4_Sgn_9;
((boolean_T*) ssGetOutputPortSignal(S, 17))[0] = CANMMCAN_Ams_RX_Msg_4_Sgn_10;
}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- ELP_TemperatureInfo  -----*/  
void RTICANMM_MAIN_CAN_Ams_copy_ELP_TemperatureInfo(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Ams_MIDFRX[4] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Ams_RXLEN[4] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Ams_RXLEN[4];                                   
                                                                                 
if(currentMsgLength >= 6) {
/* ELP_CellIdTempMax_num */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (5)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Ams_RX_Msg_5_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 5) {
/* ELP_SensorTempMax_degC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  if (unsignedTemp & 0x80) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFFFF00;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Ams_RX_Msg_5_Sgn_2 = (Int8)1 * (Int8)signedTemp + (Int8)(0);                    

}

if(currentMsgLength >= 4) {
/* ELP_CellIdMinTemp_num */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (3)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Ams_RX_Msg_5_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 3) {
/* ELP_SensorTempMin_degC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  if (unsignedTemp & 0x80) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFFFF00;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Ams_RX_Msg_5_Sgn_4 = (Int8)1 * (Int8)signedTemp + (Int8)(0);                    

}

if(currentMsgLength >= 1) {
/* ELP_PackAvgTemp_degC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  if (unsignedTemp & 0x80) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFFFF00;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Ams_RX_Msg_5_Sgn_5 = (Int8)1 * (Int8)signedTemp + (Int8)(0);                    

}

((uint8_T*) ssGetOutputPortSignal(S, 18))[0] = CANMMCAN_Ams_RX_Msg_5_Sgn_1;
((int8_T*) ssGetOutputPortSignal(S, 19))[0] = CANMMCAN_Ams_RX_Msg_5_Sgn_2;
((uint8_T*) ssGetOutputPortSignal(S, 20))[0] = CANMMCAN_Ams_RX_Msg_5_Sgn_3;
((int8_T*) ssGetOutputPortSignal(S, 21))[0] = CANMMCAN_Ams_RX_Msg_5_Sgn_4;
((int8_T*) ssGetOutputPortSignal(S, 22))[0] = CANMMCAN_Ams_RX_Msg_5_Sgn_5;
}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- ELP_VoltageInfo  -----*/  
void RTICANMM_MAIN_CAN_Ams_copy_ELP_VoltageInfo(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Ams_MIDFRX[1] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Ams_RXLEN[1] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Ams_RXLEN[1];                                   
                                                                                 
if(currentMsgLength >= 6) {
/* ELP_CellIdVoltageMax_num */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (5)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Ams_RX_Msg_6_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 5) {
/* ELP_CellVoltageMax_V */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Ams_RX_Msg_6_Sgn_2 = (double)0.1 * (double)unsignedTemp + (double)(0);                    

}

if(currentMsgLength >= 4) {
/* ELP_CellIdVoltageMin_num */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (3)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Ams_RX_Msg_6_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 3) {
/* ELP_CellVoltageMin_V */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Ams_RX_Msg_6_Sgn_4 = (double)0.1 * (double)unsignedTemp + (double)(0);                    

}

if(currentMsgLength >= 1) {
/* ELP_PackVoltage_V */ 
unsignedTemp = INT16_FROM_BE(*(UInt16*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  CANMMCAN_Ams_RX_Msg_6_Sgn_5 = (UInt16)1 * (UInt16)unsignedTemp + (UInt16)(0);                    

}

((uint8_T*) ssGetOutputPortSignal(S, 23))[0] = CANMMCAN_Ams_RX_Msg_6_Sgn_1;
((real_T*) ssGetOutputPortSignal(S, 24))[0] = CANMMCAN_Ams_RX_Msg_6_Sgn_2;
((uint8_T*) ssGetOutputPortSignal(S, 25))[0] = CANMMCAN_Ams_RX_Msg_6_Sgn_3;
((real_T*) ssGetOutputPortSignal(S, 26))[0] = CANMMCAN_Ams_RX_Msg_6_Sgn_4;
((uint16_T*) ssGetOutputPortSignal(S, 27))[0] = CANMMCAN_Ams_RX_Msg_6_Sgn_5;
}      
}


