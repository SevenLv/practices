/*
 * pra_lifo.c
 * created on Thu Sep 08 2022
 * created by Seven Lv
 * comments:    definitions and functions of lifo
 * version: 0.3
 * history: #       date                modification
 *          0.1     Thu Sep 08 2022     created
 *          0.2     Tue Sep 13 2022     move static functions to internal files
 *          0.3     Wed Sep 14 2022     include pra_lifo_ec.h
 *                                      include pra_lifo.h
 */

/* includes */
#include "pra_lifo.h"
#include "pra_lifo_ec.h"
#include "pra_lifo_internal.h"


/* variables */

/* functions */

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
