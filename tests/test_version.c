#include "pra_version.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    const uint8_t expected_major = 0U;
    const uint8_t expected_minor = 5U;
    const uint8_t expected_reversion = 19U;

    pra_version actual_version;

    actual_version = pra_get_version();

    if (expected_major != actual_version.major)
    {
        result |= err_error1;
    }

    if (expected_minor != actual_version.minor)
    {
        result |= err_error2;
    }

    if (expected_reversion != actual_version.reversion)
    {
        result |= err_error3;
    }

    return result;
}