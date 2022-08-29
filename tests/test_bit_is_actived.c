#include "pra_bits.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    pra_bit value = PRA_BIT_UNKNOWN;
    pra_bit expected = PRA_BIT_UNKNOWN;

    value = PRA_BIT_ACTIVED;
    expected = PRA_BIT_ACTIVED;
    if (expected != pra_bit_is_actived(value))
    {
        result |= err_error1;
    }

    value = PRA_BIT_INACTIVED;
    expected = PRA_BIT_INACTIVED;
    if (expected != pra_bit_is_actived(value))
    {
        result |= err_error2;
    }

    value = PRA_BIT_UNKNOWN;
    expected = PRA_BIT_INACTIVED;
    if (expected != pra_bit_is_actived(value))
    {
        result |= err_error3;
    }

    return result;
}