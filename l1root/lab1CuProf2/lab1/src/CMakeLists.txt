project(src)
set(HEADER_FILES calculator.h)
set(SOURCE_FILES calculator.cpp)
add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})