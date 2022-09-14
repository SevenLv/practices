/*
 * pra_crc16.h
 * created on Fri Sep 02 2022
 * created by Seven Lv
 * comments:    function definitions of crc16
 * version: 0.3
 * history: #       date                modification
 *          0.1     Fri Sep 02 2022     created
 *          0.2     Wed Sep 14 2022     include pra_boolean_types.h
 *                                      move type definitions to pra_crc16_types.h
 *          0.3     Wed Sep 14 2022     update file header comments
 */

#ifndef INC_PRA_CRC16_H_
#define INC_PRA_CRC16_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_crc.h"
#include "pra_crc16_types.h"
#include "pra_defs.h"
#include "stdint.h"


/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief           initialize the crc16 struct
 * @note
 * @param  p_crc:   the crc struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_init(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec);

/**
 * @brief               compute crc16
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
pra_boolean pra_crc16_compute(
    const pra_crc16 *const p_crc,
    const uint8_t *const   bytes,
    uint32_t               offset,
    uint32_t               length,
    uint16_t *const        p_result,
    PRA_EC_T *const        p_ec);

/**
 * @brief                   get new crc-16 struct
 * @note
 * @param  p_crc:           the crc-16 struct pointer
 * @param  polynomial:      polynomial
 * @param  initial_value:   initial value
 * @param  xor_out:         xor out
 * @param  ref_in:          ref in
 * @param  ref_out:         ref out
 * @param  p_ec:            output error code:
 *                          PRA_CRC_EC_NULL_PTR
 * @retval                  PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get(
    pra_crc16 *const p_crc,
    uint16_t         polynomial,
    uint16_t         initial_value,
    uint16_t         xor_out,
    pra_boolean      ref_in,
    pra_boolean      ref_out,
    PRA_EC_T *const  p_ec);

/**
 * @brief           get new crc-16/arc struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_arc(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec);

/**
 * @brief           get new crc-16/maxim struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_maxim(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec);

/**
 * @brief           get new crc-16/usb struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_usb(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec);

/**
 * @brief           get new crc-16/modbus struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_modbus(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec);

/**
 * @brief           get new crc-16/ccitt-false struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_ccitt_false(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec);

/**
 * @brief           get new crc-16/x25 struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_x25(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec);

/**
 * @brief           get new crc-16/xmodem struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_xmodem(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec);

/**
 * @brief           get new crc-16/dnp struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_dnp(
    pra_crc16 *const p_crc,
    PRA_EC_T *const  p_ec);

#endif