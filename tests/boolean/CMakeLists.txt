project(practices_test VERSION 0.1.0)

include_directories(
    ../
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