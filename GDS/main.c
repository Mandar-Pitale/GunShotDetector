#define __main_c

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Common and module include-file                                          */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* Common */
#include "Types.h"

#include "NMEA/NMEA.h"

/* Module Own Include */
#include "Main.h"
#include "COM.h"
#include "RTC.h"
#include "GDC.h"
#include "GPT.h"
#include "NMEA.h"
#include "UART.h"
#include "SND.h"
#include "ADC.h"
#include "TIME.h"
#include "DIO.h"
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Function Calls                                                          */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
void MAIN_Init (void)
{
    // Initialize all the modules
    COM_Init();
    RTC_Init();
    GDC_Init();
    WDG_Init();
    GPT_Init();
    NMEA_Init();
    UART_Init();
    SND_Init();
    ADC_Init()
    TIME_Init();
    DIO_Init();
}

void MAIN_Handler (void)
{
    // Call  all the handlers
    COM_Handler();
    RTC_Handler();
    GDC_Handler();
    NMEA_Handler();
    SND_Handler();
}
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* EOF         :  main.c                                                */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
