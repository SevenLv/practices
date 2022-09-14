/*
 * pra_timer_internal.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    internal function definitions of pra_timer
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

#ifndef INC_PRA_TIMER_INTERNAL_H_
#define INC_PRA_TIMER_INTERNAL_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_defs.h"
#include "stdint.h"


/* macros */

#define PRA_TIME_MIN  PRA_NUM_ZERO_U
#define PRA_TIME_MAX  PRA_NUM_MAX_VALUE_U32
#define PRA_TIME_STEP 1U

/* types */

/* variables */

/* functions */

pra_boolean pra_timer_get_time_args_check(
    const uint32_t *const p_time,
    uint32_t *const       p_ec);

#endif