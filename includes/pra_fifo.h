/*
 * pra_fifo.h
 * created on Tue Sep 06 2022
 * created by Seven Lv
 * comments:    definitions and functions of fifo
 */

#ifndef INC_PRA_FIFO_H_
#define INC_PRA_FIFO_H_

/* includes */
#include "pra_boolean.h"
#include "pra_defs.h"
#include "pra_num_defs.h"
#include "stdint.h"

/* macros */

#define PRA_FIFO_NULL PRA_NULL_PTR(pra_fifo)

#define PRA_FIFO_EC_NONE            PRA_NUM_ZERO_U      /* no error */
#define PRA_FIFO_EC_NULL_PTR        PRA_NUM_BIT_MASK_00 /* null pointer */
#define PRA_FIFO_EC_NOT_INIT        PRA_NUM_BIT_MASK_01 /* not initialized */
#define PRA_FIFO_EC_INVALID_LENGTH  PRA_NUM_BIT_MASK_02 /* invalid length */
#define PRA_FIFO_EC_DATA_FULL       PRA_NUM_BIT_MASK_03 /* the fifo struct is full */
#define PRA_FIFO_EC_DATA_NOT_ENOUGH PRA_NUM_BIT_MASK_04 /* the fifo struct data is not enough */

/* types */

/* fifo struct */
typedef struct _pra_fifo
{
    pra_boolean initialized; /* initialized flag */
    uint8_t    *p_data;      /* data pointer */
    uint16_t    data_length; /* data length */
    uint16_t    used_length; /* used data length */
    uint16_t    next_r_pos;  /* next read position */
    uint16_t    next_w_pos;  /* next write position */
} pra_fifo;

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