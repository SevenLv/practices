/*
 * pra_stp_cycle_internal.c
 * created on Thu Sep 22 2022
 * created by Seven Lv
 * comments:    internal functions of cycle stepper
 * version: 0.2
 * history: #       date                modification
 *          0.1     Thu Sep 22 2022     created
 *          0.2     Thu Sep 22 2022     add pra_stp_cycle_u16_args_check function
 *                                      rename pra_stp_cycle_max_u8_args_check to pra_stp_cycle_default_u8_args_check
 *                                      add pra_stp_cycle_default_u16_args_check function
 *                                      add pra_stp_cycle_u32_args_check function
 *                                      add pra_stp_cycle_default_u32_args_check function
 */

/* includes */
#include "pra_stp_cycle_ec.h"
#include "pra_stp_cycle_internal.h"

/* variables */

/* functions */

pra_boolean pra_stp_cycle_u8_args_check(
    const uint8_t *const p_value,
    const uint8_t        min_value,
    const uint8_t        max_value,
    const uint8_t        step,
    PRA_EC_T *const      p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == p_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (min_value >= max_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_INVALID_RANGE;
        result = PRA_BOOL_FALSE;
    }
    else if (min_value > *p_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_VALUE_OUT_OF_RANGE;
        result = PRA_BOOL_FALSE;
    }
    else if (max_value < *p_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_VALUE_OUT_OF_RANGE;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_ZERO_U == step)
    {
        *p_ec |= PRA_STP_CYCLE_EC_INVALID_STEP;
        result = PRA_BOOL_FALSE;
    }
    else if (max_value < step)
    {
        *p_ec |= PRA_STP_CYCLE_EC_INVALID_STEP;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_stp_cycle_default_u8_args_check(
    const uint8_t *const p_value,
    PRA_EC_T *const      p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == p_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_stp_cycle_u16_args_check(
    const uint16_t *const p_value,
    const uint16_t        min_value,
    const uint16_t        max_value,
    const uint16_t        step,
    PRA_EC_T *const       p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT16_NULL == p_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (min_value >= max_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_INVALID_RANGE;
        result = PRA_BOOL_FALSE;
    }
    else if (min_value > *p_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_VALUE_OUT_OF_RANGE;
        result = PRA_BOOL_FALSE;
    }
    else if (max_value < *p_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_VALUE_OUT_OF_RANGE;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_ZERO_U == step)
    {
        *p_ec |= PRA_STP_CYCLE_EC_INVALID_STEP;
        result = PRA_BOOL_FALSE;
    }
    else if (max_value < step)
    {
        *p_ec |= PRA_STP_CYCLE_EC_INVALID_STEP;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_stp_cycle_default_u16_args_check(
    const uint16_t *const p_value,
    PRA_EC_T *const       p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT16_NULL == p_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_stp_cycle_u32_args_check(
    const uint32_t *const p_value,
    const uint32_t        min_value,
    const uint32_t        max_value,
    const uint32_t        step,
    PRA_EC_T *const       p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT32_NULL == p_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (min_value >= max_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_INVALID_RANGE;
        result = PRA_BOOL_FALSE;
    }
    else if (min_value > *p_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_VALUE_OUT_OF_RANGE;
        result = PRA_BOOL_FALSE;
    }
    else if (max_value < *p_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_VALUE_OUT_OF_RANGE;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_ZERO_U == step)
    {
        *p_ec |= PRA_STP_CYCLE_EC_INVALID_STEP;
        result = PRA_BOOL_FALSE;
    }
    else if (max_value < step)
    {
        *p_ec |= PRA_STP_CYCLE_EC_INVALID_STEP;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_stp_cycle_default_u32_args_check(
    const uint32_t *const p_value,
    PRA_EC_T *const       p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT32_NULL == p_value)
    {
        *p_ec |= PRA_STP_CYCLE_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}
