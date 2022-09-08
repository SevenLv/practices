#include "test_lifo_push_u32.h"
#include "pra_bits.h"
#include "pra_num_defs.h"

int main(void);

static uint8_t get_u8_h_be(uint32_t data);
static uint8_t get_u8_m_h_be(uint32_t data);
static uint8_t get_u8_m_l_be(uint32_t data);
static uint8_t get_u8_l_be(uint32_t data);

static uint8_t get_u8_h_be(uint32_t data)
{
    return ((uint8_t)((data >> (PRA_NUM_BIT_WIDTH_U8 * 3)) & PRA_NUM_MAX_VALUE_U8));
}

static uint8_t get_u8_m_h_be(uint32_t data)
{
    return ((uint8_t)((data >> (PRA_NUM_BIT_WIDTH_U8 * 2)) & PRA_NUM_MAX_VALUE_U8));
}

static uint8_t get_u8_m_l_be(uint32_t data)
{
    return ((uint8_t)((data >> PRA_NUM_BIT_WIDTH_U8) & PRA_NUM_MAX_VALUE_U8));
}

static uint8_t get_u8_l_be(uint32_t data)
{
    return ((uint8_t)(data & PRA_NUM_MAX_VALUE_U8));
}

int main(void)
{
    return test_lifo_push_u32(
        &pra_lifo_push_u32_be,
        &get_u8_h_be,
        &get_u8_m_h_be,
        &get_u8_m_l_be,
        &get_u8_l_be);
}
