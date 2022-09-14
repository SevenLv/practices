/*
 * pra_fifo_types.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    type definitions of pra_fifo
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

#ifndef INC_PRA_FIFO_TYPES_H_
#define INC_PRA_FIFO_TYPES_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_defs.h"
#include "stdint.h"


/* macros */
#define PRA_FIFO_NULL PRA_NULL_PTR(pra_fifo)

/* types */

/* fifo struct */
typedef struct _pra_fifo
{
    pra_boolean initialized; /* initialized flag */
    uint8_t    *p_data;      /* data pointer */
    uint16_t    data_length; /* data length */
    uint16_t    used_length; /* used data length */
    uint16_t    next_r_pos;  /* next read position */
    uint16_t    next_w_pos;  /* next write position */
} pra_fifo;

/* variables */

/* functions */

#endif