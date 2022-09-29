/*
 * pra_bits_internal.c
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    internal functions of pra_bits
 * version: 0.3
 * history: #       date                modification
 *          0.1     Tue Sep 13 2022     created
 *          0.2     Wed Sep 14 2022     include pra_bits_ec.h
 *          0.3     Thu Sep 29 2022     reorganize error codes
 */

/* includes */

#include "pra_bits.h"
#include "pra_bits_internal.h"
#include "pra_ec.h"


/* variables */

/* functions */

pra_boolean pra_bits_u8_get_args_check(
    uint8_t                  bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const          p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_NULL == p_actived)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BIT_MAX_OFFSET_U8 < bit_offset)
    {
        *p_ec |= PRA_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bits_u8_set_args_check(
    const uint8_t *const p_value,
    uint8_t              bit_offset,
    PRA_EC_T *const      p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == p_value)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BIT_MAX_OFFSET_U8 < bit_offset)
    {
        *p_ec |= PRA_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bits_u16_get_args_check(
    uint8_t                  bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const          p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_NULL == p_actived)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BIT_MAX_OFFSET_U16 < bit_offset)
    {
        *p_ec |= PRA_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bits_u16_set_args_check(
    const uint16_t *const p_value,
    uint8_t               bit_offset,
    PRA_EC_T *const       p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT16_NULL == p_value)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BIT_MAX_OFFSET_U16 < bit_offset)
    {
        *p_ec |= PRA_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bits_u32_get_args_check(
    uint8_t                  bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const          p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_NULL == p_actived)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BIT_MAX_OFFSET_U32 < bit_offset)
    {
        *p_ec |= PRA_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bits_u32_set_args_check(
    const uint32_t *const p_value,
    uint8_t               bit_offset,
    PRA_EC_T *const       p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT32_NULL == p_value)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BIT_MAX_OFFSET_U32 < bit_offset)
    {
        *p_ec |= PRA_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bits_u8_reverse_args_check(
    const uint8_t *const p_new_value)
{
    pra_boolean result;

    if (PRA_UINT8_NULL == p_new_value)
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}