cmake_minimum_required(VERSION 3.22)
project(OpenGL)

set(CMAKE_CXX_STANDARD 14)

include_directories(3rd/glew-2.1.0/include 3rd/glfw-3.3.7.bin.WIN64/include Core/Header)
#库文件搜索路径
link_directories(3rd/glew-2.1.0/lib/Release/x64 3rd/glfw-3.3.7.bin.WIN64/lib-mingw-w64)
#link_libraries
link_libraries(opengl32 glfw3 glew32s)

add_executable(OpenGL main.cpp Core/Source/CreateGLEW.cpp Core/Header/CreateGLEW.h Core/Source/CreateGLFW.cpp Core/Header/CreateGLFW.h)

target_link_libraries(OpenGL opengl32 glfw3 glew32s)

