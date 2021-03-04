project(src)
set(HEADER_FILES car.h)
set(SOURCE_FILES car.cpp)
add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})