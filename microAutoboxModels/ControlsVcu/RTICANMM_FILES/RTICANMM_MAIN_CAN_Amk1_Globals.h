/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Amk1_Globals */
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
#define S_FUNCTION_NAME                           RTICANMM_MAIN_CAN_Amk1
#define S_FUNCTION_LEVEL 2
#include "simstruc.h"
#include <math.h>
                                                       
#if !defined(MATLAB_MEX_FILE) || defined(CANMM_HOST_DEBUG)                                                            
# include "dsRTICANMMGlobals.h"
#endif /* NOT MATLAB_MEX_FILE || CANMM_HOST_DEBUG */                                                                  
                                                       
                                                       
                                                       
#define NUM_TX_INPUT                              20
#define NUM_TX_MSG                                2
#define NUM_RX_OUTPUT                             30
#define NUM_RX_MSG                                6
#define NUM_RX                                    44
#define NUM_TX                                    14
/* #define TX_PORT_DATA_TYPES                     "RTICANMM_MAIN_CAN_Amk1_TX_PORT.h" */
/* #define RX_PORT_DATA_TYPES                     "RTICANMM_MAIN_CAN_Amk1_RX_PORT.h" */
/* #define TX_WRITE_PORT_DATA                     "RTICANMM_MAIN_CAN_Amk1_TX_INPUT.h" */
/* #define RX_WRITE_PORT_DATA                     "RTICANMM_MAIN_CAN_Amk1_RX_OUTPUT.h" */
                                                       
                                                       
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
/* #define CAN_BASEUPDATE_FILE                    "RTICANMM_MAIN_CAN_Amk1_BASEUPDATE.h" */
#undef BASEUPDATE_ACTIVE                          
/* #define CAN_DEFS_FILE                          "RTICANMM_MAIN_CAN_Amk1_DEFS.h" */
/* #define CAN_MSG_DATA_FILE                      "RTICANMM_MAIN_CAN_Amk1_MSG_DATA.h" */
/* #define CAN_ID_TABLE_FILE                      "RTICANMM_MAIN_CAN_Amk1_ID_TABLE.h" */
#define CAN_GLOBAL_ENABLE_TX                      CANMMCAN_Amk1_TXGE
#define CAN_GLOBAL_ENABLE                         CANMMCAN_Amk1_GE
#define CAN_VAR_ENABLE                            CANMM_CTL_SETUP_Amk1_ID
#define CAN_VAR_TRAFFIC                           CANMMCAN_Amk1_TRAFFIC
#define CANMM_RESET2DEFAULTS                      CANMMCAN_Amk1_RE
#define CAN_SENDBYKICKOUT                         CANMMCAN_Amk1_BYKICK
#define CAN_ENABLE                                CANMMCAN_Amk1_TXEN
#define CAN_WOULDBESENT                           CANMMCAN_Amk1_WBS
#define CAN_ENABLE_TIMEOUT                        CANMMCAN_Amk1_TXTOUT
#define CAN_CYCLIC                                CANMMCAN_Amk1_TXC
#define CAN_RX_DATA                               CANMMCAN_Amk1_RX
#define CAN_TX_DATA                               CANMMCAN_Amk1_TX
#define CAN_NUM_LOST                              CANMMCAN_Amk1_NL
#define CAN_NUM_LOST_RESET                        CANMMCAN_Amk1_NLR
#define rticanmmsaturation(value, maximum, minimum)((value >= maximum)? maximum : ((value <= minimum)? minimum : value))
#define rticanmmmaxsat(value, maximum, minimum)   ((value >= maximum)? maximum : value)
/* #define CAN_SIGNAL_HEADERFILE                  "RTICANMM_MAIN_CAN_Amk1_SIGNAL_DEFAULTS.h" */
/* #define CAN_MESSAGE_HEADERFILE                 "RTICANMM_MAIN_CAN_Amk1_MESSAGE_DEFAULTS.h" */
#define ENABLE_PORT                               0
#undef ONLYCAPTURE                                
#define TX_LOOPBACK                               1
#define TX_CYCLETIME                              CANMMCAN_Amk1_TXCT
#define TX_DELAYTIME                              CANMMCAN_Amk1_TXDT
#define TX_KICKOUT                                CANMMCAN_Amk1_TXKOUT
#define TX_KICKOUT_INTERN                         CANMMCAN_Amk1_TXKIN
#define TX_KICKOUT_INTERN_EXTERN                  CANMMCAN_Amk1_TXKIEX
#define TX_KICKOUT_CHECK_INTERN_EXTERN            CANMMCAN_Amk1_TXKIEXC
#define RX_STATUS                                 CANMMCAN_Amk1_RXsta
#define TX_STATUS                                 CANMMCAN_Amk1_TXsta
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
                                                                   
