cmake_minimum_required(VERSION 3.0.0)
project(practices VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(LIBRARY_OUTPUT_PATH .output)
set(CMAKE_STATIC_LIBRARY_PREFIX )
include(CPack)

set(
    STATIC_LIB_SOURCE
    funcs/pra_types.c
)

add_library(practices STATIC ${STATIC_LIB_SOURCE})

target_include_directories(practices PUBLIC ${PROJECT_SOURCE_DIR}/includes)
