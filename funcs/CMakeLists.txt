project(practices VERSION 0.1.0)

set(
    STATIC_LIB_SOURCE
    pra_boolean.c
    pra_bytes.c
    pra_bits.c
)

add_library(practices STATIC ${STATIC_LIB_SOURCE})