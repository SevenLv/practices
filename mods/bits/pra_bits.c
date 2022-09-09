/*
 * pra_bits.c
 * created on Mon Aug 29 2022
 * created by Seven Lv
 * comments:    functions of bit functions
 */

/* includes */
#include "pra_bits.h"
#include "pra_defs.h"
#include "pra_num_defs.h"

/* macros */

/* variables */
static uint8_t u8_masks[8] = {
    PRA_NUM_BIT_MASK_00,
    PRA_NUM_BIT_MASK_01,
    PRA_NUM_BIT_MASK_02,
    PRA_NUM_BIT_MASK_03,
    PRA_NUM_BIT_MASK_04,
    PRA_NUM_BIT_MASK_05,
    PRA_NUM_BIT_MASK_06,
    PRA_NUM_BIT_MASK_07
};

static uint8_t u8_reversed_masks[8] = {
    0xFEU, 0xFDU, 0xFBU, 0xF7U,
    0xEFU, 0xDFU, 0xBFU, 0x7FU
};

static uint16_t u16_masks[16] = {
    PRA_NUM_BIT_MASK_00, PRA_NUM_BIT_MASK_01,
    PRA_NUM_BIT_MASK_02, PRA_NUM_BIT_MASK_03,
    PRA_NUM_BIT_MASK_04, PRA_NUM_BIT_MASK_05,
    PRA_NUM_BIT_MASK_06, PRA_NUM_BIT_MASK_07,
    PRA_NUM_BIT_MASK_08, PRA_NUM_BIT_MASK_09,
    PRA_NUM_BIT_MASK_10, PRA_NUM_BIT_MASK_11,
    PRA_NUM_BIT_MASK_12, PRA_NUM_BIT_MASK_13,
    PRA_NUM_BIT_MASK_14, PRA_NUM_BIT_MASK_15
};

static uint16_t u16_reversed_masks[16] = {
    0xFFFEU, 0xFFFDU, 0xFFFBU, 0xFFF7U,
    0xFFEFU, 0xFFDFU, 0xFFBFU, 0xFF7FU,
    0xFEFFU, 0xFDFFU, 0xFBFFU, 0xF7FFU,
    0xEFFFU, 0xDFFFU, 0xBFFFU, 0x7FFFU
};

static uint32_t u32_masks[32] = {
    PRA_NUM_BIT_MASK_00, PRA_NUM_BIT_MASK_01,
    PRA_NUM_BIT_MASK_02, PRA_NUM_BIT_MASK_03,
    PRA_NUM_BIT_MASK_04, PRA_NUM_BIT_MASK_05,
    PRA_NUM_BIT_MASK_06, PRA_NUM_BIT_MASK_07,
    PRA_NUM_BIT_MASK_08, PRA_NUM_BIT_MASK_09,
    PRA_NUM_BIT_MASK_10, PRA_NUM_BIT_MASK_11,
    PRA_NUM_BIT_MASK_12, PRA_NUM_BIT_MASK_13,
    PRA_NUM_BIT_MASK_14, PRA_NUM_BIT_MASK_15,
    PRA_NUM_BIT_MASK_16, PRA_NUM_BIT_MASK_17,
    PRA_NUM_BIT_MASK_18, PRA_NUM_BIT_MASK_19,
    PRA_NUM_BIT_MASK_20, PRA_NUM_BIT_MASK_21,
    PRA_NUM_BIT_MASK_22, PRA_NUM_BIT_MASK_23,
    PRA_NUM_BIT_MASK_24, PRA_NUM_BIT_MASK_25,
    PRA_NUM_BIT_MASK_26, PRA_NUM_BIT_MASK_27,
    PRA_NUM_BIT_MASK_28, PRA_NUM_BIT_MASK_29,
    PRA_NUM_BIT_MASK_30, PRA_NUM_BIT_MASK_31
};

