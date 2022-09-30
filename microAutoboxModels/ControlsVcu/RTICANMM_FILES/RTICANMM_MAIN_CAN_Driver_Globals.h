/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Driver_Globals */
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

#undef DEBUG              
#undef IDMANIPULATION
#define WITHOUT_DELAY
#undef NO_TX         
#define KICKOUT_ACTIVE               
#define NOCANID  0xEFFFFFFF
#define S_FUNCTION_NAME                           RTICANMM_MAIN_CAN_Driver
#define S_FUNCTION_LEVEL 2
#include "simstruc.h"
#include <math.h>
                                                       
#if !defined(MATLAB_MEX_FILE) || defined(CANMM_HOST_DEBUG)                                                            
# include "dsRTICANMMGlobals.h"
#endif /* NOT MATLAB_MEX_FILE || CANMM_HOST_DEBUG */                                                                  
                                                       
                                                       
                                                       
#define NUM_TX_INPUT                              15
#define NUM_TX_MSG                                3
#define NUM_RX_OUTPUT                             20
#define NUM_RX_MSG                                5
#define NUM_RX                                    35
#define NUM_TX                                    15
/* #define TX_PORT_DATA_TYPES                     "RTICANMM_MAIN_CAN_Driver_TX_PORT.h" */
/* #define RX_PORT_DATA_TYPES                     "RTICANMM_MAIN_CAN_Driver_RX_PORT.h" */
/* #define TX_WRITE_PORT_DATA                     "RTICANMM_MAIN_CAN_Driver_TX_INPUT.h" */
/* #define RX_WRITE_PORT_DATA                     "RTICANMM_MAIN_CAN_Driver_RX_OUTPUT.h" */
                                                       
                                                       
#if !defined(MATLAB_MEX_FILE) || defined(CANMM_HOST_DEBUG)                                                            
struct MainSetupMsgData {                              
  CanMM_Msg CANMsg;                                    
  UInt8 PaddingData[4];                                
  UInt8* pData;         /* Pointer to DLC data bytes */
  double DeltaTime;                                    
  double DelayTime;                                    
  double CycleTime;                                    
  UInt8  Status;                                       
  UInt32 TXCounter;                                    
  UInt32 RXCounter;                                    
  double HwTime;                                       
  UInt8  MsgType;                                      
};                                                     
typedef struct MainSetupMsgData MainSetupMsgData;      
                                                       
enum CanMM_MsgTypes {                      
   RTICANMM_MESSAGE_TYPE_STD,              
   RTICANMM_MESSAGE_TYPE_EXT,              
   RTICANMM_MESSAGE_TYPE_J1939,            
   RTICANMM_MESSAGE_TYPE_FD_STD,           
   RTICANMM_MESSAGE_TYPE_FD_EXT            
};                                         
typedef enum CanMM_MsgTypes CanMM_MsgTypes;
                                           
#undef CAN_J1939
#undef WITHOUT_LOOPBACKSTATUS

     /* Include CRC and CustomCode here */
/* #define CAN_BASEUPDATE_FILE                    "RTICANMM_MAIN_CAN_Driver_BASEUPDATE.h" */
#undef BASEUPDATE_ACTIVE                          
/* #define CAN_DEFS_FILE                          "RTICANMM_MAIN_CAN_Driver_DEFS.h" */
/* #define CAN_MSG_DATA_FILE                      "RTICANMM_MAIN_CAN_Driver_MSG_DATA.h" */
/* #define CAN_ID_TABLE_FILE                      "RTICANMM_MAIN_CAN_Driver_ID_TABLE.h" */
#define CAN_GLOBAL_ENABLE_TX                      CANMMCAN_Driver_TXGE
#define CAN_GLOBAL_ENABLE                         CANMMCAN_Driver_GE
#define CAN_VAR_ENABLE                            CANMM_CTL_SETUP_Driver_ID
#define CAN_VAR_TRAFFIC                           CANMMCAN_Driver_TRAFFIC
#define CANMM_RESET2DEFAULTS                      CANMMCAN_Driver_RE
#define CAN_SENDBYKICKOUT                         CANMMCAN_Driver_BYKICK
#define CAN_ENABLE                                CANMMCAN_Driver_TXEN
#define CAN_WOULDBESENT                           CANMMCAN_Driver_WBS
#define CAN_ENABLE_TIMEOUT                        CANMMCAN_Driver_TXTOUT
#define CAN_CYCLIC                                CANMMCAN_Driver_TXC
#define CAN_RX_DATA                               CANMMCAN_Driver_RX
#define CAN_TX_DATA                               CANMMCAN_Driver_TX
#define CAN_NUM_LOST                              CANMMCAN_Driver_NL
#define CAN_NUM_LOST_RESET                        CANMMCAN_Driver_NLR
#define rticanmmsaturation(value, maximum, minimum)((value >= maximum)? maximum : ((value <= minimum)? minimum : value))
#define rticanmmmaxsat(value, maximum, minimum)   ((value >= maximum)? maximum : value)
/* #define CAN_SIGNAL_HEADERFILE                  "RTICANMM_MAIN_CAN_Driver_SIGNAL_DEFAULTS.h" */
/* #define CAN_MESSAGE_HEADERFILE                 "RTICANMM_MAIN_CAN_Driver_MESSAGE_DEFAULTS.h" */
#define ENABLE_PORT                               0
#undef ONLYCAPTURE                                
#define TX_LOOPBACK                               1
#define TX_CYCLETIME                              CANMMCAN_Driver_TXCT
#define TX_DELAYTIME                              CANMMCAN_Driver_TXDT
#define TX_KICKOUT                                CANMMCAN_Driver_TXKOUT
#define TX_KICKOUT_INTERN                         CANMMCAN_Driver_TXKIN
#define TX_KICKOUT_INTERN_EXTERN                  CANMMCAN_Driver_TXKIEX
#define TX_KICKOUT_CHECK_INTERN_EXTERN            CANMMCAN_Driver_TXKIEXC
#define RX_STATUS                                 CANMMCAN_Driver_RXsta
#define TX_STATUS                                 CANMMCAN_Driver_TXsta
#define TX_MESSAGES_EXIST                         1
#undef USE_CAPTURE                                
#define CANMM_Q_NUM                               1

#if (RTICANMM_FEEDTHROUGH_CHECK)        
static const void * GetInputPortSignal(SimStruct *S, int port_num);
static int CheckDirectFeedThroughInputPort(SimStruct *S, int port_num);
#else                                                              
#define GetInputPortSignal ssGetInputPortSignal                    
#endif //RTICANMM_FEEDTHROUGH_CHECK                                
#endif /* NOT MATLAB_MEX_FILE || CANMM_HOST_DEBUG */               
                                                                   
