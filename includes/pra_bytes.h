/*
 * pra_bytes.h
 * created on Wed Aug 24 2022
 * created by Seven Lv
 * comments:    definitions and functions of the bytes type
 */

#ifndef INC_PRA_BYTES_H_
#define INC_PRA_BYTES_H_

/* includes */
#include "pra_boolean.h"
#include "stdint.h"

/* macros */

#define PRA_BYTES_NULL ((pra_bytes *)0)
#define PRA_BYTES_EC_NONE 0x0U             /* no error */
#define PRA_BYTES_EC_NULL_PTR 0x1U         /* null pointer */
#define PRA_BYTES_EC_NULL_DATA_PTR 0x2U    /* null data pointer */
#define PRA_BYTES_EC_DATA_LENGTH_ZERO 0x4U /* the length of data is zero */
#define PRA_BYTES_EC_DIFFERENT_LENGTH 0x8U /* different length */

/* types */

/* byte array */
typedef struct _pra_bytes
{
    uint16_t length;      /* 字节数组长度 */
    uint16_t used_length; /*有效数据长度*/
    uint8_t *data;        /* 字节数组指针 */
} pra_bytes;

/* variables */

/* functions */

/**
 * @brief               determines a bytes pointer is not null and bytes->bytes is
 * not null
 * @note
 * @param  *p_bytes:    the bytes pointer
 * @param  *p_ec:       output error codes:
 *                      PRA_BYTES_EC_NULL_PTR;
 *                      PRA_BYTES_EC_NULL_DATA_PTR;
 * @retval              PRA_BOOL_TRUE - the bytes pointer is not null and
 * bytes->bytes is not null; PRA_BOOL_FALSE - others
 */
pra_boolean pra_bytes_not_null_ptr(
    const pra_bytes *const p_bytes,
    uint32_t *const p_ec);

/**
 * @brief               initialize a bytes value
 * @note
 * @param  *p_bytes:    the bytes pointer
 * @param  *p_ec:       output error codes:
 *                      PRA_BYTES_EC_NULL_PTR;
 *                      PRA_BYTES_EC_NULL_DATA_PTR;
 *                      PRA_BYTES_EC_DATA_LENGTH_ZERO;
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_init(
    pra_bytes *const p_bytes,
    uint32_t *const p_ec);

/**
 * @brief           copy the data and used length of bytes
 * @note
 * @param  p_src:   the source bytes
 * @param  p_dst:   the destination bytes
 * @param  p_ec:    output error codes:
 *                  PRA_BYTES_EC_NULL_PTR;
 *                  PRA_BYTES_EC_NULL_DATA_PTR;
 *                  PRA_BYTES_EC_DATA_LENGTH_ZERO;
 *                  PRA_BYTES_EC_DIFFERENT_LENGTH;
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_copy(
    const pra_bytes *const p_src,
    pra_bytes *const p_dst,
    uint32_t *const p_ec);

#endif