/*
 * pra_bytes_internal.h
 * created on Thu Sep 22 2022
 * created by Seven Lv
 * comments:    internal function declarations of pra_bytes
 * version: 0.2
 * history: #       date                modification
 *          0.1     Thu Sep 22 2022     created
 *          0.2     Thu Sep 29 2022     reorganize error codes
 */

#ifndef INC_PRA_BYTES_INTERNAL_H_
#define INC_PRA_BYTES_INTERNAL_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_bytes_types.h"
#include "pra_ec.h"

/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief           arguments validation for pra_bytes_not_null_ptr function
 * @note
 * @param  p_bytes: the bytes pointer
 * @param  p_ec:    output error codes:
 *                  PRA_EC_NULL_PTR;
 * @retval          PRA_BOOL_TRUE - the bytes pointer is not null and
 * bytes->bytes is not null; PRA_BOOL_FALSE - others
 */
pra_boolean pra_bytes_not_null_ptr_args_check(
    const pra_bytes *const p_bytes,
    PRA_EC_T *const        p_ec);

/**
 * @brief           arguments validation for pra_bytes_init function
 * @note
 * @param  p_bytes: the bytes pointer
 * @param  p_ec:    output error codes:
 *                  PRA_EC_NULL_PTR;
 *                  PRA_EC_INVALID_LENGTH;
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_init_args_check(
    const pra_bytes *const p_bytes,
    PRA_EC_T *const        p_ec);

/**
 * @brief           arguments validation for pra_bytes_copy function
 * @note
 * @param  p_src:   the source bytes
 * @param  p_dst:   the destination bytes
 * @param  p_ec:    output error codes:
 *                  PRA_EC_NULL_PTR;
 *                  PRA_EC_INVALID_LENGTH;
 *                  PRA_EC_DIFFERENT_LENGTH;
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_copy_args_check(
    const pra_bytes *const p_src,
    const pra_bytes *const p_dst,
    PRA_EC_T *const        p_ec);

/**
 * @brief               arguments validation for pra_bytes_append_u8_array function
 * @note
 * @param  p_bytes:     the bytes
 * @param  data[]:      the bytes to append
 * @param  data_length: the length of the bytes to append
 * @param  *p_ec:       output error codes:
 *                      PRA_EC_NULL_PTR;
 *                      PRA_EC_NOT_ENOUGH_LENGTH;
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_append_u8_array_args_check(
    const pra_bytes *const p_bytes,
    const uint8_t          data[],
    const uint16_t         data_length,
    PRA_EC_T *const        p_ec);

/**
 * @brief           arguments validation for pra_bytes_append function
 * @note
 * @param  p_bytes: the bytes
 * @param  p_data:  the bytes to append
 * @param  p_ec:    output error codes:
 *                  PRA_EC_NULL_PTR;
 *                  PRA_EC_NOT_ENOUGH_LENGTH;
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_append_args_check(
    const pra_bytes *const p_bytes,
    const pra_bytes *const p_data,
    PRA_EC_T *const        p_ec);

/**
 * @brief               arguments validation for pra_bytes_append_uxx_xx function
 * @note
 * @param  p_bytes:     the bytes
 * @param  data_length: data length
 * @param  p_ec:        output error codes:
 *                      PRA_EC_NULL_PTR;
 *                      PRA_EC_NOT_ENOUGH_LENGTH;
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_bytes_append_uxx_args_check(
    const pra_bytes *const p_bytes,
    const uint16_t         data_length,
    PRA_EC_T *const        p_ec);

#endif