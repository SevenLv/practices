/*
 * pra_crc16_internal.h
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    internal functions of pra_crc16
 * version: 0.3
 * history: #       date                modification
 *          0.1     Tue Sep 13 2022     created
 *          0.2     Wed Sep 14 2022     include pra_crc16_types.h
 *          0.3     Thu Sep 15 2022     include pra_ec.h
 */

#ifndef INC_PRA_CRC16_INTERNAL_H_
#define INC_PRA_CRC16_INTERNAL_H_

/* includes */
#include "pra_crc16_types.h"
#include "pra_ec.h"

/* macros */
#define MASK_H1 0x8000U

/* types */

/* variables */

/* functions */

/**
 * @brief           arguments validation for pra_crc16_init function
 * @note
 * @param  p_crc:   the crc struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_init_args_check(
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
pra_boolean pra_crc16_compute_args_check(
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
pra_boolean pra_crc16_get_args_check(
    const pra_crc16 *const p_crc,
    pra_boolean            ref_in,
    pra_boolean            ref_out,
    PRA_EC_T *const        p_ec);

#endif