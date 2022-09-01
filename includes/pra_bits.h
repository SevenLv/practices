/*
 * pra_bits.h
 * created on Mon Aug 29 2022
 * created by Seven Lv
 * comments:    functions of bit functions
 */

#ifndef INC_PRA_BITS_H_
#define INC_PRA_BITS_H_

/* includes */
#include "pra_boolean.h"
#include "stdint.h"

/* macros */

#define PRA_BITS_EC_NONE 0x0U           /* no error */
#define PRA_BITS_EC_NULL_PTR 0x1U       /* null pointer */
#define PRA_BITS_EC_INVALID_OFFSET 0x2U /* invalid bit offset */

/* types */

/* variables */

/* functions */

/**
 * @brief               get the bit state of a 8-bit value
 * @note
 * @param  value:       the 8-bit value
 * @param  bit_offset:  the offset of the bit
 * @param  p_actived:   output the bit is actived or not
 * @param  p_ec:        output error code:
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u8_get(
    uint8_t value,
    uint8_t bit_offset,
    pra_boolean *const p_actived,
    uint32_t *const p_ec);

#endif