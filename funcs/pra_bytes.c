/*
 * pra_bytes.c
 * created on Wed Aug 24 2022
 * created by Seven Lv
 * comments:    definitions and functions of the bytes type
 */

/* includes */
#include "pra_bytes.h"
#include "pra_defs.h"

/* variables */

/* functions */

pra_boolean pra_bytes_not_null_ptr(
    const pra_bytes *const p_bytes,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BYTES_NULL == p_bytes)
    {
        *p_ec = PRA_BYTES_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == p_bytes->data)
    {
        *p_ec = PRA_BYTES_EC_NULL_DATA_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        *p_ec = PRA_BYTES_EC_NONE;
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_init(
    pra_bytes *const p_bytes,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    uint16_t i = 0U;

    if (PRA_BOOL_FALSE == pra_bytes_not_null_ptr(p_bytes, p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (0U == p_bytes->length)
    {
        *p_ec |= PRA_BYTES_EC_DATA_LENGTH_ZERO;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_bytes->used_length = 0U;
        for (i = 0U; i < p_bytes->length; i++)
        {
            p_bytes->data[i] = 0U;
        }

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_copy(
    const pra_bytes *const p_src,
    pra_bytes *const p_dst,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    uint16_t i = 0U;

    if (PRA_BOOL_FALSE == pra_bytes_not_null_ptr(p_src, p_ec) ||
        PRA_BOOL_FALSE == pra_bytes_not_null_ptr(p_dst, p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (0U == p_src->length ||
             0U == p_dst->length)
    {
        *p_ec = PRA_BYTES_EC_DATA_LENGTH_ZERO;
        result = PRA_BOOL_FALSE;
    }
    else if (p_dst->length != p_src->length)
    {
        *p_ec |= PRA_BYTES_EC_DIFFERENT_LENGTH;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        for (i = 0U; i < p_src->length; i++)
        {
            if (i < p_src->used_length - 1)
            {
                p_dst->data[i] = p_src->data[i];
            }
            else
            {
                p_dst->data[i] = 0U;
            }
        }

        p_dst->used_length = p_src->used_length;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_append_u8_array(
    pra_bytes *const p_bytes,
    uint8_t data[],
    uint16_t data_length,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    uint16_t i = 0U;

    if (PRA_BOOL_FALSE == pra_bytes_not_null_ptr(p_bytes, p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == data)
    {
        *p_ec |= PRA_BYTES_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        if (0U == data_length)
        {
            result = PRA_BOOL_TRUE;
        }
        else if (p_bytes->length < (p_bytes->used_length + data_length))
        {
            *p_ec |= PRA_BYTES_EC_NOT_ENOUGH_LENGTH;
            result = PRA_BOOL_FALSE;
        }
        else
        {
            for (i = 0U; i < data_length; i++)
            {
                p_bytes->data[p_bytes->used_length] = data[i];
                p_bytes->used_length++;
            }

            result = PRA_BOOL_TRUE;
        }
    }

    return result;
}

pra_boolean pra_bytes_append(
    pra_bytes *const p_bytes,
    const pra_bytes *const p_data,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    uint16_t i = 0U;

    if (PRA_BOOL_FALSE == pra_bytes_not_null_ptr(p_bytes, p_ec) ||
        PRA_BOOL_FALSE == pra_bytes_not_null_ptr(p_data, p_ec))
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
        for (i = 0U; i < p_data->used_length; i++)
        {
            p_bytes->data[p_bytes->used_length] = p_data->data[i];
            p_bytes->used_length++;
        }

        result = PRA_BOOL_TRUE;
    }

    return result;
}
