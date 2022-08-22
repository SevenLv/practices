/*
 * pra_types_def.h
 * created on Wed Aug 17 2022
 * created by Seven Lv
 * comments: macro definitions of types
 */

#ifndef INC_PRA_TYPES_DEF_H_
#define INC_PRA_TYPES_DEF_H_

/* includes */
#include "pra_boolean.h"
#include "stdint.h"

/* macros */

/* for boolean type */

#define BOOLEAN pra_boolean /* definition of boolean type */
#define BOOLEAN_UNKNOWN \
    PRA_BOOL_UNKNOWN         /* definition of unknown boolean value */
#define TRUE PRA_BOOL_TRUE   /* definition of true value */
#define FALSE PRA_BOOL_FALSE /* definition of false value */

#define BOOLEAN_IS_TRUE(value) pra_boolean_is_true(value)
#define BOOLEAN_NOT(value) pra_boolean_not(value)
#define BOOLEAN_AND(value1, value2) pra_boolean_and(value1, value2)
#define BOOLEAN_OR(value1, value2) pra_boolean_or(value1, value2)
#define BOOLEAN_XOR(value1, value2) pra_boolean_xor(value1, value2)

/* for integer type */

#define UINT8 uint8_t
#define INT8 int8_t
#define UINT16 u_int16_t
#define INT16 int16_t
#define UINT32 uint32_t
#define INT32 int32_t
#define UINT64 uint64_t
#define INT64 int64_t

/* types */

/* variables */

/* functions */

#endif