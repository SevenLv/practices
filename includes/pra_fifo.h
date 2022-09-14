/*
 * pra_fifo.h
 * created on Tue Sep 06 2022
 * created by Seven Lv
 * comments:    definitions and functions of fifo
 * version: 0.2
 * history: #       date                modification
 *          0.1     Tue Sep 06 2022     created
 *          0.2     Wed Sep 14 2022     include pra_boolean_types.h
 *                                      move type definitions to pra_fifo_types.h
 *                                      move error code definitiosn to pra_fifo_ec.h
 */

#ifndef INC_PRA_FIFO_H_
#define INC_PRA_FIFO_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_fifo_types.h"
#include "stdint.h"

/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief               initialize a pra_fifo struct
 * @note
 * @param  p_fifo:      pra_fifo struct pointer
 * @param  data[]:      data array
 * @param  data_length: data array length
 * @param  p_ec:        output error code:
 *                      PRA_FIFO_EC_NULL_PTR
 *                      PRA_FIFO_EC_INVALID_LENGTH
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_fifo_init(
    pra_fifo *const p_fifo,
    uint8_t         data[],
    uint16_t        data_length,
    PRA_EC_T *const p_ec);

/**
 * @brief           append a byte to the fifo struct
 * @note
 * @param  p_fifo:  pra_fifo struct pointer
 * @param  data:    data to append
 * @param  p_ec:    output error code:
 *                  PRA_FIFO_EC_NULL_PTR
 *                  PRA_FIFO_EC_NOT_INIT
 *                  PRA_FIFO_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_fifo_append_u8(
    pra_fifo *const p_fifo,
    uint8_t         data,
    PRA_EC_T *const p_ec);

/**
 * @brief           take a byte from the fifo struct
 * @note
 * @param  p_fifo:  pra_fifo struct pointer
 * @param  p_data:  output data
 * @param  p_ec:    output error code:
 *                  PRA_FIFO_EC_NULL_PTR
 *                  PRA_FIFO_EC_NOT_INIT
 *                  PRA_FIFO_EC_DATA_NOT_ENOUGH
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_fifo_take_u8(
    pra_fifo *const p_fifo,
    uint8_t *const  p_data,
    PRA_EC_T *const p_ec);

/**
 * @brief           append 2 bytes to the fifo struct
 * @note            big endianness
 * @param  p_fifo:  pra_fifo struct pointer
 * @param  data:    data to append
 * @param  p_ec:    output error code:
 *                  PRA_FIFO_EC_NULL_PTR
 *                  PRA_FIFO_EC_NOT_INIT
 *                  PRA_FIFO_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_fifo_append_u16_be(
    pra_fifo *const p_fifo,
    uint16_t        data,
    PRA_EC_T *const p_ec);

/**
 * @brief           append 2 bytes to the fifo struct
 * @note            little endianness
 * @param  p_fifo:  pra_fifo struct pointer
 * @param  data:    data to append
 * @param  p_ec:    output error code:
 *                  PRA_FIFO_EC_NULL_PTR
 *                  PRA_FIFO_EC_NOT_INIT
 *                  PRA_FIFO_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_fifo_append_u16_le(
    pra_fifo *const p_fifo,
    uint16_t        data,
    PRA_EC_T *const p_ec);

/**
 * @brief           take 2 byte from the fifo struct
 * @note            big endianness
 * @param  p_fifo:  pra_fifo struct pointer
 * @param  p_data:  output data
 * @param  p_ec:    output error code:
 *                  PRA_FIFO_EC_NULL_PTR
 *                  PRA_FIFO_EC_NOT_INIT
 *                  PRA_FIFO_EC_DATA_NOT_ENOUGH
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_fifo_take_u16_be(
    pra_fifo *const p_fifo,
    uint16_t *const p_data,
    PRA_EC_T *const p_ec);

/**
 * @brief           take 2 byte from the fifo struct
 * @note            little endianness
 * @param  p_fifo:  pra_fifo struct pointer
 * @param  p_data:  output data
 * @param  p_ec:    output error code:
 *                  PRA_FIFO_EC_NULL_PTR
 *                  PRA_FIFO_EC_NOT_INIT
 *                  PRA_FIFO_EC_DATA_NOT_ENOUGH
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_fifo_take_u16_le(
    pra_fifo *const p_fifo,
    uint16_t *const p_data,
    PRA_EC_T *const p_ec);

/**
 * @brief           append 4 bytes to the fifo struct
 * @note            big endianness
 * @param  p_fifo:  pra_fifo struct pointer
 * @param  data:    data to append
 * @param  p_ec:    output error code:
 *                  PRA_FIFO_EC_NULL_PTR
 *                  PRA_FIFO_EC_NOT_INIT
 *                  PRA_FIFO_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_fifo_append_u32_be(
    pra_fifo *const p_fifo,
    uint32_t        data,
    PRA_EC_T *const p_ec);

/**
 * @brief           append 4 bytes to the fifo struct
 * @note            little endianness
 * @param  p_fifo:  pra_fifo struct pointer
 * @param  data:    data to append
 * @param  p_ec:    output error code:
 *                  PRA_FIFO_EC_NULL_PTR
 *                  PRA_FIFO_EC_NOT_INIT
 *                  PRA_FIFO_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_fifo_append_u32_le(
    pra_fifo *const p_fifo,
    uint32_t        data,
    PRA_EC_T *const p_ec);

/**
 * @brief           take 4 bytes from the fifo struct
 * @note            big endianness
 * @param  p_fifo:  pra_fifo struct pointer
 * @param  p_data:  output data
 * @param  p_ec:    output error code:
 *                  PRA_FIFO_EC_NULL_PTR
 *                  PRA_FIFO_EC_NOT_INIT
 *                  PRA_FIFO_EC_DATA_NOT_ENOUGH
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_fifo_take_u32_be(
    pra_fifo *const p_fifo,
    uint32_t *const p_data,
    PRA_EC_T *const p_ec);

/**
 * @brief           take 4 bytes from the fifo struct
 * @note            little endianness
 * @param  p_fifo:  pra_fifo struct pointer
 * @param  p_data:  output data
 * @param  p_ec:    output error code:
 *                  PRA_FIFO_EC_NULL_PTR
 *                  PRA_FIFO_EC_NOT_INIT
 *                  PRA_FIFO_EC_DATA_NOT_ENOUGH
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_fifo_take_u32_le(
    pra_fifo *const p_fifo,
    uint32_t *const p_data,
    PRA_EC_T *const p_ec);

#endif