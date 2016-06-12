/* ====================================== */
/* Definition for mono-inclusion          */
/* ====================================== */
#ifndef __rtc_loc_h__
#define __rtc_loc_h__

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Typedef                                                                 */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Timestamp */
typedef struct
{
    /* Time Stamp */
    uint8 u8Hour;
    uint8 u8Minute;
    uint8 u8Second;
    uint8 u8Date;
    uint8 u8Month;
    uint8 u8Year;
   
} RTC_tstrTimestamp;

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Declaration of local module variables                                   */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* Variable for time calculation */
static RTC_tstrTimestamp strRTC_Timestamp;
static boolean bTSCalculated;
static uint32 u32RTC_1SCnt;
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* EOF         :  rtc_loc.h                                                */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

#endif