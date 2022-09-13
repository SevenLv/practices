/*
 * pra_fifo.c
 * created on Tue Sep 06 2022
 * created by Seven Lv
 * comments:    definitions and functions of fifo
 * version: 0.2
 * history: #       date                modification
 *          0.1     Tue Sep 06 2022     created
 *          0.2     Tue Sep 13 2022     move static functions to internal files
 */

/* includes */
#include "pra_fifo_internal.h"

/* variables */

/* functions */

pra_boolean pra_fifo_init(
    pra_fifo *const p_fifo,
    uint8_t         data[],
    uint16_t        data_length,
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
        for (uint16_t i = PRA_NUM_ZERO_U; i < data_length; i++)
        {
            data[i] = PRA_NUM_ZERO_U;
        }
        p_fifo->p_data = data;
        p_fifo->data_length = data_length;
        p_fifo->used_length = PRA_NUM_ZERO_U;
        p_fifo->next_r_pos = PRA_NUM_ZERO_U;
        p_fifo->next_w_pos = PRA_NUM_ZERO_U;
        p_fifo->initialized = PRA_BOOL_TRUE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_append_u8(
    pra_fifo *const p_fifo,
    uint8_t         data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_fifo_append_args_check(
                             p_fifo,
                             PRA_NUM_BYTE_SIZE_U8,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_fifo->p_data[p_fifo->next_w_pos] = data;
        p_fifo->used_length += PRA_NUM_BYTE_SIZE_U8;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_take_u8(
    pra_fifo *const p_fifo,
    uint8_t *const  p_data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_fifo_take_u8_args_check(
                             p_fifo,
                             p_data,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        *p_data = p_fifo->p_data[p_fifo->next_r_pos];
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_r_pos);
        p_fifo->used_length -= PRA_NUM_BYTE_SIZE_U8;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_append_u16_be(
    pra_fifo *const p_fifo,
    uint16_t        data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_fifo_append_args_check(
                             p_fifo,
                             PRA_NUM_BYTE_SIZE_U16,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint8_t data_h = (uint8_t)((data >> PRA_NUM_BIT_WIDTH_U8) & PRA_NUM_MAX_VALUE_U8);
        uint8_t data_l = (uint8_t)(data & PRA_NUM_MAX_VALUE_U8);
        p_fifo->p_data[p_fifo->next_w_pos] = data_h;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);
        p_fifo->p_data[p_fifo->next_w_pos] = data_l;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);
        p_fifo->used_length += PRA_NUM_BYTE_SIZE_U16;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_append_u16_le(
    pra_fifo *const p_fifo,
    uint16_t        data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_fifo_append_args_check(
                             p_fifo,
                             PRA_NUM_BYTE_SIZE_U16,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint8_t data_h = (uint8_t)(data & PRA_NUM_MAX_VALUE_U8);
        uint8_t data_l = (uint8_t)((data >> PRA_NUM_BIT_WIDTH_U8) & PRA_NUM_MAX_VALUE_U8);
        p_fifo->p_data[p_fifo->next_w_pos] = data_h;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);
        p_fifo->p_data[p_fifo->next_w_pos] = data_l;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);
        p_fifo->used_length += PRA_NUM_BYTE_SIZE_U16;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_take_u16_be(
    pra_fifo *const p_fifo,
    uint16_t *const p_data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_fifo_take_u16_args_check(
                             p_fifo,
                             p_data,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint16_t tmp_data = PRA_NUM_ZERO_U;

        tmp_data |= (((uint16_t)p_fifo->p_data[p_fifo->next_r_pos]) << PRA_NUM_BIT_WIDTH_U8);
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_r_pos);

        tmp_data |= ((uint16_t)p_fifo->p_data[p_fifo->next_r_pos]);
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_r_pos);
        p_fifo->used_length -= PRA_NUM_BYTE_SIZE_U16;

        *p_data = tmp_data;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_take_u16_le(
    pra_fifo *const p_fifo,
    uint16_t *const p_data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_fifo_take_u16_args_check(
                             p_fifo,
                             p_data,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint16_t tmp_data = PRA_NUM_ZERO_U;

        tmp_data |= ((uint16_t)p_fifo->p_data[p_fifo->next_r_pos]);
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_r_pos);

        tmp_data |= (((uint16_t)p_fifo->p_data[p_fifo->next_r_pos]) << PRA_NUM_BIT_WIDTH_U8);
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_r_pos);
        p_fifo->used_length -= PRA_NUM_BYTE_SIZE_U16;

        *p_data = tmp_data;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_append_u32_be(
    pra_fifo *const p_fifo,
    uint32_t        data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_fifo_append_args_check(
                             p_fifo,
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
        p_fifo->p_data[p_fifo->next_w_pos] = data_h;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);
        p_fifo->p_data[p_fifo->next_w_pos] = data_m_h;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);
        p_fifo->p_data[p_fifo->next_w_pos] = data_m_l;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);
        p_fifo->p_data[p_fifo->next_w_pos] = data_l;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);
        p_fifo->used_length += PRA_NUM_BYTE_SIZE_U32;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_append_u32_le(
    pra_fifo *const p_fifo,
    uint32_t        data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_fifo_append_args_check(
                             p_fifo,
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
        p_fifo->p_data[p_fifo->next_w_pos] = data_h;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);
        p_fifo->p_data[p_fifo->next_w_pos] = data_m_h;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);
        p_fifo->p_data[p_fifo->next_w_pos] = data_m_l;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);
        p_fifo->p_data[p_fifo->next_w_pos] = data_l;
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_w_pos);
        p_fifo->used_length += PRA_NUM_BYTE_SIZE_U32;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_take_u32_be(
    pra_fifo *const p_fifo,
    uint32_t *const p_data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_fifo_take_u32_args_check(
                             p_fifo,
                             p_data,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint32_t tmp_data = PRA_NUM_ZERO_U;

        tmp_data |= (((uint32_t)p_fifo->p_data[p_fifo->next_r_pos]) << (PRA_NUM_BIT_WIDTH_U8 * 3));
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_r_pos);

        tmp_data |= (((uint32_t)p_fifo->p_data[p_fifo->next_r_pos]) << (PRA_NUM_BIT_WIDTH_U8 * 2));
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_r_pos);

        tmp_data |= (((uint32_t)p_fifo->p_data[p_fifo->next_r_pos]) << PRA_NUM_BIT_WIDTH_U8);
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_r_pos);

        tmp_data |= ((uint32_t)p_fifo->p_data[p_fifo->next_r_pos]);
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_r_pos);
        p_fifo->used_length -= PRA_NUM_BYTE_SIZE_U32;

        *p_data = tmp_data;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_take_u32_le(
    pra_fifo *const p_fifo,
    uint32_t *const p_data,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_fifo_take_u32_args_check(
                             p_fifo,
                             p_data,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        uint32_t tmp_data = PRA_NUM_ZERO_U;

        tmp_data |= ((uint32_t)p_fifo->p_data[p_fifo->next_r_pos]);
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_r_pos);

        tmp_data |= (((uint32_t)p_fifo->p_data[p_fifo->next_r_pos]) << PRA_NUM_BIT_WIDTH_U8);
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_r_pos);

        tmp_data |= (((uint32_t)p_fifo->p_data[p_fifo->next_r_pos]) << (PRA_NUM_BIT_WIDTH_U8 * 2));
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_r_pos);

        tmp_data |= (((uint32_t)p_fifo->p_data[p_fifo->next_r_pos]) << (PRA_NUM_BIT_WIDTH_U8 * 3));
        pra_fifo_position_move(
            p_fifo->data_length,
            &p_fifo->next_r_pos);
        p_fifo->used_length -= PRA_NUM_BYTE_SIZE_U32;

        *p_data = tmp_data;

        result = PRA_BOOL_TRUE;
    }

    return result;
}
