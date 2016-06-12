#define __nmea_c

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Common and module include-file                                          */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* Common */
#include "Types.h"
#include "mem.h"

/* Module Own Include */
#include "NMEA.h"

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Function Calls                                                          */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
void NMEA_Init (void)
{
    /* One Single EMEA Received String */
    u8ARxString[u8LINE_LENGTH];

    /* Current Index where data is written in the Received String */
    u8Index = UINT8_MIN;

    /* Time Stamp received from EMEA Device */
    (void )memset((void *)strNMEA_Timestamp, UINT8_MIN, (sizeof)strNMEA_Timestamp);

    /* Location received from EMEA Device */
    (void )memset((void *)strNMEA_Location, UINT8_MIN, (sizeof)strNMEA_Location);

    /* if Time stamp received at least once  */
    bTSReceived = FALSE;

    /* if location received at least once  */
    bLocReceived = FALSE;

    /* if the start of the line is detected  */
    bSoLDetected = FALSE;
}

/*
 * Example. $GPRMC,225446,A,4916.45,N,12311.12,W,000.5,054.7,191194,020.3,E*68


           225446       Time of fix 22:54:46 UTC
           A            Navigation receiver warning A = OK, V = warning
           4916.45,N    Latitude 49 deg. 16.45 min North
           12311.12,W   Longitude 123 deg. 11.12 min West
           000.5        Speed over ground, Knots
           054.7        Course Made Good, True
           191194       Date of fix  19 November 1994
           020.3,E      Magnetic variation 20.3 deg East
           *68          mandatory checksum
*/
void NMEA_Handler (void)
{
    boolean bNoMatch = FALSE;
    uint8 u8ReadChar;
    uint8 u8LocIndex = UINT8_MIN;
    uint8 u8LocLatLonIdx;
    uint8 u8LocDateTimeIdx;
    uint8 u8PtrDateTimeStamp;
    uint8 u8Length;
    
    // Check if new character is received
    while ( TRUE ==  UART_Read(&u8ReadChar) )
    {
        // Check if the we are at the end of Line 
        if ( u8Index < u8LINE_LENGTH)
        {
            // Check if start of line detected
            if ( bSoLDetected == TRUE)
            {
                //Copy the data
                u8ARxString [u8Index] = u8ReadChar;
                u8Index++;

                // Check if the LF is encountered?
                if ( u8ReadChar == u8LF)
                {
                    //Store the total length
                    u8Length = u8Index - 2;
                    
                    // Wrap Around
                    u8Index = UINT8_MIN;
            
                    // Start with the new line
                    u8SOLDetected = FALSE;
                    
                    // Its already Line Feed, process all the data
                    for ( u8LocIndex = UINT8_MIN; u8LocIndex < u8ID_LENGTH; u8LocIndex++)
                    {
                        if ( u8ARxString[u8LocIndex] != u8Identifier[u8LocIndex])
                        {   
                            bNoMatch = TRUE;
                            
                            // Come out of the loop as there is no match
                            break;
                        }
                    }
                    
                    // Check if the required string is found
                    if (bNoMatch != TRUE)
                    {
                        // Process further 
                        bCSResult = bEnsureCheckSum (u8ARxString, u8Length);
                        
                        // Check if the checksum is correct
                        if (bCSResult == TRUE)
                        {
                            // Go to the correct index
                            u8LocLatLonIdx = u8LAT_INDEX;
                            
                            // Store the latitude
                            for ( u8LocIndex = UINT8_MIN; u8LocIndex < u8LAT_LENGTH; u8LocIndex++)
                            {
                                u8ALatitude[u8LocIndex] = u8ARxString[u8LocLatLonIdx];
                                u8LocLatLonIdx++;
                            }   
                            
                            // Go to the correct index
                            u8LocLatLonIdx = u8LON_INDEX;
                            
                            // Store the Longitude
                            for ( u8LocIndex = UINT8_MIN; u8LocIndex < u8LON_LENGTH; u8LocIndex++)
                            {
                                u8ALongitude[u8LocIndex] = u8ARxString[u8LocLatLonIdx];
                                u8LocLatLonIdx++;
                            }   
                            
                            // Mark that location is received
                            bLocReceived = TRUE;
                            
                            // Go to the correct index
                            u8LocDateTimeIdx = u8TIME_INDEX;
                            u8PtrDateTimeStamp = (uint8*)(&strNMEA_Timestamp);
                            
                            // Store the time stamp
                            for ( u8LocIndex = UINT8_MIN; u8LocIndex < u8TIME_LENGTH; u8LocIndex++)
                            {
                                u8PtrDateTimeStamp[u8LocIndex] = u8ARxString[u8LocDateTimeIdx];
                                u8LocDateTimeIdx++;
                            }
                            
                              // Go to the correct index
                            u8LocDateTimeIdx = u8DATE_INDEX;
                            u8PtrDateTimeStamp = (uint8*)(&strNMEA_Timestamp.u8ADate);
                            
                            // Store the time stamp
                            for ( u8LocIndex = UINT8_MIN; u8LocIndex < u8DATE_LENGTH; u8LocIndex++)
                            {
                                u8PtrDateTimeStamp[u8LocIndex] = u8ARxString[u8LocDateTimeIdx];
                                u8LocDateTimeIdx++;
                            }

                            // Mark that timrstamp is received
                            bTSReceived = TRUE;   
                        }
                        else
                        {
                            // Checksum is wrong, ignore the string
                        }
                    }
                    else
                    {
                        // The required string is not found, ignore the string
                    }
                }
                else
                {
                    //LF not encountered yet, Wait till detecting end of the line
                }
                
            }
            // Is Start of line detected
            else if (u8ReadChar == '$')
            {
                // Mark the start of new line is detected
                bSoLDetected = TRUE;
                
                //Copy the data
                u8ARxString [u8Index] = u8ReadChar;
                u8Index++;
                
                // No more processing is required as its just start of line
            }
            else 
            {
                //No Need to copy the data as '$' is not detected yetS
            }
           
        }
        else
        {
            // This cant happen as the length is bigger than the actual length. Wrap Around
            u8Index = UINT8_MIN;
            
            u8SOLDetected = FALSE;
        }
    }
}

