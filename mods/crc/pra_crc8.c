/*
 * pra_crc8.c
 * created on Thu Sep 01 2022
 * created by Seven Lv
 * comments:    functions of crc8
 */

/* includes */
#include "pra_crc8.h"
#include "pra_bits.h"
#include "pra_defs.h"
#include "pra_num_defs.h"

/* macros */
#define MASK_H1 0x80U

/* variables */

/* function declarations */

/**
 * @brief           arguments validation for pra_crc8_init function
 * @note
 * @param  p_crc:   the crc struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_crc8_init_args_check(
    const pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec);

/**
 * @brief               arguments validation for pra_crc8_compute function
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
static pra_boolean pra_crc8_compute_args_check(
    const pra_crc8 *const p_crc,
    const uint8_t *const bytes,
    uint32_t offset,
    uint32_t length,
    const uint8_t *const p_result,
    PRA_EC_T *const p_ec);
/**
 * @brief                   arguments validation for pra_crc8_get function
 * @note
 * @param  p_crc:           the crc-8 struct pointer
 * @param  ref_in:          ref in
 * @param  ref_out:         ref out
 * @param  p_ec:            output error code:
 *                          PRA_CRC_EC_NULL_PTR
 * @retval                  PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_crc8_get_args_check(
    const pra_crc8 *const p_crc,
    pra_boolean ref_in,
    pra_boolean ref_out,
    PRA_EC_T *const p_ec);

/* functions */

static pra_boolean pra_crc8_init_args_check(
    const pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC8_NULL == p_crc)
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

pra_boolean pra_crc8_init(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    uint8_t current_value;
    uint16_t i;
    uint8_t j;

    if (PRA_BOOL_TRUE != pra_crc8_init_args_check(
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
            for (j = PRA_NUM_ZERO_U; j < PRA_NUM_BIT_WIDTH_U8; j++)
            {
                if (MASK_H1 == (current_value & MASK_H1))
                {
                    current_value = ((current_value << 1) ^ p_crc->polynomial);
                }
                else
                {
                    current_value <<= 1U;
                }
                p_crc->table[i] = current_value;
            }
        }
        p_crc->initialized = PRA_BOOL_TRUE;
        result = PRA_BOOL_TRUE;
    }

    return result;
}

static pra_boolean pra_crc8_compute_args_check(
    const pra_crc8 *const p_crc,
    const uint8_t *const bytes,
    uint32_t offset,
    uint32_t length,
    const uint8_t *const p_result,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC8_NULL == p_crc)
    {
        *p_ec |= PRA_CRC_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == bytes)
    {
        *p_ec |= PRA_CRC_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == p_result)
    {
        *p_ec |= PRA_CRC_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != pra_boolean_is_true(p_crc->initialized))
    {
        *p_ec |= PRA_CRC_EC_NOT_INIT;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_ZERO_U == length)
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

pra_boolean pra_crc8_compute(
    const pra_crc8 *const p_crc,
    const uint8_t *const bytes,
    uint32_t offset,
    uint32_t length,
    uint8_t *const p_result,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    pra_boolean failed = PRA_BOOL_FALSE;
    uint8_t tmp_value;

    if (PRA_BOOL_TRUE != pra_crc8_compute_args_check(
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
        uint8_t current_value = PRA_NUM_ZERO_U;
        uint8_t tmp_crc = p_crc->initial_value;
        for (uint32_t i = offset; i < length; i++)
        {
            if (PRA_BOOL_TRUE != failed)
            {
                if (PRA_BOOL_TRUE == p_crc->ref_in)
                {
                    tmp_value = PRA_NUM_ZERO_U;
                    if (PRA_BOOL_TRUE == pra_bits_u8_reverse(bytes[i], &tmp_value))
                    {
                        current_value = tmp_value;
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
                tmp_crc = p_crc->table[(tmp_crc ^ current_value)];
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
                tmp_value = PRA_NUM_ZERO_U;
                if (PRA_BOOL_TRUE == pra_bits_u8_reverse(tmp_crc, &tmp_value))
                {
                    tmp_crc = tmp_value;
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

static pra_boolean pra_crc8_get_args_check(
    const pra_crc8 *const p_crc,
    pra_boolean ref_in,
    pra_boolean ref_out,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_CRC8_NULL == p_crc)
    {
        *p_ec |= PRA_CRC_EC_NULL_PTR;
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

pra_boolean pra_crc8_get(
    pra_crc8 *const p_crc,
    uint8_t polynomial,
    uint8_t initial_value,
    uint8_t xor_out,
    pra_boolean ref_in,
    pra_boolean ref_out,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_BOOL_TRUE != pra_crc8_get_args_check(
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
        p_crc->initial_value = initial_value,
        p_crc->xor_out = xor_out;
        p_crc->ref_in = ref_in;
        p_crc->ref_out = ref_out;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_crc8_get_default(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec)
{
    return pra_crc8_get(
        p_crc,
        0x07U,
        0x00U,
        0x00U,
        PRA_BOOL_FALSE,
        PRA_BOOL_FALSE,
        p_ec);
}

pra_boolean pra_crc8_get_itu(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec)
{
    return pra_crc8_get(
        p_crc,
        0x07U,
        0x00U,
        0x55U,
        PRA_BOOL_FALSE,
        PRA_BOOL_FALSE,
        p_ec);
}

pra_boolean pra_crc8_get_rohc(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec)
{
    return pra_crc8_get(
        p_crc,
        0x07U,
        0xFFU,
        0x00U,
        PRA_BOOL_TRUE,
        PRA_BOOL_TRUE,
        p_ec);
}

pra_boolean pra_crc8_get_maxim(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec)
{
    return pra_crc8_get(
        p_crc,
        0x31U,
        0x00U,
        0x00U,
        PRA_BOOL_TRUE,
        PRA_BOOL_TRUE,
        p_ec);
}

pra_boolean pra_crc8_get_cdma2000(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec)
{
    return pra_crc8_get(
        p_crc,
        0x9BU,
        0xFFU,
        0x00U,
        PRA_BOOL_FALSE,
        PRA_BOOL_FALSE,
        p_ec);
}

pra_boolean pra_crc8_get_wcdma(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec)
{
    return pra_crc8_get(
        p_crc,
        0x9BU,
        0x00U,
        0x00U,
        PRA_BOOL_TRUE,
        PRA_BOOL_TRUE,
        p_ec);
}
