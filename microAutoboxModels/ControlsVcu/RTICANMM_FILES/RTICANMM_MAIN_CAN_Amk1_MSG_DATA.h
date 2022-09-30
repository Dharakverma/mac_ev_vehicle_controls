/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Amk1_MSG_DATA */
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


void RTICANMM_MAIN_CAN_Amk1_copy_AMK0_ActualValues1(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Amk1_copy_AMK0_ActualValues2(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Amk1_copy_AMK0_SetPoints1(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Amk1_copy_AMK1_ActualValues1(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Amk1_copy_AMK1_ActualValues2(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Amk1_copy_AMK1_SetPoints1(MainSetupMsgData* data, int direction, SimStruct *S);
                                           
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
/* ----- AMK0_ActualValues1  -----*/  
void RTICANMM_MAIN_CAN_Amk1_copy_AMK0_ActualValues1(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Amk1_MIDFRX[2] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Amk1_RXLEN[2] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Amk1_RXLEN[2];                                   
                                                                                 
if(currentMsgLength >= 2) {
/* AMK_bSystemReady */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_1_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bError */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 1;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_1_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bWarn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 2;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_1_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bQuitDcOn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 3;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_1_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bDcOn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 4;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_1_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bQuitInverterOn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 5;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_1_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bInverterOn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 6;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_1_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bDerating */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 7;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_1_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* AMK_ActualVelocity */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_1_Sgn_9 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

}

if(currentMsgLength >= 6) {
/* AMK_TorqueCurrent */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_1_Sgn_10 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

}

if(currentMsgLength >= 8) {
/* AMK_MagnetizingCurrent */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_1_Sgn_11 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

}

((boolean_T*) ssGetOutputPortSignal(S, 0))[0] = CANMMCAN_Amk1_RX_Msg_1_Sgn_1;
((boolean_T*) ssGetOutputPortSignal(S, 1))[0] = CANMMCAN_Amk1_RX_Msg_1_Sgn_2;
((boolean_T*) ssGetOutputPortSignal(S, 2))[0] = CANMMCAN_Amk1_RX_Msg_1_Sgn_3;
((boolean_T*) ssGetOutputPortSignal(S, 3))[0] = CANMMCAN_Amk1_RX_Msg_1_Sgn_4;
((boolean_T*) ssGetOutputPortSignal(S, 4))[0] = CANMMCAN_Amk1_RX_Msg_1_Sgn_5;
((boolean_T*) ssGetOutputPortSignal(S, 5))[0] = CANMMCAN_Amk1_RX_Msg_1_Sgn_6;
((boolean_T*) ssGetOutputPortSignal(S, 6))[0] = CANMMCAN_Amk1_RX_Msg_1_Sgn_7;
((boolean_T*) ssGetOutputPortSignal(S, 7))[0] = CANMMCAN_Amk1_RX_Msg_1_Sgn_8;
((int16_T*) ssGetOutputPortSignal(S, 8))[0] = CANMMCAN_Amk1_RX_Msg_1_Sgn_9;
((int16_T*) ssGetOutputPortSignal(S, 9))[0] = CANMMCAN_Amk1_RX_Msg_1_Sgn_10;
((int16_T*) ssGetOutputPortSignal(S, 10))[0] = CANMMCAN_Amk1_RX_Msg_1_Sgn_11;
}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- AMK0_ActualValues2  -----*/  
void RTICANMM_MAIN_CAN_Amk1_copy_AMK0_ActualValues2(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Amk1_MIDFRX[4] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Amk1_RXLEN[4] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Amk1_RXLEN[4];                                   
                                                                                 
if(currentMsgLength >= 2) {
/* AMK_TempMotor */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_2_Sgn_1 = (double)0.1 * (double)signedTemp + (double)(0);                    

}

if(currentMsgLength >= 4) {
/* AMK_TempInverter */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_2_Sgn_2 = (double)0.1 * (double)signedTemp + (double)(0);                    

}

if(currentMsgLength >= 6) {
/* AMK_ErrorInfo */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  CANMMCAN_Amk1_RX_Msg_2_Sgn_3 = (UInt16)1 * (UInt16)unsignedTemp + (UInt16)(0);                    

}

if(currentMsgLength >= 8) {
/* AMK_TempIGBT */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_2_Sgn_4 = (double)0.1 * (double)signedTemp + (double)(0);                    

}

((real_T*) ssGetOutputPortSignal(S, 11))[0] = CANMMCAN_Amk1_RX_Msg_2_Sgn_1;
((real_T*) ssGetOutputPortSignal(S, 12))[0] = CANMMCAN_Amk1_RX_Msg_2_Sgn_2;
((uint16_T*) ssGetOutputPortSignal(S, 13))[0] = CANMMCAN_Amk1_RX_Msg_2_Sgn_3;
((real_T*) ssGetOutputPortSignal(S, 14))[0] = CANMMCAN_Amk1_RX_Msg_2_Sgn_4;
}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- AMK0_SetPoints1  -----*/  
void RTICANMM_MAIN_CAN_Amk1_copy_AMK0_SetPoints1(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Amk1_MIDFRX[0] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Amk1_RXLEN[0] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Amk1_RXLEN[0];                                   
                                                                                 
if(currentMsgLength >= 2) {
/* AMK_bInverterOn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_3_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bDcOn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 1;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_3_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bEnable */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 2;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_3_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bErrorReset */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 3;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_3_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* AMK_TargetVelocity */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_3_Sgn_5 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

}

if(currentMsgLength >= 6) {
/* AMK_TorqueLimitPositiv */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_3_Sgn_6 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

}

if(currentMsgLength >= 8) {
/* AMK_TorqueLimitNegativ */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_3_Sgn_7 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

}

}      
else {  /* TX ========================================================================================== */ 

  /* Init encode structure */                               
    *((UInt32*)(data->pData)) = INT32_TO_BE(0x00000000);        
    *((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);      

/* AMK_bInverterOn */
CANMMCAN_Amk1_TX_Msg_3_Sgn_1 = ((boolean_T*)GetInputPortSignal(S,6))[0];

/* AMK_bDcOn */
CANMMCAN_Amk1_TX_Msg_3_Sgn_2 = ((boolean_T*)GetInputPortSignal(S,7))[0];

/* AMK_bEnable */
CANMMCAN_Amk1_TX_Msg_3_Sgn_3 = ((boolean_T*)GetInputPortSignal(S,8))[0];

/* AMK_bErrorReset */
CANMMCAN_Amk1_TX_Msg_3_Sgn_4 = ((boolean_T*)GetInputPortSignal(S,9))[0];

/* AMK_TargetVelocity */
CANMMCAN_Amk1_TX_Msg_3_Sgn_5 = ((int16_T*)GetInputPortSignal(S,10))[0];

/* AMK_TorqueLimitPositiv */
CANMMCAN_Amk1_TX_Msg_3_Sgn_6 = ((int16_T*)GetInputPortSignal(S,11))[0];

/* AMK_TorqueLimitNegativ */
CANMMCAN_Amk1_TX_Msg_3_Sgn_7 = ((int16_T*)GetInputPortSignal(S,12))[0];
/* AMK_bInverterOn */ 
unsignedTemp = (CANMMCAN_Amk1_TX_Msg_3_Sgn_1 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 0;                         
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x1 << 0))) | INT8_TO_LE(unsignedTemp);               

/* AMK_bDcOn */ 
unsignedTemp = (CANMMCAN_Amk1_TX_Msg_3_Sgn_2 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 1;                         
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x1 << 1))) | INT8_TO_LE(unsignedTemp);               

/* AMK_bEnable */ 
unsignedTemp = (CANMMCAN_Amk1_TX_Msg_3_Sgn_3 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 2;                         
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x1 << 2))) | INT8_TO_LE(unsignedTemp);               

/* AMK_bErrorReset */ 
unsignedTemp = (CANMMCAN_Amk1_TX_Msg_3_Sgn_4 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 3;                         
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x1 << 3))) | INT8_TO_LE(unsignedTemp);               

