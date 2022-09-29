/*
 * pra_lifo.h
 * created on Thu Sep 08 2022
 * created by Seven Lv
 * comments:    function definitions of lifo
 * version: 0.5
 * history: #       date                modification
 *          0.1     Thu Sep 08 2022     created
 *          0.2     Wed Sep 14 2022     include pra_boolean_types.h
 *                                      move type definitions to pra_lifo_types.h
 *                                      move error code definitions to pra_lifo_ec.h
 *          0.3     Wed Sep 14 2022     update file header comments
 *          0.4     Thu Sep 15 2022     include pra_ec.h
 *          0.5     Thu Sep 29 2022     reorganize error codes
 */

#ifndef INC_PRA_LIFO_H_
#define INC_PRA_LIFO_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_ec.h"
#include "pra_lifo_types.h"
#include "stdint.h"


/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief               initialize a pra_lifo struct
 * @note
 * @param  p_lifo:      pra_lifo struct pointer
 * @param  data[]:      data array
 * @param  data_length: data array length
 * @param  p_ec:        output error code:
 *                      PRA_EC_NULL_PTR
 *                      PRA_EC_INVALID_LENGTH
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_init(
    pra_lifo *const p_lifo,
    uint8_t         data[],
    uint16_t        data_length,
    PRA_EC_T *const p_ec);

/**
 * @brief           push a byte to the lifo struct
 * @note
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  data:    data to push
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 *                  PRA_EC_NOT_INIT
 *                  PRA_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_push_u8(
    pra_lifo *const p_lifo,
    uint8_t         data,
    PRA_EC_T *const p_ec);

/**
 * @brief           pop a byte from the lifo struct
 * @note
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  p_data:  ouput data
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 *                  PRA_EC_NOT_INIT
 *                  PRA_EC_NOT_ENOUGH_LENGTH
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_pop_u8(
    pra_lifo *const p_lifo,
    uint8_t *const  p_data,
    PRA_EC_T *const p_ec);

/**
 * @brief           push 2 bytes to the lifo struct
 * @note            big endianness
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  data:    data to push
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 *                  PRA_EC_NOT_INIT
 *                  PRA_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_push_u16_be(
    pra_lifo *const p_lifo,
    uint16_t        data,
    PRA_EC_T *const p_ec);

/**
 * @brief           push 2 bytes to the lifo struct
 * @note            little endianness
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  data:    data to push
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 *                  PRA_EC_NOT_INIT
 *                  PRA_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_push_u16_le(
    pra_lifo *const p_lifo,
    uint16_t        data,
    PRA_EC_T *const p_ec);

/**
 * @brief           pop 2 bytes from the lifo struct
 * @note            big endianness
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  p_data:  ouput data
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 *                  PRA_EC_NOT_INIT
 *                  PRA_EC_NOT_ENOUGH_LENGTH
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_pop_u16_be(
    pra_lifo *const p_lifo,
    uint16_t *const p_data,
    PRA_EC_T *const p_ec);

/**
 * @brief           pop 2 bytes from the lifo struct
 * @note            little endianness
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  p_data:  ouput data
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 *                  PRA_EC_NOT_INIT
 *                  PRA_EC_NOT_ENOUGH_LENGTH
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_pop_u16_le(
    pra_lifo *const p_lifo,
    uint16_t *const p_data,
    PRA_EC_T *const p_ec);

/**
 * @brief           push 4 bytes to the lifo struct
 * @note            big endianness
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  data:    data to push
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 *                  PRA_EC_NOT_INIT
 *                  PRA_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_push_u32_be(
    pra_lifo *const p_lifo,
    uint32_t        data,
    PRA_EC_T *const p_ec);

/**
 * @brief           push 4 bytes to the lifo struct
 * @note            little endianness
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  data:    data to push
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 *                  PRA_EC_NOT_INIT
 *                  PRA_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_push_u32_le(
    pra_lifo *const p_lifo,
    uint32_t        data,
    PRA_EC_T *const p_ec);

/**
 * @brief           pop 4 bytes from the lifo struct
 * @note            big endianness
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  p_data:  ouput data
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 *                  PRA_EC_NOT_INIT
 *                  PRA_EC_NOT_ENOUGH_LENGTH
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_pop_u32_be(
    pra_lifo *const p_lifo,
    uint32_t *const p_data,
    PRA_EC_T *const p_ec);

/**
 * @brief           pop 4 bytes from the lifo struct
 * @note            little endianness
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  p_data:  ouput data
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 *                  PRA_EC_NOT_INIT
 *                  PRA_EC_NOT_ENOUGH_LENGTH
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_pop_u32_le(
    pra_lifo *const p_lifo,
    uint32_t *const p_data,
    PRA_EC_T *const p_ec);

#endif