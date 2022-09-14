/*
 * pra_crc8_internal.h
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    internal functions of pra_crc8
 * version: 0.2
 * history: #       date                modification
 *          0.1     Tue Sep 13 2022     created
 *          0.2     Wed Sep 14 2022     include pra_crc8_types.h
 */

#ifndef INC_PRA_CRC8_INTERNAL_H_
#define INC_PRA_CRC8_INTERNAL_H_

/* includes */
#include "pra_crc8_types.h"

/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief           arguments validation for pra_crc8_init function
 * @note
 * @param  p_crc:   the crc struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_init_args_check(
    const pra_crc8 *const p_crc,
    PRA_EC_T *const       p_ec);

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
pra_boolean pra_crc8_compute_args_check(
    const pra_crc8 *const p_crc,
    const uint8_t *const  bytes,
    uint32_t              offset,
    uint32_t              length,
    const uint8_t *const  p_result,
    PRA_EC_T *const       p_ec);
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
pra_boolean pra_crc8_get_args_check(
    const pra_crc8 *const p_crc,
    pra_boolean           ref_in,
    pra_boolean           ref_out,
    PRA_EC_T *const       p_ec);

#endif