boolean NMEA_GetTimeStamp (NMEA_tstrTimestamp *strNMEA_TS)
{
    // Input parameter validation
    if (strNMEA_TS == NULL)
    {
        return FALSE;
    }
    
    // Check if timestamp is received
    if (bTSReceived)
    {
        // Copy the time stamp
        (void) memcpy((void *)strNMEA_TS, (const void *)strNMEA_Timestamp, (uint8)((sizeof)strNMEA_Timestamp));
        
    }
    return bTSReceived;
}

boolean NMEA_GetLocation (NMEA_tstrLocation *strNMEA_Loc)
{
    boolean bRetVal = bLocReceived;
    
    // Input parameter validation
    if (strNMEA_Loc == NULL)
    {
        return FALSE;
    }
    
    // Check if Location is received
    if (bLocReceived)
    {
        // Copy the location
        (void) memcpy((void *)strNMEA_Loc, (const void *)strNMEA_Location, (uint8)((sizeof)strNMEA_Location));
        
    }
    
    //Set the Location Received to False until the next location is received
    bLocReceived = FALSE;
    
    return bRetVal;
}

boolean bEnsureCheckSum (uint8 *u8String, uint8 u8Length)
{
    boolean bCSResult = FALSE;
    uint8 u8LocIdx;
    uint8 u8ChecksumCalc = UINT8_MIN;
    uint8 u8ChecksumRecvd = UINT8_MIN;
    
    // Calculate checksum that is based on simple XOR
    for (u8LocIdx = UINT8_MIN; u8LocIdx < u8Length-2)
    {
        u8ChecksumCalc ^= u8String[u8LocIdx];
    }
    
    // Convert from string to hex
    u8ChecksumRecvd = 10 * (u8String[u8Length-2] - '0');
    u8ChecksumRecvd += u8String[u8Length-1] - '0';
    
    if (u8ChecksumRecvd == u8ChecksumCalc)
    {
        bCSResult = TRUE;
    }
    
    return bCSResult;
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* EOF         :  NMEA.c                                                */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */