/*****************************************************************************************************************************/
/* MAIN S-FUNCTION for RTICANMM MainBlock (RTICANMM_MAIN_CAN_Ams.c) */
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

                                                                                                                           
                                                                                                                           
#include "RTICANMM_SETUP_Ams.h"                                                                                                            
#include "RTICANMM_MAIN_CAN_Ams_Globals.h"                                                                                                              
                                                                                                                           
                                                                                                                           
#define NUM_PARAM       0                            /* Number of Parameter */                                             
#define NUM_IN          2                            /* Number of Input Ports */                                           
#define NUM_OUT         0                            /* Number of Output Ports */                                          
                                                                                                                           
#define NUM_CSTATES     0                            /* Number of Continuous States */                                     
#define NUM_DSTATES     0                            /* Number of Discrete States */                                       
                                                                                                                           
#define NUM_IWORK       0                            /* Number of I WORKS */                                               
#define NUM_PWORK       16                           /* Number of P WORKS */                                               
#define NUM_RWORK       1                            /* Number of R WORKS */                                               
                                                                                                                           
#define NUM_STIMES      1                            /* Number of Sample Times */                                          
#define NUM_MODES       0                            /* Number of Modes */                                                 
#define NUM_NSZCS       0                            /* Number of None Sampled ZCs */                                      
#define SET_OPTS        0                            /* Options */                                                         
                                                                                                                           
#define PWORK(X)   (PWork[X])                                                                                              
                                                                                                                           
#define IDPTR_MEM_T          PWORK(0)  /* Pointer to copy functions */                                                     
#define IDPTR_MEM_R          PWORK(1)  /* Pointer to copy functions */                                                     
#define TX_QUEUE_MEM         PWORK(2)  /* Pointer to TX QUEUE array */                                                     
#define TX_OLDTIME_Ptr       PWORK(6)                                                                                      
#define TX_KO_OLD_Ptr        PWORK(8)  /* Pointer to TX Enable Table */                                                    
#define TX_CYCL_OLD_Ptr      PWORK(9)  /* Pointer to extern TX Enable Table  */                                            
#define TX_COUNTER_Ptr       PWORK(10)  /* Pointer to TX Counter Table */                                                  
#define TX_TIMESTAMP_Ptr     PWORK(11)  /* Pointer to TX Counter Table */                                                  
#define RX_OLDTIME_Ptr       PWORK(13)                                                                                     
#define OLD_TIMESTAMP_Ptr    PWORK(14)                                                                                     
#define OLD_TX_TIMESTAMP_Ptr PWORK(15)                                                                                     
                                                                                                                           
                                                                                                                           
#define TX_KO_OLD            ((UInt8*)  TX_KO_OLD_Ptr)     /* Pointer to elements of TX Enable  Table */                   
#define TX_CYCL_OLD          ((UInt8*)  TX_CYCL_OLD_Ptr)   /* Pointer to elements of TX Cyclic  Table */                   
#define TX_ENABLE_OLD        ((UInt8*)  TX_ENABLE_OLD_Ptr)  /* Pointer to elements of TX Enable  Table */                  
#define TX_COUNTER           ((Int32*)  TX_COUNTER_Ptr)     /* Pointer to elements of TX Counter Table  */                 
#define TX_TIMESTAMP         ((unsigned long*)  TX_TIMESTAMP_Ptr)    /* Pointer to elements of TX Counter Table */         
#define OLD_TX_TIMESTAMP     ((unsigned long*)  OLD_TX_TIMESTAMP_Ptr)    /* Pointer to elements of TX Counter Table */     
#define RX_OLDTIME           ((double*) RX_OLDTIME_Ptr)                                                                    
#define TX_OLDTIME           ((double*) TX_OLDTIME_Ptr)                                                                    
#define OLD_TIMESTAMP        ((double*) OLD_TIMESTAMP_Ptr)                                                                 
                                                                                                                           
#define TX_QUEUE(X)        ((tx_queue_msg*) TX_QUEUE_MEM)[X]                                                               
#define IDPtr_T(X)         ((UInt32*) IDPTR_MEM_T)[X]                                                                      
#define IDPtr_R(X)         ((UInt32*) IDPTR_MEM_R)[X]                                                                      
#define RX 0                                                                                                               
#define TX 1                                                                                                               
                                                                                                                           
#define CANMM_CONTROLLER_ID CANMM_CTL_SETUP_Ams                                                                                             
                                                                                                                           
 /* Max number of TX Messages per step */                                                                                  
#define MAX_TX_PERSTEP (unsigned long)((6*CANMM_CTL_BAUDRATE_GET(CANMM_CONTROLLER_ID)/500.0)*((sampletime)/1000.0)+0.5)   
                                                                                                                           
                                                                                                                           
static int memAllocatedStart    = 0;                                                                                       
static int memAllocatedInitCond = 0;                                                                                       
static int LastActiveState;                                                                                                
                                                                                                                           
#if !defined(MATLAB_MEX_FILE) || defined(CANMM_HOST_DEBUG)                                                            
static MainSetupMsgData MsgData;                                                                                           
static CANMM_CTL_CLIENT_TYPE(CANMM_CONTROLLER_ID) ctlsetup_client;                                                         
                                                                                                                           
