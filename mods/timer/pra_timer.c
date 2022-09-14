/*
 * pra_timer.c
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    functions of pra_timer
 * version: 0.2
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 *          0.2     Wed Sep 14 2022     modify pra_timer_execute function to use pra_timer_increase function
 *                                      add pra_timer_is_done function
 *                                      add pra_timer_stop function
 *                                      add pra_timer_init function
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

pra_boolean pra_timer_init(
    pra_timer *const p_timer,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_timer_init_args_check(
                             p_timer,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_timer->actived = PRA_BOOL_UNKNOWN;
        p_timer->interval = PRA_NUM_ZERO_U;
        p_timer->start_time = PRA_TIME_MIN;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_timer_execute(void)
{
    pra_boolean result;

    result = pra_timer_increase(
        &current_time,
        PRA_TIME_STEP);

    return result;
}

pra_boolean pra_timer_start(
    pra_timer *const p_timer,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_timer_start_args_check(
                             p_timer,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_timer->start_time = current_time;
        p_timer->actived = PRA_BOOL_TRUE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_timer_is_done(
    const pra_timer *const p_timer,
    pra_boolean *const     p_done,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_timer_is_done_args_check(
                             p_timer,
                             p_done,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint32_t expected_time = p_timer->start_time;
        result = pra_timer_increase(
            &expected_time,
            p_timer->interval);

        if (PRA_BOOL_TRUE != result)
        {
            *p_ec |= PRA_TIMER_EC_CALCULATION_FAILED;
        }
        else
        {
            if (expected_time <= current_time)
            {
                *p_done = PRA_BOOL_TRUE;
            }
            else
            {
                *p_done = PRA_BOOL_FALSE;
            }
        }
    }

    return result;
}

pra_boolean pra_timer_stop(
    pra_timer *const p_timer,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_timer_stop_args_check(
                             p_timer,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_timer->actived = PRA_BOOL_FALSE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}
