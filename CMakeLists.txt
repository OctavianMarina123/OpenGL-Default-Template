cmake_minimum_required(VERSION 3.20)
project(OpenGL_CLion_Template)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        libraries/glfw/include
        libraries/glad/include
        libraries/stb_images/include
        libraries/glm
)
link_directories(
        libraries/glfw/lib
)
link_libraries(
        opengl32.lib
        glfw3.lib
)
add_executable(
        OpenGL_CLion_Template
        src/main.cpp
        libraries/glad/src/glad.c src/Shader.cpp include/Shader.h src/Camera.cpp include/Camera.h src/EBO.cpp include/EBO.h src/Texture.cpp include/Texture.h src/VAO.cpp include/VAO.h src/VBO.cpp include/VBO.h src/stb.cpp)

