#include "test_fifo_append_u32.h"
#include "pra_bits.h"

int main(void);

static uint8_t get_u8_h_be(uint32_t data);
static uint8_t get_u8_m_h_be(uint32_t data);
static uint8_t get_u8_m_l_be(uint32_t data);
static uint8_t get_u8_l_be(uint32_t data);

int main(void)
{
    return test_fifo_append_u32(
        &pra_fifo_append_u32_be,
        &get_u8_h_be,
        &get_u8_m_h_be,
        &get_u8_m_l_be,
        &get_u8_l_be);
}

static uint8_t get_u8_h_be(uint32_t data)
{
    return ((uint8_t)((data >> (PRA_BITS_U8_WIDTH * 3)) & UINT8_MAX));
}

static uint8_t get_u8_m_h_be(uint32_t data)
{
    return ((uint8_t)((data >> (PRA_BITS_U8_WIDTH * 2)) & UINT8_MAX));
}

static uint8_t get_u8_m_l_be(uint32_t data)
{
    return ((uint8_t)((data >> PRA_BITS_U8_WIDTH) & UINT8_MAX));
}

static uint8_t get_u8_l_be(uint32_t data)
{
    return ((uint8_t)(data & UINT8_MAX));
}