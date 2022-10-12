project(practices_test VERSION 0.1.0)

include_directories(
    ./includes
)

add_executable(test_version test_version.c)
target_link_libraries(test_version practices)
add_test(NAME test_version COMMAND test_version)

add_subdirectory(bits)

add_subdirectory(boolean)

add_subdirectory(bytes)

add_subdirectory(crc8)

add_subdirectory(crc16)

add_subdirectory(crc32)

add_subdirectory(fifo)

add_subdirectory(lifo)

add_subdirectory(list)

add_subdirectory(timer)

add_subdirectory(task)

add_subdirectory(stepper)

add_subdirectory(math)