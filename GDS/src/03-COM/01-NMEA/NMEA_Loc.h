/* ====================================== */
/* Definition for mono-inclusion          */
/* ====================================== */
#ifndef __nmea_loc_h__
#define __nmea_loc_h__

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Macros                                                                 */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#define u8ID_LENGTH      ((uint8)0x06)
#define u8LINE_LENGTH    ((uint8)100)
#define u8LAT_LENGTH     ((uint8)0x08)
#define u8LAT_INDEX      ((uint8)16)
#define u8LON_INDEX      ((uint8)26)
#define u8LON_LENGTH     ((uint8)0x09)
#define u8CR             ((uint8)0x0D)
#define u8TIME_INDEX     ((uint8)7)
#define u8TIME_LENGTH    ((uint8)6) 
#define u8DATE_INDEX     ((uint8)49)
#define u8DATE_LENGTH    ((uint8)6) 
#define u8LF             ((uint8)0x0A)

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Typedef                                                                 */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Location */
typedef struct
{
    /* Location */
    uint8 u8ALatitude[u8LAT_LENGTH];
    uint8 u8ALongitude[u8LON_LENGTH];   
} NMEA_tstrLocation;

/* Timestamp */
typedef struct
{
    /* Time Stamp */
    uint8 u8AHour[2];
    uint8 u8AMinute[2];
    uint8 u8ASecond[2];
    uint8 u8ADate[2];
    uint8 u8AMonth[2];
    uint8 u8AYear[2];
   
} NMEA_tstrTimestamp;

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Declaration of local module variables                                   */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* Identifier for extracting the GPS and Time info */
static const uint8 u8Identifier[u8ID_LENGTH] = "$GPRMC";

/* One Single EMEA Received String */
static uint8 u8ARxString[u8LINE_LENGTH];

/* Current Index where data is written in the Received String */
static uint8 u8Index;

/* Time Stamp received from EMEA Device */
static NMEA_tstrTimestamp strNMEA_Timestamp;

/* Location received from EMEA Device */
static NMEA_tstrLocation strNMEA_Location;

/* if Time stamp received at least once  */
static boolean bTSReceived;

/* if location received at least once  */
static boolean bLocReceived;

/* if the start of the line is detected  */
static boolean bSoLDetected;
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* EOF         :  nmea_loc.h                                                */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

#endif