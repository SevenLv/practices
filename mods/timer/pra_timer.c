/*
 * pra_timer.c
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    functions of pra_timer
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

/* includes */
#include "pra_num_defs.h"
#include "pra_timer.h"
#include "pra_timer_ec.h"
#include "pra_timer_internal.h"


/* variables */

static uint32_t current_time = PRA_TIME_MIN;

/* functions */

pra_boolean pra_timer_get_time(
    uint32_t *const p_time,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_timer_get_time_args_check(
                             p_time,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        *p_time = current_time;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_timer_execute(void)
{
    pra_boolean result;

    if (PRA_TIME_MAX == current_time)
    {
        current_time = PRA_TIME_MIN;
    }
    else
    {
        current_time += PRA_TIME_STEP;
    }

    return result;
}