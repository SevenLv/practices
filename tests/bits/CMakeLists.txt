project(practices_test VERSION 0.1.0)

include_directories(
    ../
)

add_executable(test_bits_u8_get test_bits_u8_get.c)
target_link_libraries(test_bits_u8_get practices)
add_test(NAME test_bits_u8_get COMMAND test_bits_u8_get)

add_executable(test_bits_u8_set test_bits_u8_set.c)
target_link_libraries(test_bits_u8_set practices)
add_test(NAME test_bits_u8_set COMMAND test_bits_u8_set)

add_executable(test_bits_u16_get test_bits_u16_get.c)
target_link_libraries(test_bits_u16_get practices)
add_test(NAME test_bits_u16_get COMMAND test_bits_u16_get)

add_executable(test_bits_u16_set test_bits_u16_set.c)
target_link_libraries(test_bits_u16_set practices)
add_test(NAME test_bits_u16_set COMMAND test_bits_u16_set)

add_executable(test_bits_u32_get test_bits_u32_get.c)
target_link_libraries(test_bits_u32_get practices)
add_test(NAME test_bits_u32_get COMMAND test_bits_u32_get)

add_executable(test_bits_u32_set test_bits_u32_set.c)
target_link_libraries(test_bits_u32_set practices)
add_test(NAME test_bits_u32_set COMMAND test_bits_u32_set)