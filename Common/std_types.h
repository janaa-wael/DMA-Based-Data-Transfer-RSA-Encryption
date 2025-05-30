 /******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: std_types.h
 *
 * Description: types for ARM Cortex M4F
 *
 * Author: Edges Team
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

#define NULL_PTR    ((void*)0)

typedef unsigned char         u8;          /*           0 .. 255              */
typedef signed char           s8;          /*        -128 .. +127             */
typedef unsigned short        u16;         /*           0 .. 65535            */
typedef signed short          s16;         /*      -32768 .. +32767           */
typedef unsigned long         u32;         /*           0 .. 4294967295       */
typedef signed long           s32;         /* -2147483648 .. +2147483647      */
typedef unsigned long long    u64;         /*       0 .. 18446744073709551615  */
typedef signed long long      s64;         /* -9223372036854775808 .. 9223372036854775807 */
typedef float                 f32;
typedef double                f64;

/* Boolean Data Type */
typedef u8 boolean;

#endif /* STD_TYPE_H_ */