typedef struct{                                                                                                            
  UInt32 id;                                                                                                               
  UInt32 kickout;                                                                                                          
  UInt32 idx;                                                                                                              
  UInt32 cycletime;                                                                                                        
} tx_queue_msg;                                                                                                            
                                                                                                                           
                                                                                                                           
                                                                                                                           
                                                                                                                           
UInt32 CAN_NUM_LOST=0;                                                                                                     
                                                                                                                           
                                                                                                                           
#include "RTICANMM_MAIN_CAN_Ams_DEFS.h"                                                                                                              
#include "RTICANMM_MAIN_CAN_Ams_MSG_DATA.h"                                                                                                              
                                                                                                                           
static int find_ID_number(SimStruct *S, CanMM_Msg *Msg)                                                                
{                                                                                                                      
  /* find corresponding number to Identifier ID */                                                                     
  void** PWork = ssGetPWork(S);                  /* For all PWorks */                                                  
  static Int32 StartIdx[8] = {0, 6, 6, 6, 6, 6, 6, 6};                                                         
  static Int32 StopIdx[8]  = {5, 5, 5, 5, 5, 5, 5, 5};                                                         
  static Int32 NumOfIds[8] = {6, 0, 0, 0, 0, 0, 0, 0};                                                         
  Int32 MsgId = Msg->Id;                                                                                                     
  UInt8 MsgIDFormat = Msg->Format; // 0=STD, 1=EXT, 2=STD FD SLOW, 3=EXT FD SLOW, 4=RES, 5=RES, 6=STD FD FAST, 7=EXT FD FAST 
  int Pos;                                                                                                                   
  int i;                                                                                                                     
  int Start, Stop;                                                                                                 
  int found = 0;                                                                                                   
                                                                                                                   
  if(MsgIDFormat > 1)                                                                                          
    return -1;                                                                                                 
                                                                                                               
  for (i=0; i<8; i++) {                                                                                            
    if( NumOfIds[MsgIDFormat]>0) {                                                                                 
      Start = (unsigned int) StartIdx[MsgIDFormat];                                                                
      Stop  = (unsigned int) StopIdx[MsgIDFormat];                                                                 
                                                                                                                   
      while (!found && (Start <= Stop)) {                                                                          
        /* Search in the middle of the table */                                                                    
        Pos = (Start + Stop)>>1;                                                                                   
        if ((ID_Table_RX(Pos) == MsgId) && (Msg->Format == CANMMCAN_Ams_MIDFRX[Pos])) {                                             
          found = 1;                                                                                               
          break; // while                                                                                          
        }                                                                                                          
        else {                                                                                                     
          if (MsgId < ID_Table_RX(Pos))                                                                            
            Stop  = Pos - 1;                                                                                       
          else                                                                                                     
            Start = Pos + 1;                                                                                       
        }                                                                                                          
      }                                                                                                            
    }                                                                                                              
    if (found) {                                                                                                   
      break; // i                                                                                                  
    }                                                                                                              
    else {                                                                                                         
      /* Try other message format, because of message id manipulation format may have changed. */                  
      MsgIDFormat = (MsgIDFormat + 1) & 0x7; // Toogle message format locally!!!                                   
    }                                                                                                              
  }                                                                                                                
                                                                                                                   
  if (!found) {                                                                                              
    Pos = -1; /* not found */                                                                                      
  }                                                                                                                
                                                                                                                   
  return Pos;                                                                                                          
}                                                                                                                      
                                                                                                                       
                                                                                                                       
static int GlobalTxActive = -1;                                                                                        
static int lastGlobalTxActive = -1;                                                                                    
static dsfloat noMsgFormatTime;                                                                                        
                                                                                                                       
/* This function clears the TX queue from messages which have                                                          
 * been delayed to the next SimStep. It is called whenever                                                             
 * transmission of messages is completely disabled.                                                                    
 * (due to global enable, global tx enable, switch of variation,                                                       
 *  or silent mode of TJA 1041 transceiver)                                                                            
 */                                                                                                                    
static void clearTxQueue(SimStruct* S) {                                                                               
  void **PWork = ssGetPWork(S);                                                                                        
  int i = 0;                                                                                                           
                                                                                                                       
  for(i = 0; i < NUM_TX_MSG; i++) {                                                                                    
      TX_QUEUE(i).id = NOCANID;                                                                                        
      CAN_SENDBYKICKOUT[i] = 0;                                                                                        
  }                                                                                                                    
}                                                                                                                      
                                                                                                                       
#endif /* MATLAB_MEX_FILE */                                                                                               
                                                                                                                           
                                                                                                                           
static void mdlInitializeSizes(SimStruct *S)                                                                               
{                                                                                                                          
  int i;                                                                                                                   
                                                                                                                           
  static int sizes_once = 0;                                                                                               
  ssSetNumSFcnParams(S, NUM_PARAM);                                                                                        
  if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)){                                                                   
    return;                                                                                                                
  }                                                                                                                        
  ssSetNumContStates(S, NUM_CSTATES);                                                                                      
  ssSetNumDiscStates(S, NUM_DSTATES);                                                                                      
                                                                                                                           
                                                                                                                           
  if (!ssSetNumOutputPorts(S, NUM_RX_OUTPUT))  {                                                                           
    return;                                                                                                                
  }                                                                                                                        
                                                                                                                           
  if (NUM_RX_OUTPUT) {                                                                                                     
#include "RTICANMM_MAIN_CAN_Ams_RX_PORT.h"                                                                                                              
  }                                                                                                                        
                                                                                                                           
  if (!ssSetNumInputPorts(S, NUM_TX_INPUT)){                                                                               
    return;                                                                                                                
  }                                                                                                                        
                                                                                                                           
