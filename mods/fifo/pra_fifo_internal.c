/*
 * pra_fifo_internal.c
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    internal functions of pra_fifo
 * version: 0.3
 * history: #       date                modification
 *          0.1     Tue Sep 13 2022     created
 *          0.2     Wed Sep 14 2022     include pra_fifo_ec.h
 *          0.3     Thu Sep 22 2022     use PRA_NUM_BIT_MAX_OFFSET_U16 macro in pra_fifo_position_move function
 * */

/* includes */
#include "pra_fifo_ec.h"
#include "pra_fifo_internal.h"


/* variables */

/* functions */

pra_boolean pra_fifo_init_args_check(
    const pra_fifo *const p_fifo,
    uint16_t              data_length,
    PRA_EC_T *const       p_ec)
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
    else if (PRA_NUM_ZERO_U == data_length)
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

void pra_fifo_position_move(
    uint16_t        data_length,
    uint16_t *const p_position)
{
    if (PRA_NUM_ZERO_U == data_length)
    {
        /* NOTE do nothing */
    }
    if (PRA_NUM_BIT_MAX_OFFSET_U16 == *p_position)
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

pra_boolean pra_fifo_append_args_check(
    const pra_fifo *const p_fifo,
    uint16_t              data_length,
    PRA_EC_T *const       p_ec)
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
    else if (PRA_NUM_MAX_VALUE_U16 == p_fifo->used_length)
    {
        *p_ec |= PRA_FIFO_EC_DATA_FULL;
        result = PRA_BOOL_FALSE;
    }
    else if (p_fifo->data_length < p_fifo->used_length + data_length)
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

pra_boolean pra_fifo_take_u8_args_check(
    const pra_fifo *const p_fifo,
    const uint8_t *const  p_data,
    PRA_EC_T *const       p_ec)
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
    else if (PRA_UINT8_NULL == p_data)
    {
        *p_ec |= PRA_FIFO_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != p_fifo->initialized)
    {
        *p_ec |= PRA_FIFO_EC_NOT_INIT;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BYTE_SIZE_U8 > p_fifo->used_length)
    {
        *p_ec |= PRA_FIFO_EC_DATA_NOT_ENOUGH;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_take_u16_args_check(
    const pra_fifo *const p_fifo,
    const uint16_t *const p_data,
    PRA_EC_T *const       p_ec)
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
    else if (PRA_UINT16_NULL == p_data)
    {
        *p_ec |= PRA_FIFO_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != p_fifo->initialized)
    {
        *p_ec |= PRA_FIFO_EC_NOT_INIT;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BYTE_SIZE_U16 > p_fifo->used_length)
    {
        *p_ec |= PRA_FIFO_EC_DATA_NOT_ENOUGH;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_fifo_take_u32_args_check(
    const pra_fifo *const p_fifo,
    const uint32_t *const p_data,
    PRA_EC_T *const       p_ec)
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
    else if (PRA_UINT32_NULL == p_data)
    {
        *p_ec |= PRA_FIFO_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE != p_fifo->initialized)
    {
        *p_ec |= PRA_FIFO_EC_NOT_INIT;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_NUM_BYTE_SIZE_U32 > p_fifo->used_length)
    {
        *p_ec |= PRA_FIFO_EC_DATA_NOT_ENOUGH;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}