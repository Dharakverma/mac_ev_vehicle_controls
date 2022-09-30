/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Driver_MSG_DATA */
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


void RTICANMM_MAIN_CAN_Driver_copy_CoolingLoopModes(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Driver_copy_CoolingLoopsData(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Driver_copy_PedalPositions(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Driver_copy_TemperatureInfo(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Driver_copy_VehicleInfo(MainSetupMsgData* data, int direction, SimStruct *S);
                                           
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
/* ----- CoolingLoopModes  -----*/  
void RTICANMM_MAIN_CAN_Driver_copy_CoolingLoopModes(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Driver_MIDFRX[2] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Driver_RXLEN[2] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Driver_RXLEN[2];                                   
                                                                                 
if(currentMsgLength >= 1) {
/* InverterLoopFanMode */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0x7;                             
  CANMMCAN_Driver_RX_Msg_1_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* InverterLoopPumpMode */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 3;                    
  unsignedTemp = unsignedTemp & 0x7;                             
  CANMMCAN_Driver_RX_Msg_1_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* SpeakerRequest */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 6;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Driver_RX_Msg_1_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* MotorLoopFanMode */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp & 0x7;                             
  CANMMCAN_Driver_RX_Msg_1_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* MotorLoopPumpMode */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 3;                    
  unsignedTemp = unsignedTemp & 0x7;                             
  CANMMCAN_Driver_RX_Msg_1_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

}      
else {  /* TX ========================================================================================== */ 

  /* Init encode structure */                               
    *((UInt32*)(data->pData)) = INT32_TO_BE(0x00000000);        
    *((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);      

/* InverterLoopFanMode */
CANMMCAN_Driver_TX_Msg_1_Sgn_1 = ((uint8_T*)GetInputPortSignal(S,0))[0];

/* InverterLoopPumpMode */
CANMMCAN_Driver_TX_Msg_1_Sgn_2 = ((uint8_T*)GetInputPortSignal(S,1))[0];

/* SpeakerRequest */
CANMMCAN_Driver_TX_Msg_1_Sgn_3 = ((boolean_T*)GetInputPortSignal(S,2))[0];

/* MotorLoopFanMode */
CANMMCAN_Driver_TX_Msg_1_Sgn_4 = ((uint8_T*)GetInputPortSignal(S,3))[0];

/* MotorLoopPumpMode */
CANMMCAN_Driver_TX_Msg_1_Sgn_5 = ((uint8_T*)GetInputPortSignal(S,4))[0];
/* InverterLoopFanMode */ 
unsignedTemp = (CANMMCAN_Driver_TX_Msg_1_Sgn_1 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x7)) << 0;                         
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0x7 << 0))) | INT8_TO_LE(unsignedTemp);               

/* InverterLoopPumpMode */ 
unsignedTemp = (CANMMCAN_Driver_TX_Msg_1_Sgn_2 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x7)) << 3;                         
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0x7 << 3))) | INT8_TO_LE(unsignedTemp);               

/* SpeakerRequest */ 
unsignedTemp = (CANMMCAN_Driver_TX_Msg_1_Sgn_3 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 6;                         
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0x1 << 6))) | INT8_TO_LE(unsignedTemp);               

/* MotorLoopFanMode */ 
unsignedTemp = (CANMMCAN_Driver_TX_Msg_1_Sgn_4 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x7)) << 0;                         
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x7 << 0))) | INT8_TO_LE(unsignedTemp);               

/* MotorLoopPumpMode */ 
unsignedTemp = (CANMMCAN_Driver_TX_Msg_1_Sgn_5 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x7)) << 3;                         
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x7 << 3))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_Driver_TXLEN[0], (uint8_T)8, (uint8_T)0);

