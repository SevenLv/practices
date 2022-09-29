/*
 * pra_crc32.h
 * created on Fri Sep 02 2022
 * created by Seven Lv
 * comments:    function definitions of crc32
 * version: 0.5
 * history: #       date                modification
 *          0.1     Fri Sep 02 2022     created
 *          0.2     Wed Sep 14 2022     include pra_boolean_types.h
 *                                      move type definitions to pra_crc32_types.h
 *          0.3     Wed Sep 14 2022     update file header comments
 *          0.4     Thu Sep 15 2022     include pra_ec.h
 *          0.5     Thu Sep 29 2022     reorganize error codes
 */

#ifndef INC_PRA_CRC32_H_
#define INC_PRA_CRC32_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_crc.h"
#include "pra_crc32_types.h"
#include "pra_defs.h"
#include "pra_ec.h"
#include "stdint.h"


/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief           initialize the crc32 struct
 * @note
 * @param  p_crc:   the crc struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc32_init(
    pra_crc32 *const p_crc,
    PRA_EC_T *const  p_ec);

/**
 * @brief               compute crc32
 * @note
 * @param  p_crc:       the crc struct pointer
 * @param  bytes:       the bytes to compute
 * @param  offset:      the start position, base zero
 * @param  length:      length of the bytes
 * @param  p_result:    the crc result
 * @param  p_ec:        output error code:
 *                      PRA_EC_NULL_PTR
 *                      PRA_EC_NOT_INIT
 *                      PRA_EC_INVALID_OFFSET
 *                      PRA_EC_INVALID_LENGTH
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc32_compute(
    const pra_crc32 *const p_crc,
    const uint8_t *const   bytes,
    uint32_t               offset,
    uint32_t               length,
    uint32_t *const        p_result,
    PRA_EC_T *const        p_ec);

/**
 * @brief                   get new crc-32 struct
 * @note
 * @param  p_crc:           the crc-32 struct pointer
 * @param  polynomial:      polynomial
 * @param  initial_value:   initial value
 * @param  xor_out:         xor out
 * @param  ref_in:          ref in
 * @param  ref_out:         ref out
 * @param  p_ec:            output error code:
 *                          PRA_EC_NULL_PTR
 * @retval                  PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc32_get(
    pra_crc32 *const p_crc,
    uint32_t         polynomial,
    uint32_t         initial_value,
    uint32_t         xor_out,
    pra_boolean      ref_in,
    pra_boolean      ref_out,
    PRA_EC_T *const  p_ec);

/**
 * @brief           get new crc-32/default struct
 * @note
 * @param  p_crc:   the crc-32 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc32_get_default(
    pra_crc32 *const p_crc,
    PRA_EC_T *const  p_ec);

/**
 * @brief           get new crc-32/mpeg2 struct
 * @note
 * @param  p_crc:   the crc-32 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc32_get_mpeg2(
    pra_crc32 *const p_crc,
    PRA_EC_T *const  p_ec);

/**
 * @brief           get new crc-32/bzip2 struct
 * @note
 * @param  p_crc:   the crc-32 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc32_get_bzip2(
    pra_crc32 *const p_crc,
    PRA_EC_T *const  p_ec);

/**
 * @brief           get new crc-32/posix struct
 * @note
 * @param  p_crc:   the crc-32 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc32_get_posix(
    pra_crc32 *const p_crc,
    PRA_EC_T *const  p_ec);

/**
 * @brief           get new crc-32/jamcrc struct
 * @note
 * @param  p_crc:   the crc-32 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc32_get_jamcrc(
    pra_crc32 *const p_crc,
    PRA_EC_T *const  p_ec);

#endif