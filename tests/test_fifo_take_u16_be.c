#include "test_fifo_take_u16.h"

int main(void);

int main(void)
{
    return test_fifo_take_u16(
        &pra_fifo_take_u16_be,
        &pra_fifo_append_u16_be);
}