data->CANMsg.Id = CANMMCAN_Driver_MIDRX[2];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_Driver_MIDFTX[2];  
CANMMCAN_Driver_TXsta[0] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CoolingLoopsData  -----*/  
void RTICANMM_MAIN_CAN_Driver_copy_CoolingLoopsData(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Driver_MIDFRX[1] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Driver_RXLEN[1] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Driver_RXLEN[1];                                   
                                                                                 
if(currentMsgLength >= 1) {
/* InverterLoopFluidTemp */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Driver_RX_Msg_2_Sgn_1 = (Int16)1 * (Int16)unsignedTemp + (Int16)(-20);                    

}

if(currentMsgLength >= 2) {
/* MotorLoopFluidTemp */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Driver_RX_Msg_2_Sgn_2 = (Int16)1 * (Int16)unsignedTemp + (Int16)(-20);                    

}

if(currentMsgLength >= 3) {
/* InverterLoopPressure */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0x7F;                             
  CANMMCAN_Driver_RX_Msg_2_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* MotorLoopPressure */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp >> 7;                    
  unsignedTemp = unsignedTemp & 0x7F;                             
  CANMMCAN_Driver_RX_Msg_2_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 5) {
/* InverterLoopTempSensorStatus */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (3)));           
  unsignedTemp = unsignedTemp >> 6;                    
  unsignedTemp = unsignedTemp & 0x7;                             
  CANMMCAN_Driver_RX_Msg_2_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 5) {
/* MotorLoopTempSensorStatus */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp >> 1;                    
  unsignedTemp = unsignedTemp & 0x7;                             
  CANMMCAN_Driver_RX_Msg_2_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 5) {
/* InverterLoopPressureSensorStatus */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp >> 4;                    
  unsignedTemp = unsignedTemp & 0x7;                             
  CANMMCAN_Driver_RX_Msg_2_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 6) {
/* MotorLoopPressureSensorStatus */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp >> 7;                    
  unsignedTemp = unsignedTemp & 0x7;                             
  CANMMCAN_Driver_RX_Msg_2_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 6) {
/* MC_CoolingLoopsData */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (5)));           
  unsignedTemp = unsignedTemp >> 2;                    
  unsignedTemp = unsignedTemp & 0xF;                             
  CANMMCAN_Driver_RX_Msg_2_Sgn_9 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

((int16_T*) ssGetOutputPortSignal(S, 0))[0] = CANMMCAN_Driver_RX_Msg_2_Sgn_1;
((int16_T*) ssGetOutputPortSignal(S, 1))[0] = CANMMCAN_Driver_RX_Msg_2_Sgn_2;
((uint8_T*) ssGetOutputPortSignal(S, 2))[0] = CANMMCAN_Driver_RX_Msg_2_Sgn_3;
((uint8_T*) ssGetOutputPortSignal(S, 3))[0] = CANMMCAN_Driver_RX_Msg_2_Sgn_4;
((uint8_T*) ssGetOutputPortSignal(S, 4))[0] = CANMMCAN_Driver_RX_Msg_2_Sgn_5;
((uint8_T*) ssGetOutputPortSignal(S, 5))[0] = CANMMCAN_Driver_RX_Msg_2_Sgn_6;
((uint8_T*) ssGetOutputPortSignal(S, 6))[0] = CANMMCAN_Driver_RX_Msg_2_Sgn_7;
((uint8_T*) ssGetOutputPortSignal(S, 7))[0] = CANMMCAN_Driver_RX_Msg_2_Sgn_8;
((uint8_T*) ssGetOutputPortSignal(S, 8))[0] = CANMMCAN_Driver_RX_Msg_2_Sgn_9;
}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- PedalPositions  -----*/  
void RTICANMM_MAIN_CAN_Driver_copy_PedalPositions(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Driver_MIDFRX[0] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Driver_RXLEN[0] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Driver_RXLEN[0];                                   
                                                                                 
if(currentMsgLength >= 1) {
/* BrakePedalPosition0 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Driver_RX_Msg_3_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* BrakePedalPosition1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Driver_RX_Msg_3_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 3) {
/* AcceleratorPedalPosition1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Driver_RX_Msg_3_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* AcceleratorPedalPosition0 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Driver_RX_Msg_3_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 5) {
/* DriveButton */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_Driver_RX_Msg_3_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 5) {
/* Bpps0Status */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp >> 2;                    
  unsignedTemp = unsignedTemp & 0x7;                             
  CANMMCAN_Driver_RX_Msg_3_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 5) {
/* Bpps1Status */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp >> 5;                    
  unsignedTemp = unsignedTemp & 0x7;                             
  CANMMCAN_Driver_RX_Msg_3_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 6) {
/* Apps0Status */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (5)));           
  unsignedTemp = unsignedTemp & 0x7;                             
  CANMMCAN_Driver_RX_Msg_3_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 6) {
/* Apps1Status */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (5)));           
  unsignedTemp = unsignedTemp >> 3;                    
  unsignedTemp = unsignedTemp & 0x7;                             
  CANMMCAN_Driver_RX_Msg_3_Sgn_9 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 6) {
/* BspdFault */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (5)));           
  unsignedTemp = unsignedTemp >> 6;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_Driver_RX_Msg_3_Sgn_10 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 7) {
/* MC_PedalPosition */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (6)));           
  unsignedTemp = unsignedTemp & 0xF;                             
  CANMMCAN_Driver_RX_Msg_3_Sgn_11 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

