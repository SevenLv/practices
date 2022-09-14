/*
 * pra_boolean_types.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    type definitions of pra_bits
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

#ifndef INC_PRA_BOOLEAN_TYPES_H_
#define INC_PRA_BOOLEAN_TYPES_H_

/* includes */
#include "pra_defs.h"

/* macros */

#define PRA_BOOL_NULL ((pra_boolean *)0)

/* types */

/* the boolean enum type */
typedef enum _pra_boolean
{
    PRA_BOOL_UNKNOWN = 0x00, /* the unknown value of pra_boolean type */
    PRA_BOOL_TRUE = 0x55,    /* the true value of pra_boolean */
    PRA_BOOL_FALSE = 0xAA,   /* the false value of pra_boolean */
} pra_boolean;

/* variables */

/* functions */

#endif