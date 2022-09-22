/*
 * pra_stp_cycle.c
 * created on Thu Sep 22 2022
 * created by Seven Lv
 * comments:    functions of cycle stepper
 * version: 0.2
 * history: #       date                modification
 *          0.1     Thu Sep 22 2022     created
 *          0.2     Thu Sep 22 2022     add pra_stp_cycle_u16 function
 *                                      rename pra_stp_cycle_max_u8 to pra_stp_cycle_default_u8
 *                                      add pra_stp_cycle_default_u16 function
 *                                      add pra_stp_cycle_u32 function
 *                                      add pra_stp_cycle_default_u32 function
 */

/* includes */
#include "pra_stp_cycle.h"
#include "pra_stp_cycle_internal.h"

/* variables */

/* functions */

pra_boolean pra_stp_cycle_u8(
    uint8_t *const  p_value,
    const uint8_t   min_value,
    const uint8_t   max_value,
    const uint8_t   step,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_stp_cycle_u8_args_check(
                             p_value,
                             min_value,
                             max_value,
                             step,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (max_value == step)
    {
        result = PRA_BOOL_TRUE;
    }
    else if (max_value == *p_value)
    {
        *p_value = min_value + step - 1U;
        result = PRA_BOOL_TRUE;
    }
    else if ((max_value - *p_value) < step)
    {
        *p_value = step - (max_value - *p_value) - 1U + min_value;
        result = PRA_BOOL_TRUE;
    }
    else
    {
        *p_value += step;
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_stp_cycle_default_u8(
    uint8_t *const  p_value,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_stp_cycle_default_u8_args_check(
                             p_value,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = pra_stp_cycle_u8(
            p_value,
            PRA_NUM_ZERO_U,
            PRA_NUM_MAX_VALUE_U8,
            1U,
            p_ec);
    }

    return result;
}

pra_boolean pra_stp_cycle_u16(
    uint16_t *const p_value,
    const uint16_t  min_value,
    const uint16_t  max_value,
    const uint16_t  step,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_stp_cycle_u16_args_check(
                             p_value,
                             min_value,
                             max_value,
                             step,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (max_value == step)
    {
        result = PRA_BOOL_TRUE;
    }
    else if (max_value == *p_value)
    {
        *p_value = min_value + step - 1U;
        result = PRA_BOOL_TRUE;
    }
    else if ((max_value - *p_value) < step)
    {
        *p_value = step - (max_value - *p_value) - 1U + min_value;
        result = PRA_BOOL_TRUE;
    }
    else
    {
        *p_value += step;
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_stp_cycle_default_u16(
    uint16_t *const p_value,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_stp_cycle_default_u16_args_check(
                             p_value,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = pra_stp_cycle_u16(
            p_value,
            PRA_NUM_ZERO_U,
            PRA_NUM_MAX_VALUE_U16,
            1U,
            p_ec);
    }

    return result;
}

pra_boolean pra_stp_cycle_u32(
    uint32_t *const p_value,
    const uint32_t  min_value,
    const uint32_t  max_value,
    const uint32_t  step,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_stp_cycle_u32_args_check(
                             p_value,
                             min_value,
                             max_value,
                             step,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (max_value == step)
    {
        result = PRA_BOOL_TRUE;
    }
    else if (max_value == *p_value)
    {
        *p_value = min_value + step - 1U;
        result = PRA_BOOL_TRUE;
    }
    else if ((max_value - *p_value) < step)
    {
        *p_value = step - (max_value - *p_value) - 1U + min_value;
        result = PRA_BOOL_TRUE;
    }
    else
    {
        *p_value += step;
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_stp_cycle_default_u32(
    uint32_t *const p_value,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_stp_cycle_default_u32_args_check(
                             p_value,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = pra_stp_cycle_u32(
            p_value,
            PRA_NUM_ZERO_U,
            PRA_NUM_MAX_VALUE_U32,
            1U,
            p_ec);
    }

    return result;
}
