/*
 * pra_lifo.h
 * created on Thu Sep 08 2022
 * created by Seven Lv
 * comments:    definitions and functions of lifo
 */

#ifndef INC_PRA_LIFO_H_
#define INC_PRA_LIFO_H_

/* includes */
#include "pra_boolean.h"
#include "pra_defs.h"
#include "stdint.h"

/* macros */

#define PRA_LIFO_NULL ((pra_lifo *)0)

#define PRA_LIFO_EC_NONE 0x0U             /* no error */
#define PRA_LIFO_EC_NULL_PTR 0x1U         /* null pointer */
#define PRA_LIFO_EC_NOT_INIT 0x2U         /* not initialized */
#define PRA_LIFO_EC_INVALID_LENGTH 0x4U   /* invalid length */
#define PRA_LIFO_EC_DATA_FULL 0x8U        /* the lifo struct is full */
#define PRA_LIFO_EC_DATA_NOT_ENOUGH 0x10U /* the lifo struct data is not enough */

/* types */

/* lifo struct */
typedef struct _pra_lifo
{
    pra_boolean initialized; /* initialized flag */
    uint8_t *p_data;         /* data pointer */
    uint16_t data_length;    /* data length */
    uint16_t used_length;    /* used data length */
    uint16_t next_r_pos;     /* next read position */
    uint16_t next_w_pos;     /* next write position */
} pra_lifo;

/* variables */

/* functions */

/**
 * @brief               initialize a pra_lifo struct
 * @note
 * @param  p_lifo:      pra_lifo struct pointer
 * @param  data[]:      data array
 * @param  data_length: data array length
 * @param  p_ec:        output error code:
 *                      PRA_LIFO_EC_NULL_PTR
 *                      PRA_LIFO_EC_INVALID_LENGTH
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_init(
    pra_lifo *const p_lifo,
    uint8_t data[],
    uint16_t data_length,
    PRA_EC_T *const p_ec);

/**
 * @brief           push a byte to the lifo struct
 * @note
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  data:    data to push
 * @param  p_ec:    output error code:
 *                  PRA_LIFO_EC_NULL_PTR
 *                  PRA_LIFO_EC_NOT_INIT
 *                  PRA_LIFO_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_push_u8(
    pra_lifo *const p_lifo,
    uint8_t data,
    PRA_EC_T *const p_ec);

/**
 * @brief           pop a byte from the lifo struct
 * @note
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  p_data:  ouput data
 * @param  p_ec:    output error code:
 *                  PRA_LIFO_EC_NULL_PTR
 *                  PRA_LIFO_EC_NOT_INIT
 *                  PRA_LIFO_EC_DATA_NOT_ENOUGH
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_pop_u8(
    pra_lifo *const p_lifo,
    uint8_t *const p_data,
    PRA_EC_T *const p_ec);

/**
 * @brief           push 2 bytes to the lifo struct
 * @note            big endianness
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  data:    data to push
 * @param  p_ec:    output error code:
 *                  PRA_LIFO_EC_NULL_PTR
 *                  PRA_LIFO_EC_NOT_INIT
 *                  PRA_LIFO_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_push_u16_be(
    pra_lifo *const p_lifo,
    uint16_t data,
    PRA_EC_T *const p_ec);

/**
 * @brief           push 2 bytes to the lifo struct
 * @note            little endianness
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  data:    data to push
 * @param  p_ec:    output error code:
 *                  PRA_LIFO_EC_NULL_PTR
 *                  PRA_LIFO_EC_NOT_INIT
 *                  PRA_LIFO_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_push_u16_le(
    pra_lifo *const p_lifo,
    uint16_t data,
    PRA_EC_T *const p_ec);

#endif