#include "RTICANMM_MAIN_CAN_Ams_TX_PORT.h"                                                                                                              
                                                                                                                           
  for (i=0; i<NUM_TX_INPUT; i++) {                                                                                         
    ssSetInputPortDirectFeedThrough(S, i, 1);                                                                              
  }                                                                                                                        
  for (i=0; i<NUM_TX_INPUT; i++) {                                                                                         
    ssSetInputPortRequiredContiguous(S, i, true); /* direct input signal access */                                           
  }                                                                                                                        
                                                                                                                           
  ssSetNumRWork(S, NUM_RWORK);                                                                                             
  ssSetNumIWork(S, NUM_IWORK);                                                                                             
  ssSetNumPWork(S, NUM_PWORK);                                                                                             
  ssSetNumSampleTimes(S, NUM_STIMES);                                                                                      
  ssSetNumModes(S, NUM_MODES);                                                                                             
  ssSetNumNonsampledZCs(S, NUM_NSZCS);                                                                                     
  ssSetOptions(S, SET_OPTS | SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME);                                                                                      
  LastActiveState = -1;                                                                                                    
}                                                                                                                          
                                                                                                                           
                                                                                                                           
                                                                                                                           
/* Function: mdlInitializeSampleTimes =========================================                                            
 * Abstract:                                                                                                               
 *    This function is used to specify the sample time(s) for your                                                         
 *    S-function. You must register the same number of sample times as                                                     
 *    specified in ssSetNumSampleTimes.                                                                                    
 */                                                                                                                        
static void mdlInitializeSampleTimes(SimStruct *S)                                                                         
{                                                                                                                          
  ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);                                                                                               
  ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);                                                                                               
}                                                                                                                          
                                                                                                                           
                                                                                                                           
                                                                                                                           
#define MDL_INITIALIZE_CONDITIONS   /* Change to #undef to remove function */                                              
#if defined(MDL_INITIALIZE_CONDITIONS)                                                                                     
/* Function: mdlInitializeConditions ========================================                                              
 */                                                                                                                        
static void mdlInitializeConditions(SimStruct *S)                                                                          
{                                                                                                                          
  void **PWork = ssGetPWork(S);                                                                                            
  int i = 0;                                                                                                               
#if !defined(MATLAB_MEX_FILE) || defined(CANMM_HOST_DEBUG)                                                            
#include "RTICANMM_MAIN_CAN_Ams_ID_TABLE.h"  /* fills the variable ID_Table with identifiers in rising order */                                          
#include "RTICANMM_MAIN_CAN_Ams_SIGNAL_DEFAULTS.h"                                                                                                              
#include "RTICANMM_MAIN_CAN_Ams_MESSAGE_DEFAULTS.h"                                                                                                              
  /* Allocate memory only once */                                                                                          
  if (!memAllocatedInitCond)                                                                                               
  {                                                                                                                        
      memAllocatedInitCond = 1;                                                                                            
      TX_TIMESTAMP_Ptr       = malloc(sizeof(unsigned long)*(NUM_TX_MSG));   /* memory for TX_TIMESTAMP of each TX message */
      OLD_TX_TIMESTAMP_Ptr   = malloc(sizeof(unsigned long)*(NUM_TX_MSG));   /* memory for TX_TIMESTAMP of each TX message */
      if ((TX_TIMESTAMP_Ptr == NULL) || (OLD_TX_TIMESTAMP_Ptr == NULL))                                                
      {                                                                                                                
          msg_error_printf(MSG_SM_CANNEDY, RTICANMM_MAINSFCN_MALLOC_ERROR , RTICANMM_MAINSFCN_MALLOC_ERROR_TXT, "CAN_Ams");
      }                                                                                                                
  }                                                                                                                        
  for (i = 0; i < NUM_TX_MSG; i++) {                                                                                   
      TX_TIMESTAMP[i] = (long unsigned int)(TX_CYCLETIME[i]*1000000 - TX_DELAYTIME[i]*1000000 - (unsigned long) (ssGetSampleTime(S, 0)*1000000));
      OLD_TX_TIMESTAMP[i] = 0;                                                                                         
  }                                                                                                                    
                                                                                                                           
CANMM_CTL_CLIENT_INIT(CANMM_CONTROLLER_ID, &ctlsetup_client);                                                              
#endif /* NOT MATLAB_MEX_FILE || CANMM_HOST_DEBUG */                                                                  
}                                                                                                                          
#endif /* MDL_INITIALIZE_CONDITIONS */                                                                                     
                                                                                                                           
                                                                                                                           
#define MDL_START  /* Change to #undef to remove function */                                                               
#if defined(MDL_START)                                                                                                     
/* Function: mdlStart =======================================================                                              
 */                                                                                                                        
