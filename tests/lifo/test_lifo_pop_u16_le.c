#include "test_lifo_pop_u16.h"

int main(void);

int main(void)
{
    return test_lifo_pop_u16(
        &pra_lifo_pop_u16_le,
        &pra_lifo_push_u16_le);
}