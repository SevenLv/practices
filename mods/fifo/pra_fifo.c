/*
 * pra_fifo.c
 * created on Tue Sep 06 2022
 * created by Seven Lv
 * comments:    definitions and functions of fifo
 */

/* includes */
#include "pra_fifo.h"

/* variables */

/* function declarations */

/**
 * @brief               arguments validation for pra_fifo_init function
 * @note
 * @param  p_fifo:      pra_fifo struct pointer
 * @param  data[]:      data array
 * @param  data_length: data array length
 * @param  p_ec:        output error code:
 *                      PRA_FIFO_EC_NULL_PTR
 *                      PRA_FIFO_EC_INVALID_LENGTH
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_fifo_init_args_check(
    const pra_fifo *const p_fifo,
    uint16_t data_length,
    PRA_EC_T *const p_ec);

/**
 * @brief           arguments validation for pra_fifo_append_u8 function
 * @note
 * @param  p_fifo:  pra_fifo struct pointer
 * @param  p_ec:    output error code:
 *                  PRA_FIFO_EC_NULL_PTR
 *                  PRA_FIFO_EC_NOT_INIT
 *                  PRA_FIFO_EC_DATA_FULL
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_fifo_append_u8_args_check(
    const pra_fifo *const p_fifo,
    PRA_EC_T *const p_ec);

/**
 * @brief               increase the position
 * @note
 * @param  p_position:  the position pointer
 * @retval None
 */
static void pra_fifo_position_move(
    uint16_t data_length,
    uint16_t *const p_position);

/* functions */

static pra_boolean pra_fifo_init_args_check(
    const pra_fifo *const p_fifo,
    uint16_t data_length,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_FIFO_NULL == p_fifo)
    {
        *p_ec |= PRA_FIFO_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (0U == data_length)
    {
        *p_ec |= PRA_FIFO_EC_INVALID_LENGTH;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_init(
    pra_fifo *const p_fifo,
    uint8_t data[],
    uint16_t data_length,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_fifo_init_args_check(
                             p_fifo,
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
        p_fifo->p_data = data;
        p_fifo->data_length = data_length;
        p_fifo->used_length = 0U;
        p_fifo->next_r_pos = 0U;
        p_fifo->next_w_pos = 0U;
        p_fifo->initialized = PRA_BOOL_TRUE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

static void pra_fifo_position_move(
    uint16_t data_length,
    uint16_t *const p_position)
{
    if (0U == data_length)
    {
        /* NOTE do nothing */
    }
    if ((UINT16_MAX - 1U) == *p_position)
    {
        *p_position = 0U;
    }
    else if ((data_length - 1U) == *p_position)
    {
        *p_position = 0U;
    }
    else
    {
        *p_position += 1U;
    }
}

static pra_boolean pra_fifo_append_u8_args_check(
    const pra_fifo *const p_fifo,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_FIFO_NULL == p_fifo)
    {
        *p_ec |= PRA_FIFO_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == p_fifo->p_data)
    {
        *p_ec |= PRA_FIFO_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != p_fifo->initialized)
    {
        *p_ec |= PRA_FIFO_EC_NOT_INIT;
        result = PRA_BOOL_FALSE;
    }
    else if (UINT16_MAX == p_fifo->used_length)
    {
        *p_ec |= PRA_FIFO_EC_DATA_FULL;
        result = PRA_BOOL_FALSE;
    }
    else if (p_fifo->data_length < p_fifo->used_length + 1U)
    {
        *p_ec |= PRA_FIFO_EC_DATA_FULL;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_append_u8(
    pra_fifo *const p_fifo,
    uint8_t data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_fifo_append_u8_args_check(
                             p_fifo,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_fifo->p_data[p_fifo->next_w_pos] = data;
        p_fifo->used_length++;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);

        result = PRA_BOOL_TRUE;
    }

    return result;
}
