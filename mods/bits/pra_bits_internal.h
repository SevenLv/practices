/*
 * pra_bits_internal.h
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    internal functions of pra_bits
 * version: 0.3
 * history: #       date                modification
 *          0.1     Tue Sep 13 2022     created
 *          0.2     Wed Sep 14 2022     change include file
 *          0.3     Thu Sep 29 2022     reorganize error codes
 */

#ifndef INC_PRA_BITS_INTERNAL_H_
#define INC_PRA_BITS_INTERNAL_H_

/* includes */

#include "pra_boolean_types.h"
#include "pra_defs.h"
#include "pra_ec.h"
#include "stdint.h"

/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief               arguments validation for pra_bits_u8_get function
 * @note
 * @param  bit_offset:  the offset of the bit
 * @param  p_actived:   output the bit is actived or not
 * @param  p_ec:        output error code:
 *                      PRA_EC_NULL_PTR
 *                      PRA_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u8_get_args_check(
    uint8_t                  bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const          p_ec);

/**
 * @brief               arguments validation for pra_bits_u8_set function
 * @note
 * @param  *p_value:    the pointer of the 8-bit value
 * @param  bit_offset:  the offset of the bit
 * @param  p_ec:        output error code:
 *                      PRA_EC_NULL_PTR
 *                      PRA_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u8_set_args_check(
    const uint8_t *const p_value,
    uint8_t              bit_offset,
    PRA_EC_T *const      p_ec);

/**
 * @brief               arguments validation for pra_bits_u16_get function
 * @note
 * @param  bit_offset:  the offset of the bit
 * @param  p_ec:        output error code:
 *                      PRA_EC_NULL_PTR
 *                      PRA_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u16_get_args_check(
    uint8_t                  bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const          p_ec);

/**
 * @brief               arguments validation for pra_bits_u16_set function
 * @note
 * @param  *p_value:    the pointer of the 16-bit value
 * @param  bit_offset:  the offset of the bit
 * @param  p_ec:        output error code:
 *                      PRA_EC_NULL_PTR
 *                      PRA_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u16_set_args_check(
    const uint16_t *const p_value,
    uint8_t               bit_offset,
    PRA_EC_T *const       p_ec);

/**
 * @brief               arguments validation for pra_bits_u32_get function
 * @note
 * @param  bit_offset:  the offset of the bit
 * @param  p_actived:   output the bit is actived or not
 * @param  p_ec:        output error code:
 *                      PRA_EC_NULL_PTR
 *                      PRA_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u32_get_args_check(
    uint8_t                  bit_offset,
    const pra_boolean *const p_actived,
    PRA_EC_T *const          p_ec);

/**
 * @brief               arguments validation for pra_bits_u32_set function
 * @note
 * @param  *p_value:    the pointer of the 32-bit value
 * @param  bit_offset:  the offset of the bit
 * @param  p_ec:        output error code:
 *                      PRA_EC_NULL_PTR
 *                      PRA_EC_INVALID_OFFSET
 * @retval              PRA_BOOL_TRUE - success;PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u32_set_args_check(
    const uint32_t *const p_value,
    uint8_t               bit_offset,
    PRA_EC_T *const       p_ec);

/**
 * @brief               arguments validation for pra_bits_u8_reverse function
 * @note
 * @param  p_new_value: the new 8-bit value
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bits_u8_reverse_args_check(
    const uint8_t *const p_new_value);

#endif