static void mdlStart(SimStruct *S)                                                                                         
{                                                                                                                          
#if !defined(MATLAB_MEX_FILE) || defined(CANMM_HOST_DEBUG)                                                                 
                                                                                                                           
  int i, j;                                                                                                                
  void (*copy_func)(RTICANMMMsgStruct*, int, SimStruct*);                                                                  
  void **PWork = ssGetPWork(S);                                                                                            
                                                                                                                           
                                                                                                                           
#if RTICANMM_LOGLEVEL > 1                                                                                                  
      msg_info_printf(MSG_SM_CANNEDY, RTICANMM_MAINSFCN_MDL_START_INFO , RTICANMM_MAINSFCN_MDL_START_INFO_TXT, "CAN_Ams");  
#endif                                                                                                                     
                                                                                                                           
  if (!memAllocatedStart) {                                                                                                
    memAllocatedStart = 1;                                                                                                 
    TX_QUEUE_MEM           = malloc(sizeof(tx_queue_msg)*NUM_TX_MSG); /* memory for TX queues */                           
    TX_KO_OLD_Ptr          = malloc(sizeof(UInt8)*NUM_TX_MSG);        /* memory for TX Enable Table */                     
    TX_CYCL_OLD_Ptr        = malloc(sizeof(UInt8)*NUM_TX_MSG);        /* memory for extern TX_ENABLE signal of each TX message */
    IDPTR_MEM_R            = malloc(sizeof(UInt32)*NUM_RX_MSG);       /* memory for RX copy functions */                   
    IDPTR_MEM_T            = malloc(sizeof(UInt32)*NUM_TX_MSG);       /* memory for TX copy functions */                   
    TX_COUNTER_Ptr         = malloc(sizeof(Int32)*(NUM_RX_MSG));      /* memory for TX_COUNTER of each TX message */       
    RX_OLDTIME_Ptr         = malloc(sizeof(double)*(NUM_RX_MSG));                                                          
    TX_OLDTIME_Ptr         = malloc(sizeof(double)*(NUM_RX_MSG));                                                          
    OLD_TIMESTAMP_Ptr      = malloc(sizeof(double));                                                                       
    if ((NULL == TX_QUEUE_MEM) || (NULL == TX_KO_OLD_Ptr) || (NULL == TX_CYCL_OLD_Ptr) || (NULL == IDPTR_MEM_R) ||         
        (NULL == IDPTR_MEM_T) || (NULL == TX_COUNTER_Ptr) || (NULL == RX_OLDTIME_Ptr) || (NULL == TX_OLDTIME_Ptr) ||       
        (NULL == OLD_TIMESTAMP_Ptr))                                                                                       
    {                                                                                                                      
          msg_error_printf(MSG_SM_CANNEDY, RTICANMM_MAINSFCN_MALLOC_ERROR , RTICANMM_MAINSFCN_MALLOC_ERROR_TXT, "CAN_Ams");     
    }                                                                                                                      
  }                                                                                                                        
#if RTICANMM_LOGLEVEL > 2                                                                                              
  msg_info_printf(MSG_SM_CANNEDY, RTICANMM_MAINSFCN_MDL_START_CYCLETIME_INFO, RTICANMM_MAINSFCN_MDL_START_CYCLETIME_INFO_TXT, "CAN_Ams", TX_CYCLETIME[0]);
#endif                                                                                                                 
                                                                                                                           
  for (i = 0; i < NUM_RX_MSG; i++) {                                                                                       
    TX_COUNTER[i] = -1;   /* initial values, will be incremented when sending message */                                   
  }                                                                                                                        
  for (i = 0;i < NUM_TX_MSG; i++) {                                                                                    
                                                                                                                       
    TX_KO_OLD[i]     = 0;                                                                                              
    TX_CYCL_OLD[i]   = 0;                                                                                              
                                                                                                                       
    TX_QUEUE(i).id = NOCANID;                                                                                          
    TX_QUEUE(i).idx = 0;                                                                                               
  }                                                                                                                    
                                                                                                                           
  for (i = 0; i < NUM_RX_MSG; i++) {                                                                                       
    RX_OLDTIME[i] = 0.0;                                                                                                   
    TX_OLDTIME[i] = 0.0;                                                                                                   
  }                                                                                                                        
  OLD_TIMESTAMP[0] = 0;                                                                                                    
#endif /* NOT MATLAB_MEX_FILE || CANMM_HOST_DEBUG */                                                                       
}                                                                                                                          
#endif /* MDL_START */                                                                                                     
                                                                                                                           
                                                                                                                           
/* Function: mdlOutputs =======================================================                                            
 */                                                                                                                        
