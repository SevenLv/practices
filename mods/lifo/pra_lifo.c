/*
 * pra_lifo.c
 * created on Thu Sep 08 2022
 * created by Seven Lv
 * comments:    definitions and functions of lifo
 */

/* includes */
#include "pra_lifo.h"

/* variables */

/* function declarations */

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
static pra_boolean pra_lifo_init_args_check(
    const pra_lifo *const p_lifo,
    uint16_t data_length,
    PRA_EC_T *const p_ec);

/* functions */

static pra_boolean pra_lifo_init_args_check(
    const pra_lifo *const p_lifo,
    uint16_t data_length,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_LIFO_NULL == p_lifo)
    {
        *p_ec |= PRA_LIFO_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (0U == data_length)
    {
        *p_ec |= PRA_LIFO_EC_INVALID_LENGTH;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_lifo_init(
    pra_lifo *const p_lifo,
    uint8_t data[],
    uint16_t data_length,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_lifo_init_args_check(
                             p_lifo,
                             data_length,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        for (uint16_t i = 0U; i < data_length; i++)
        {
            data[i] = 0U;
        }

        p_lifo->p_data = data;
        p_lifo->data_length = data_length;
        p_lifo->used_length = 0U;
        p_lifo->next_r_pos = 0U;
        p_lifo->next_w_pos = 0U;
        p_lifo->initialized = PRA_BOOL_TRUE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}