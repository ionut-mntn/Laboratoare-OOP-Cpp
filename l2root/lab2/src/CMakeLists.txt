project(src)
set(HEADER_FILES complex.h)
set(SOURCE_FILES complex.cpp)
add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})