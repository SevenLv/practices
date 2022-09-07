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
#include "stdint.h"

/* macros */

#define PRA_FIFO_NULL ((pra_fifo *)0)

#define PRA_FIFO_EC_NONE 0x0U             /* no error */
#define PRA_FIFO_EC_NULL_PTR 0x1U         /* null pointer */
#define PRA_FIFO_EC_NOT_INIT 0x2U         /* not initialized */
#define PRA_FIFO_EC_INVALID_LENGTH 0x4U   /* invalid length */
#define PRA_FIFO_EC_DATA_FULL 0x8U        /* the fifo struct is full */
#define PRA_FIFO_EC_DATA_NOT_ENOUGH 0x10U /* the fifo struct data is not enough */

/* types */

typedef struct _pra_fifo
{
    pra_boolean initialized; /* initialized flag */
    uint8_t *p_data;         /* data pointer */
    uint16_t data_length;    /* data length */
    uint16_t used_length;    /* used data length */
    uint16_t next_r_pos;     /* next read position */
    uint16_t next_w_pos;     /* next write position */
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
    uint8_t data[],
    uint16_t data_length,
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
    uint8_t data,
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
    uint8_t *const p_data,
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
    uint16_t data,
    PRA_EC_T *const p_ec);

#endif