/*
 * pra_lifo.c
 * created on Thu Sep 08 2022
 * created by Seven Lv
 * comments:    definitions and functions of lifo
 * version: 0.1
 * history: #       date               modification
 *          0.1     Thu Sep 08 2022    created
 */

/* includes */
#include "pra_lifo.h"
#include "pra_num_defs.h"

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
static pra_boolean pra_lifo_push_args_check(
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
static void pra_lifo_position_move(
    uint16_t        data_length,
    uint16_t *const p_position);

/**
 * @brief               decrease the position
 * @note
 * @param  data_length: data length
 * @param  p_position:  the position pointer
 * @retval None
 */
static void pra_lifo_position_back(
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
static pra_boolean pra_lifo_pop_u8_args_check(
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
static pra_boolean pra_lifo_pop_u16_args_check(
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
static pra_boolean pra_lifo_pop_u32_args_check(
    const pra_lifo *const p_lifo,
    const uint32_t *const p_data,
    PRA_EC_T *const       p_ec);

/* functions */

static pra_boolean pra_lifo_init_args_check(
    const pra_lifo *const p_lifo,
    uint16_t              data_length,
    PRA_EC_T *const       p_ec)
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
    else if (PRA_NUM_ZERO_U == data_length)
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
    uint16_t              data_length,
    PRA_EC_T *const       p_ec)
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
    else if (PRA_NUM_MAX_VALUE_U16 == p_lifo->used_length)
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
    uint16_t        data_length,
    uint16_t *const p_position)
{
    if (PRA_NUM_ZERO_U == data_length)
    {
        /* NOTE do nothing */
    }
    if ((PRA_NUM_MAX_VALUE_U16 - 1U) == *p_position)
    {
        *p_position = PRA_NUM_ZERO_U;
    }
    else if ((data_length - 1U) == *p_position)
    {
        *p_position = PRA_NUM_ZERO_U;
    }
    else
    {
        *p_position += 1U;
    }
}

static void pra_lifo_position_back(
    uint16_t        data_length,
    uint16_t *const p_position)
{
    if (PRA_NUM_ZERO_U == data_length)
    {
        /* NOTE do nothing */
    }
    else if (PRA_NUM_ZERO_U == *p_position)
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
    const uint8_t *const  p_data,
    PRA_EC_T *const       p_ec)
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
    else if (PRA_NUM_BYTE_SIZE_U8 > p_lifo->used_length)
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

static pra_boolean pra_lifo_pop_u16_args_check(
    const pra_lifo *const p_lifo,
    const uint16_t *const p_data,
    PRA_EC_T *const       p_ec)
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
    else if (PRA_UINT16_NULL == p_data)
    {
        *p_ec |= PRA_LIFO_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != p_lifo->initialized)
    {
        *p_ec |= PRA_LIFO_EC_NOT_INIT;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BYTE_SIZE_U16 > p_lifo->used_length)
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

static pra_boolean pra_lifo_pop_u32_args_check(
    const pra_lifo *const p_lifo,
    const uint32_t *const p_data,
    PRA_EC_T *const       p_ec)
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
    else if (PRA_UINT32_NULL == p_data)
    {
        *p_ec |= PRA_LIFO_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != p_lifo->initialized)
    {
        *p_ec |= PRA_LIFO_EC_NOT_INIT;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BYTE_SIZE_U32 > p_lifo->used_length)
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
    uint8_t         data[],
    uint16_t        data_length,
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
        for (uint16_t i = PRA_NUM_ZERO_U; i < data_length; i++)
        {
            data[i] = PRA_NUM_ZERO_U;
        }

        p_lifo->p_data = data;
        p_lifo->data_length = data_length;
        p_lifo->used_length = PRA_NUM_ZERO_U;
        p_lifo->next_r_pos = PRA_NUM_ZERO_U;
        p_lifo->next_w_pos = PRA_NUM_ZERO_U;
        p_lifo->initialized = PRA_BOOL_TRUE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_lifo_push_u8(
    pra_lifo *const p_lifo,
    uint8_t         data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_lifo_push_args_check(
                             p_lifo,
                             PRA_NUM_BYTE_SIZE_U8,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_lifo->p_data[p_lifo->next_w_pos] = data;
        p_lifo->used_length += PRA_NUM_BYTE_SIZE_U8;
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
    uint8_t *const  p_data,
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
        p_lifo->used_length -= PRA_NUM_BYTE_SIZE_U8;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_lifo_push_u16_be(
    pra_lifo *const p_lifo,
    uint16_t        data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_lifo_push_args_check(
                             p_lifo,
                             PRA_NUM_BYTE_SIZE_U16,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint8_t data_h = (uint8_t)((data >> PRA_NUM_BIT_WIDTH_U8) & PRA_NUM_MAX_VALUE_U8);
        uint8_t data_l = (uint8_t)(data & PRA_NUM_MAX_VALUE_U8);

        p_lifo->p_data[p_lifo->next_w_pos] = data_h;
        p_lifo->next_r_pos = p_lifo->next_w_pos;
        pra_lifo_position_move(
            p_lifo->data_length,
            &p_lifo->next_w_pos);

        p_lifo->p_data[p_lifo->next_w_pos] = data_l;
        p_lifo->next_r_pos = p_lifo->next_w_pos;
        pra_lifo_position_move(
            p_lifo->data_length,
            &p_lifo->next_w_pos);

        p_lifo->used_length += PRA_NUM_BYTE_SIZE_U16;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_lifo_push_u16_le(
    pra_lifo *const p_lifo,
    uint16_t        data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_lifo_push_args_check(
                             p_lifo,
                             PRA_NUM_BYTE_SIZE_U16,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint8_t data_h = (uint8_t)(data & PRA_NUM_MAX_VALUE_U8);
        uint8_t data_l = (uint8_t)((data >> PRA_NUM_BIT_WIDTH_U8) & PRA_NUM_MAX_VALUE_U8);

        p_lifo->p_data[p_lifo->next_w_pos] = data_h;
        p_lifo->next_r_pos = p_lifo->next_w_pos;
        pra_lifo_position_move(
            p_lifo->data_length,
            &p_lifo->next_w_pos);

        p_lifo->p_data[p_lifo->next_w_pos] = data_l;
        p_lifo->next_r_pos = p_lifo->next_w_pos;
        pra_lifo_position_move(
            p_lifo->data_length,
            &p_lifo->next_w_pos);

        p_lifo->used_length += PRA_NUM_BYTE_SIZE_U16;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_lifo_pop_u16_be(
    pra_lifo *const p_lifo,
    uint16_t *const p_data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_lifo_pop_u16_args_check(
                             p_lifo,
                             p_data,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint16_t tmp_data = PRA_NUM_ZERO_U;

        tmp_data |= ((uint16_t)p_lifo->p_data[p_lifo->next_r_pos]);
        p_lifo->next_w_pos = p_lifo->next_r_pos;
        pra_lifo_position_back(
            p_lifo->data_length,
            &p_lifo->next_r_pos);

        tmp_data |= (((uint16_t)p_lifo->p_data[p_lifo->next_r_pos]) << PRA_NUM_BIT_WIDTH_U8);
        p_lifo->next_w_pos = p_lifo->next_r_pos;
        pra_lifo_position_back(
            p_lifo->data_length,
            &p_lifo->next_r_pos);
        p_lifo->used_length -= PRA_NUM_BYTE_SIZE_U16;

        *p_data = tmp_data;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_lifo_pop_u16_le(
    pra_lifo *const p_lifo,
    uint16_t *const p_data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_lifo_pop_u16_args_check(
                             p_lifo,
                             p_data,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint16_t tmp_data = PRA_NUM_ZERO_U;

        tmp_data |= (((uint16_t)p_lifo->p_data[p_lifo->next_r_pos]) << PRA_NUM_BIT_WIDTH_U8);
        p_lifo->next_w_pos = p_lifo->next_r_pos;
        pra_lifo_position_back(
            p_lifo->data_length,
            &p_lifo->next_r_pos);

        tmp_data |= ((uint16_t)p_lifo->p_data[p_lifo->next_r_pos]);
        p_lifo->next_w_pos = p_lifo->next_r_pos;
        pra_lifo_position_back(
            p_lifo->data_length,
            &p_lifo->next_r_pos);
        p_lifo->used_length -= PRA_NUM_BYTE_SIZE_U16;

        *p_data = tmp_data;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_lifo_push_u32_be(
    pra_lifo *const p_lifo,
    uint32_t        data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_lifo_push_args_check(
                             p_lifo,
                             PRA_NUM_BYTE_SIZE_U32,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint8_t data_h = (uint8_t)((data >> (PRA_NUM_BIT_WIDTH_U8 * 3)) & PRA_NUM_MAX_VALUE_U8);
        uint8_t data_m_h = (uint8_t)((data >> (PRA_NUM_BIT_WIDTH_U8 * 2)) & PRA_NUM_MAX_VALUE_U8);
        uint8_t data_m_l = (uint8_t)((data >> PRA_NUM_BIT_WIDTH_U8) & PRA_NUM_MAX_VALUE_U8);
        uint8_t data_l = (uint8_t)(data & PRA_NUM_MAX_VALUE_U8);

        p_lifo->p_data[p_lifo->next_w_pos] = data_h;
        p_lifo->next_r_pos = p_lifo->next_w_pos;
        pra_lifo_position_move(
            p_lifo->data_length,
            &p_lifo->next_w_pos);

        p_lifo->p_data[p_lifo->next_w_pos] = data_m_h;
        p_lifo->next_r_pos = p_lifo->next_w_pos;
        pra_lifo_position_move(
            p_lifo->data_length,
            &p_lifo->next_w_pos);

        p_lifo->p_data[p_lifo->next_w_pos] = data_m_l;
        p_lifo->next_r_pos = p_lifo->next_w_pos;
        pra_lifo_position_move(
            p_lifo->data_length,
            &p_lifo->next_w_pos);

        p_lifo->p_data[p_lifo->next_w_pos] = data_l;
        p_lifo->next_r_pos = p_lifo->next_w_pos;
        pra_lifo_position_move(
            p_lifo->data_length,
            &p_lifo->next_w_pos);

        p_lifo->used_length += PRA_NUM_BYTE_SIZE_U32;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_lifo_push_u32_le(
    pra_lifo *const p_lifo,
    uint32_t        data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_lifo_push_args_check(
                             p_lifo,
                             PRA_NUM_BYTE_SIZE_U32,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint8_t data_h = (uint8_t)(data & PRA_NUM_MAX_VALUE_U8);
        uint8_t data_m_h = (uint8_t)((data >> PRA_NUM_BIT_WIDTH_U8) & PRA_NUM_MAX_VALUE_U8);
        uint8_t data_m_l = (uint8_t)((data >> (PRA_NUM_BIT_WIDTH_U8 * 2)) & PRA_NUM_MAX_VALUE_U8);
        uint8_t data_l = (uint8_t)((data >> (PRA_NUM_BIT_WIDTH_U8 * 3)) & PRA_NUM_MAX_VALUE_U8);

        p_lifo->p_data[p_lifo->next_w_pos] = data_h;
        p_lifo->next_r_pos = p_lifo->next_w_pos;
        pra_lifo_position_move(
            p_lifo->data_length,
            &p_lifo->next_w_pos);

        p_lifo->p_data[p_lifo->next_w_pos] = data_m_h;
        p_lifo->next_r_pos = p_lifo->next_w_pos;
        pra_lifo_position_move(
            p_lifo->data_length,
            &p_lifo->next_w_pos);

        p_lifo->p_data[p_lifo->next_w_pos] = data_m_l;
        p_lifo->next_r_pos = p_lifo->next_w_pos;
        pra_lifo_position_move(
            p_lifo->data_length,
            &p_lifo->next_w_pos);

        p_lifo->p_data[p_lifo->next_w_pos] = data_l;
        p_lifo->next_r_pos = p_lifo->next_w_pos;
        pra_lifo_position_move(
            p_lifo->data_length,
            &p_lifo->next_w_pos);

        p_lifo->used_length += PRA_NUM_BYTE_SIZE_U32;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_lifo_pop_u32_be(
    pra_lifo *const p_lifo,
    uint32_t *const p_data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_lifo_pop_u32_args_check(
                             p_lifo,
                             p_data,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint32_t tmp_data = PRA_NUM_ZERO_U;

        tmp_data |= ((uint32_t)p_lifo->p_data[p_lifo->next_r_pos]);
        p_lifo->next_w_pos = p_lifo->next_r_pos;
        pra_lifo_position_back(
            p_lifo->data_length,
            &p_lifo->next_r_pos);

        tmp_data |= (((uint32_t)p_lifo->p_data[p_lifo->next_r_pos]) << PRA_NUM_BIT_WIDTH_U8);
        p_lifo->next_w_pos = p_lifo->next_r_pos;
        pra_lifo_position_back(
            p_lifo->data_length,
            &p_lifo->next_r_pos);

        tmp_data |= (((uint32_t)p_lifo->p_data[p_lifo->next_r_pos]) << (PRA_NUM_BIT_WIDTH_U8 * 2));
        p_lifo->next_w_pos = p_lifo->next_r_pos;
        pra_lifo_position_back(
            p_lifo->data_length,
            &p_lifo->next_r_pos);

        tmp_data |= (((uint32_t)p_lifo->p_data[p_lifo->next_r_pos]) << (PRA_NUM_BIT_WIDTH_U8 * 3));
        p_lifo->next_w_pos = p_lifo->next_r_pos;
        pra_lifo_position_back(
            p_lifo->data_length,
            &p_lifo->next_r_pos);
        p_lifo->used_length -= PRA_NUM_BYTE_SIZE_U32;

        *p_data = tmp_data;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_lifo_pop_u32_le(
    pra_lifo *const p_lifo,
    uint32_t *const p_data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_lifo_pop_u32_args_check(
                             p_lifo,
                             p_data,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint32_t tmp_data = PRA_NUM_ZERO_U;

        tmp_data |= (((uint32_t)p_lifo->p_data[p_lifo->next_r_pos]) << (PRA_NUM_BIT_WIDTH_U8 * 3));
        p_lifo->next_w_pos = p_lifo->next_r_pos;
        pra_lifo_position_back(
            p_lifo->data_length,
            &p_lifo->next_r_pos);

        tmp_data |= (((uint32_t)p_lifo->p_data[p_lifo->next_r_pos]) << (PRA_NUM_BIT_WIDTH_U8 * 2));
        p_lifo->next_w_pos = p_lifo->next_r_pos;
        pra_lifo_position_back(
            p_lifo->data_length,
            &p_lifo->next_r_pos);

        tmp_data |= (((uint32_t)p_lifo->p_data[p_lifo->next_r_pos]) << PRA_NUM_BIT_WIDTH_U8);
        p_lifo->next_w_pos = p_lifo->next_r_pos;
        pra_lifo_position_back(
            p_lifo->data_length,
            &p_lifo->next_r_pos);

        tmp_data |= ((uint32_t)p_lifo->p_data[p_lifo->next_r_pos]);
        p_lifo->next_w_pos = p_lifo->next_r_pos;
        pra_lifo_position_back(
            p_lifo->data_length,
            &p_lifo->next_r_pos);
        p_lifo->used_length -= PRA_NUM_BYTE_SIZE_U32;

        *p_data = tmp_data;

        result = PRA_BOOL_TRUE;
    }

    return result;
}
