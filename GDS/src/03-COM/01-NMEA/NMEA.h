/* +++++++++++++++++++++++++++++ */
/* Definition for mono-inclusion */
/* +++++++++++++++++++++++++++++ */
#ifndef __nmea_h
#define __nmea_h

#include "Types.h"
#include "RTC/RTC.h"

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Declaration of exported functions                                       */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
extern void NMEA_Init (void);
extern void NMEA_Handler (void);
extern boolean NMEA_GetTimeStamp (NMEA_tstrTimestamp *strNMEA_TS);
extern boolean NMEA_GetLocation (NMEA_tstrLocation *strNMEA_Loc);

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Declaration of internal module definitions                              */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#ifdef __nmea_c
#include "NMEA_Loc.h"
#endif

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* EOF         :  nmea.h                                                   */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif