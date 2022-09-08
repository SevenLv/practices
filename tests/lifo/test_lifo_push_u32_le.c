#include "test_lifo_push_u32.h"
#include "pra_bits.h"

int main(void);

static uint8_t get_u8_h_le(uint32_t data);
static uint8_t get_u8_m_h_le(uint32_t data);
static uint8_t get_u8_m_l_le(uint32_t data);
static uint8_t get_u8_l_le(uint32_t data);

static uint8_t get_u8_h_le(uint32_t data)
{
    return ((uint8_t)(data & UINT8_MAX));
}

static uint8_t get_u8_m_h_le(uint32_t data)
{
    return ((uint8_t)((data >> PRA_BITS_U8_WIDTH) & UINT8_MAX));
}

static uint8_t get_u8_m_l_le(uint32_t data)
{
    return ((uint8_t)((data >> (PRA_BITS_U8_WIDTH * 2)) & UINT8_MAX));
}

static uint8_t get_u8_l_le(uint32_t data)
{
    return ((uint8_t)((data >> (PRA_BITS_U8_WIDTH * 3)) & UINT8_MAX));
}

int main(void)
{
    return test_lifo_push_u32(
        &pra_lifo_push_u32_le,
        &get_u8_h_le,
        &get_u8_m_h_le,
        &get_u8_m_l_le,
        &get_u8_l_le);
}
