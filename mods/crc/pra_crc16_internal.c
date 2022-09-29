/*
 * pra_crc16_internal.c
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    internal functions of pra_crc16
 * version: 0.4
 * history: #       date                modification
 *          0.1     Tue Sep 13 2022     created
 *          0.2     Wed Sep 14 2022     include pra_crc_ec.h
 *                                      include pra_boolean.h
 *          0.3     Thu Sep 22 2022     remove pra_boolean_is_true invocation in pra_crc16_compute_args_check function
 *          0.4     Thu Sep 29 2022     reorganize error codes
 */

/* includes */
#include "pra_boolean.h"
#include "pra_crc16_internal.h"
#include "pra_ec.h"


/* variables */

/* functions */

pra_boolean pra_crc16_init_args_check(
    const pra_crc16 *const p_crc,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC16_NULL == p_crc)
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

pra_boolean pra_crc16_compute_args_check(
    const pra_crc16 *const p_crc,
    const uint8_t *const   bytes,
    uint32_t               offset,
    uint32_t               length,
    const uint16_t *const  p_result,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC16_NULL == p_crc)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == bytes)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT16_NULL == p_result)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != p_crc->initialized)
    {
        *p_ec |= PRA_EC_NOT_INIT;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_ZERO_U == length)
    {
        *p_ec |= PRA_EC_INVALID_LENGTH;
        result = PRA_BOOL_FALSE;
    }
    else if (length <= offset)
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

pra_boolean pra_crc16_get_args_check(
    const pra_crc16 *const p_crc,
    pra_boolean            ref_in,
    pra_boolean            ref_out,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC16_NULL == p_crc)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != ref_in &&
             PRA_BOOL_FALSE != ref_in)
    {
        *p_ec |= PRA_EC_INVALID_REF_IN;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != ref_out &&
             PRA_BOOL_FALSE != ref_out)
    {
        *p_ec |= PRA_EC_INVALID_REF_OUT;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}