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

/* macros */

/* for boolean boolean */

#define BOOLEAN pra_boolean /* definition of boolean type */
#define BOOLEAN_UNKNOWN \
    PRA_BOOL_UNKNOWN         /* definition of unknown boolean value */
#define TRUE PRA_BOOL_TRUE   /* definition of true value */
#define FALSE PRA_BOOL_FALSE /* definition of false value */

#define BOOLEAN_IS_TRUE(value) pra_boolean_is_true(value)
#define BOOLEAN_NOT(value) pra_boolean_not(value)
#define BOOLEAN_AND(value1, value2) pra_boolean_and(value1, value2)
#define BOOLEAN_OR(value1, value2) pra_boolean_or(value1, value2)

/* types */

/* variables */

/* functions */

#endif