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
#define MIN_OFFSET 0U
#define MAX_U8_OFFSET 7U
#define MAX_U16_OFFSET 15U
#define MAX_U32_OFFSET 31U

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

/* functions */

pra_boolean pra_bits_u8_get(
    uint8_t value,
    uint8_t bit_offset,
    pra_boolean *const p_actived,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    uint8_t mask = 0U;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_NULL == p_actived)
    {
        *p_ec |= PRA_BITS_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (MAX_U8_OFFSET < bit_offset)
    {
        *p_ec |= PRA_BITS_EC_INVALID_OFFSET;
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

pra_boolean pra_bits_u8_set(
    uint8_t *const p_value,
    uint8_t bit_offset,
    pra_boolean actived,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == p_value)
    {
        *p_ec |= PRA_BITS_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (MAX_U8_OFFSET < bit_offset)
    {
        *p_ec |= PRA_BITS_EC_INVALID_OFFSET;
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

pra_boolean pra_bits_u16_get(
    uint16_t value,
    uint8_t bit_offset,
    pra_boolean *const p_actived,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    uint16_t mask = 0U;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_NULL == p_actived)
    {
        *p_ec |= PRA_BITS_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (MAX_U16_OFFSET < bit_offset)
    {
        *p_ec |= PRA_BITS_EC_INVALID_OFFSET;
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

pra_boolean pra_bits_u16_set(
    uint16_t *const p_value,
    uint8_t bit_offset,
    pra_boolean actived,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT16_NULL == p_value)
    {
        *p_ec |= PRA_BITS_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (MAX_U16_OFFSET < bit_offset)
    {
        *p_ec |= PRA_BITS_EC_INVALID_OFFSET;
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

pra_boolean pra_bits_u32_get(
    uint32_t value,
    uint8_t bit_offset,
    pra_boolean *const p_actived,
    uint32_t *const p_ec)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    uint32_t mask = 0U;

    if (PRA_UINT32_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_NULL == p_actived)
    {
        *p_ec |= PRA_BITS_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (MAX_U32_OFFSET < bit_offset)
    {
        *p_ec |= PRA_BITS_EC_INVALID_OFFSET;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        mask = u32_masks[bit_offset];
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