#include "pra_list.h"
#include "pra_list_ec.h"
#include "test.h"


int main(void);

int main(void)
{
    int result = err_none;

    pra_list_node          node;
    pra_boolean            expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T               expected_ec = PRA_EC_NONE;
    PRA_EC_T               acctual_ec = PRA_EC_NONE;
    struct _pra_list_node *expected_next = PRA_LIST_ST_NODE_NULL;
    struct _pra_list_node *expected_previous = PRA_LIST_ST_NODE_NULL;
    void                  *expected_data = PRA_VOID_NULL;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_list_init(
                               &node,
                               PRA_EC_T_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIST_EC_NULL_PTR;
    acctual_ec = PRA_EC_NONE;
    if (expected_result != pra_list_init(
                               PRA_LIST_NODE_NULL,
                               &acctual_ec) ||
        expected_ec != acctual_ec)
    {
        result |= err_error2;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    acctual_ec = PRA_EC_NONE;
    if (expected_result != pra_list_init(
                               &node,
                               &acctual_ec) ||
        expected_ec != acctual_ec ||
        expected_next != node.p_next ||
        expected_previous != node.p_previous ||
        expected_data != node.p_data)
    {
        result |= err_error3;
    }

    return result;
}