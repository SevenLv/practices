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

add_executable(test_list_insert test_list_insert.c)
target_link_libraries(test_list_insert practices)
add_test(NAME test_list_insert COMMAND test_list_insert)

add_executable(test_list_remove test_list_remove.c)
target_link_libraries(test_list_remove practices)
add_test(NAME test_list_remove COMMAND test_list_remove)