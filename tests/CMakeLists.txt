project(practices_test VERSION 0.1.0)

include_directories(
    ./includes
)

add_executable(test_boolean_is_true test_boolean_is_true.c)
target_link_libraries(test_boolean_is_true practices)
add_test(NAME test_boolean_is_true COMMAND test_boolean_is_true)

add_executable(test_boolean_not test_boolean_not.c)
target_link_libraries(test_boolean_not practices)
add_test(NAME test_boolean_not COMMAND test_boolean_not)

add_executable(test_boolean_and test_boolean_and.c)
target_link_libraries(test_boolean_and practices)
add_test(NAME test_boolean_and COMMAND test_boolean_and)

add_executable(test_boolean_or test_boolean_or.c)
target_link_libraries(test_boolean_or practices)
add_test(NAME test_boolean_or COMMAND test_boolean_or)

add_executable(test_boolean_xor test_boolean_xor.c)
target_link_libraries(test_boolean_xor practices)
add_test(NAME test_boolean_xor COMMAND test_boolean_xor)

add_executable(test_bytes_not_null_ptr test_bytes_not_null_ptr.c)
target_link_libraries(test_bytes_not_null_ptr practices)
add_test(NAME test_bytes_not_null_ptr COMMAND test_bytes_not_null_ptr)

add_executable(test_bytes_init test_bytes_init.c)
target_link_libraries(test_bytes_init practices)
add_test(NAME test_bytes_init COMMAND test_bytes_init)
