project(practices_test VERSION 0.1.0)

include_directories(
    ../
)

add_executable(test_list_init test_list_init.c)
target_link_libraries(test_list_init practices)
add_test(NAME test_list_init COMMAND test_list_init)

add_executable(test_list_append test_list_append.c)
target_link_libraries(test_list_append practices)
add_test(NAME test_list_append COMMAND test_list_append)