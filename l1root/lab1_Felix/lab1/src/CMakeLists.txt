project(src)
set(HEADER_FILES divisibility.h prime.h sequences.h)
set(SOURCE_FILES divisibility.cpp prime.cpp sequences.cpp)
add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})