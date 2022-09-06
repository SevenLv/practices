/*
 * pra_bits.c
 * created on Mon Aug 29 2022
 * created by Seven Lv
 * comments:    functions of bit functions
 */

/* includes */
#include "pra_bits.h"
#include "pra_defs.h"

/* macros */

/* variables */
static uint8_t u8_masks[8] = {
    0x01U, 0x02U, 0x04U, 0x08U,
    0x10U, 0x20U, 0x40U, 0x80U};

static uint8_t u8_reversed_masks[8] = {
    0xFEU, 0xFDU, 0xFBU, 0xF7U,
    0xEFU, 0xDFU, 0xBFU, 0x7FU};

static uint16_t u16_masks[16] = {
    0x0001U, 0x0002U, 0x0004U, 0x0008U,
    0x0010U, 0x0020U, 0x0040U, 0x0080U,
    0x0100U, 0x0200U, 0x0400U, 0x0800U,
    0x1000U, 0x2000U, 0x4000U, 0x8000U};

static uint16_t u16_reversed_masks[16] = {
    0xFFFEU, 0xFFFDU, 0xFFFBU, 0xFFF7U,
    0xFFEFU, 0xFFDFU, 0xFFBFU, 0xFF7FU,
    0xFEFFU, 0xFDFFU, 0xFBFFU, 0xF7FFU,
    0xEFFFU, 0xDFFFU, 0xBFFFU, 0x7FFFU};

static uint32_t u32_masks[32] = {
    0x00000001U, 0x00000002U, 0x00000004U, 0x00000008U,
    0x00000010U, 0x00000020U, 0x00000040U, 0x00000080U,
    0x00000100U, 0x00000200U, 0x00000400U, 0x00000800U,
    0x00001000U, 0x00002000U, 0x00004000U, 0x00008000U,
    0x00010000U, 0x00020000U, 0x00040000U, 0x00080000U,
    0x00100000U, 0x00200000U, 0x00400000U, 0x00800000U,
    0x01000000U, 0x02000000U, 0x04000000U, 0x08000000U,
    0x10000000U, 0x20000000U, 0x40000000U, 0x80000000U};

static uint32_t u32_reversed_masks[32] = {
    0xFFFFFFFEU, 0xFFFFFFFDU, 0xFFFFFFFBU, 0xFFFFFFF7U,
    0xFFFFFFEFU, 0xFFFFFFDFU, 0xFFFFFFBFU, 0xFFFFFF7FU,
    0xFFFFFEFFU, 0xFFFFFDFFU, 0xFFFFFBFFU, 0xFFFFF7FFU,
    0xFFFFEFFFU, 0xFFFFDFFFU, 0xFFFFBFFFU, 0xFFFF7FFFU,
    0xFFFEFFFFU, 0xFFFDFFFFU, 0xFFFBFFFFU, 0xFFF7FFFFU,
    0xFFEFFFFFU, 0xFFDFFFFFU, 0xFFBFFFFFU, 0xFF7FFFFFU,
    0xFEFFFFFFU, 0xFDFFFFFFU, 0xFBFFFFFFU, 0xF7FFFFFFU,
    0xEFFFFFFFU, 0xDFFFFFFFU, 0xBFFFFFFFU, 0x7FFFFFFFU};

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
    uint8_t bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const p_ec);

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
    uint8_t bit_offset,
    PRA_EC_T *const p_ec);

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
    uint8_t bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const p_ec);

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
    uint8_t bit_offset,
    PRA_EC_T *const p_ec);

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
    uint8_t bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const p_ec);

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
    uint8_t bit_offset,
    PRA_EC_T *const p_ec);

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
    uint8_t bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const p_ec)
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
    else if (PRA_BITS_U8_MAX_OFFSET < bit_offset)
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
    uint8_t value,
    uint8_t bit_offset,
    pra_boolean *const p_actived,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;
    uint8_t mask;

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
    uint8_t bit_offset,
    PRA_EC_T *const p_ec)
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
    else if (PRA_BITS_U8_MAX_OFFSET < bit_offset)
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
    uint8_t *const p_value,
    uint8_t bit_offset,
    pra_boolean actived,
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
    uint8_t bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const p_ec)
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
    else if (PRA_BITS_U16_MAX_OFFSET < bit_offset)
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
    uint16_t value,
    uint8_t bit_offset,
    pra_boolean *const p_actived,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;
    uint16_t mask;

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
    uint8_t bit_offset,
    PRA_EC_T *const p_ec)
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
    else if (PRA_BITS_U16_MAX_OFFSET < bit_offset)
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
    uint8_t bit_offset,
    pra_boolean actived,
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
    uint8_t bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const p_ec)
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
    else if (PRA_BITS_U32_MAX_OFFSET < bit_offset)
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
    uint32_t value,
    uint8_t bit_offset,
    pra_boolean *const p_actived,
    PRA_EC_T *const p_ec)
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
    uint8_t bit_offset,
    PRA_EC_T *const p_ec)
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
    else if (PRA_BITS_U32_MAX_OFFSET < bit_offset)
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
    uint8_t bit_offset,
    pra_boolean actived,
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
    uint8_t value,
    uint8_t *const p_new_value)
{
    pra_boolean result;
    pra_boolean actived;
    uint32_t error_code = PRA_BITS_EC_NONE;
    pra_boolean failed = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_bits_u8_reverse_args_check(
                             p_new_value))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        *p_new_value = 0U;
        for (uint8_t i = 0U; i < PRA_BITS_U8_WIDTH; i++)
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
                                             PRA_BITS_U8_MAX_OFFSET - i,
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
    uint16_t value,
    uint16_t *const p_new_value)
{
    pra_boolean result;
    pra_boolean actived;
    uint32_t error_code = PRA_BITS_EC_NONE;
    pra_boolean failed = PRA_BOOL_FALSE;

    if (PRA_UINT16_NULL != p_new_value)
    {
        *p_new_value = 0U;
        for (uint8_t i = 0U; i < PRA_BITS_U16_WITDH; i++)
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
                                             PRA_BITS_U16_MAX_OFFSET - i,
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
    uint32_t value,
    uint32_t *const p_new_value)
{
    pra_boolean result;
    pra_boolean actived;
    uint32_t error_code = PRA_BITS_EC_NONE;
    pra_boolean failed = PRA_BOOL_FALSE;

    if (PRA_UINT32_NULL != p_new_value)
    {
        *p_new_value = 0U;
        for (uint8_t i = 0U; i < PRA_BITS_U32_WITDH; i++)
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
                                             PRA_BITS_U32_MAX_OFFSET - i,
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
