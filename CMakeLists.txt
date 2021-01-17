cmake_minimum_required(VERSION 3.17)
project(GeoTR)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(SDL2 REQUIRED)

add_executable(GeoTR
        include/Display.h
        include/Mesh.h
        include/Shader.h
        include/Vertices.h
        src/Display.cpp
        src/Mesh.cpp
        src/Shader.cpp
        src/Vertices.cpp
        main.cpp)

target_include_directories(GeoTR  PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(GeoTR PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(GeoTR PUBLIC ${GLEW_INCLUDE_DIRS})

target_link_libraries(GeoTR PUBLIC ${OPENGL_LIBRARIES})
target_link_libraries(GeoTR PUBLIC ${SDL2_LIBRARIES})
target_link_libraries(GeoTR PUBLIC ${GLEW_LIBRARIES})



