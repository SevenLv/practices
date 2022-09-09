/*
 * pra_crc8.h
 * created on Thu Sep 01 2022
 * created by Seven Lv
 * comments:    functions of crc8
 */

#ifndef INC_PRA_CRC8_H_
#define INC_PRA_CRC8_H_

/* includes */
#include "pra_boolean.h"
#include "pra_crc.h"
#include "pra_defs.h"
#include "stdint.h"

/* macros */
#define PRA_CRC8_NULL PRA_NULL_PTR(pra_crc8)

/* types */

/* crc8 struct */
typedef struct _pra_crc8
{
    pra_boolean initialized;               /* initialized flag */
    uint8_t     table[PRA_CRC_TABLE_SIZE]; /* the crc8 table */
    uint8_t     polynomial;                /* polynomial */
    uint8_t     initial_value;             /* initial value */
    uint8_t     xor_out;                   /* xor out*/
    pra_boolean ref_in;                    /* ref in */
    pra_boolean ref_out;                   /* ref out */
} pra_crc8;

/* variables */

/* functions */

/**
 * @brief           initialize the crc8 struct
 * @note
 * @param  p_crc:   the crc struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_init(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec);

/**
 * @brief               compute crc8
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
pra_boolean pra_crc8_compute(
    const pra_crc8 *const p_crc,
    const uint8_t *const  bytes,
    uint32_t              offset,
    uint32_t              length,
    uint8_t *const        p_result,
    PRA_EC_T *const       p_ec);

/**
 * @brief                   get new crc-8 struct
 * @note
 * @param  p_crc:           the crc-8 struct pointer
 * @param  polynomial:      polynomial
 * @param  initial_value:   initial value
 * @param  xor_out:         xor out
 * @param  ref_in:          ref in
 * @param  ref_out:         ref out
 * @param  p_ec:            output error code:
 *                          PRA_CRC_EC_NULL_PTR
 * @retval                  PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_get(
    pra_crc8 *const p_crc,
    uint8_t         polynomial,
    uint8_t         initial_value,
    uint8_t         xor_out,
    pra_boolean     ref_in,
    pra_boolean     ref_out,
    PRA_EC_T *const p_ec);

/**
 * @brief           get new crc-8 struct
 * @note
 * @param  p_crc:   the crc-8 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_get_default(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec);

/**
 * @brief           get new crc-8/itu struct
 * @note
 * @param  p_crc:   the crc-8 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_get_itu(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec);

/**
 * @brief           get new crc-8/rohc struct
 * @note
 * @param  p_crc:   the crc-8 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_get_rohc(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec);

/**
 * @brief           get new crc-8/maxim struct
 * @note
 * @param  p_crc:   the crc-8 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_get_maxim(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec);

/**
 * @brief           get new crc-8/cdma2000 struct
 * @note
 * @param  p_crc:   the crc-8 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_get_cdma2000(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec);

/**
 * @brief           get new crc-8/wcdma struct
 * @note
 * @param  p_crc:   the crc-8 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_get_wcdma(
    pra_crc8 *const p_crc,
    PRA_EC_T *const p_ec);
#endif