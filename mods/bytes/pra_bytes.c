/*
 * pra_bytes.c
 * created on Wed Aug 24 2022
 * created by Seven Lv
 * comments:    definitions and functions of the bytes type
 * version: 0.4
 * history: #       date                modification
 *          0.1     Wed Aug 24 2022     created
 *          0.2     Wed Sep 14 2022     include pra_bytes_ec.h
 *          0.3     Thu Sep 15 2022     replace PRA_BYTES_EC_NONE with PRA_EC_NONE
 *          0.4     Thu Sep 22 2022     add pra_bytes_internal.h
 *                                      add args_check functions invocation
 */

/* includes */
#include "pra_bytes.h"
#include "pra_bytes_ec.h"
#include "pra_bytes_internal.h"
#include "pra_defs.h"
#include "pra_ec.h"
#include "pra_num_defs.h"

/* variables */

/* functions */

pra_boolean pra_bytes_not_null_ptr(
    const pra_bytes *const p_bytes,
    PRA_EC_T *const        p_ec)
{
    return pra_bytes_not_null_ptr_args_check(
        p_bytes,
        p_ec);
}

pra_boolean pra_bytes_init(
    pra_bytes *const p_bytes,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_init_args_check(
                             p_bytes,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_bytes->used_length = PRA_NUM_ZERO_U;

        for (uint16_t i = PRA_NUM_ZERO_U; i < p_bytes->length; i++)
        {
            p_bytes->data[i] = PRA_NUM_ZERO_U;
        }

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_copy(
    const pra_bytes *const p_src,
    pra_bytes *const       p_dst,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_copy_args_check(
                             p_src,
                             p_dst,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        for (uint16_t i = PRA_NUM_ZERO_U; i < p_src->length; i++)
        {
            if (i < p_src->used_length - 1)
            {
                p_dst->data[i] = p_src->data[i];
            }
            else
            {
                p_dst->data[i] = PRA_NUM_ZERO_U;
            }
        }

        p_dst->used_length = p_src->used_length;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_append_u8_array(
    pra_bytes *const p_bytes,
    const uint8_t    data[],
    uint16_t         data_length,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_append_u8_array_args_check(
                             p_bytes,
                             data,
                             data_length,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_ZERO_U == data_length)
    {
        result = PRA_BOOL_TRUE;
    }
    else
    {
        for (uint16_t i = PRA_NUM_ZERO_U; i < data_length; i++)
        {
            p_bytes->data[p_bytes->used_length] = data[i];
            p_bytes->used_length++;
        }

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_append(
    pra_bytes *const       p_bytes,
    const pra_bytes *const p_data,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_append_args_check(
                             p_bytes,
                             p_data,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        for (uint16_t i = PRA_NUM_ZERO_U; i < p_data->used_length; i++)
        {
            p_bytes->data[p_bytes->used_length] = p_data->data[i];
            p_bytes->used_length += PRA_NUM_BYTE_SIZE_U8;
        }

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_append_u8(
    pra_bytes *const p_bytes,
    uint8_t          data,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_append_uxx_args_check(
                             p_bytes,
                             PRA_NUM_BYTE_SIZE_U8,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_bytes->data[p_bytes->used_length] = data;
        p_bytes->used_length += PRA_NUM_BYTE_SIZE_U8;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_append_u16_be(
    pra_bytes *const p_bytes,
    uint16_t         data,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_append_uxx_args_check(
                             p_bytes,
                             PRA_NUM_BYTE_SIZE_U16,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_bytes->data[p_bytes->used_length] = (uint8_t)((data >> PRA_NUM_BIT_WIDTH_U8) & PRA_NUM_MAX_VALUE_U8);
        p_bytes->data[p_bytes->used_length + 1] = (uint8_t)(data & PRA_NUM_MAX_VALUE_U8);
        p_bytes->used_length += PRA_NUM_BYTE_SIZE_U16;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_append_u16_le(
    pra_bytes *const p_bytes,
    uint16_t         data,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_append_uxx_args_check(
                             p_bytes,
                             PRA_NUM_BYTE_SIZE_U16,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_bytes->data[p_bytes->used_length] = (uint8_t)(data & PRA_NUM_MAX_VALUE_U8);
        p_bytes->data[p_bytes->used_length + 1] = (uint8_t)((data >> PRA_NUM_BIT_WIDTH_U8) & PRA_NUM_MAX_VALUE_U8);
        p_bytes->used_length += PRA_NUM_BYTE_SIZE_U16;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_append_u32_be(
    pra_bytes *const p_bytes,
    uint32_t         data,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_append_uxx_args_check(
                             p_bytes,
                             PRA_NUM_BYTE_SIZE_U32,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_bytes->data[p_bytes->used_length] = (uint8_t)((data >> (PRA_NUM_BIT_WIDTH_U8 * 3U)) & PRA_NUM_MAX_VALUE_U8);
        p_bytes->data[p_bytes->used_length + 1] = (uint8_t)((data >> (PRA_NUM_BIT_WIDTH_U8 * 2U)) & PRA_NUM_MAX_VALUE_U8);
        p_bytes->data[p_bytes->used_length + 2] = (uint8_t)((data >> PRA_NUM_BIT_WIDTH_U8) & PRA_NUM_MAX_VALUE_U8);
        p_bytes->data[p_bytes->used_length + 3] = (uint8_t)(data & PRA_NUM_MAX_VALUE_U8);
        p_bytes->used_length += PRA_NUM_BYTE_SIZE_U32;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_append_u32_le(
    pra_bytes *const p_bytes,
    uint32_t         data,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bytes_append_uxx_args_check(
                             p_bytes,
                             PRA_NUM_BYTE_SIZE_U32,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_bytes->data[p_bytes->used_length] = (uint8_t)(data & PRA_NUM_MAX_VALUE_U8);
        p_bytes->data[p_bytes->used_length + 1] = (uint8_t)((data >> PRA_NUM_BIT_WIDTH_U8) & PRA_NUM_MAX_VALUE_U8);
        p_bytes->data[p_bytes->used_length + 2] = (uint8_t)((data >> (PRA_NUM_BIT_WIDTH_U8 * 2U)) & PRA_NUM_MAX_VALUE_U8);
        p_bytes->data[p_bytes->used_length + 3] = (uint8_t)((data >> (PRA_NUM_BIT_WIDTH_U8 * 3U)) & PRA_NUM_MAX_VALUE_U8);
        p_bytes->used_length += PRA_NUM_BYTE_SIZE_U32;

        result = PRA_BOOL_TRUE;
    }

    return result;
}