static uint32_t u32_reversed_masks[32] = {
    0xFFFFFFFEU, 0xFFFFFFFDU, 0xFFFFFFFBU, 0xFFFFFFF7U,
    0xFFFFFFEFU, 0xFFFFFFDFU, 0xFFFFFFBFU, 0xFFFFFF7FU,
    0xFFFFFEFFU, 0xFFFFFDFFU, 0xFFFFFBFFU, 0xFFFFF7FFU,
    0xFFFFEFFFU, 0xFFFFDFFFU, 0xFFFFBFFFU, 0xFFFF7FFFU,
    0xFFFEFFFFU, 0xFFFDFFFFU, 0xFFFBFFFFU, 0xFFF7FFFFU,
    0xFFEFFFFFU, 0xFFDFFFFFU, 0xFFBFFFFFU, 0xFF7FFFFFU,
    0xFEFFFFFFU, 0xFDFFFFFFU, 0xFBFFFFFFU, 0xF7FFFFFFU,
    0xEFFFFFFFU, 0xDFFFFFFFU, 0xBFFFFFFFU, 0x7FFFFFFFU
};

/* function declarations */

/**
 * @brief               arguments validation for pra_bits_u8_get function
 * @note
 * @param  bit_offset:  the offset of the bit
 * @param  p_actived:   output the bit is actived or not
 * @param  p_ec:        output error code:
 *                      PRA_BITS_EC_NULL_PTR
 *                      PRA_BITS_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_bits_u8_get_args_check(
    uint8_t                  bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const          p_ec);

/**
 * @brief               arguments validation for pra_bits_u8_set function
 * @note
 * @param  *p_value:    the pointer of the 8-bit value
 * @param  bit_offset:  the offset of the bit
 * @param  p_ec:        output error code:
 *                      PRA_BITS_EC_NULL_PTR
 *                      PRA_BITS_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_bits_u8_set_args_check(
    const uint8_t *const p_value,
    uint8_t              bit_offset,
    PRA_EC_T *const      p_ec);

/**
 * @brief               arguments validation for pra_bits_u16_get function
 * @note
 * @param  bit_offset:  the offset of the bit
 * @param  p_ec:        output error code:
 *                      PRA_BITS_EC_NULL_PTR
 *                      PRA_BITS_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_bits_u16_get_args_check(
    uint8_t                  bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const          p_ec);

/**
 * @brief               arguments validation for pra_bits_u16_set function
 * @note
 * @param  *p_value:    the pointer of the 16-bit value
 * @param  bit_offset:  the offset of the bit
 * @param  p_ec:        output error code:
 *                      PRA_BITS_EC_NULL_PTR
 *                      PRA_BITS_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_bits_u16_set_args_check(
    const uint16_t *const p_value,
    uint8_t               bit_offset,
    PRA_EC_T *const       p_ec);

/**
 * @brief               arguments validation for pra_bits_u32_get function
 * @note
 * @param  bit_offset:  the offset of the bit
 * @param  p_actived:   output the bit is actived or not
 * @param  p_ec:        output error code:
 *                      PRA_BITS_EC_NULL_PTR
 *                      PRA_BITS_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_bits_u32_get_args_check(
    uint8_t                  bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const          p_ec);

/**
 * @brief               arguments validation for pra_bits_u32_set function
 * @note
 * @param  *p_value:    the pointer of the 32-bit value
 * @param  bit_offset:  the offset of the bit
 * @param  p_ec:        output error code:
 *                      PRA_BITS_EC_NULL_PTR
 *                      PRA_BITS_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_bits_u32_set_args_check(
    const uint32_t *const p_value,
    uint8_t               bit_offset,
    PRA_EC_T *const       p_ec);

/**
 * @brief               arguments validation for pra_bits_u8_reverse function
 * @note
 * @param  p_new_value: the new 8-bit value
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_bits_u8_reverse_args_check(
    const uint8_t *const p_new_value);

/* functions */

