project(practices_test VERSION 0.1.0)

include_directories(
    ../
)

add_executable(test_math_gcd_euclid test_math_gcd_euclid.c)
target_link_libraries(test_math_gcd_euclid practices)
add_test(NAME test_math_gcd_euclid COMMAND test_math_gcd_euclid)

add_executable(test_math_is_coprime test_math_is_coprime.c)
target_link_libraries(test_math_is_coprime practices)
add_test(NAME test_math_is_coprime COMMAND test_math_is_coprime)