/* AMK_TargetVelocity */ 
signedTemp = (CANMMCAN_Amk1_TX_Msg_3_Sgn_5 );                               
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                         
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* AMK_TorqueLimitPositiv */ 
signedTemp = (CANMMCAN_Amk1_TX_Msg_3_Sgn_6 );                               
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                         
*((UInt16*)&data->pData[4]) = (*((UInt16*)&data->pData[4]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* AMK_TorqueLimitNegativ */ 
signedTemp = (CANMMCAN_Amk1_TX_Msg_3_Sgn_7 );                               
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                         
*((UInt16*)&data->pData[6]) = (*((UInt16*)&data->pData[6]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_Amk1_TXLEN[0], (uint8_T)8, (uint8_T)0);

data->CANMsg.Id = CANMMCAN_Amk1_MIDRX[0];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_Amk1_MIDFTX[0];  
CANMMCAN_Amk1_TXsta[0] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- AMK1_ActualValues1  -----*/  
void RTICANMM_MAIN_CAN_Amk1_copy_AMK1_ActualValues1(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Amk1_MIDFRX[3] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Amk1_RXLEN[3] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Amk1_RXLEN[3];                                   
                                                                                 
if(currentMsgLength >= 2) {
/* AMK_bSystemReady */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_4_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bError */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 1;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_4_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bWarn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 2;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_4_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bQuitDcOn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 3;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_4_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bDcOn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 4;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_4_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bQuitInverterOn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 5;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_4_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bInverterOn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 6;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_4_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bDerating */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 7;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_4_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* AMK_ActualVelocity */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_4_Sgn_9 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

}

if(currentMsgLength >= 6) {
/* AMK_TorqueCurrent */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_4_Sgn_10 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

}

if(currentMsgLength >= 8) {
/* AMK_MagnetizingCurrent */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_4_Sgn_11 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

}

((boolean_T*) ssGetOutputPortSignal(S, 15))[0] = CANMMCAN_Amk1_RX_Msg_4_Sgn_1;
((boolean_T*) ssGetOutputPortSignal(S, 16))[0] = CANMMCAN_Amk1_RX_Msg_4_Sgn_2;
((boolean_T*) ssGetOutputPortSignal(S, 17))[0] = CANMMCAN_Amk1_RX_Msg_4_Sgn_3;
((boolean_T*) ssGetOutputPortSignal(S, 18))[0] = CANMMCAN_Amk1_RX_Msg_4_Sgn_4;
((boolean_T*) ssGetOutputPortSignal(S, 19))[0] = CANMMCAN_Amk1_RX_Msg_4_Sgn_5;
((boolean_T*) ssGetOutputPortSignal(S, 20))[0] = CANMMCAN_Amk1_RX_Msg_4_Sgn_6;
((boolean_T*) ssGetOutputPortSignal(S, 21))[0] = CANMMCAN_Amk1_RX_Msg_4_Sgn_7;
((boolean_T*) ssGetOutputPortSignal(S, 22))[0] = CANMMCAN_Amk1_RX_Msg_4_Sgn_8;
((int16_T*) ssGetOutputPortSignal(S, 23))[0] = CANMMCAN_Amk1_RX_Msg_4_Sgn_9;
((int16_T*) ssGetOutputPortSignal(S, 24))[0] = CANMMCAN_Amk1_RX_Msg_4_Sgn_10;
((int16_T*) ssGetOutputPortSignal(S, 25))[0] = CANMMCAN_Amk1_RX_Msg_4_Sgn_11;
}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- AMK1_ActualValues2  -----*/  
void RTICANMM_MAIN_CAN_Amk1_copy_AMK1_ActualValues2(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Amk1_MIDFRX[5] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Amk1_RXLEN[5] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Amk1_RXLEN[5];                                   
                                                                                 
if(currentMsgLength >= 2) {
/* AMK_TempMotor */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_5_Sgn_1 = (double)0.1 * (double)signedTemp + (double)(0);                    

}

if(currentMsgLength >= 4) {
/* AMK_TempInverter */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_5_Sgn_2 = (double)0.1 * (double)signedTemp + (double)(0);                    

}

if(currentMsgLength >= 6) {
/* AMK_ErrorInfo */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  CANMMCAN_Amk1_RX_Msg_5_Sgn_3 = (UInt16)1 * (UInt16)unsignedTemp + (UInt16)(0);                    

}

if(currentMsgLength >= 8) {
/* AMK_TempIGBT */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_5_Sgn_4 = (double)0.1 * (double)signedTemp + (double)(0);                    

}

((real_T*) ssGetOutputPortSignal(S, 26))[0] = CANMMCAN_Amk1_RX_Msg_5_Sgn_1;
((real_T*) ssGetOutputPortSignal(S, 27))[0] = CANMMCAN_Amk1_RX_Msg_5_Sgn_2;
((uint16_T*) ssGetOutputPortSignal(S, 28))[0] = CANMMCAN_Amk1_RX_Msg_5_Sgn_3;
((real_T*) ssGetOutputPortSignal(S, 29))[0] = CANMMCAN_Amk1_RX_Msg_5_Sgn_4;
}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- AMK1_SetPoints1  -----*/  
void RTICANMM_MAIN_CAN_Amk1_copy_AMK1_SetPoints1(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Amk1_MIDFRX[1] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Amk1_RXLEN[1] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Amk1_RXLEN[1];                                   
                                                                                 
if(currentMsgLength >= 2) {
/* AMK_bInverterOn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_6_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bDcOn */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 1;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_6_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bEnable */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 2;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_6_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* AMK_bErrorReset */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 3;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Amk1_RX_Msg_6_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* AMK_TargetVelocity */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_6_Sgn_5 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

}

if(currentMsgLength >= 6) {
/* AMK_TorqueLimitPositiv */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_6_Sgn_6 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

}

if(currentMsgLength >= 8) {
/* AMK_TorqueLimitNegativ */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  if (unsignedTemp & 0x8000) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFF0000;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_Amk1_RX_Msg_6_Sgn_7 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

}

}      
else {  /* TX ========================================================================================== */ 

  /* Init encode structure */                               
    *((UInt32*)(data->pData)) = INT32_TO_BE(0x00000000);        
    *((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);      

/* AMK_bInverterOn */
CANMMCAN_Amk1_TX_Msg_6_Sgn_1 = ((boolean_T*)GetInputPortSignal(S,13))[0];

/* AMK_bDcOn */
CANMMCAN_Amk1_TX_Msg_6_Sgn_2 = ((boolean_T*)GetInputPortSignal(S,14))[0];

/* AMK_bEnable */
CANMMCAN_Amk1_TX_Msg_6_Sgn_3 = ((boolean_T*)GetInputPortSignal(S,15))[0];

/* AMK_bErrorReset */
CANMMCAN_Amk1_TX_Msg_6_Sgn_4 = ((boolean_T*)GetInputPortSignal(S,16))[0];

/* AMK_TargetVelocity */
CANMMCAN_Amk1_TX_Msg_6_Sgn_5 = ((int16_T*)GetInputPortSignal(S,17))[0];

/* AMK_TorqueLimitPositiv */
CANMMCAN_Amk1_TX_Msg_6_Sgn_6 = ((int16_T*)GetInputPortSignal(S,18))[0];

/* AMK_TorqueLimitNegativ */
CANMMCAN_Amk1_TX_Msg_6_Sgn_7 = ((int16_T*)GetInputPortSignal(S,19))[0];
/* AMK_bInverterOn */ 
unsignedTemp = (CANMMCAN_Amk1_TX_Msg_6_Sgn_1 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 0;                         
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x1 << 0))) | INT8_TO_LE(unsignedTemp);               

/* AMK_bDcOn */ 
unsignedTemp = (CANMMCAN_Amk1_TX_Msg_6_Sgn_2 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 1;                         
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x1 << 1))) | INT8_TO_LE(unsignedTemp);               

/* AMK_bEnable */ 
unsignedTemp = (CANMMCAN_Amk1_TX_Msg_6_Sgn_3 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 2;                         
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x1 << 2))) | INT8_TO_LE(unsignedTemp);               

/* AMK_bErrorReset */ 
unsignedTemp = (CANMMCAN_Amk1_TX_Msg_6_Sgn_4 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 3;                         
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x1 << 3))) | INT8_TO_LE(unsignedTemp);               

/* AMK_TargetVelocity */ 
signedTemp = (CANMMCAN_Amk1_TX_Msg_6_Sgn_5 );                               
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                         
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* AMK_TorqueLimitPositiv */ 
signedTemp = (CANMMCAN_Amk1_TX_Msg_6_Sgn_6 );                               
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                         
*((UInt16*)&data->pData[4]) = (*((UInt16*)&data->pData[4]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* AMK_TorqueLimitNegativ */ 
signedTemp = (CANMMCAN_Amk1_TX_Msg_6_Sgn_7 );                               
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                         
*((UInt16*)&data->pData[6]) = (*((UInt16*)&data->pData[6]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_Amk1_TXLEN[1], (uint8_T)8, (uint8_T)0);

data->CANMsg.Id = CANMMCAN_Amk1_MIDRX[1];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_Amk1_MIDFTX[1];  
CANMMCAN_Amk1_TXsta[1] = 1;                                       
} /* TX */
}


