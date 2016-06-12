#define __rtc_c

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Common and module include-file                                          */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* Common */
#include "Types.h"

#include "NMEA/NMEA.h"

/* Module Own Include */
#include "RTC.h"

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Function Calls                                                          */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
void RTC_Init (void)
{
    // Initialize the timestamp 
    strRTC_Timestamp.u8Hour = (uint8) 0x00;
    strRTC_Timestamp.u8Minute = (uint8) 0x00;
    strRTC_Timestamp.u8Second = (uint16) 0x00;
    strRTC_Timestamp.u8Date = (uint8) 0x01;
    strRTC_Timestamp.u8Month = (uint8) 0x01;
    strRTC_Timestamp.u8Year = (uint8) 15;
    
    // No TimeStamp is calculated yet
    bTSCalculated = FALSE;
    
    // Clear the one second count
    u32RTC_1SCnt = UINT32_MIN;
}

void RTC_Handler (void)
{
    strNMEA_Timestamp strLoc_Timestamp;
    
    bRetVal = FALSE;
    
    // Check if the Time stamp is calulated at least once
    if (bTSCalculated == FALSE)
    {
        //Gets the time stamp from the NMEA module.
        bRetVal = NMEA_GetTimeStamp(&strLoc_Timestamp);
        
        if (bRetVal == TRUE)
        {
            // Time stamp is calculated
            bTSCalculated = TRUE;
            
            // Convert the time stamp from string to hex values
            RTC_ConvertTimeStamp (&strLoc_Timestamp);
            
            // Do the RTC Calculation
            RTC_CalculateRTC();
        }
            
    }
    else
    {
        // Do the RTC Calculation
        RTC_CalculateRTC();
        
    }
}

static void RTC_ConvertTimeStamp (strNMEA_Timestamp *strNMEA_Timestamp)
{
    // Convert from string to hex
    strRTC_Timestamp.u8Hour = 10 * (strNMEA_Timestamp->u8AHour[0] - '0');
    strRTC_Timestamp.u8Hour += strNMEA_Timestamp->u8AHour[1] - '0';
    
    strRTC_Timestamp.u8Minute = 10 * (strNMEA_Timestamp->u8AMinute[0] - '0');
    strRTC_Timestamp.u8Minute += strNMEA_Timestamp->u8AMinute[1] - '0';
    
    strRTC_Timestamp.u8Second = 10 * (strNMEA_Timestamp->u8ASecond[0] - '0');
    strRTC_Timestamp.u8Second += strNMEA_Timestamp->u8Second[1] - '0';
    
    strRTC_Timestamp.u8Date = 10 * (strNMEA_Timestamp->u8ADate[0] - '0');
    strRTC_Timestamp.u8Date += strNMEA_Timestamp->u8ADate[1] - '0';
    
    strRTC_Timestamp.u8Month = 10 * (strNMEA_Timestamp->u8AMonth[0] - '0');
    strRTC_Timestamp.u8Month += strNMEA_Timestamp->u8AMonth[1] - '0'
    
    strRTC_Timestamp.u8Year = 10 * (strNMEA_Timestamp->u8AYear[0] - '0');
    strRTC_Timestamp.u8Year += strNMEA_Timestamp->u8AYear[1] - '0'
}

static void RTC_CalculateRTC (void)
{
    uint32 u32TimeTick;
    uint32 u32Increment;
    uint32 u32Index;
    
    // Get the time tick
    u32TimeTick = TIME_GetOneSecondTick();
    
    // Check if increment is necessary
    if ( u32RTC_1SCnt < u32TimeTick)
    {
        // Compute the difference
        u32Increment = u32TimeTick - u32RTC_1SCnt:
        
        for (u32Index = UINT32_MIN; u32Index < u32Increment; u32Index++)
        {
            // Increment seconds 
            strRTC_Timestamp.u8Second++;
            
            if (strRTC_Timestamp.u8Second == 60) 
            {
                strRTC_Timestamp.u8Minute++; 
                strRTC_Timestamp.u8Second=0; 
                
                if (strRTC_Timestamp.u8Minute == 60) 
                {
                    strRTC_Timestamp.u8Hour++; 
                    strRTC_Timestamp.u8Minute=0; 
      
                    if (strRTC_Timestamp.u8Hour == 24) 
                    {
                        strRTC_Timestamp.u8Date++; 
                        strRTC_Timestamp.u8Hour=0;
                        
                        // February in leap year
                        if (   (strRTC_Timestamp.u8Date == 29 && strRTC_Timestamp.u8Month==2 && !(strRTC_Timestamp.u8Year%4))          
                            || (strRTC_Timestamp.u8Date == 30 && strRTC_Timestamp.u8Month==2 )                                         // February in normal years 
                            || (strRTC_Timestamp.u8Date == 31 && (strRTC_Timestamp.u8Month==4 || strRTC_Timestamp.u8Month==6 || strRTC_Timestamp.u8Month==9 || strRTC_Timestamp.u8Month==11 ))  // All months with 30 days 
                            || (strRTC_Timestamp.u8Date == 32) )                                                   // All months with 31 days 
                        {
                            strRTC_Timestamp.u8Month++; 
                            strRTC_Timestamp.u8Date =1;
                        } 
                            
                        if (strRTC_Timestamp.u8Month == 13) 
                        {
                            strRTC_Timestamp.u8Year++; 
                            strRTC_Timestamp.u8Month=1;
                        } 
                    }
                }
            } 
        }
    }
    
    // Equate the second counts
    u32RTC_1SCnt = u32TimeTick;
}

boolean RTC_GetRTC (RTC_tstrTimestamp *strRTC_TS)
{
    boolean bRetVal = FALSE;
    
    // Do the input parameter validation
    if (strRTC_TS == NULL)
    {
        // Return false as the data cant be copied
        return bRetVal;
    }
           
    // Is timestamp calculated at leaast once;
    if (bTSCalculated == TRUE)
    {
        // Yes, then return TRUE;
        bRetVal = TRUE;        
    } 
    else
    {
        return bRetVal;
    }
    
    // Copy the data
    *strRTC_TSstr = strRTC_Timestamp;
    
    return bRetVal;
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* EOF         :  rtc.c                                                */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
