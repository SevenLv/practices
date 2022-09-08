#include "test_fifo_append_u16.h"
#include "pra_bits.h"
#include "pra_num_defs.h"

int main(void);

static uint8_t get_u8_h_be(uint16_t data);
static uint8_t get_u8_l_be(uint16_t data);

static uint8_t get_u8_h_be(uint16_t data)
{
    return ((uint8_t)((data >> PRA_NUM_BIT_WIDTH_U8) & PRA_NUM_MAX_VALUE_U8));
}

static uint8_t get_u8_l_be(uint16_t data)
{
    return ((uint8_t)(data & PRA_NUM_MAX_VALUE_U8));
}

int main(void)
{
    return test_fifo_append_u16(
        &pra_fifo_append_u16_be,
        &get_u8_h_be,
        &get_u8_l_be);
}