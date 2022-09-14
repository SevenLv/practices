/*
 * pra_lifo_internal.h
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    internal functions of pra_lifo
 * version: 0.2
 * history: #       date                modification
 *          0.1     Tue Sep 13 2022     created
 *          0.2     Wed Sep 14 2022     include pra_lifo_types.h
 */

#ifndef INC_PRA_LIFO_INTERNAL_H_
#define INC_PRA_LIFO_INTERNAL_H_

/* includes */
#include "pra_lifo_types.h"

/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief               arguments validation for pra_lifo_init function
 * @note
 * @param  p_fifo:      pra_lifo struct pointer
 * @param  data[]:      data array
 * @param  data_length: data array length
 * @param  p_ec:        output error code:
 *                      PRA_LIFO_EC_NULL_PTR
 *                      PRA_LIFO_EC_INVALID_LENGTH
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_init_args_check(
    const pra_lifo *const p_lifo,
    uint16_t              data_length,
    PRA_EC_T *const       p_ec);

/**
 * @brief               arguments validation for pra_lifo_push_xx function
 * @note
 * @param  p_lifo:      pra_lifo struct pointer
 * @param  data_length: length of the data to push
 * @param  p_ec:        output error code:
 *                      PRA_LIFO_EC_NULL_PTR
 *                      PRA_LIFO_EC_NOT_INIT
 *                      PRA_LIFO_EC_DATA_FULL
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_push_args_check(
    const pra_lifo *const p_lifo,
    uint16_t              data_length,
    PRA_EC_T *const       p_ec);

/**
 * @brief               increase the position
 * @note
 * @param  data_length: data length
 * @param  p_position:  the position pointer
 * @retval None
 */
void pra_lifo_position_move(
    uint16_t        data_length,
    uint16_t *const p_position);

/**
 * @brief               decrease the position
 * @note
 * @param  data_length: data length
 * @param  p_position:  the position pointer
 * @retval None
 */
void pra_lifo_position_back(
    uint16_t        data_length,
    uint16_t *const p_position);

/**
 * @brief           arguments validation for pra_lifo_pop_u8 function
 * @note
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  p_data:  output data
 * @param  p_ec:    output error code:
 *                  PRA_LIFO_EC_NULL_PTR
 *                  PRA_LIFO_EC_NOT_INIT
 *                  PRA_LIFO_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_pop_u8_args_check(
    const pra_lifo *const p_lifo,
    const uint8_t *const  p_data,
    PRA_EC_T *const       p_ec);

/**
 * @brief           arguments validation for pra_lifo_po_u16_xx function
 * @note
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  p_data:  output data
 * @param  p_ec:    output error code:
 *                  PRA_LIFO_EC_NULL_PTR
 *                  PRA_LIFO_EC_NOT_INIT
 *                  PRA_LIFO_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_pop_u16_args_check(
    const pra_lifo *const p_lifo,
    const uint16_t *const p_data,
    PRA_EC_T *const       p_ec);

/**
 * @brief           arguments validation for pra_lifo_po_u32_xx function
 * @note
 * @param  p_lifo:  pra_lifo struct pointer
 * @param  p_data:  output data
 * @param  p_ec:    output error code:
 *                  PRA_LIFO_EC_NULL_PTR
 *                  PRA_LIFO_EC_NOT_INIT
 *                  PRA_LIFO_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_lifo_pop_u32_args_check(
    const pra_lifo *const p_lifo,
    const uint32_t *const p_data,
    PRA_EC_T *const       p_ec);

#endif