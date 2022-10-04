/*****************************************************************************************************************************/
/* RTICANMM_MAIN_Inverters_MESSAGE_DEFAULTS */
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

CANMMInverters_MAXMSGPERSTEP = 0;

/* DefaultGlobalEnable */
CANMMInverters_GEIN = 1;


/* Feedthrough debug variable*/
CANMMInverters_FTD = 0;
CANMMInverters_RTVE = 1;


/* AMK0_ActualValues1 */
CANMMInverters_RXCT1 = 5.000000e-03; /* RX CycleTime[s] */
CANMMInverters_RXdt[2] = 5.000000e-03; /* RX DeltaTime[s] */
CANMMInverters_RXt[2] = 0.0; /* RX Time[s] */
CANMMInverters_RXerr[2] = 0; /* RX Error */
CANMMInverters_RXLEN[2] = 8; /* RX Message Length */


/* AMK0_ActualValues2 */
CANMMInverters_RXCT2 = 5.000000e-03; /* RX CycleTime[s] */
CANMMInverters_RXdt[4] = 5.000000e-03; /* RX DeltaTime[s] */
CANMMInverters_RXt[4] = 0.0; /* RX Time[s] */
CANMMInverters_RXerr[4] = 0; /* RX Error */
CANMMInverters_RXLEN[4] = 8; /* RX Message Length */


/* AMK0_SetPoints1 */
CANMMInverters_TXCT[0] = 1.000000e-03; /* TX CycleTime[s] */
CANMMInverters_TXDT[0] = 0; /* TX DelayTime[s] */
CANMMInverters_RXdt[0] = 1.000000e-03; /* RX DeltaTime[s] */
CANMMInverters_RXt[0] = 0.0; /* RX Time[s] */
CANMMInverters_RXerr[0] = 0; /* RX Error */
CANMMInverters_RXLEN[0] = 8; /* RX Message Length */


/* AMK1_ActualValues1 */
CANMMInverters_RXCT4 = 5.000000e-03; /* RX CycleTime[s] */
CANMMInverters_RXdt[3] = 5.000000e-03; /* RX DeltaTime[s] */
CANMMInverters_RXt[3] = 0.0; /* RX Time[s] */
CANMMInverters_RXerr[3] = 0; /* RX Error */
CANMMInverters_RXLEN[3] = 8; /* RX Message Length */


/* AMK1_ActualValues2 */
CANMMInverters_RXCT5 = 5.000000e-03; /* RX CycleTime[s] */
CANMMInverters_RXdt[5] = 5.000000e-03; /* RX DeltaTime[s] */
CANMMInverters_RXt[5] = 0.0; /* RX Time[s] */
CANMMInverters_RXerr[5] = 0; /* RX Error */
CANMMInverters_RXLEN[5] = 8; /* RX Message Length */


/* AMK1_SetPoints1 */
CANMMInverters_TXCT[1] = 1.000000e-03; /* TX CycleTime[s] */
CANMMInverters_TXDT[1] = 0; /* TX DelayTime[s] */
CANMMInverters_RXdt[1] = 1.000000e-03; /* RX DeltaTime[s] */
CANMMInverters_RXt[1] = 0.0; /* RX Time[s] */
CANMMInverters_RXerr[1] = 0; /* RX Error */
CANMMInverters_RXLEN[1] = 8; /* RX Message Length */


/* DefaultGlobalEnable TX */
CANMMInverters_TXGEIN = 1;


/* ECU ENABLE */
/* VCU*/
CANMMInverters_TXEEIE[0] = 1;
CANMMInverters_TXEEIEOLD[0] = 1;




/* ------------------------------------------------------------------------------ */
/* Message Defaults: */


/* AMK0_SetPoints1 */
CANMMInverters_WBS[0] = 0; /* Would be sent */
CANMMInverters_TXEIN[0] = 1; /* DefaultEnable */
CANMMInverters_TXENIE[0] = 1; /* DefaultEnable */
CANMMInverters_TXCIN[0] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMInverters_TXCIE[0] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMInverters_TXKIEXC[0] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMInverters_TXLEN[0] = 8; /* Message length */
CANMMInverters_TXRBUF[0] = 0; /* internal -> do not change */
CANMMInverters_TXRXBUF[0] = 0; /* internal -> do not change */
CANMMInverters_TXusrm[0] = 1;
CANMMInverters_TXcraw[0] = 0; /* 0: SIGNALS 1:RAWDATA */


/* AMK1_SetPoints1 */
CANMMInverters_WBS[1] = 0; /* Would be sent */
CANMMInverters_TXEIN[1] = 1; /* DefaultEnable */
CANMMInverters_TXENIE[1] = 1; /* DefaultEnable */
CANMMInverters_TXCIN[1] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMInverters_TXCIE[1] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMInverters_TXKIEXC[1] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMInverters_TXLEN[1] = 8; /* Message length */
CANMMInverters_TXRBUF[1] = 0; /* internal -> do not change */
CANMMInverters_TXRXBUF[1] = 0; /* internal -> do not change */
CANMMInverters_TXusrm[1] = 1;
CANMMInverters_TXcraw[1] = 0; /* 0: SIGNALS 1:RAWDATA */

