/*
 * pra_crc16.c
 * created on Fri Sep 02 2022
 * created by Seven Lv
 * comments:    functions of crc16
 */

/* includes */
#include "pra_bits.h"
#include "pra_crc16.h"
#include "pra_defs.h"
#include "pra_num_defs.h"


/* variables */
#define MASK_H1 0x8000U

/* function declarations */

/**
 * @brief           arguments validation for pra_crc16_init function
 * @note
 * @param  p_crc:   the crc struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_crc16_init_args_check(
    const pra_crc16 *const p_crc,
    PRA_EC_T *const        p_ec);

/**
 * @brief               arguments validation for pra_crc16_compute function
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
static pra_boolean pra_crc16_compute_args_check(
    const pra_crc16 *const p_crc,
    const uint8_t *const   bytes,
    uint32_t               offset,
    uint32_t               length,
    const uint16_t *const  p_result,
    PRA_EC_T *const        p_ec);

/**
 * @brief                   arguments validation for pra_crc16_get function
 * @note
 * @param  p_crc:           the crc-16 struct pointer
 * @param  ref_in:          ref in
 * @param  ref_out:         ref out
 * @param  p_ec:            output error code:
 *                          PRA_CRC_EC_NULL_PTR
 * @retval                  PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_crc16_get_args_check(
    const pra_crc16 *const p_crc,
    pra_boolean            ref_in,
    pra_boolean            ref_out,
    PRA_EC_T *const        p_ec);

/* functions */

static pra_boolean pra_crc16_init_args_check(
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
        *p_ec |= PRA_CRC_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_crc16_init(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    if (PRA_BOOL_TRUE != pra_crc16_init_args_check(
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
        for (uint16_t i = PRA_NUM_ZERO_U; i < PRA_CRC_TABLE_SIZE; i++)
        {
            uint16_t current_value = i;
            for (uint8_t j = PRA_NUM_ZERO_U; j < PRA_NUM_BIT_WIDTH_U16; j++)
            {
                if (MASK_H1 == (current_value & MASK_H1))
                {
                    current_value = ((current_value << 1U) ^ p_crc->polynomial);
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

static pra_boolean pra_crc16_compute_args_check(
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
        *p_ec |= PRA_CRC_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == bytes)
    {
        *p_ec |= PRA_CRC_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT16_NULL == p_result)
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

pra_boolean pra_crc16_compute(
    const pra_crc16 *const p_crc,
    const uint8_t *const   bytes,
    uint32_t               offset,
    uint32_t               length,
    uint16_t *const        p_result,
    PRA_EC_T *const        p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    pra_boolean failed = PRA_BOOL_FALSE;
    uint16_t    tmp_u16_value;
    uint8_t     tmp_u8_value;

    if (PRA_BOOL_TRUE != pra_crc16_compute_args_check(
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
        uint16_t tmp_crc = p_crc->initial_value;
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
                tmp_crc = (tmp_crc << PRA_NUM_BIT_WIDTH_U8) ^ p_crc->table[((tmp_crc >> PRA_NUM_BIT_WIDTH_U8) ^ current_value) & PRA_NUM_MAX_VALUE_U8];
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
                tmp_u16_value = PRA_NUM_ZERO_U;
                if (PRA_BOOL_TRUE == pra_bits_u16_reverse(tmp_crc, &tmp_u16_value))
                {
                    tmp_crc = tmp_u16_value;
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

static pra_boolean pra_crc16_get_args_check(
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

pra_boolean pra_crc16_get(
    pra_crc16 *const p_crc,
    uint16_t         polynomial,
    uint16_t         initial_value,
    uint16_t         xor_out,
    pra_boolean      ref_in,
    pra_boolean      ref_out,
    PRA_EC_T *const  p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_BOOL_TRUE != pra_crc16_get_args_check(
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

pra_boolean pra_crc16_get_arc(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    return pra_crc16_get(
        p_crc,
        0x8005U,
        0x0000U,
        0x0000U,
        PRA_BOOL_TRUE,
        PRA_BOOL_TRUE,
        p_ec);
}

pra_boolean pra_crc16_get_maxim(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    return pra_crc16_get(
        p_crc,
        0x8005U,
        0x0000U,
        0xFFFFU,
        PRA_BOOL_TRUE,
        PRA_BOOL_TRUE,
        p_ec);
}

pra_boolean pra_crc16_get_usb(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    return pra_crc16_get(
        p_crc,
        0x8005U,
        0xFFFFU,
        0xFFFFU,
        PRA_BOOL_TRUE,
        PRA_BOOL_TRUE,
        p_ec);
}

pra_boolean pra_crc16_get_modbus(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    return pra_crc16_get(
        p_crc,
        0x8005U,
        0xFFFFU,
        0x0000U,
        PRA_BOOL_TRUE,
        PRA_BOOL_TRUE,
        p_ec);
}

pra_boolean pra_crc16_get_ccitt_false(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    return pra_crc16_get(
        p_crc,
        0x1021U,
        0xFFFFU,
        0x0000U,
        PRA_BOOL_FALSE,
        PRA_BOOL_FALSE,
        p_ec);
}

pra_boolean pra_crc16_get_x25(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    return pra_crc16_get(
        p_crc,
        0x1021U,
        0xFFFFU,
        0xFFFFU,
        PRA_BOOL_TRUE,
        PRA_BOOL_TRUE,
        p_ec);
}

pra_boolean pra_crc16_get_xmodem(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    return pra_crc16_get(
        p_crc,
        0x1021U,
        0x0000U,
        0x0000U,
        PRA_BOOL_FALSE,
        PRA_BOOL_FALSE,
        p_ec);
}

pra_boolean pra_crc16_get_dnp(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec)
{
    return pra_crc16_get(
        p_crc,
        0x3D65U,
        0x0000U,
        0xFFFFU,
        PRA_BOOL_TRUE,
        PRA_BOOL_TRUE,
        p_ec);
}
