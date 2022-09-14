/*
 * pra_lifo_types.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    type definitions of pra_lifo
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

#ifndef INC_PRA_LIFO_TYPES_H_
#define INC_PRA_LIFO_TYPES_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_defs.h"
#include "stdint.h"


/* macros */
#define PRA_LIFO_NULL PRA_NULL_PTR(pra_lifo)

/* types */

/* lifo struct */
typedef struct _pra_lifo
{
    pra_boolean initialized; /* initialized flag */
    uint8_t    *p_data;      /* data pointer */
    uint16_t    data_length; /* data length */
    uint16_t    used_length; /* used data length */
    uint16_t    next_r_pos;  /* next read position */
    uint16_t    next_w_pos;  /* next write position */
} pra_lifo;

/* variables */

/* functions */

#endif