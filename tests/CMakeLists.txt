project(practices_test VERSION 0.1.0)

include_directories(
    ./includes
)

add_subdirectory(bits)

add_subdirectory(boolean)

add_subdirectory(bytes)

add_subdirectory(crc8)

add_subdirectory(crc16)

add_subdirectory(crc32)

add_subdirectory(fifo)

add_subdirectory(lifo)