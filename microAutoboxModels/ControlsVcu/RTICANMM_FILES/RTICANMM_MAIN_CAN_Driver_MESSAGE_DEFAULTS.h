/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Driver_MESSAGE_DEFAULTS */
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

CANMMCAN_Driver_MAXMSGPERSTEP = 0;

/* DefaultGlobalEnable */
CANMMCAN_Driver_GEIN = 1;


/* Feedthrough debug variable*/
CANMMCAN_Driver_FTD = 0;
CANMMCAN_Driver_RTVE = 1;


/* CoolingLoopModes */
CANMMCAN_Driver_TXCT[0] = 0; /* TX CycleTime[s] */
CANMMCAN_Driver_TXDT[0] = 0; /* TX DelayTime[s] */
CANMMCAN_Driver_RXdt[2] = 0; /* RX DeltaTime[s] */
CANMMCAN_Driver_RXt[2] = 0.0; /* RX Time[s] */
CANMMCAN_Driver_RXerr[2] = 0; /* RX Error */
CANMMCAN_Driver_RXLEN[2] = 2; /* RX Message Length */


/* CoolingLoopsData */
CANMMCAN_Driver_RXCT2 = 0; /* RX CycleTime[s] */
CANMMCAN_Driver_RXdt[1] = 0; /* RX DeltaTime[s] */
CANMMCAN_Driver_RXt[1] = 0.0; /* RX Time[s] */
CANMMCAN_Driver_RXerr[1] = 0; /* RX Error */
CANMMCAN_Driver_RXLEN[1] = 7; /* RX Message Length */


/* PedalPositions */
CANMMCAN_Driver_RXCT3 = 0; /* RX CycleTime[s] */
CANMMCAN_Driver_RXdt[0] = 0; /* RX DeltaTime[s] */
CANMMCAN_Driver_RXt[0] = 0.0; /* RX Time[s] */
CANMMCAN_Driver_RXerr[0] = 0; /* RX Error */
CANMMCAN_Driver_RXLEN[0] = 7; /* RX Message Length */


/* TemperatureInfo */
CANMMCAN_Driver_TXCT[1] = 0; /* TX CycleTime[s] */
CANMMCAN_Driver_TXDT[1] = 0; /* TX DelayTime[s] */
CANMMCAN_Driver_RXdt[3] = 0; /* RX DeltaTime[s] */
CANMMCAN_Driver_RXt[3] = 0.0; /* RX Time[s] */
CANMMCAN_Driver_RXerr[3] = 0; /* RX Error */
CANMMCAN_Driver_RXLEN[3] = 5; /* RX Message Length */


/* VehicleInfo */
CANMMCAN_Driver_TXCT[2] = 0; /* TX CycleTime[s] */
CANMMCAN_Driver_TXDT[2] = 0; /* TX DelayTime[s] */
CANMMCAN_Driver_RXdt[4] = 0; /* RX DeltaTime[s] */
CANMMCAN_Driver_RXt[4] = 0.0; /* RX Time[s] */
CANMMCAN_Driver_RXerr[4] = 0; /* RX Error */
CANMMCAN_Driver_RXLEN[4] = 5; /* RX Message Length */


/* DefaultGlobalEnable TX */
CANMMCAN_Driver_TXGEIN = 1;


/* ECU ENABLE */
/* VCU*/
CANMMCAN_Driver_TXEEIE[0] = 1;
CANMMCAN_Driver_TXEEIEOLD[0] = 1;




/* ------------------------------------------------------------------------------ */
/* Message Defaults: */


/* CoolingLoopModes */
CANMMCAN_Driver_WBS[0] = 0; /* Would be sent */
CANMMCAN_Driver_TXEIN[0] = 1; /* DefaultEnable */
CANMMCAN_Driver_TXENIE[0] = 1; /* DefaultEnable */
CANMMCAN_Driver_TXCIN[0] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Driver_TXCIE[0] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Driver_TXKIEXC[0] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_Driver_TXLEN[0] = 2; /* Message length */
CANMMCAN_Driver_TXRBUF[0] = 0; /* internal -> do not change */
CANMMCAN_Driver_TXRXBUF[0] = 0; /* internal -> do not change */
CANMMCAN_Driver_TXusrm[0] = 1;
CANMMCAN_Driver_TXcraw[0] = 0; /* 0: SIGNALS 1:RAWDATA */


/* TemperatureInfo */
CANMMCAN_Driver_WBS[1] = 0; /* Would be sent */
CANMMCAN_Driver_TXEIN[1] = 1; /* DefaultEnable */
CANMMCAN_Driver_TXENIE[1] = 1; /* DefaultEnable */
CANMMCAN_Driver_TXCIN[1] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Driver_TXCIE[1] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Driver_TXKIEXC[1] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_Driver_TXLEN[1] = 5; /* Message length */
CANMMCAN_Driver_TXRBUF[1] = 0; /* internal -> do not change */
CANMMCAN_Driver_TXRXBUF[1] = 0; /* internal -> do not change */
CANMMCAN_Driver_TXusrm[1] = 1;
CANMMCAN_Driver_TXcraw[1] = 0; /* 0: SIGNALS 1:RAWDATA */


/* VehicleInfo */
CANMMCAN_Driver_WBS[2] = 0; /* Would be sent */
CANMMCAN_Driver_TXEIN[2] = 1; /* DefaultEnable */
CANMMCAN_Driver_TXENIE[2] = 1; /* DefaultEnable */
CANMMCAN_Driver_TXCIN[2] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Driver_TXCIE[2] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Driver_TXKIEXC[2] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_Driver_TXLEN[2] = 5; /* Message length */
CANMMCAN_Driver_TXRBUF[2] = 0; /* internal -> do not change */
CANMMCAN_Driver_TXRXBUF[2] = 0; /* internal -> do not change */
CANMMCAN_Driver_TXusrm[2] = 1;
CANMMCAN_Driver_TXcraw[2] = 0; /* 0: SIGNALS 1:RAWDATA */

