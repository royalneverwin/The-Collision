cmake_minimum_required(VERSION 3.0.0)
project(music)
add_definitions(--std=c++11)

set(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

include_directories(
    ${PROJECT_DIR}/include/
)

set(RAYLIB_LIB
    ${PROJECT_DIR}/lib/libraylib.dll.a
)

aux_source_directory("${PROJECT_DIR}/src/" SRC_LIST)
aux_source_directory("${PROJECT_DIR}/src/page" PAGE_LIST)
aux_source_directory("${PROJECT_DIR}/src/object" OBJECT_LIST)

add_executable(music ${SRC_LIST} ${PAGE_LIST} ${OBJECT_LIST})
target_link_libraries(music ${RAYLIB_LIB})