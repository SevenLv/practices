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
#include "pra_defs.h"
#include "pra_num_defs.h"
#include "stdint.h"

/* macros */

#define PRA_BITS_EC_NONE PRA_NUM_ZERO_U                /* no error */
#define PRA_BITS_EC_NULL_PTR PRA_NUM_BIT_MASK_00       /* null pointer */
#define PRA_BITS_EC_INVALID_OFFSET PRA_NUM_BIT_MASK_01 /* invalid bit offset */

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
 *                      PRA_BITS_EC_NULL_PTR
 *                      PRA_BITS_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u8_get(
    uint8_t value,
    uint8_t bit_offset,
    pra_boolean *const p_actived,
    PRA_EC_T *const p_ec);

/**
 * @brief               set the bit state of a 8-bit value
 * @note
 * @param  *p_value:    the pointer of the 8-bit value
 * @param  bit_offset:  the offset of the bit
 * @param  actived:     the bit state
 * @param  p_ec:        output error code:
 *                      PRA_BITS_EC_NULL_PTR
 *                      PRA_BITS_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u8_set(
    uint8_t *const p_value,
    uint8_t bit_offset,
    pra_boolean actived,
    PRA_EC_T *const p_ec);

/**
 * @brief               get the bit state of a 16-bit value
 * @note
 * @param  value:       the 16-bit value
 * @param  bit_offset:  the offset of the bit
 * @param  p_actived:   output the bit is actived or not
 * @param  p_ec:        output error code:
 *                      PRA_BITS_EC_NULL_PTR
 *                      PRA_BITS_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u16_get(
    uint16_t value,
    uint8_t bit_offset,
    pra_boolean *const p_actived,
    PRA_EC_T *const p_ec);

/**
 * @brief               set the bit state of a 16-bit value
 * @note
 * @param  *p_value:    the pointer of the 16-bit value
 * @param  bit_offset:  the offset of the bit
 * @param  actived:     the bit state
 * @param  p_ec:        output error code:
 *                      PRA_BITS_EC_NULL_PTR
 *                      PRA_BITS_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u16_set(
    uint16_t *const p_value,
    uint8_t bit_offset,
    pra_boolean actived,
    PRA_EC_T *const p_ec);

/**
 * @brief               get the bit state of a 32-bit value
 * @note
 * @param  value:       the 32-bit value
 * @param  bit_offset:  the offset of the bit
 * @param  p_actived:   output the bit is actived or not
 * @param  p_ec:        output error code:
 *                      PRA_BITS_EC_NULL_PTR
 *                      PRA_BITS_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u32_get(
    uint32_t value,
    uint8_t bit_offset,
    pra_boolean *const p_actived,
    PRA_EC_T *const p_ec);

/**
 * @brief               set the bit state of a 32-bit value
 * @note
 * @param  *p_value:    the pointer of the 32-bit value
 * @param  bit_offset:  the offset of the bit
 * @param  actived:     the bit state
 * @param  p_ec:        output error code:
 *                      PRA_BITS_EC_NULL_PTR
 *                      PRA_BITS_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u32_set(
    uint32_t *const p_value,
    uint8_t bit_offset,
    pra_boolean actived,
    PRA_EC_T *const p_ec);

/**
 * @brief               reverse bits
 * @note
 * @param  value:       the 8-bit value
 * @param  p_new_value: the new 8-bit value
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u8_reverse(
    uint8_t value,
    uint8_t *const p_new_value);

/**
 * @brief               reverse bits
 * @note
 * @param  value:       the 16-bit value
 * @param  p_new_value: the new 16-bit value
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u16_reverse(
    uint16_t value,
    uint16_t *const p_new_value);

/**
 * @brief               reverse bits
 * @note
 * @param  value:       the 32-bit value
 * @param  p_new_value: the new 32-bit value
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u32_reverse(
    uint32_t value,
    uint32_t *const p_new_value);

#endif