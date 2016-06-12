#define __GSD_c

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Common and module include-file                                          */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* Common */
#include "Types.h"

#include "NMEA.h"

/* Module Own Include */
#include "GSD.h"

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Function Calls                                                          */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
void GSD_Init (void)
{
    
}

void GSD_Handler (void)
{
    SND_GetLastShockWave() 
    SND_GetLastMuzzleShot()
    RTC_GetRTC()
    TIME_GetOneSecondTick()
    NMEA_GetLocation()
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* EOF         :  gsd.c                                                */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */