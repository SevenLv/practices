/*
 * pra_crc32.h
 * created on Fri Sep 02 2022
 * created by Seven Lv
 * comments:    functions of crc32
 */

#ifndef INC_PRA_CRC32_H_
#define INC_PRA_CRC32_H_

/* includes */
#include "pra_boolean.h"
#include "pra_crc.h"
#include "stdint.h"

/* macros */
#define PRA_CRC32_NULL ((pra_crc32 *)0)

/* types */

/* crc16 struct */
typedef struct _pra_crc32
{
    pra_boolean initialized;            /* initialized flag */
    uint32_t table[PRA_CRC_TABLE_SIZE]; /* the crc32 table */
    uint32_t polynomial;                /* polynomial */
    uint32_t initial_value;             /* initial value */
    uint32_t xor_out;                   /* xor out */
    pra_boolean ref_in;                 /* ref in */
    pra_boolean ref_out;                /* ref out */
} pra_crc32;

/* variables */

/* functions */

/**
 * @brief           initialize the crc32 struct
 * @note
 * @param  p_crc:   the crc struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc32_init(
    pra_crc32 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief               compute crc32
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
pra_boolean pra_crc32_compute(
    const pra_crc32 *const p_crc,
    const uint8_t *const bytes,
    uint32_t offset,
    uint32_t length,
    uint32_t *const p_result,
    uint32_t *const p_ec);

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
 *                          PRA_CRC_EC_NULL_PTR
 * @retval                  PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc32_get(
    pra_crc32 *const p_crc,
    uint32_t polynomial,
    uint32_t initial_value,
    uint32_t xor_out,
    pra_boolean ref_in,
    pra_boolean ref_out,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-32/default struct
 * @note
 * @param  p_crc:   the crc-32 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc32_get_default(
    pra_crc32 *const p_crc,
    uint32_t *const p_ec);

#endif