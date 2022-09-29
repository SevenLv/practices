#include "pra_defs.h"
#include "pra_ec.h"
#include "test.h"
#include "test_crc32.h"


int test_get(get_func get)
{
    int result = err_none;

    pra_crc32   crc;
    uint32_t    expected_ec = PRA_EC_NONE;
    uint32_t    actual_ec = PRA_EC_NONE;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != get(&crc, PRA_UINT32_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != get(PRA_CRC32_NULL, &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != get(&crc, &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    return result;
}

int test_init(get_func get)
{
    int result = err_none;

    pra_crc32 crc;
    uint32_t  expected_ec = PRA_EC_NONE;
    uint32_t  actual_ec = PRA_EC_NONE;

    pra_boolean expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_crc32_init(
                               &crc,
                               PRA_UINT32_NULL))
    {
        result |= err_error4;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_crc32_init(
                               PRA_CRC32_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }

    if (PRA_BOOL_TRUE != get(&crc, &actual_ec))
    {
        result |= err_error6;
    }
    else
    {
        expected_result = PRA_BOOL_TRUE;
        expected_ec = PRA_EC_NONE;
        actual_ec = PRA_EC_NONE;
        if (expected_result != pra_crc32_init(
                                   &crc,
                                   &actual_ec) ||
            expected_ec != actual_ec ||
            PRA_BOOL_TRUE != crc.initialized)
        {
            result |= err_error7;
        }
    }

    return result;
}

int test_compute(
    get_func get,
    uint32_t expected_crc_result)
{
    int result = err_none;

    pra_crc32   crc;
    uint8_t     bytes[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    uint32_t    offset = 0U;
    uint32_t    length = 9U;
    uint32_t    actual_crc_result = 0U;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    uint32_t    expected_ec = PRA_EC_NONE;
    uint32_t    actual_ec = PRA_EC_NONE;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_crc32_compute(
                               &crc,
                               bytes,
                               offset,
                               length,
                               &actual_crc_result,
                               PRA_UINT32_NULL))
    {
        result |= err_error8;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_crc32_compute(
                               PRA_CRC32_NULL,
                               bytes,
                               offset,
                               length,
                               &actual_crc_result,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error9;
    }

    if (PRA_BOOL_TRUE != get(&crc, &actual_ec))
    {
        result |= err_error10;
    }

    if (PRA_BOOL_TRUE != pra_crc32_init(&crc, &actual_ec))
    {
        result |= err_error11;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_crc32_compute(
                               &crc,
                               PRA_UINT8_NULL,
                               offset,
                               length,
                               &actual_crc_result,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error12;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_crc32_compute(
                               &crc,
                               bytes,
                               offset,
                               length,
                               PRA_UINT32_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error13;
    }

    crc.initialized = PRA_BOOL_FALSE;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NOT_INIT;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_crc32_compute(
                               &crc,
                               bytes,
                               offset,
                               length,
                               &actual_crc_result,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error14;
    }

    crc.initialized = PRA_BOOL_TRUE;
    offset = length;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_INVALID_OFFSET;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_crc32_compute(
                               &crc,
                               bytes,
                               offset,
                               length,
                               &actual_crc_result,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error15;
    }

    offset = 0;
    length = 0;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_INVALID_LENGTH;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_crc32_compute(
                               &crc,
                               bytes,
                               offset,
                               length,
                               &actual_crc_result,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error16;
    }

    offset = 0;
    length = 9;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_crc32_compute(
                               &crc,
                               bytes,
                               offset,
                               length,
                               &actual_crc_result,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_crc_result != actual_crc_result)
    {
        result |= err_error17;
    }

    return result;
}
