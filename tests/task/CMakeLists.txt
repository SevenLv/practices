project(practices_test VERSION 0.1.0)

include_directories(
    ../
)

add_executable(test_task_init test_task_init.c)
target_link_libraries(test_task_init practices)
add_test(NAME test_task_init COMMAND test_task_init)

add_executable(test_task_add test_task_add.c)
target_link_libraries(test_task_add practices)
add_test(NAME test_task_add COMMAND test_task_add)

add_executable(test_task_remove test_task_remove.c)
target_link_libraries(test_task_remove practices)
add_test(NAME test_task_remove COMMAND test_task_remove)