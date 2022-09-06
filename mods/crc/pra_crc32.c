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
#define MASK_H1 0x80000000U

/* variables */

/* function declarations */

/**
 * @brief           arguments validation for pra_crc32_init function
 * @note
 * @param  p_crc:   the crc struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_crc32_init_args_check(
    const pra_crc32 *const p_crc,
    PRA_EC_T *const p_ec);

/**
 * @brief               arguments validation for pra_crc32_compute function
 * @note
 * @param  p_crc:       the crc struct pointer
 * @param  bytes:       the bytes to compute
 * @param  offset:      the start position, base zero
 * @param  length:      length of the bytes
 * @param  p_result:    the crc result
 * @param  p_ec:        output error code:
 *                      PRA_CRC_EC_NULL_PTR
 *                      PRA_CRC_EC_NOT_INIT
 *                      PRA_CRC_EC_INVALID_OFFSET
 *                      PRA_CRC_EC_INVALID_LENGTH
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_crc32_compute_args_check(
    const pra_crc32 *const p_crc,
    const uint8_t *const bytes,
    uint32_t offset,
    uint32_t length,
    const uint32_t *const p_result,
    PRA_EC_T *const p_ec);

/**
 * @brief                   arguments declaration for pra_crc32_get function
 * @note
 * @param  p_crc:           the crc-32 struct pointer
 * @param  ref_in:          ref in
 * @param  ref_out:         ref out
 * @param  p_ec:            output error code:
 *                          PRA_CRC_EC_NULL_PTR
 * @retval                  PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_crc32_get_args_check(
    const pra_crc32 *const p_crc,
    pra_boolean ref_in,
    pra_boolean ref_out,
    PRA_EC_T *const p_ec);

/* functions */

static pra_boolean pra_crc32_init_args_check(
    const pra_crc32 *const p_crc,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC32_NULL == p_crc)
    {
        *p_ec |= PRA_CRC_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_crc32_init(
    pra_crc32 *const p_crc,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    uint32_t current_value;
    uint16_t i;
    uint8_t j;

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
        for (i = 0U; i < PRA_CRC_TABLE_SIZE; i++)
        {
            current_value = i;
            for (j = 0U; j < PRA_BITS_U32_WITDH; j++)
            {
                if (MASK_H1 == (current_value & MASK_H1))
                {
                    current_value = ((current_value << 1U) ^ p_crc->polynomial);
                }
                else
                {
                    current_value <<= 1U;
                }
                p_crc->table[i] = (current_value & PRA_BITS_U32_MAX_VALUE);
            }
        }
        p_crc->initialized = PRA_BOOL_TRUE;
        result = PRA_BOOL_TRUE;
    }

    return result;
}

static pra_boolean pra_crc32_compute_args_check(
    const pra_crc32 *const p_crc,
    const uint8_t *const bytes,
    uint32_t offset,
    uint32_t length,
    const uint32_t *const p_result,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

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
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    pra_boolean failed = PRA_BOOL_FALSE;
    uint32_t tmp_u32_value;
    uint8_t tmp_u8_value;

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
        uint8_t current_value;
        for (uint32_t i = offset; i < length; i++)
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
                        *p_ec |= PRA_CRC_EC_REVERSE_FAILED;
                        failed = PRA_BOOL_TRUE;
                    }
                }
                else
                {
                    current_value = bytes[i];
                }
                tmp_crc = (tmp_crc << PRA_BITS_U8_WIDTH) ^ p_crc->table[((tmp_crc >> (PRA_BITS_U8_WIDTH * 3)) ^ current_value) & PRA_BITS_U8_MAX_VALUE];
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

static pra_boolean pra_crc32_get_args_check(
    const pra_crc32 *const p_crc,
    pra_boolean ref_in,
    pra_boolean ref_out,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

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
        result = PRA_BOOL_TRUE;
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
    PRA_EC_T *const p_ec)
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
    PRA_EC_T *const p_ec)
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
    PRA_EC_T *const p_ec)
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
    PRA_EC_T *const p_ec)
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
    PRA_EC_T *const p_ec)
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
    PRA_EC_T *const p_ec)
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
