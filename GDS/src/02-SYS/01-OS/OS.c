#define __os_c

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Common and module include-file                                          */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#include "OS.h"

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Declaration of local module macros                                      */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* Value that indicates the execution of a new slice */
#define  OS_NEW_SLICE            0x55U

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Declaration of local module variables                                   */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* Indicator for the execution of a new slice */
static volatile uint8 OS_u8NewSlice;

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Function Calls                                                          */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
void OS_Main(void)
{
   /* Initialize this module */
   OS_Init();
   
   /* Initialize all other modules */
   MAIN_Init();

   /* Start the systems timer */
   OS_TIMER_ENA();
   
   /* Enable global interrupts */
   __enable_interrupt();
   
   /* +++++++++++++++++++++++ */
   /* Start working from here */
   /* +++++++++++++++++++++++ */
   
   /* Do this forever */
   for(;;)
   {
      /* A new slice starts */
      if (OS_u8NewSlice == OS_NEW_SLICE)
      {
         /* Reset */
         OS_u8NewSlice = UINT8_MIN;

         /* Execute all common functions */
         MAIN_Handler();
      } 
      
   } /* while(TRUE) */
}

static void OS_Init(void)
{
   /* After initialization, the 1st time slice will be started by */
   /* the timer to avoid synchronization problems.                */
   OS_u8NewSlice = UINT8_MIN;

   /* initialise HW timer */
   OS_TIMER_INIT ();
}

__interrupt void OS_Timer(void)
{
   /* Reset the timer */
   OS_TIMER_RESET();

   /* Indicate that a new slice can start */
   OS_u8NewSlice = OS_NEW_SLICE;
}
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* EOF         :  syst.c                                                   */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