((uint8_T*) ssGetOutputPortSignal(S, 9))[0] = CANMMCAN_Driver_RX_Msg_3_Sgn_1;
((uint8_T*) ssGetOutputPortSignal(S, 10))[0] = CANMMCAN_Driver_RX_Msg_3_Sgn_2;
((uint8_T*) ssGetOutputPortSignal(S, 11))[0] = CANMMCAN_Driver_RX_Msg_3_Sgn_3;
((uint8_T*) ssGetOutputPortSignal(S, 12))[0] = CANMMCAN_Driver_RX_Msg_3_Sgn_4;
((uint8_T*) ssGetOutputPortSignal(S, 13))[0] = CANMMCAN_Driver_RX_Msg_3_Sgn_5;
((uint8_T*) ssGetOutputPortSignal(S, 14))[0] = CANMMCAN_Driver_RX_Msg_3_Sgn_6;
((uint8_T*) ssGetOutputPortSignal(S, 15))[0] = CANMMCAN_Driver_RX_Msg_3_Sgn_7;
((uint8_T*) ssGetOutputPortSignal(S, 16))[0] = CANMMCAN_Driver_RX_Msg_3_Sgn_8;
((uint8_T*) ssGetOutputPortSignal(S, 17))[0] = CANMMCAN_Driver_RX_Msg_3_Sgn_9;
((boolean_T*) ssGetOutputPortSignal(S, 18))[0] = CANMMCAN_Driver_RX_Msg_3_Sgn_10;
((uint8_T*) ssGetOutputPortSignal(S, 19))[0] = CANMMCAN_Driver_RX_Msg_3_Sgn_11;
}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- TemperatureInfo  -----*/  
void RTICANMM_MAIN_CAN_Driver_copy_TemperatureInfo(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Driver_MIDFRX[3] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Driver_RXLEN[3] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Driver_RXLEN[3];                                   
                                                                                 
if(currentMsgLength >= 1) {
/* LeftFrontMotorTemperature */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Driver_RX_Msg_4_Sgn_1 = (Int16)1 * (Int16)unsignedTemp + (Int16)(-20);                    

}

if(currentMsgLength >= 2) {
/* LeftRearMotorTemperature */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Driver_RX_Msg_4_Sgn_2 = (Int16)1 * (Int16)unsignedTemp + (Int16)(-20);                    

}

if(currentMsgLength >= 3) {
/* RightFrontMotorTemperature */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Driver_RX_Msg_4_Sgn_3 = (Int16)1 * (Int16)unsignedTemp + (Int16)(-20);                    

}

if(currentMsgLength >= 4) {
/* RightRearMotorTemperature */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Driver_RX_Msg_4_Sgn_4 = (Int16)1 * (Int16)unsignedTemp + (Int16)(-20);                    

}

if(currentMsgLength >= 5) {
/* BatteryTemperature */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Driver_RX_Msg_4_Sgn_5 = (Int16)1 * (Int16)unsignedTemp + (Int16)(-20);                    

}

}      
else {  /* TX ========================================================================================== */ 

  /* Init encode structure */                               
    *((UInt32*)(data->pData)) = INT32_TO_BE(0x00000000);        
    *((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);      

/* LeftFrontMotorTemperature */
CANMMCAN_Driver_TX_Msg_4_Sgn_1 = ((int16_T*)GetInputPortSignal(S,5))[0];

/* LeftRearMotorTemperature */
CANMMCAN_Driver_TX_Msg_4_Sgn_2 = ((int16_T*)GetInputPortSignal(S,6))[0];

/* RightFrontMotorTemperature */
CANMMCAN_Driver_TX_Msg_4_Sgn_3 = ((int16_T*)GetInputPortSignal(S,7))[0];

/* RightRearMotorTemperature */
CANMMCAN_Driver_TX_Msg_4_Sgn_4 = ((int16_T*)GetInputPortSignal(S,8))[0];

/* BatteryTemperature */
CANMMCAN_Driver_TX_Msg_4_Sgn_5 = ((int16_T*)GetInputPortSignal(S,9))[0];
/* LeftFrontMotorTemperature */ 
unsignedTemp = ((CANMMCAN_Driver_TX_Msg_4_Sgn_1 - (-20)) + (CANMMCAN_Driver_TX_Msg_4_Sgn_1 > -20) - 0.5);                       
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                         
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* LeftRearMotorTemperature */ 
unsignedTemp = ((CANMMCAN_Driver_TX_Msg_4_Sgn_2 - (-20)) + (CANMMCAN_Driver_TX_Msg_4_Sgn_2 > -20) - 0.5);                       
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                         
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RightFrontMotorTemperature */ 
unsignedTemp = ((CANMMCAN_Driver_TX_Msg_4_Sgn_3 - (-20)) + (CANMMCAN_Driver_TX_Msg_4_Sgn_3 > -20) - 0.5);                       
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                         
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RightRearMotorTemperature */ 
unsignedTemp = ((CANMMCAN_Driver_TX_Msg_4_Sgn_4 - (-20)) + (CANMMCAN_Driver_TX_Msg_4_Sgn_4 > -20) - 0.5);                       
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                         
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* BatteryTemperature */ 
unsignedTemp = ((CANMMCAN_Driver_TX_Msg_4_Sgn_5 - (-20)) + (CANMMCAN_Driver_TX_Msg_4_Sgn_5 > -20) - 0.5);                       
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                         
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_Driver_TXLEN[1], (uint8_T)8, (uint8_T)0);

data->CANMsg.Id = CANMMCAN_Driver_MIDRX[3];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_Driver_MIDFTX[3];  
CANMMCAN_Driver_TXsta[1] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- VehicleInfo  -----*/  
void RTICANMM_MAIN_CAN_Driver_copy_VehicleInfo(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_Driver_MIDFRX[4] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_Driver_RXLEN[4] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_Driver_RXLEN[4];                                   
                                                                                 
if(currentMsgLength >= 1) {
/* MaximumPowerAvailablePercentage */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0x7F;                             
  CANMMCAN_Driver_RX_Msg_5_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* SocPercentage */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp & 0x7F;                             
  CANMMCAN_Driver_RX_Msg_5_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 3) {
/* VcuErrors */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Driver_RX_Msg_5_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* VehicleSpeed */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_Driver_RX_Msg_5_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 5) {
/* VehicleStatus */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_Driver_RX_Msg_5_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

}      
else {  /* TX ========================================================================================== */ 

  /* Init encode structure */                               
    *((UInt32*)(data->pData)) = INT32_TO_BE(0x00000000);        
    *((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);      

/* MaximumPowerAvailablePercentage */
CANMMCAN_Driver_TX_Msg_5_Sgn_1 = ((uint8_T*)GetInputPortSignal(S,10))[0];

/* SocPercentage */
CANMMCAN_Driver_TX_Msg_5_Sgn_2 = ((uint8_T*)GetInputPortSignal(S,11))[0];

/* VcuErrors */
CANMMCAN_Driver_TX_Msg_5_Sgn_3 = ((uint8_T*)GetInputPortSignal(S,12))[0];

/* VehicleSpeed */
CANMMCAN_Driver_TX_Msg_5_Sgn_4 = ((uint8_T*)GetInputPortSignal(S,13))[0];

/* VehicleStatus */
CANMMCAN_Driver_TX_Msg_5_Sgn_5 = ((uint8_T*)GetInputPortSignal(S,14))[0];
/* MaximumPowerAvailablePercentage */ 
unsignedTemp = (CANMMCAN_Driver_TX_Msg_5_Sgn_1 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x7F)) << 0;                         
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0x7F << 0))) | INT8_TO_LE(unsignedTemp);               

/* SocPercentage */ 
unsignedTemp = (CANMMCAN_Driver_TX_Msg_5_Sgn_2 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x7F)) << 0;                         
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x7F << 0))) | INT8_TO_LE(unsignedTemp);               

/* VcuErrors */ 
unsignedTemp = (CANMMCAN_Driver_TX_Msg_5_Sgn_3 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                         
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* VehicleSpeed */ 
unsignedTemp = (CANMMCAN_Driver_TX_Msg_5_Sgn_4 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                         
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* VehicleStatus */ 
unsignedTemp = (CANMMCAN_Driver_TX_Msg_5_Sgn_5 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x3)) << 0;                         
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0x3 << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_Driver_TXLEN[2], (uint8_T)8, (uint8_T)0);

data->CANMsg.Id = CANMMCAN_Driver_MIDRX[4];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_Driver_MIDFTX[4];  
CANMMCAN_Driver_TXsta[2] = 1;                                       
} /* TX */
}


