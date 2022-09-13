/*
 * pra_crc32.c
 * created on Fri Sep 02 2022
 * created by Seven Lv
 * comments:    functions of crc32
 * version: 0.2
 * history: #       date                modification
 *          0.1     Fri Sep 02 2022     created
 *          0.2     Tue Sep 13 2022     move static functions to internal files
 */

/* includes */
#include "pra_bits.h"
#include "pra_crc32_internal.h"


/* macros */

/* variables */

/* functions */

pra_boolean pra_crc32_init(
    pra_crc32 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    uint32_t    current_value;
    uint16_t    i;
    uint8_t     j;

    if (PRA_BOOL_TRUE != pra_crc32_init_args_check(
                             p_crc,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE == pra_boolean_is_true(p_crc->initialized))
    {
        result = PRA_BOOL_TRUE;
    }
    else
    {
        for (i = PRA_NUM_ZERO_U; i < PRA_CRC_TABLE_SIZE; i++)
        {
            current_value = i;
            for (j = PRA_NUM_ZERO_U; j < PRA_NUM_BIT_WIDTH_U32; j++)
            {
                if (MASK_H1 == (current_value & MASK_H1))
                {
                    current_value = ((current_value << 1U) ^ p_crc->polynomial);
                }
                else
                {
                    current_value <<= 1U;
                }
                p_crc->table[i] = (current_value & PRA_NUM_MAX_VALUE_U32);
            }
        }
        p_crc->initialized = PRA_BOOL_TRUE;
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_crc32_compute(
    const pra_crc32 *const p_crc,
    const uint8_t *const   bytes,
    uint32_t               offset,
    uint32_t               length,
    uint32_t *const        p_result,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    pra_boolean failed = PRA_BOOL_FALSE;
    uint32_t    tmp_u32_value;
    uint8_t     tmp_u8_value;

    if (PRA_BOOL_TRUE != pra_crc32_compute_args_check(
                             p_crc,
                             bytes,
                             offset,
                             length,
                             p_result,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint32_t tmp_crc = p_crc->initial_value;
        uint8_t  current_value;
        for (uint32_t i = offset; i < length; i++)
        {
            if (PRA_BOOL_TRUE != failed)
            {
                if (PRA_BOOL_TRUE == p_crc->ref_in)
                {
                    tmp_u8_value = PRA_NUM_ZERO_U;
                    if (PRA_BOOL_TRUE == pra_bits_u8_reverse(bytes[i], &tmp_u8_value))
                    {
                        current_value = tmp_u8_value;
                    }
                    else
                    {
                        *p_ec |= PRA_CRC_EC_REVERSE_FAILED;
                        failed = PRA_BOOL_TRUE;
                    }
                }
                else
                {
                    current_value = bytes[i];
                }
                tmp_crc = (tmp_crc << PRA_NUM_BIT_WIDTH_U8) ^ p_crc->table[((tmp_crc >> (PRA_NUM_BIT_WIDTH_U8 * 3)) ^ current_value) & PRA_NUM_MAX_VALUE_U8];
            }
            else
            {
                /* NOTE do nothing */
            }
        }

        if (PRA_BOOL_TRUE != failed)
        {
            if (PRA_BOOL_TRUE == p_crc->ref_out)
            {
                tmp_u32_value = PRA_NUM_ZERO_U;
                if (PRA_BOOL_TRUE == pra_bits_u32_reverse(tmp_crc, &tmp_u32_value))
                {
                    tmp_crc = tmp_u32_value;
                }
                else
                {
                    *p_ec |= PRA_CRC_EC_REVERSE_FAILED;
                    failed = PRA_BOOL_TRUE;
                }
            }

            tmp_crc = (tmp_crc ^ p_crc->xor_out);

            *p_result = tmp_crc;
        }

        result = pra_boolean_not(failed);
    }

    return result;
}

pra_boolean pra_crc32_get(
    pra_crc32 *const p_crc,
    uint32_t         polynomial,
    uint32_t         initial_value,
    uint32_t         xor_out,
    pra_boolean      ref_in,
    pra_boolean      ref_out,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_BOOL_TRUE != pra_crc32_get_args_check(
                             p_crc,
                             ref_in,
                             ref_out,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_crc->initialized = PRA_BOOL_FALSE;
        p_crc->polynomial = polynomial;
        p_crc->initial_value = initial_value;
        p_crc->xor_out = xor_out;
        p_crc->ref_in = ref_in;
        p_crc->ref_out = ref_out;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_crc32_get_default(
    pra_crc32 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    return pra_crc32_get(
        p_crc,
        0x04C11DB7,
        0xFFFFFFFF,
        0xFFFFFFFF,
        PRA_BOOL_TRUE,
        PRA_BOOL_TRUE,
        p_ec);
}

pra_boolean pra_crc32_get_mpeg2(
    pra_crc32 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    return pra_crc32_get(
        p_crc,
        0x04C11DB7,
        0xFFFFFFFF,
        0x00000000,
        PRA_BOOL_FALSE,
        PRA_BOOL_FALSE,
        p_ec);
}

pra_boolean pra_crc32_get_bzip2(
    pra_crc32 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    return pra_crc32_get(
        p_crc,
        0x04C11DB7,
        0xFFFFFFFF,
        0xFFFFFFFF,
        PRA_BOOL_FALSE,
        PRA_BOOL_FALSE,
        p_ec);
}

pra_boolean pra_crc32_get_posix(
    pra_crc32 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    return pra_crc32_get(
        p_crc,
        0x04C11DB7,
        0x00000000,
        0xFFFFFFFF,
        PRA_BOOL_FALSE,
        PRA_BOOL_FALSE,
        p_ec);
}

pra_boolean pra_crc32_get_jamcrc(
    pra_crc32 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    return pra_crc32_get(
        p_crc,
        0x04C11DB7,
        0xFFFFFFFF,
        0x00000000,
        PRA_BOOL_TRUE,
        PRA_BOOL_TRUE,
        p_ec);
}
