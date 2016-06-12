#ifndef TYPES_H
#define TYPES_H

#include "Limits.h"

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
/* !Comment : Defines a boolean 1 bits                                        */
/* !Range   : 0 (FALSE), 1(TRUE)                                              */
typedef unsigned char        boolean;

/* !Comment : Defines an signed 8 bits                                        */
/* !Range   : -128..127                                                       */
typedef signed   char       sint8;
/* !Comment : Defines an unsigned 8 bits                                      */
/* !Range   : 0..255                                                          */
typedef unsigned char       uint8;

/* !Comment : Defines a signed 16 bits                                        */
/* !Range   : -32768..32767                                                   */
typedef signed   short      sint16; 
/* !Comment : Defines an unsigned 16 bits                                     */
/* !Range   : 0..65535                                                        */
typedef unsigned short      uint16;

/* !Comment : Defines a signed 32 bits                                        */
/* !Range   : -2147483648..2147483647                                         */
typedef signed   long       sint32;
/* !Comment : Defines an unsigned 32 bits                                     */
/* !Range   : 0..4294967295                                                   */
typedef unsigned long       uint32;

/* !Comment : Defines an signed 8 bits (minimum range)                        */
/* !Range   : -128..127                                                       */
typedef signed   char      sint8_least;  
/* !Comment : Defines an unsigned 8 bits (minimum range)                      */
/* !Range   : 0..255                                                          */
typedef unsigned char       uint8_least;  

/* !Comment : Defines a signed 16 bits (minimum range)                        */
/* !Range   : -32768..32767                                                   */
typedef signed   short      sint16_least; 
/* !Comment : Defines an unsigned 16 bits (minimum range)                     */
/* !Range   : 0..65535                                                        */
typedef unsigned short      uint16_least; 

/* !Comment : Defines a signed 32 bits (minimum range)                        */
/* !Range   : -2147483648..2147483647                                         */
typedef signed   long       sint32_least; 
/* !Comment : Defines an unsigned 32 bits (minimum range)                     */
/* !Range   : 0..4294967295                                                   */
typedef unsigned long       uint32_least; 

/* !Comment : Defines a float number of 32 bits                               */
typedef float               float32;
/* !Comment : Defines a float number of 64 bits                               */
typedef double              float64;

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/* !Comment: TRUE Value for boolean type                                      */
#ifndef TRUE 
  #define TRUE   ((boolean) 1)
#endif

/* !Comment: FALSE Value for boolean type                                     */
#ifndef FALSE 
  #define FALSE  ((boolean) 0)
#endif

/* !Comment: SAFE_TRUE Value for boolean type                                      */
#ifndef SAFE_TRUE 
  #define SAFE_TRUE   ((boolean) 0xAA)
#endif

/* !Comment: SAFE_FALSE Value for boolean type                                     */
#ifndef SAFE_FALSE 
  #define SAFE_FALSE  ((boolean) 0xF0)
#endif
#endif /* TYPES_H */