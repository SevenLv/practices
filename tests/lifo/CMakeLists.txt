project(practices_test VERSION 0.1.0)

include_directories(
    ../
)

add_executable(test_lifo_init test_lifo_init.c)
target_link_libraries(test_lifo_init practices)
add_test(NAME test_lifo_init COMMAND test_lifo_init)

add_executable(test_lifo_push_u8 test_lifo_push_u8.c)
target_link_libraries(test_lifo_push_u8 practices)
add_test(NAME test_lifo_push_u8 COMMAND test_lifo_push_u8)

add_executable(test_lifo_pop_u8 test_lifo_pop_u8.c)
target_link_libraries(test_lifo_pop_u8 practices)
add_test(NAME test_lifo_pop_u8 COMMAND test_lifo_pop_u8)

add_executable(
    test_lifo_push_u16_be 
    test_lifo_push_u16_be.c 
    test_lifo_push_u16.c)
target_link_libraries(test_lifo_push_u16_be practices)
add_test(NAME test_lifo_push_u16_be COMMAND test_lifo_push_u16_be)

add_executable(
    test_lifo_push_u16_le 
    test_lifo_push_u16_le.c 
    test_lifo_push_u16.c)
target_link_libraries(test_lifo_push_u16_le practices)
add_test(NAME test_lifo_push_u16_le COMMAND test_lifo_push_u16_le)

add_executable(
    test_lifo_pop_u16_be 
    test_lifo_pop_u16_be.c 
    test_lifo_pop_u16.c)
target_link_libraries(test_lifo_pop_u16_be practices)
add_test(NAME test_lifo_pop_u16_be COMMAND test_lifo_pop_u16_be)

add_executable(
    test_lifo_pop_u16_le 
    test_lifo_pop_u16_le.c 
    test_lifo_pop_u16.c)
target_link_libraries(test_lifo_pop_u16_le practices)
add_test(NAME test_lifo_pop_u16_le COMMAND test_lifo_pop_u16_le)

add_executable(
    test_lifo_push_u32_be 
    test_lifo_push_u32_be.c 
    test_lifo_push_u32.c)
target_link_libraries(test_lifo_push_u32_be practices)
add_test(NAME test_lifo_push_u32_be COMMAND test_lifo_push_u32_be)

add_executable(
    test_lifo_push_u32_le 
    test_lifo_push_u32_le.c 
    test_lifo_push_u32.c)
target_link_libraries(test_lifo_push_u32_le practices)
add_test(NAME test_lifo_push_u32_le COMMAND test_lifo_push_u32_le)

add_executable(
    test_lifo_pop_u32_be 
    test_lifo_pop_u32_be.c 
    test_lifo_pop_u32.c)
target_link_libraries(test_lifo_pop_u32_be practices)
add_test(NAME test_lifo_pop_u32_be COMMAND test_lifo_pop_u32_be)