#ifndef LIMITS_H
#define LIMITS_H


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/* !Comment: Minimum value of a data of type uint8 or uint8_least             */
#define UINT8_MIN    ((uint8) 0)
#define U8LEAST_MIN  ((uint8_least) 0)
/* !Comment: Maximum value of a data of type uint8 or uint8_least             */
#define UINT8_MAX    ((uint8) 255)
#define U8LEAST_MAX  ((uint8_least) 255)

/* !Comment: Minimum value of a data of type sint8 or sint8_least             */
#define SINT8_MIN    ((sint8) -128)
#define S8LEAST_MIN  ((sint8_least) -128)
/* !Comment: Maximum value of a data of type sint8 or sint8_least             */
#define SINT8_MAX    ((sint8) 127)
#define S8LEAST_MAX  ((sint8_least) 127)

/* !Comment: Minimum value of a data of type uint16 or uint16_least           */
#define UINT16_MIN   ((uint16) 0)
#define U16LEAST_MIN ((uint16_least) 0)
/* !Comment: Maximum value of a data of type uint16 or uint16_least           */
#define UINT16_MAX   ((uint16) 65535)
#define U16LEAST_MAX ((uint16_least) 65535)

/* !Comment: Minimum value of a data of type sint16 or sint16_least           */
#define SINT16_MIN   ((sint16) (-32767 - 1))
#define S16LEAST_MIN ((sint16_least) (-32767 - 1))
/* !Comment: Maximum value of a data of type sint16 or sint16_least           */
#define SINT16_MAX   ((sint16) 32767)
#define S16LEAST_MAX ((sint16_least) 32767)

/* !Comment: Minimum value of a data of type uint32                           */
#define UINT32_MIN   ((uint32) 0)
/* !Comment: Maximum value of a data of type uint32                           */
#define UINT32_MAX   ((uint32) 4294967295)

/* !Comment: Minimum value of a data of type sint32                           */
#define SINT32_MIN   ((sint32) (-2147483647 - 1))
/* !Comment: Maximum value of a data of type sint32                           */
#define SINT32_MAX   ((sint32) 2147483647)


#endif /* LIMITS_H */

/*-------------------------------- end of file -------------------------------*/