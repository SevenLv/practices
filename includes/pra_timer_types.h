/*
 * pra_timer_types.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    type definitions of pra_timer
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

#ifndef INC_PRA_TIMER_TYPES_H_
#define INC_PRA_TIMER_TYPES_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_defs.h"
#include "stdint.h"

/* macros */

#define PRA_TIMER_NULL PRA_NULL_PTR(pra_timer)

/* types */

/* pra_timer struct */
typedef struct _pra_timer
{
    pra_boolean actived;    /* the timer is actived or not */
    uint32_t    start_time; /* the start time of the timer */
    uint32_t    interval;   /* target interval time */
} pra_timer;

/* variables */

/* functions */

#endif