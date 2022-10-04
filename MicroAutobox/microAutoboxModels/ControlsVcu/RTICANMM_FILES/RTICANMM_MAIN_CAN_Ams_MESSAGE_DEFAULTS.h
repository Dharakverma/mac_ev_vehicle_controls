/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Ams_MESSAGE_DEFAULTS */
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

CANMMCAN_Ams_MAXMSGPERSTEP = 0;

/* DefaultGlobalEnable */
CANMMCAN_Ams_GEIN = 1;


/* Feedthrough debug variable*/
CANMMCAN_Ams_FTD = 0;
CANMMCAN_Ams_RTVE = 1;


/* ELP_ContactorRequest */
CANMMCAN_Ams_TXCT[0] = 0; /* TX CycleTime[s] */
CANMMCAN_Ams_TXDT[0] = 0; /* TX DelayTime[s] */
CANMMCAN_Ams_RXdt[5] = 0; /* RX DeltaTime[s] */
CANMMCAN_Ams_RXt[5] = 0.0; /* RX Time[s] */
CANMMCAN_Ams_RXerr[5] = 0; /* RX Error */
CANMMCAN_Ams_RXLEN[5] = 1; /* RX Message Length */


/* ELP_CurrentInfo */
CANMMCAN_Ams_RXCT2 = 0; /* RX CycleTime[s] */
CANMMCAN_Ams_RXdt[2] = 0; /* RX DeltaTime[s] */
CANMMCAN_Ams_RXt[2] = 0.0; /* RX Time[s] */
CANMMCAN_Ams_RXerr[2] = 0; /* RX Error */
CANMMCAN_Ams_RXLEN[2] = 6; /* RX Message Length */


/* ELP_SOCInfo */
CANMMCAN_Ams_RXCT3 = 0; /* RX CycleTime[s] */
CANMMCAN_Ams_RXdt[3] = 0; /* RX DeltaTime[s] */
CANMMCAN_Ams_RXt[3] = 0.0; /* RX Time[s] */
CANMMCAN_Ams_RXerr[3] = 0; /* RX Error */
CANMMCAN_Ams_RXLEN[3] = 7; /* RX Message Length */


/* ELP_StateInfo */
CANMMCAN_Ams_RXCT4 = 0; /* RX CycleTime[s] */
CANMMCAN_Ams_RXdt[0] = 0; /* RX DeltaTime[s] */
CANMMCAN_Ams_RXt[0] = 0.0; /* RX Time[s] */
CANMMCAN_Ams_RXerr[0] = 0; /* RX Error */
CANMMCAN_Ams_RXLEN[0] = 7; /* RX Message Length */


/* ELP_TemperatureInfo */
CANMMCAN_Ams_RXCT5 = 0; /* RX CycleTime[s] */
CANMMCAN_Ams_RXdt[4] = 0; /* RX DeltaTime[s] */
CANMMCAN_Ams_RXt[4] = 0.0; /* RX Time[s] */
CANMMCAN_Ams_RXerr[4] = 0; /* RX Error */
CANMMCAN_Ams_RXLEN[4] = 6; /* RX Message Length */


/* ELP_VoltageInfo */
CANMMCAN_Ams_RXCT6 = 0; /* RX CycleTime[s] */
CANMMCAN_Ams_RXdt[1] = 0; /* RX DeltaTime[s] */
CANMMCAN_Ams_RXt[1] = 0.0; /* RX Time[s] */
CANMMCAN_Ams_RXerr[1] = 0; /* RX Error */
CANMMCAN_Ams_RXLEN[1] = 6; /* RX Message Length */


/* DefaultGlobalEnable TX */
CANMMCAN_Ams_TXGEIN = 1;


/* ECU ENABLE */
/* VCU_03*/
CANMMCAN_Ams_TXEEIE[0] = 1;
CANMMCAN_Ams_TXEEIEOLD[0] = 1;




/* ------------------------------------------------------------------------------ */
/* Message Defaults: */


/* ELP_ContactorRequest */
CANMMCAN_Ams_WBS[0] = 0; /* Would be sent */
CANMMCAN_Ams_TXEIN[0] = 1; /* DefaultEnable */
CANMMCAN_Ams_TXENIE[0] = 1; /* DefaultEnable */
CANMMCAN_Ams_TXCIN[0] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Ams_TXCIE[0] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Ams_TXKIEXC[0] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_Ams_TXLEN[0] = 1; /* Message length */
CANMMCAN_Ams_TXRBUF[0] = 0; /* internal -> do not change */
CANMMCAN_Ams_TXRXBUF[0] = 0; /* internal -> do not change */
CANMMCAN_Ams_TXusrm[0] = 1;
CANMMCAN_Ams_TXcraw[0] = 0; /* 0: SIGNALS 1:RAWDATA */

