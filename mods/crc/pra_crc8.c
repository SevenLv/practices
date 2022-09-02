/*
 * pra_crc8.c
 * created on Thu Sep 01 2022
 * created by Seven Lv
 * comments:    functions of crc8
 */

/* includes */
#include "pra_crc8.h"
#include "pra_defs.h"
#include "pra_bits.h"

/* macros */
#define BIT_SIZE 8U
#define MASK_H1 0x80U
#define MASK_MAX 0xFFU

/* variables */

/* functions */

pra_boolean pra_crc8_init(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    uint8_t current_value;
    uint16_t i;
    uint8_t j;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC8_NULL == p_crc)
    {
        *p_ec |= PRA_CRC8_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE == pra_boolean_is_true(p_crc->initialized))
    {
        result = PRA_BOOL_TRUE;
    }
    else
    {
        for (i = 0U; i < PRA_CRC8_TABLE_SIZE; i++)
        {
            current_value = i;
            for (j = 0U; j < BIT_SIZE; j++)
            {
                if (MASK_H1 == (current_value & MASK_H1))
                {
                    current_value = ((current_value << 1) ^ p_crc->polynomial);
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

pra_boolean pra_crc8_compute(
    const pra_crc8 *const p_crc,
    const uint8_t *const bytes,
    uint32_t offset,
    uint32_t length,
    uint8_t *const p_result,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    pra_boolean failed = PRA_BOOL_FALSE;
    uint8_t tmp_crc;
    uint8_t current_value = 0U;
    uint8_t tmp_value;
    uint32_t i;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC8_NULL == p_crc)
    {
        *p_ec |= PRA_CRC8_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == bytes)
    {
        *p_ec |= PRA_CRC8_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == p_result)
    {
        *p_ec |= PRA_CRC8_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != pra_boolean_is_true(p_crc->initialized))
    {
        *p_ec |= PRA_CRC8_EC_NOT_INIT;
        result = PRA_BOOL_FALSE;
    }
    else if (0U == length)
    {
        *p_ec |= PRA_CRC8_EC_INVALID_LENGTH;
        result = PRA_BOOL_FALSE;
    }
    else if (length <= offset)
    {
        *p_ec |= PRA_CRC8_EC_INVALID_OFFSET;
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
                    tmp_value = 0U;
                    if (PRA_BOOL_TRUE == pra_bits_u8_reverse(bytes[i], &tmp_value))
                    {
                        current_value = tmp_value;
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
                tmp_crc = p_crc->table[((tmp_crc ^ current_value) & MASK_MAX)];
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
                tmp_value = 0U;
                if (PRA_BOOL_TRUE == pra_bits_u8_reverse(tmp_crc, &tmp_value))
                {
                    tmp_crc = tmp_value;
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

pra_boolean pra_crc8_get_default(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC8_NULL == p_crc)
    {
        *p_ec |= PRA_CRC8_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_crc->initialized = PRA_BOOL_FALSE;
        p_crc->polynomial = 0x07U;
        p_crc->initial_value = 0x00U,
        p_crc->xor_out = 0x00U;
        p_crc->ref_in = PRA_BOOL_FALSE;
        p_crc->ref_out = PRA_BOOL_FALSE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_crc8_get_itu(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC8_NULL == p_crc)
    {
        *p_ec |= PRA_CRC8_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_crc->initialized = PRA_BOOL_FALSE;
        p_crc->polynomial = 0x07U;
        p_crc->initial_value = 0x00U,
        p_crc->xor_out = 0x55U;
        p_crc->ref_in = PRA_BOOL_FALSE;
        p_crc->ref_out = PRA_BOOL_FALSE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_crc8_get_rohc(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC8_NULL == p_crc)
    {
        *p_ec |= PRA_CRC8_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_crc->initialized = PRA_BOOL_FALSE;
        p_crc->polynomial = 0x07U;
        p_crc->initial_value = 0xFFU,
        p_crc->xor_out = 0x00U;
        p_crc->ref_in = PRA_BOOL_TRUE;
        p_crc->ref_out = PRA_BOOL_TRUE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_crc8_get_maxim(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC8_NULL == p_crc)
    {
        *p_ec |= PRA_CRC8_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_crc->initialized = PRA_BOOL_FALSE;
        p_crc->polynomial = 0x31U;
        p_crc->initial_value = 0x00U,
        p_crc->xor_out = 0x00U;
        p_crc->ref_in = PRA_BOOL_TRUE;
        p_crc->ref_out = PRA_BOOL_TRUE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_crc8_get_cdma2000(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC8_NULL == p_crc)
    {
        *p_ec |= PRA_CRC8_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_crc->initialized = PRA_BOOL_FALSE;
        p_crc->polynomial = 0x9BU;
        p_crc->initial_value = 0xFFU,
        p_crc->xor_out = 0x00U;
        p_crc->ref_in = PRA_BOOL_FALSE;
        p_crc->ref_out = PRA_BOOL_FALSE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_crc8_get_wcdma(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC8_NULL == p_crc)
    {
        *p_ec |= PRA_CRC8_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_crc->initialized = PRA_BOOL_FALSE;
        p_crc->polynomial = 0x9BU;
        p_crc->initial_value = 0x00U,
        p_crc->xor_out = 0x00U;
        p_crc->ref_in = PRA_BOOL_TRUE;
        p_crc->ref_out = PRA_BOOL_TRUE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}
