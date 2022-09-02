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
#include "stdint.h"

/* macros */

#define PRA_CRC8_NULL ((pra_crc8 *)0)

#define PRA_CRC8_TABLE_SIZE 0x100U

#define PRA_CRC8_EC_NONE 0x0U           /* no error */
#define PRA_CRC8_EC_NULL_PTR 0x1U       /* null pointer */
#define PRA_CRC8_EC_NOT_INIT 0x2U       /* not initialized */
#define PRA_CRC8_EC_INVALID_OFFSET 0x4U /* invalid offset */
#define PRA_CRC8_EC_INVALID_LENGTH 0x8U /* invalid length */

/* types */

/* crc8 struct */
typedef struct _pra_crc8
{
    pra_boolean intialized;             /* initialized flag */
    uint8_t table[PRA_CRC8_TABLE_SIZE]; /* the crc8 table */
    uint8_t polynomial;                 /* polynomial */
    uint8_t intial_value;               /* initial value */
    uint8_t xor_out;                    /*xor out*/
    pra_boolean ref_in;                 /* ref in */
    pra_boolean ref_out;                /* ref out */
} pra_crc8;

/* variables */

/* functions */

/**
 * @brief           initialize the crc8 module
 * @note
 * @param  p_crc:   the crc struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC8_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_init(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief               compute crc8
 * @note
 * @param  p_crc:       the crc struct pointer
 * @param  bytes:       the bytes to compute
 * @param  offset:      the start position, base zero
 * @param  length:      length of the bytes
 * @param  p_result:    the crc result
 * @param  p_ec:        output error code:
 *                      PRA_CRC8_EC_NULL_PTR
 *                      PRA_CRC8_EC_NOT_INIT
 *                      PRA_CRC8_EC_INVALID_OFFSET
 *                      PRA_CRC8_EC_INVALID_LENGTH
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_compute(
    const pra_crc8 *const p_crc,
    const uint8_t *const bytes,
    uint32_t offset,
    uint32_t length,
    uint8_t *const p_result,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-8 struct
 * @note
 * @param  p_crc:   the crc-8 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC8_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_get_default(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-8/itu struct
 * @note
 * @param  p_crc:   the crc-8 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC8_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_get_itu(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-8/rohc struct
 * @note
 * @param  p_crc:   the crc-8 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC8_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_get_rohc(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-8/maxim struct
 * @note
 * @param  p_crc:   the crc-8 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC8_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_get_maxim(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-8/cdma2000 struct
 * @note
 * @param  p_crc:   the crc-8 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC8_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_get_cdma2000(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-8/wcdma struct
 * @note
 * @param  p_crc:   the crc-8 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC8_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc8_get_wcdma(
    pra_crc8 *const p_crc,
    uint32_t *const p_ec);
#endif