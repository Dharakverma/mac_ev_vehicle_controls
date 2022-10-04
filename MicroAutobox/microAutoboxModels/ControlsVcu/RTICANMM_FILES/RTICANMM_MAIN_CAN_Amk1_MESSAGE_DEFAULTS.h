/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Amk1_MESSAGE_DEFAULTS */
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

CANMMCAN_Amk1_MAXMSGPERSTEP = 0;

/* DefaultGlobalEnable */
CANMMCAN_Amk1_GEIN = 1;


/* Feedthrough debug variable*/
CANMMCAN_Amk1_FTD = 0;
CANMMCAN_Amk1_RTVE = 1;


/* AMK0_ActualValues1 */
CANMMCAN_Amk1_RXCT1 = 0; /* RX CycleTime[s] */
CANMMCAN_Amk1_RXdt[2] = 0; /* RX DeltaTime[s] */
CANMMCAN_Amk1_RXt[2] = 0.0; /* RX Time[s] */
CANMMCAN_Amk1_RXerr[2] = 0; /* RX Error */
CANMMCAN_Amk1_RXLEN[2] = 8; /* RX Message Length */


/* AMK0_ActualValues2 */
CANMMCAN_Amk1_RXCT2 = 0; /* RX CycleTime[s] */
CANMMCAN_Amk1_RXdt[4] = 0; /* RX DeltaTime[s] */
CANMMCAN_Amk1_RXt[4] = 0.0; /* RX Time[s] */
CANMMCAN_Amk1_RXerr[4] = 0; /* RX Error */
CANMMCAN_Amk1_RXLEN[4] = 8; /* RX Message Length */


/* AMK0_SetPoints1 */
CANMMCAN_Amk1_TXCT[0] = 0; /* TX CycleTime[s] */
CANMMCAN_Amk1_TXDT[0] = 0; /* TX DelayTime[s] */
CANMMCAN_Amk1_RXdt[0] = 0; /* RX DeltaTime[s] */
CANMMCAN_Amk1_RXt[0] = 0.0; /* RX Time[s] */
CANMMCAN_Amk1_RXerr[0] = 0; /* RX Error */
CANMMCAN_Amk1_RXLEN[0] = 8; /* RX Message Length */


/* AMK1_ActualValues1 */
CANMMCAN_Amk1_RXCT4 = 0; /* RX CycleTime[s] */
CANMMCAN_Amk1_RXdt[3] = 0; /* RX DeltaTime[s] */
CANMMCAN_Amk1_RXt[3] = 0.0; /* RX Time[s] */
CANMMCAN_Amk1_RXerr[3] = 0; /* RX Error */
CANMMCAN_Amk1_RXLEN[3] = 8; /* RX Message Length */


/* AMK1_ActualValues2 */
CANMMCAN_Amk1_RXCT5 = 0; /* RX CycleTime[s] */
CANMMCAN_Amk1_RXdt[5] = 0; /* RX DeltaTime[s] */
CANMMCAN_Amk1_RXt[5] = 0.0; /* RX Time[s] */
CANMMCAN_Amk1_RXerr[5] = 0; /* RX Error */
CANMMCAN_Amk1_RXLEN[5] = 8; /* RX Message Length */


/* AMK1_SetPoints1 */
CANMMCAN_Amk1_TXCT[1] = 0; /* TX CycleTime[s] */
CANMMCAN_Amk1_TXDT[1] = 0; /* TX DelayTime[s] */
CANMMCAN_Amk1_RXdt[1] = 0; /* RX DeltaTime[s] */
CANMMCAN_Amk1_RXt[1] = 0.0; /* RX Time[s] */
CANMMCAN_Amk1_RXerr[1] = 0; /* RX Error */
CANMMCAN_Amk1_RXLEN[1] = 8; /* RX Message Length */


/* DefaultGlobalEnable TX */
CANMMCAN_Amk1_TXGEIN = 1;


/* ECU ENABLE */
/* VCU_02*/
CANMMCAN_Amk1_TXEEIE[0] = 1;
CANMMCAN_Amk1_TXEEIEOLD[0] = 1;




/* ------------------------------------------------------------------------------ */
/* Message Defaults: */


/* AMK0_SetPoints1 */
CANMMCAN_Amk1_WBS[0] = 0; /* Would be sent */
CANMMCAN_Amk1_TXEIN[0] = 1; /* DefaultEnable */
CANMMCAN_Amk1_TXENIE[0] = 1; /* DefaultEnable */
CANMMCAN_Amk1_TXCIN[0] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Amk1_TXCIE[0] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Amk1_TXKIEXC[0] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_Amk1_TXLEN[0] = 8; /* Message length */
CANMMCAN_Amk1_TXRBUF[0] = 0; /* internal -> do not change */
CANMMCAN_Amk1_TXRXBUF[0] = 0; /* internal -> do not change */
CANMMCAN_Amk1_TXusrm[0] = 1;
CANMMCAN_Amk1_TXcraw[0] = 0; /* 0: SIGNALS 1:RAWDATA */


/* AMK1_SetPoints1 */
CANMMCAN_Amk1_WBS[1] = 0; /* Would be sent */
CANMMCAN_Amk1_TXEIN[1] = 1; /* DefaultEnable */
CANMMCAN_Amk1_TXENIE[1] = 1; /* DefaultEnable */
CANMMCAN_Amk1_TXCIN[1] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Amk1_TXCIE[1] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Amk1_TXKIEXC[1] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_Amk1_TXLEN[1] = 8; /* Message length */
CANMMCAN_Amk1_TXRBUF[1] = 0; /* internal -> do not change */
CANMMCAN_Amk1_TXRXBUF[1] = 0; /* internal -> do not change */
CANMMCAN_Amk1_TXusrm[1] = 1;
CANMMCAN_Amk1_TXcraw[1] = 0; /* 0: SIGNALS 1:RAWDATA */

