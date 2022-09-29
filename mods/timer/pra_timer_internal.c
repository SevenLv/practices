/*
 * pra_timer_internal.c
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    internal functions of pra_timer
 * version: 0.4
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 *          0.2     Wed Sep 14 2022     add pra_timer_is_done_args_check function
 *                                      add pra_timer_increase function
 *                                      add pra_timer_stop_args_check function
 *                                      add pra_timer_init_args_check function
 *          0.3     Fri Sep 23 2022     remove pra_timer_increase function
 *          0.4     Thu Sep 29 2022     reorganize error codes
 */

/* includes */
#include "pra_ec.h"
#include "pra_timer_internal.h"


/* variables */

/* functions */

pra_boolean pra_timer_init_args_check(
    const pra_timer *const p_timer,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_TIMER_NULL == p_timer)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_timer_get_time_args_check(
    const uint32_t *const p_time,
    PRA_EC_T *const       p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT32_NULL == p_time)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_timer_start_args_check(
    const pra_timer *const p_timer,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_TIMER_NULL == p_timer)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_ZERO_U == p_timer->interval)
    {
        *p_ec |= PRA_EC_INVALID_INTERVAL;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE == p_timer->actived)
    {
        *p_ec |= PRA_EC_ALREADY_STARTED;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_timer_is_done_args_check(
    const pra_timer *const   p_timer,
    const pra_boolean *const p_done,
    PRA_EC_T *const          p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_TIMER_NULL == p_timer)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_NULL == p_done)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != p_timer->actived)
    {
        *p_ec |= PRA_EC_NOT_STARTED;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_timer_stop_args_check(
    const pra_timer *const p_timer,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_TIMER_NULL == p_timer)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != p_timer->actived)
    {
        *p_ec |= PRA_EC_NOT_STARTED;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}