static void mdlOutputs(SimStruct *S, int_T tid) {                                                                          
  void    **PWork = ssGetPWork(S);                   /* For all PWorks */                                                  
                                                                                                                           
#if !defined(MATLAB_MEX_FILE) || defined(CANMM_HOST_DEBUG)                                                                 
  int mbActive = -1;                                                                                                       
  int ite, k;                                                                                                              
  dsfloat noMsgFormatTimeDiff = 0.0;                                                                                   
  dsfloat noMsgFormatTimePeriod = 10.0;                                                                                
                                                                                                                           
  Int32 idIdx = -1;                                                                                                    
                                                                                                                           
                                                                                                                           
  Int32 i, j;                                                                                                              
  UInt32 tx_queue_level;                                                                                                   
  unsigned long cycletime;                                                                                             
  unsigned long delaytime;                                                                                             
  unsigned long sampletime = 0;                                                                                    
  unsigned long sampletime_halbe = 0;                                                                              
  void (*copy_func)(MainSetupMsgData*, int, SimStruct*);                                                                   
                                                                                                                           
                                                                                                                       
  tx_queue_level = CANMM_CTL_TX_QUEUE_LEVEL(CANMM_CONTROLLER_ID, &ctlsetup_client);                                    
                                                                                                                       
                                                                                                                           
  if (ssGetSampleTime(S, 0) > 0.0) {                                                                                   
    sampletime = (unsigned long) (ssGetSampleTime(S, 0)*1000000);                                                      
    OLD_TIMESTAMP[0] = ts_time_read();                                                                                 
  }                                                                                                                    
  else {                                                                                                               
    if ( ts_time_read() < OLD_TIMESTAMP[0]) {                                                                          
      sampletime = (unsigned long) (ts_time_read()*1000000+0.5);                                                       
      OLD_TIMESTAMP[0] = 0.0;                                                                                          
    }                                                                                                                  
    else {                                                                                                             
      sampletime = (unsigned long) ((ts_time_read()-OLD_TIMESTAMP[0])*1000000+0.5);                                    
      OLD_TIMESTAMP[0] = ts_time_read();                                                                               
    }                                                                                                                  
  }                                                                                                                    
                                                                                                                       
  sampletime_halbe = sampletime/2;                                                                                     
  noMsgFormatTime += sampletime;                                                                                       
  noMsgFormatTimeDiff = noMsgFormatTime/1000000.0;                                                                     
                                                                                                                           
  mbActive = CAN_GLOBAL_ENABLE && (CANMM_CTL_VARIATION(CANMM_CONTROLLER_ID) == 1);                                        
                                                                                                                           
  if (mbActive != LastActiveState) {                                                                                       
    if(mbActive == 1) {                                                                                                    
      CANMM_CTL_RX_START(CANMM_CONTROLLER_ID, &ctlsetup_client);                                                           
    }                                                                                                                      
    else {                                                                                                                 
      CANMM_CTL_RX_STOP(CANMM_CONTROLLER_ID, &ctlsetup_client);                                                            
    }                                                                                                                      
  }                                                                                                                        
                                                                                                                           
  LastActiveState = mbActive;                                                                                              
                                                                                                                           
  if (lastGlobalTxActive == 1 && GlobalTxActive == 0) {                                                                
    clearTxQueue(S);                                                                                                   
  }                                                                                                                    
                                                                                                                       
  lastGlobalTxActive = GlobalTxActive;                                                                                 
  GlobalTxActive = 0;                                                                                                  
                                                                                                                       
  if (mbActive) {                                                                                                          
    CAN_VAR_TRAFFIC = 0;                                                                                                   
                                                                                                                           
    /* Reset RX status */                                                                                          
    for (ite = 0; ite < NUM_RX_MSG; ite++)                                                                         
      RX_STATUS[ite] = 0;                                                                                          
                                                                                                                   
    /* Reset TX status */                                                                                          
    for (ite = 0; ite < NUM_TX_MSG; ite++)                                                                         
      TX_STATUS[ite] = 0;                                                                                          
                                                                                                                   
                                                                                                                           
    /* Receive all messages */                                                                                             
    while (CANMM_CTL_RX(CANMM_CONTROLLER_ID, &ctlsetup_client, &MsgData.CANMsg)) {                                         
                                                                                                                           
      /* Detect lost messages (not used to count lost messages since not supported by DS4302, DS22xx, ... */               
      if(MsgData.CANMsg.Flags & RTICANMM_FLAG_MSGLOST) {                                                                   
        continue;                                                                                                          
      }                                                                                                                    
      CAN_VAR_TRAFFIC = 1;                                                                                                 
                                                                                                                           
/* Convert timestamp from HW time to model(current) time */                                                                
#if defined(RTICANMM_HAVE_RTK)                                                                                             
      MsgData.CANMsg.TimeStamp = rtk_dsts_time_to_simtime_convert(MsgData.CANMsg.TimeStamp);                               
      if (MsgData.CANMsg.TimeStamp == 0.0) continue;                                                                       
#elif defined(RTICANMM_HAVE_DSRT)                                                                                          
      MsgData.CANMsg.TimeStamp = CANMM_DsConvertToSimTime(MsgData.CANMsg.TimeStamp);                                       
      if (MsgData.CANMsg.TimeStamp == 0.0) continue;                                                                       
#endif                                                                                                                     
                                                                                                                           
                                                                                                                           
#if RTICANMM_LOGLEVEL > 3                                                                                                  
      if(!MsgData.CANMsg.Loopback) {                                                                                       
        msg_info_printf(MSG_SM_CANNEDY, RTICANMM_MAINSFCN_RX_LOOPBACK_INFO,                                                
                        RTICANMM_MAINSFCN_RX_LOOPBACK_INFO_TXT, "CAN_Ams",                                                      
                        MsgData.CANMsg.Id,                                                                                 
                        MsgData.CANMsg.TimeStamp,                                                                          
                        MsgData.CANMsg.Dlc,                                                                                
                        MsgData.CANMsg.Data[0]);                                                                           
      }                                                                                                                    
      else {                                                                                                               
        msg_info_printf(MSG_SM_CANNEDY, RTICANMM_MAINSFCN_RX_MSG_INFO, RTICANMM_MAINSFCN_RX_MSG_INFO_TXT, "CAN_Ams",            
                        MsgData.CANMsg.Id,                                                                                 
                        MsgData.CANMsg.TimeStamp,                                                                          
                        MsgData.CANMsg.Dlc,                                                                                
                        MsgData.CANMsg.Data[0]);                                                                           
      }                                                                                                                    
#endif                                                                                                                     
                                                                                                                           
                                                                                                                           
      if(MsgData.CANMsg.Loopback) {                                                                                            
        CAN_NUM_LOST -= 1;                                                                                                 
      }                                                                                                                    
                                                                                                                           
      idIdx = -1;                                                                                                  
      idIdx = find_ID_number(S, &MsgData.CANMsg);                                                              
                                                                                                                   
      if (idIdx != -1) {                                                                                           
        /* For all messages delta time and status: */                                                                  
        CANMMCAN_Ams_RXt[idIdx] = MsgData.CANMsg.TimeStamp;                   
        if (MsgData.CANMsg.Loopback) {                          
          CANMMCAN_Ams_RXdt[idIdx] = CANMMCAN_Ams_RXt[idIdx] - TX_OLDTIME[idIdx];            
          TX_OLDTIME[idIdx] = CANMMCAN_Ams_RXt[idIdx];                        
          CANMMCAN_Ams_RXsta[idIdx] = 1;                                    
        }                                                       
        else {                                                  
          CANMMCAN_Ams_RXdt[idIdx] = CANMMCAN_Ams_RXt[idIdx] - RX_OLDTIME[idIdx];            
          RX_OLDTIME[idIdx] = CANMMCAN_Ams_RXt[idIdx];                        
          CANMMCAN_Ams_RXsta[idIdx] = 1;                                        
        }                                                       
                                                                    
        MsgData.pData = MsgData.CANMsg.Data;                        
        copy_func = (void (*)(MainSetupMsgData *, int, SimStruct*)) IDPtr_R(idIdx);  /* get copy function */       
        copy_func(&MsgData, RX, S);  /* copy and convert RAW Data to TRC variables */                              
  }                                                                                                                
    } /* while RX */                                                                                                   
                                                                                                                       
#include "RTICANMM_MAIN_CAN_Ams_TX_INPUT.h"                                                                                                          
                                                                                                                       
    /* Send TX Data */                                                                                                 
    /* Check for changes in tx enable list */                                                                          
    if (CAN_GLOBAL_ENABLE_TX && (CANMM_CTL_TX_STATUS(CANMM_CONTROLLER_ID) == 1)) {                                     
       GlobalTxActive = 1;                                                                                             
      for (i = 0; i < NUM_TX_MSG; i++) {                                                                               
                                                                                                                       
        if (TX_KICKOUT(i) > TX_KO_OLD[i]) {                                                                        
                                                                                                                       
            if (CAN_ENABLE(i)) {                                                                                       
              TX_QUEUE(i).id = ID_Table_RX(ID_Table_TX(i));  /* Add message direct to sending queue */                 
              TX_QUEUE(i).kickout = 1;      /* Set kickout flag */                                                     
              CAN_SENDBYKICKOUT[i] = 1;     /* Remember message has been triggered by kickout */                       
            }                                                                                                          
        }                                                                                                              
        TX_KO_OLD[i] = TX_KICKOUT(i);                                                                              
        if (TX_KICKOUT_CHECK_INTERN_EXTERN[i]) {                                                                   
          TX_KICKOUT_INTERN_EXTERN[i] = 0;                                                                         
        }                                                                                                          
        else {                                                                                                     
          TX_KICKOUT_INTERN[i] = 0;                                                                                
        }                                                                                                          
}                                                                                                                      
      for (i = 0; i < NUM_TX_MSG; i++) {                                                                                   
                                                                                                                           
/* Set status of message (if message could basically be sent) -------------------------- */                                
        if (CAN_ENABLE(i)) {                                                                                           
            CAN_WOULDBESENT[i] = 1;                                                                                        
        }                                                                                                                  
        else {                                                                                                             
            CAN_WOULDBESENT[i] = 0;                                                                                        
        }                                                                                                                  
                                                                                                                           
     {                                                                                                                  
        /* Update prospective tx time stamps for this sample step */                                                                          
        unsigned long old_time = TX_TIMESTAMP[i];                                                                          
        TX_TIMESTAMP[i] = TX_TIMESTAMP[i] + sampletime;                                                                    
                                                                                                                           
        /* Check for arithmetic overflow */                                                                                
        if (TX_TIMESTAMP[i] < old_time)  {                                                                                 
          TX_TIMESTAMP[i] = 0xffffffff - OLD_TX_TIMESTAMP[i] + TX_TIMESTAMP[i];                                            
          OLD_TX_TIMESTAMP[i] = 0;                                                                                         
        }                                                                                                                  
                                                                                                                           
        /* Prevent arithmetic overflow */                                                                                
        if (TX_TIMESTAMP[i] > 0xf0000000) {                                                                                
          TX_TIMESTAMP[i] = TX_TIMESTAMP[i] - OLD_TX_TIMESTAMP[i];                                                         
          OLD_TX_TIMESTAMP[i] = 0;                                                                                         
        }                                                                                                                  
     }                                                                                                                  
                                                                                                                           
                                                                                                                           
                                                                                                                           
                                                                                                                           
        cycletime = (unsigned long) (TX_CYCLETIME[i]*1000000);                                                         
        if  (cycletime > 0) {                                                                                              
          if ((OLD_TX_TIMESTAMP[i] + cycletime) <= (TX_TIMESTAMP[i] + (sampletime_halbe))) {                               
                                                                                                                           
            if (CAN_CYCLIC(i) && CAN_ENABLE(i)) {                                                                          
              TX_QUEUE(i).id = ID_Table_RX(ID_Table_TX(i));  /* add message direct to sending queue */                     
              TX_QUEUE(i).kickout = 0;  /* remove kickout flag */                                                          
              TX_CYCL_OLD[i] = 1;                                                                                          
                                                                                                                           
            }                                                                                                          
            else {                                                                                                     
              TX_CYCL_OLD[i] = 0;                                                                                      
            }                                                                                                          
            OLD_TX_TIMESTAMP[i] = TX_TIMESTAMP[i];                                                                 
          }                                                                                                                
        }                                                                                                                  
                                                                                                                           
      }                                                                                                                    
                                                                                                                       
      /* Send the first MAX_TX_PERSTEP queue entries: */                                                               
      j = 0;                                                                                                           
      i = 0;                                                                                                           
      if (CANMMCAN_Ams_MAXMSGPERSTEP < 1) {                                                                                                    
          if (MAX_TX_PERSTEP < 1) {                                                                                    
            CANMMCAN_Ams_MAXMSGPERSTEP = 1;                                                                                                    
          }                                                                                                            
          else {                                                                                                       
            CANMMCAN_Ams_MAXMSGPERSTEP = MAX_TX_PERSTEP;                                                                                       
          }                                                                                                            
      }                                                                                                                
                                                                                                                       
      do { /* while ((i < NUM_TX_MSG) && (j < (CANMMCAN_Ams_MAXMSGPERSTEP-(Int32)tx_queue_level)) && (j < CANMM_CTL_TX_QUEUE_SIZE(CANMM_CONTROLLER_ID))) */           
        UInt32 ID_number = TX_QUEUE(i).id;                                                                                 
        if (ID_number != NOCANID) {                                                                                      
          UInt8 TxMsgSent = 0;                                                                                             
                                                                                                                           
#if RTICANMM_LOGLEVEL > 3                                                                                                  
          msg_info_printf(MSG_SM_CANNEDY, RTICANMM_MAINSFCN_TX_MSG_INFO, RTICANMM_MAINSFCN_TX_MSG_INFO_TXT, "CAN_Ams",  ID_number);
#endif                                                                                                                     
                                                                                                                           
          switch (CANMMCAN_Ams_RXMT[ID_Table_TX(i)]) {                                                                                    
            case RTICANMM_MESSAGE_TYPE_STD:                                                                                
            case RTICANMM_MESSAGE_TYPE_EXT:                                                                                
              MsgData.pData = MsgData.CANMsg.Data;                                                                         
              copy_func = (void (*)(MainSetupMsgData *, int, SimStruct*)) IDPtr_T(i);                                      
              copy_func(&MsgData, TX, S);    /* Encode/Pack signals to Msg.-RAW Data */                                    
              MsgData.CANMsg.Id = ID_number;                                                                               
              CANMM_CTL_TX(CANMM_CONTROLLER_ID, &ctlsetup_client, &MsgData.CANMsg);                                        
              TxMsgSent = 1;                                                                                           
              break;                                                                                                       
            default:                                                                                                                      
              TxMsgSent = 1;                                                                                                          
              if(noMsgFormatTimeDiff >= (1.0*noMsgFormatTimePeriod)) {                                                                
                noMsgFormatTime = 0;                                                                                                  
                msg_info_printf(MSG_SM_CANNEDY, RTICANMM_MAINSFCN_TX_MSG_INFO, "Unsupported frame type shall not be transmitted.");   
              }                                                                                                                       
              break;                                                                                                   
          }                                                                                                            
          if (TxMsgSent == 1) {                                                                                        
            CAN_NUM_LOST += 1;                                                                                         
                                                                                                                       
            CAN_SENDBYKICKOUT[i] = 0;                                                                                  
            TX_QUEUE(i).id = NOCANID; /* Delete entry from sending queue */                                            
            j++;                                                                                                   
          }                                                                                                                
        } /* ID_number != NOCANID */                                                                                       
        i++;                                                                                                               
      } while ((i < NUM_TX_MSG) && (j < DPMEM_SIZE) && (j < (CANMMCAN_Ams_MAXMSGPERSTEP-(Int32)tx_queue_level)) && (j < CANMM_CTL_TX_QUEUE_SIZE(CANMM_CONTROLLER_ID)));       
    }                                                                                                                  
    else { /* CAN_GLOBAL_ENABLE_TX */                                                                                  
      for (i = 0; i < NUM_TX_MSG; i++) {                                                                               
        CAN_WOULDBESENT[i] = 0;                                                                                        
      }                                                                                                                
    } /* CAN_GLOBAL_ENABLE_TX */                                                                                       
                                                                                                                       
#include "RTICANMM_MAIN_CAN_Ams_RX_OUTPUT.h"                                                                                                          
                                                                                                                       
  } /* CAN_GLOBAL_ENABLE && CAN_VAR_ENABLE */                                                                              
  else {                                                                                                               
    for (i = 0; i < NUM_TX_MSG; i++){                                                                                  
      CAN_WOULDBESENT[i] = 0;                                                                                          
    }                                                                                                                  
  } /* if (CAN_GLOBAL_ENABLE && CAN_VAR_ENABLE) */                                                                     
#endif /* NOT MATLAB_MEX_FILE || CANMM_HOST_DEBUG */                                                                 
                                                                                                                           
} /* static void mdlOutputs(SimStruct *S, int_T tid) */                                                                    
                                                                                                                           
