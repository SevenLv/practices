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

/* variables */
static uint8_t u8_masks[8] = {
    0x01U, 0x02U, 0x04U, 0x08U,
    0x10U, 0x20U, 0x40U, 0x80U};

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
        *p_ec |= PRA_BITS_INVALID_OFFSET;
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