/*
 * pra_bytes.h
 * created on Wed Aug 24 2022
 * created by Seven Lv
 * comments:    function definitions of the bytes type
 * version: 0.3
 * history: #       date                modification
 *          0.1     Wed Aug 24 2022     created
 *          0.2     Wed Sep 14 2022     move type definitions to pra_bytes_types.h
 *                                      move error code definitions to pra_bytes_ec.h
 *                                      include pra_boolean_types.h
 *          0.3     Wed Sep 14 2022     update file header comments
 */

#ifndef INC_PRA_BYTES_H_
#define INC_PRA_BYTES_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_bytes_types.h"
#include "pra_defs.h"
#include "stdint.h"


/* macros */

/* types */

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
    PRA_EC_T *const        p_ec);

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
    PRA_EC_T *const  p_ec);

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
    pra_bytes *const       p_dst,
    PRA_EC_T *const        p_ec);

/**
 * @brief               append some bytes to a bytes struct
 * @note
 * @param  p_bytes:     the bytes
 * @param  data[]:      the bytes to append
 * @param  data_length: the length of the bytes to append
 * @param  *p_ec:       output error codes:
 *                      PRA_BYTES_EC_NULL_PTR;
 *                      PRA_BYTES_EC_NULL_DATA_PTR;
 *                      PRA_BYTES_EC_NOT_ENOUGH_LENGTH;
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_append_u8_array(
    pra_bytes *const p_bytes,
    const uint8_t    data[],
    uint16_t         data_length,
    PRA_EC_T *const  p_ec);

/**
 * @brief           append some bytes to a bytes struct
 * @note
 * @param  p_bytes: the bytes
 * @param  p_data:  the bytes to append
 * @param  p_ec:    output error codes:
 *                  PRA_BYTES_EC_NULL_PTR;
 *                  PRA_BYTES_EC_NULL_DATA_PTR;
 *                  PRA_BYTES_EC_NOT_ENOUGH_LENGTH;
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_append(
    pra_bytes *const       p_bytes,
    const pra_bytes *const p_data,
    PRA_EC_T *const        p_ec);

/**
 * @brief           append a byte to a bytes struct
 * @note
 * @param  p_bytes: the bytes
 * @param  data:    the byte to append
 * @param  p_ec:    output error codes:
 *                  PRA_BYTES_EC_NULL_PTR;
 *                  PRA_BYTES_EC_NULL_DATA_PTR;
 *                  PRA_BYTES_EC_NOT_ENOUGH_LENGTH;
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_append_u8(
    pra_bytes *const p_bytes,
    uint8_t          data,
    PRA_EC_T *const  p_ec);

/**
 * @brief           append a 16-bits value to a bytes struct
 * @note            big endianness
 * @param  p_bytes: the bytes
 * @param  data:    the 16-bits value
 * @param  p_ec:    output error codes:
 *                  PRA_BYTES_EC_NULL_PTR;
 *                  PRA_BYTES_EC_NULL_DATA_PTR;
 *                  PRA_BYTES_EC_NOT_ENOUGH_LENGTH;
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_append_u16_be(
    pra_bytes *const p_bytes,
    uint16_t         data,
    PRA_EC_T *const  p_ec);

/**
 * @brief           append a 16-bits value to a bytes struct
 * @note            little endianness
 * @param  p_bytes: the bytes
 * @param  data:    the 16-bits value
 * @param  p_ec:    output error codes:
 *                  PRA_BYTES_EC_NULL_PTR;
 *                  PRA_BYTES_EC_NULL_DATA_PTR;
 *                  PRA_BYTES_EC_NOT_ENOUGH_LENGTH;
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_append_u16_le(
    pra_bytes *const p_bytes,
    uint16_t         data,
    PRA_EC_T *const  p_ec);

/**
 * @brief           append a 32-bits value to a bytes struct
 * @note            big endianness
 * @param  p_bytes: the bytes
 * @param  data:    the 32-bits value
 * @param  p_ec:    output error codes:
 *                  PRA_BYTES_EC_NULL_PTR;
 *                  PRA_BYTES_EC_NULL_DATA_PTR;
 *                  PRA_BYTES_EC_NOT_ENOUGH_LENGTH;
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_append_u32_be(
    pra_bytes *const p_bytes,
    uint32_t         data,
    PRA_EC_T *const  p_ec);

/**
 * @brief           append a 32-bits value to a bytes struct
 * @note            little endianness
 * @param  p_bytes: the bytes
 * @param  data:    the 32-bits value
 * @param  p_ec:    output error codes:
 *                  PRA_BYTES_EC_NULL_PTR;
 *                  PRA_BYTES_EC_NULL_DATA_PTR;
 *                  PRA_BYTES_EC_NOT_ENOUGH_LENGTH;
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_append_u32_le(
    pra_bytes *const p_bytes,
    uint32_t         data,
    PRA_EC_T *const  p_ec);

#endif