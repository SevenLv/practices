/*
 * pra_crc32.c
 * created on Fri Sep 02 2022
 * created by Seven Lv
 * comments:    functions of crc32
 */

/* includes */
#include "pra_crc32.h"
#include "pra_defs.h"
#include "pra_bits.h"

/* macros */
#define U8_BIT_SIZE 8U
#define BIT_SIZE 32U
#define U8_MASK_MAX 0xFFU
#define MASK_H1 0x80000000U
#define MASK_MAX 0xFFFFFFFFU

/* variables */

/* functions */

pra_boolean pra_crc32_init(
    pra_crc32 *const p_crc,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    uint32_t current_value;
    uint16_t i;
    uint8_t j;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC32_NULL == p_crc)
    {
        *p_ec |= PRA_CRC_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE == pra_boolean_is_true(p_crc->initialized))
    {
        result = PRA_BOOL_TRUE;
    }
    else
    {
        for (i = 0U; i < PRA_CRC_TABLE_SIZE; i++)
        {
            current_value = i;
            for (j = 0U; j < BIT_SIZE; j++)
            {
                if (MASK_H1 == (current_value & MASK_H1))
                {
                    current_value = ((current_value << 1U) ^ p_crc->polynomial);
                }
                else
                {
                    current_value <<= 1U;
                }
                p_crc->table[i] = (current_value & MASK_MAX);
            }
        }
        p_crc->initialized = PRA_BOOL_TRUE;
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_crc32_compute(
    const pra_crc32 *const p_crc,
    const uint8_t *const bytes,
    uint32_t offset,
    uint32_t length,
    uint32_t *const p_result,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    pra_boolean failed = PRA_BOOL_FALSE;
    uint32_t tmp_crc;
    uint8_t current_value;
    uint32_t tmp_u32_value;
    uint8_t tmp_u8_value;
    uint32_t i;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC32_NULL == p_crc)
    {
        *p_ec |= PRA_CRC_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == bytes)
    {
        *p_ec |= PRA_CRC_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT32_NULL == p_result)
    {
        *p_ec |= PRA_CRC_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != pra_boolean_is_true(p_crc->initialized))
    {
        *p_ec |= PRA_CRC_EC_NOT_INIT;
        result = PRA_BOOL_FALSE;
    }
    else if (0U == length)
    {
        *p_ec |= PRA_CRC_EC_INVALID_LENGTH;
        result = PRA_BOOL_FALSE;
    }
    else if (length <= offset)
    {
        *p_ec |= PRA_CRC_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        tmp_crc = p_crc->initial_value;
        for (i = offset; i < length; i++)
        {
            if (PRA_BOOL_TRUE != failed)
            {
                if (PRA_BOOL_TRUE == p_crc->ref_in)
                {
                    tmp_u8_value = 0U;
                    if (PRA_BOOL_TRUE == pra_bits_u8_reverse(bytes[i], &tmp_u8_value))
                    {
                        current_value = tmp_u8_value;
                    }
                    else
                    {
                        failed = PRA_BOOL_TRUE;
                    }
                }
                else
                {
                    current_value = bytes[i];
                }
                tmp_crc = (tmp_crc << U8_BIT_SIZE) ^ p_crc->table[((tmp_crc >> (U8_BIT_SIZE * 3)) ^ current_value) & U8_MASK_MAX];
                tmp_crc &= MASK_MAX;
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
                tmp_u32_value = 0U;
                if (PRA_BOOL_TRUE == pra_bits_u32_reverse(tmp_crc, &tmp_u32_value))
                {
                    tmp_crc = tmp_u32_value;
                }
                else
                {
                    failed = PRA_BOOL_TRUE;
                }
            }

            tmp_crc = (tmp_crc ^ p_crc->xor_out & MASK_MAX);

            *p_result = tmp_crc;
        }

        result = pra_boolean_not(failed);
    }

    return result;
}

pra_boolean pra_crc32_get(
    pra_crc32 *const p_crc,
    uint32_t polynomial,
    uint32_t initial_value,
    uint32_t xor_out,
    pra_boolean ref_in,
    pra_boolean ref_out,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC32_NULL == p_crc)
    {
        *p_ec |= PRA_BITS_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != ref_in &&
             PRA_BOOL_FALSE != ref_in)
    {
        *p_ec |= PRA_CRC_EC_INVALID_REF_IN;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != ref_out &&
             PRA_BOOL_FALSE != ref_out)
    {
        *p_ec |= PRA_CRC_EC_INVALID_REF_OUT;
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
    uint32_t *const p_ec)
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
    uint32_t *const p_ec)
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
    uint32_t *const p_ec)
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
    uint32_t *const p_ec)
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
    uint32_t *const p_ec)
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
