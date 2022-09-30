/*****************************************************************************************************************************/
/* RTICANMM_MAIN_Inverters_TX_PORT */
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

/* AMK0_SetPoints1.AMK_bInverterOn */ 
ssSetInputPortDataType(S, 0, SS_BOOLEAN); 
ssSetInputPortWidth(S, 0, 1);
/* AMK0_SetPoints1.AMK_bDcOn */ 
ssSetInputPortDataType(S, 1, SS_BOOLEAN); 
ssSetInputPortWidth(S, 1, 1);
/* AMK0_SetPoints1.AMK_bEnable */ 
ssSetInputPortDataType(S, 2, SS_BOOLEAN); 
ssSetInputPortWidth(S, 2, 1);
/* AMK0_SetPoints1.AMK_bErrorReset */ 
ssSetInputPortDataType(S, 3, SS_BOOLEAN); 
ssSetInputPortWidth(S, 3, 1);
/* AMK0_SetPoints1.AMK_TargetVelocity */ 
ssSetInputPortDataType(S, 4, SS_INT16); 
ssSetInputPortWidth(S, 4, 1);
/* AMK0_SetPoints1.AMK_TorqueLimitPositiv */ 
ssSetInputPortDataType(S, 5, SS_INT16); 
ssSetInputPortWidth(S, 5, 1);
/* AMK0_SetPoints1.AMK_TorqueLimitNegativ */ 
ssSetInputPortDataType(S, 6, SS_INT16); 
ssSetInputPortWidth(S, 6, 1);
/* AMK1_SetPoints1.AMK_bInverterOn */ 
ssSetInputPortDataType(S, 7, SS_BOOLEAN); 
ssSetInputPortWidth(S, 7, 1);
/* AMK1_SetPoints1.AMK_bDcOn */ 
ssSetInputPortDataType(S, 8, SS_BOOLEAN); 
ssSetInputPortWidth(S, 8, 1);
/* AMK1_SetPoints1.AMK_bEnable */ 
ssSetInputPortDataType(S, 9, SS_BOOLEAN); 
ssSetInputPortWidth(S, 9, 1);
/* AMK1_SetPoints1.AMK_bErrorReset */ 
ssSetInputPortDataType(S, 10, SS_BOOLEAN); 
ssSetInputPortWidth(S, 10, 1);
/* AMK1_SetPoints1.AMK_TargetVelocity */ 
ssSetInputPortDataType(S, 11, SS_INT16); 
ssSetInputPortWidth(S, 11, 1);
/* AMK1_SetPoints1.AMK_TorqueLimitPositiv */ 
ssSetInputPortDataType(S, 12, SS_INT16); 
ssSetInputPortWidth(S, 12, 1);
/* AMK1_SetPoints1.AMK_TorqueLimitNegativ */ 
ssSetInputPortDataType(S, 13, SS_INT16); 
ssSetInputPortWidth(S, 13, 1);
