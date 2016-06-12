/* +++++++++++++++++++++++++++++ */
/* Definition for mono-inclusion */
/* +++++++++++++++++++++++++++++ */
#ifndef __os_h
#define __os_h

#include "Types.h"

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Declaration of Macros those are dependent on HW                         */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#define OS_TIMER_ENA()
#define __enable_interrupt()
#define OS_TIMER_INIT()    // Initialize the timer to offer 2ms interrupts
#define OS_TIMER_RESET()

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Declaration of exported functions                                       */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
extern void OS_Main (void);
extern boolean RTC_GetRTC (RTC_tstrTimestamp *strRTC_TS);

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Declaration of internal module definitions                              */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* EOF         :  os.h                                                    */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif