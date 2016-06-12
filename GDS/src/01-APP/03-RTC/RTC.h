/* +++++++++++++++++++++++++++++ */
/* Definition for mono-inclusion */
/* +++++++++++++++++++++++++++++ */
#ifndef __rtc_h
#define __rtc_h

#include "Types.h"

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Declaration of exported functions                                       */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
extern void RTC_Init (void);
extern void RTC_Handler (void);
extern boolean RTC_GetRTC (RTC_tstrTimestamp *strRTC_TS);

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Declaration of internal module definitions                              */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#ifdef __rtc_c
#include "RTC_Loc.h"
#endif

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* EOF         :  rtc.h                                                    */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif