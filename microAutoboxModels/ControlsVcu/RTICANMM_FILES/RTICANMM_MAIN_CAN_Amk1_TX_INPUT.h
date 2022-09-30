/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Amk1_TX_INPUT */
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


/* AMK0_ActualValues1 */

/* AMK0_ActualValues1 */
CANMMCAN_Amk1_RXCT1 = ((real_T*)GetInputPortSignal(S, 0))[0];

/* AMK0_ActualValues2 */

/* AMK0_ActualValues2 */
CANMMCAN_Amk1_RXCT2 = ((real_T*)GetInputPortSignal(S, 1))[0];

/* AMK0_SetPoints1 */

/* AMK0_SetPoints1 */
CANMMCAN_Amk1_TXCT[0] = ((real_T*)GetInputPortSignal(S, 2))[0];

/* AMK1_ActualValues1 */

/* AMK1_ActualValues1 */
CANMMCAN_Amk1_RXCT4 = ((real_T*)GetInputPortSignal(S, 3))[0];

/* AMK1_ActualValues2 */

/* AMK1_ActualValues2 */
CANMMCAN_Amk1_RXCT5 = ((real_T*)GetInputPortSignal(S, 4))[0];

/* AMK1_SetPoints1 */

/* AMK1_SetPoints1 */
CANMMCAN_Amk1_TXCT[1] = ((real_T*)GetInputPortSignal(S, 5))[0];
/* VCU_02 */ 

/* AMK0_SetPoints1 */
CANMMCAN_Amk1_TXENIE[0] =  CANMMCAN_Amk1_TXEIN[0] && (CANMMCAN_Amk1_TXEEIE[0]) && CANMMCAN_Amk1_RTVE;

/* AMK1_SetPoints1 */
CANMMCAN_Amk1_TXENIE[1] =  CANMMCAN_Amk1_TXEIN[1] && (CANMMCAN_Amk1_TXEEIE[0]) && CANMMCAN_Amk1_RTVE;
