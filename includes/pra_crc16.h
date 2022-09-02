/*
 * pra_crc16.h
 * created on Fri Sep 02 2022
 * created by Seven Lv
 * comments:    functions of crc16
 */

#ifndef INC_PRA_CRC16_H_
#define INC_PRA_CRC16_H_

/* includes */
#include "pra_boolean.h"
#include "stdint.h"

/* macros */

#define PRA_CRC16_NULL ((pra_crc16 *)0)

#define PRA_CRC16_TABLE_SIZE 0x100U

#define PRA_CRC16_EC_NONE 0x0U           /* no error */
#define PRA_CRC16_EC_NULL_PTR 0x1U       /* null pointer */
#define PRA_CRC16_EC_NOT_INIT 0x2U       /* not initialized */
#define PRA_CRC16_EC_INVALID_OFFSET 0x4U /* invalid offset */
#define PRA_CRC16_EC_INVALID_LENGTH 0x8U /* invalid length */

/* types */

/* crc16 struct */
typedef struct _pra_crc16
{
    pra_boolean initialized;              /* initialized flag */
    uint16_t table[PRA_CRC16_TABLE_SIZE]; /* the crc16 table */
    uint16_t polynomial;                  /* polynomial */
    uint16_t initial_value;               /* initial value */
    uint16_t xor_out;                     /* xor out */
    pra_boolean ref_in;                   /* ref in */
    pra_boolean ref_out;                  /* ref out */
} pra_crc16;

/* variables */

/* functions */

/**
 * @brief           initialize the crc16 struct
 * @note
 * @param  p_crc:   the crc struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC16_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_init(
    pra_crc16 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief               compute crc16
 * @note
 * @param  p_crc:       the crc struct pointer
 * @param  bytes:       the bytes to compute
 * @param  offset:      the start position, base zero
 * @param  length:      length of the bytes
 * @param  p_result:    the crc result
 * @param  p_ec:        output error code:
 *                      PRA_CRC16_EC_NULL_PTR
 *                      PRA_CRC16_EC_NOT_INIT
 *                      PRA_CRC16_EC_INVALID_OFFSET
 *                      PRA_CRC16_EC_INVALID_LENGTH
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_compute(
    const pra_crc16 *const p_crc,
    const uint8_t *const bytes,
    uint32_t offset,
    uint32_t length,
    uint16_t *const p_result,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-16/arc struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC16_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_arc(
    pra_crc16 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-16/maxim struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC16_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_maxim(
    pra_crc16 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-16/usb struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC16_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_usb(
    pra_crc16 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-16/modbus struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC16_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_modbus(
    pra_crc16 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-16/ccitt-false struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC16_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_ccitt_false(
    pra_crc16 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-16/x25 struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC16_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_x25(
    pra_crc16 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-16/xmodem struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC16_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_xmodem(
    pra_crc16 *const p_crc,
    uint32_t *const p_ec);

/**
 * @brief           get new crc-16/dnp struct
 * @note
 * @param  p_crc:   the crc-16 struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_CRC16_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_crc16_get_dnp(
    pra_crc16 *const p_crc,
    uint32_t *const p_ec);

#endif