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
static pra_boolean pra_lifo_push_args_check(
    const pra_lifo *const p_lifo,
    uint16_t data_length,
    PRA_EC_T *const p_ec);

/**
 * @brief               increase the position
 * @note
 * @param  data_length: data length
 * @param  p_position:  the position pointer
 * @retval None
 */
static void pra_lifo_position_move(
    uint16_t data_length,
    uint16_t *const p_position);

/**
 * @brief               decrease the position
 * @note
 * @param  data_length: data length
 * @param  p_position:  the position pointer
 * @retval None
 */
static void pra_lifo_position_back(
    uint16_t data_length,
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
static pra_boolean pra_lifo_pop_u8_args_check(
    const pra_lifo *const p_lifo,
    const uint8_t *const p_data,
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

static pra_boolean pra_lifo_push_args_check(
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
    else if (PRA_UINT8_NULL == p_lifo->p_data)
    {
        *p_ec |= PRA_LIFO_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != p_lifo->initialized)
    {
        *p_ec |= PRA_LIFO_EC_NOT_INIT;
        result = PRA_BOOL_FALSE;
    }
    else if (UINT16_MAX == p_lifo->used_length)
    {
        *p_ec |= PRA_LIFO_EC_DATA_FULL;
        result = PRA_BOOL_FALSE;
    }
    else if (p_lifo->data_length < p_lifo->used_length + data_length)
    {
        *p_ec |= PRA_LIFO_EC_DATA_FULL;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

static void pra_lifo_position_move(
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

static void pra_lifo_position_back(
    uint16_t data_length,
    uint16_t *const p_position)
{
    if (0U == data_length)
    {
        /* NOTE do nothing */
    }
    else if (0U == *p_position)
    {
        *p_position = (data_length - 1U);
    }
    else
    {
        *p_position -= 1U;
    }
}

static pra_boolean pra_lifo_pop_u8_args_check(
    const pra_lifo *const p_lifo,
    const uint8_t *const p_data,
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
    else if (PRA_UINT8_NULL == p_lifo->p_data)
    {
        *p_ec |= PRA_LIFO_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == p_data)
    {
        *p_ec |= PRA_LIFO_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != p_lifo->initialized)
    {
        *p_ec |= PRA_LIFO_EC_NOT_INIT;
        result = PRA_BOOL_FALSE;
    }
    else if (1U > p_lifo->used_length)
    {
        *p_ec |= PRA_LIFO_EC_DATA_NOT_ENOUGH;
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

pra_boolean pra_lifo_push_u8(
    pra_lifo *const p_lifo,
    uint8_t data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_lifo_push_args_check(
                             p_lifo,
                             1U,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_lifo->p_data[p_lifo->next_w_pos] = data;
        p_lifo->used_length++;
        p_lifo->next_r_pos = p_lifo->next_w_pos;
        pra_lifo_position_move(
            p_lifo->data_length,
            &p_lifo->next_w_pos);

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_lifo_pop_u8(
    pra_lifo *const p_lifo,
    uint8_t *const p_data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_lifo_pop_u8_args_check(
                             p_lifo,
                             p_data,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        *p_data = p_lifo->p_data[p_lifo->next_r_pos];
        p_lifo->next_w_pos = p_lifo->next_r_pos;
        pra_lifo_position_back(
            p_lifo->data_length,
            &p_lifo->next_r_pos);
        p_lifo->used_length--;

        result = PRA_BOOL_TRUE;
    }

    return result;
}