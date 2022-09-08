#include "test_fifo_append_u16.h"
#include "pra_bits.h"

int main(void);

static uint8_t get_u8_h_be(uint16_t data);
static uint8_t get_u8_l_be(uint16_t data);

int main(void)
{
    return test_fifo_append_u16(
        &pra_fifo_append_u16_le,
        &get_u8_h_be,
        &get_u8_l_be);
}

static uint8_t get_u8_h_be(uint16_t data)
{
    return ((uint8_t)(data & UINT8_MAX));
}

static uint8_t get_u8_l_be(uint16_t data)
{
    return ((uint8_t)((data >> PRA_BITS_U8_WIDTH) & UINT8_MAX));
}