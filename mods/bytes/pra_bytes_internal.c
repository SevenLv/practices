/*
 * pra_bytes_internal.c
 * created on Thu Sep 22 2022
 * created by Seven Lv
 * comments:    internal functions of pra_bytes
 * version: 0.1
 * history: #       date                modification
 *          0.1     Thu Sep 22 2022     created
 */

/* includes */
#include "pra_boolean.h"
#include "pra_bytes_ec.h"
#include "pra_bytes_internal.h"

/* variables */

/* functions */

pra_boolean pra_bytes_not_null_ptr_args_check(
    const pra_bytes *const p_bytes,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BYTES_NULL == p_bytes)
    {
        *p_ec |= PRA_BYTES_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == p_bytes->data)
    {
        *p_ec |= PRA_BYTES_EC_NULL_DATA_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_init_args_check(
    const pra_bytes *const p_bytes,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_not_null_ptr_args_check(
                             p_bytes,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_ZERO_U == p_bytes->length)
    {
        *p_ec |= PRA_BYTES_EC_DATA_LENGTH_ZERO;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_copy_args_check(
    const pra_bytes *const p_src,
    const pra_bytes *const p_dst,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_not_null_ptr_args_check(
                             p_src,
                             p_ec) ||
        PRA_BOOL_TRUE != pra_bytes_not_null_ptr_args_check(
                             p_dst,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_ZERO_U == p_src->length ||
             PRA_NUM_ZERO_U == p_dst->length)
    {
        *p_ec |= PRA_BYTES_EC_DATA_LENGTH_ZERO;
        result = PRA_BOOL_FALSE;
    }
    else if (p_dst->length != p_src->length)
    {
        *p_ec |= PRA_BYTES_EC_DIFFERENT_LENGTH;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_append_u8_array_args_check(
    const pra_bytes *const p_bytes,
    const uint8_t          data[],
    const uint16_t         data_length,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_not_null_ptr_args_check(
                             p_bytes,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == data)
    {
        *p_ec |= PRA_BYTES_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (p_bytes->length < (p_bytes->used_length + data_length))
    {
        *p_ec |= PRA_BYTES_EC_NOT_ENOUGH_LENGTH;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_append_args_check(
    const pra_bytes *const p_bytes,
    const pra_bytes *const p_data,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_not_null_ptr_args_check(
                             p_bytes,
                             p_ec) ||
        PRA_BOOL_TRUE != pra_bytes_not_null_ptr_args_check(
                             p_data,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (p_bytes->length < (p_bytes->used_length + p_data->used_length))
    {
        *p_ec |= PRA_BYTES_EC_NOT_ENOUGH_LENGTH;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}
pra_boolean pra_bytes_append_uxx_args_check(
    const pra_bytes *const p_bytes,
    const uint16_t         data_length,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_not_null_ptr_args_check(
                             p_bytes,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (p_bytes->length < (p_bytes->used_length + data_length))
    {
        *p_ec |= PRA_BYTES_EC_NOT_ENOUGH_LENGTH;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}
