#include "test_fifo_take_u32.h"

int main(void);

int main(void)
{
    return test_fifo_take_u32(
        &pra_fifo_take_u32_be,
        &pra_fifo_append_u32_be);
}