static pra_boolean pra_bits_u8_get_args_check(
    uint8_t                  bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const          p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_NULL == p_actived)
    {
        *p_ec |= PRA_BITS_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BIT_MAX_OFFSET_U8 < bit_offset)
    {
        *p_ec |= PRA_BITS_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bits_u8_get(
    uint8_t            value,
    uint8_t            bit_offset,
    pra_boolean *const p_actived,
    PRA_EC_T *const    p_ec)
{
    pra_boolean result;
    uint8_t     mask;

    if (PRA_BOOL_TRUE != pra_bits_u8_get_args_check(
                             bit_offset,
                             p_actived,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        mask = u8_masks[bit_offset];

        if (mask == (value & mask))
        {
            *p_actived = PRA_BOOL_TRUE;
        }
        else
        {
            *p_actived = PRA_BOOL_FALSE;
        }

        result = PRA_BOOL_TRUE;
    }

    return result;
}

static pra_boolean pra_bits_u8_set_args_check(
    const uint8_t *const p_value,
    uint8_t              bit_offset,
    PRA_EC_T *const      p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == p_value)
    {
        *p_ec |= PRA_BITS_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BIT_MAX_OFFSET_U8 < bit_offset)
    {
        *p_ec |= PRA_BITS_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bits_u8_set(
    uint8_t *const  p_value,
    uint8_t         bit_offset,
    pra_boolean     actived,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_BOOL_TRUE != pra_bits_u8_set_args_check(
                             p_value,
                             bit_offset,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        if (PRA_BOOL_TRUE == pra_boolean_is_true(actived))
        {
            *p_value |= u8_masks[bit_offset];
        }
        else
        {
            *p_value &= u8_reversed_masks[bit_offset];
        }

        result = PRA_BOOL_TRUE;
    }

    return result;
}

static pra_boolean pra_bits_u16_get_args_check(
    uint8_t                  bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const          p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_NULL == p_actived)
    {
        *p_ec |= PRA_BITS_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BIT_MAX_OFFSET_U16 < bit_offset)
    {
        *p_ec |= PRA_BITS_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bits_u16_get(
    uint16_t           value,
    uint8_t            bit_offset,
    pra_boolean *const p_actived,
    PRA_EC_T *const    p_ec)
{
    pra_boolean result;
    uint16_t    mask;

    if (PRA_BOOL_TRUE != pra_bits_u16_get_args_check(
                             bit_offset,
                             p_actived,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        mask = u16_masks[bit_offset];

        if (mask == (value & mask))
        {
            *p_actived = PRA_BOOL_TRUE;
        }
        else
        {
            *p_actived = PRA_BOOL_FALSE;
        }

        result = PRA_BOOL_TRUE;
    }

    return result;
}

static pra_boolean pra_bits_u16_set_args_check(
    const uint16_t *const p_value,
    uint8_t               bit_offset,
    PRA_EC_T *const       p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT16_NULL == p_value)
    {
        *p_ec |= PRA_BITS_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BIT_MAX_OFFSET_U16 < bit_offset)
    {
        *p_ec |= PRA_BITS_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bits_u16_set(
    uint16_t *const p_value,
    uint8_t         bit_offset,
    pra_boolean     actived,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_BOOL_TRUE != pra_bits_u16_set_args_check(
                             p_value,
                             bit_offset,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        if (PRA_BOOL_TRUE == pra_boolean_is_true(actived))
        {
            *p_value |= u16_masks[bit_offset];
        }
        else
        {
            *p_value &= u16_reversed_masks[bit_offset];
        }

        result = PRA_BOOL_TRUE;
    }

    return result;
}

static pra_boolean pra_bits_u32_get_args_check(
    uint8_t                  bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const          p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_NULL == p_actived)
    {
        *p_ec |= PRA_BITS_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BIT_MAX_OFFSET_U32 < bit_offset)
    {
        *p_ec |= PRA_BITS_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bits_u32_get(
    uint32_t           value,
    uint8_t            bit_offset,
    pra_boolean *const p_actived,
    PRA_EC_T *const    p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_bits_u32_get_args_check(
                             bit_offset,
                             p_actived,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint32_t mask = u32_masks[bit_offset];

        if (mask == (mask & value))
        {
            *p_actived = PRA_BOOL_TRUE;
        }
        else
        {
            *p_actived = PRA_BOOL_FALSE;
        }

        result = PRA_BOOL_TRUE;
    }

    return result;
}

static pra_boolean pra_bits_u32_set_args_check(
    const uint32_t *const p_value,
    uint8_t               bit_offset,
    PRA_EC_T *const       p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT32_NULL == p_value)
    {
        *p_ec |= PRA_BITS_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BIT_MAX_OFFSET_U32 < bit_offset)
    {
        *p_ec |= PRA_BITS_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bits_u32_set(
    uint32_t *const p_value,
    uint8_t         bit_offset,
    pra_boolean     actived,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_BOOL_TRUE != pra_bits_u32_set_args_check(
                             p_value,
                             bit_offset,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        if (PRA_BOOL_TRUE == pra_boolean_is_true(actived))
        {
            *p_value |= u32_masks[bit_offset];
        }
        else
        {
            *p_value &= u32_reversed_masks[bit_offset];
        }

        result = PRA_BOOL_TRUE;
    }

    return result;
}

static pra_boolean pra_bits_u8_reverse_args_check(
    const uint8_t *const p_new_value)
{
    pra_boolean result;

    if (PRA_UINT8_NULL == p_new_value)
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bits_u8_reverse(
    uint8_t        value,
    uint8_t *const p_new_value)
{
    pra_boolean result;
    pra_boolean actived;
    uint32_t    error_code = PRA_BITS_EC_NONE;
    pra_boolean failed = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_bits_u8_reverse_args_check(
                             p_new_value))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        *p_new_value = PRA_NUM_ZERO_U;

        for (uint8_t i = PRA_NUM_ZERO_U; i < PRA_NUM_BIT_WIDTH_U8; i++)
        {
            if (PRA_BOOL_FALSE == failed)
            {
                if (PRA_BOOL_TRUE == pra_bits_u8_get(
                                         value,
                                         i,
                                         &actived,
                                         &error_code))
                {
                    if (PRA_BOOL_TRUE != pra_bits_u8_set(
                                             p_new_value,
                                             PRA_NUM_BIT_MAX_OFFSET_U8 - i,
                                             actived,
                                             &error_code))
                    {
                        failed = PRA_BOOL_TRUE;
                    }
                }
                else
                {
                    failed = PRA_BOOL_TRUE;
                }
            }
            else
            {
                /* NOTE do nothing */
            }
        }

        result = pra_boolean_not(failed);
    }

    return result;
}

pra_boolean pra_bits_u16_reverse(
    uint16_t        value,
    uint16_t *const p_new_value)
{
    pra_boolean result;
    pra_boolean actived;
    uint32_t    error_code = PRA_BITS_EC_NONE;
    pra_boolean failed = PRA_BOOL_FALSE;

    if (PRA_UINT16_NULL != p_new_value)
    {
        *p_new_value = PRA_NUM_ZERO_U;

        for (uint8_t i = PRA_NUM_ZERO_U; i < PRA_NUM_BIT_WIDTH_U16; i++)
        {
            if (PRA_BOOL_FALSE == failed)
            {
                if (PRA_BOOL_TRUE == pra_bits_u16_get(
                                         value,
                                         i,
                                         &actived,
                                         &error_code))
                {
                    if (PRA_BOOL_TRUE != pra_bits_u16_set(
                                             p_new_value,
                                             PRA_NUM_BIT_MAX_OFFSET_U16 - i,
                                             actived,
                                             &error_code))
                    {
                        failed = PRA_BOOL_TRUE;
                    }
                }
                else
                {
                    failed = PRA_BOOL_TRUE;
                }
            }
            else
            {
                /* NOTE do nothing */
            }
        }

        result = pra_boolean_not(failed);
    }
    else
    {
        result = PRA_BOOL_FALSE;
    }

    return result;
}

pra_boolean pra_bits_u32_reverse(
    uint32_t        value,
    uint32_t *const p_new_value)
{
    pra_boolean result;
    pra_boolean actived;
    uint32_t    error_code = PRA_BITS_EC_NONE;
    pra_boolean failed = PRA_BOOL_FALSE;

    if (PRA_UINT32_NULL != p_new_value)
    {
        *p_new_value = PRA_NUM_ZERO_U;

        for (uint8_t i = PRA_NUM_ZERO_U; i < PRA_NUM_BIT_WIDTH_U32; i++)
        {
            if (PRA_BOOL_FALSE == failed)
            {
                if (PRA_BOOL_TRUE == pra_bits_u32_get(
                                         value,
                                         i,
                                         &actived,
                                         &error_code))
                {
                    if (PRA_BOOL_TRUE != pra_bits_u32_set(
                                             p_new_value,
                                             PRA_NUM_BIT_MAX_OFFSET_U32 - i,
                                             actived,
                                             &error_code))
                    {
                        failed = PRA_BOOL_TRUE;
                    }
                }
                else
                {
                    failed = PRA_BOOL_TRUE;
                }
            }
            else
            {
                /* NOTE do nothing */
            }
        }

        result = pra_boolean_not(failed);
    }
    else
    {
        result = PRA_BOOL_FALSE;
    }

    return result;
}