#define MDL_UPDATE  /* Change to #undef to remove function */                                                              
#if defined(MDL_UPDATE)                                                                                                    
/* Function: mdlUpdate ======================================================                                              
 */                                                                                                                        
static void mdlUpdate(SimStruct *S, int_T tid)                                                                             
{                                                                                                                          
}/* static void mdlUpdate(SimStruct *S, int_T tid) */                                                                      
#endif /* MDL_UPDATE */                                                                                                    
                                                                                                                           
                                                                                                                           
                                                                                                                           
#define MDL_DERIVATIVES  /* Change to #undef to remove function */                                                         
#if defined(MDL_DERIVATIVES)                                                                                               
/* Function: mdlDerivatives =================================================                                              
 */                                                                                                                        
static void mdlDerivatives(SimStruct *S)                                                                                   
{                                                                                                                          
}                                                                                                                          
#endif /* MDL_DERIVATIVES */                                                                                               
                                                                                                                           
                                                                                                                           
                                                                                                                           
/* Function: mdlTerminate =====================================================                                            
 */                                                                                                                        
static void mdlTerminate(SimStruct *S)                                                                                     
{                                                                                                                          
    void** PWork = ssGetPWork(S);                  /* For all PWorks */                                                    
    if (memAllocatedStart || memAllocatedInitCond)                                                                         
    {                                                                                                                      
        memAllocatedStart = 0;                                                                                             
        memAllocatedInitCond = 0;                                                                                          
        if (TX_TIMESTAMP_Ptr != NULL)                                                                                      
        {                                                                                                                  
            free(TX_TIMESTAMP_Ptr);                                                                                        
            TX_TIMESTAMP_Ptr = NULL;                                                                                       
        }                                                                                                                  
        if (OLD_TX_TIMESTAMP_Ptr != NULL)                                                                                  
        {                                                                                                                  
            free(OLD_TX_TIMESTAMP_Ptr);                                                                                    
            OLD_TX_TIMESTAMP_Ptr = NULL;                                                                                   
        }                                                                                                                  
        if (TX_QUEUE_MEM != NULL)                                                                                          
        {                                                                                                                  
            free(TX_QUEUE_MEM);                                                                                            
            TX_QUEUE_MEM = NULL;                                                                                           
        }                                                                                                                  
        if (TX_KO_OLD_Ptr != NULL)                                                                                         
        {                                                                                                                  
            free(TX_KO_OLD_Ptr);                                                                                           
            TX_KO_OLD_Ptr = NULL;                                                                                          
        }                                                                                                                  
        if (TX_CYCL_OLD_Ptr != NULL)                                                                                       
        {                                                                                                                  
            free(TX_CYCL_OLD_Ptr);                                                                                         
            TX_CYCL_OLD_Ptr = NULL;                                                                                        
        }                                                                                                                  
        if (IDPTR_MEM_R != NULL)                                                                                           
        {                                                                                                                  
            free(IDPTR_MEM_R);                                                                                             
            IDPTR_MEM_R = NULL;                                                                                            
        }                                                                                                                  
        if (IDPTR_MEM_T != NULL)                                                                                           
        {                                                                                                                  
            free(IDPTR_MEM_T);                                                                                             
            IDPTR_MEM_T = NULL;                                                                                            
        }                                                                                                                  
        if (TX_COUNTER_Ptr != NULL)                                                                                        
        {                                                                                                                  
            free(TX_COUNTER_Ptr);                                                                                          
            TX_COUNTER_Ptr = NULL;                                                                                         
        }                                                                                                                  
        if (RX_OLDTIME_Ptr != NULL)                                                                                        
        {                                                                                                                  
            free(RX_OLDTIME_Ptr);                                                                                          
            RX_OLDTIME_Ptr = NULL;                                                                                         
        }                                                                                                                  
        if (TX_OLDTIME_Ptr != NULL)                                                                                        
        {                                                                                                                  
            free(TX_OLDTIME_Ptr);                                                                                          
            TX_OLDTIME_Ptr = NULL;                                                                                         
        }                                                                                                                  
        if (OLD_TIMESTAMP_Ptr != NULL)                                                                                     
        {                                                                                                                  
            free(OLD_TIMESTAMP_Ptr);                                                                                       
            OLD_TIMESTAMP_Ptr = NULL;                                                                                      
        }                                                                                                                  
    }                                                                                                                      
                                                                                                                           
#if !defined(MATLAB_MEX_FILE) || defined(CANMM_HOST_DEBUG)                                                                 
    CANMM_CTL_RX_STOP(CANMM_CONTROLLER_ID, &ctlsetup_client);                                                              
#endif /* NOT MATLAB_MEX_FILE || CANMM_HOST_DEBUG */                                                                       
}                                                                                                                          
                                                                                                                           
#if defined(MATLAB_MEX_FILE)   /* Is this file being compiled as a MEX-file? */                                            
    #include "simulink.c"      /* MEX-file interface mechanism */                                                          
#else                                                                                                                      
    #include "cg_sfun.h"       /* Code generation registration function */                                                 
#endif                                                                                                                     
