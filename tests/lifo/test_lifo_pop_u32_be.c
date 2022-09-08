#include "test_lifo_pop_u32.h"

int main(void);

int main(void)
{
    return test_lifo_pop_u32(
        &pra_lifo_pop_u32_be,
        &pra_lifo_push_u32_be);
}