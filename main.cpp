#include <iostream>
#include "Core/Header/CreateGLEW.h"
#include "Core/Header/CreateGLFW.h"
float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
};

const char* vertexShader = "#version 330 core\n"
                           "layout (location = 0) in vec3 aPos;\n"
                           "void main(){gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);}";
const char* fragmentShader = "#version 330 core\n"
                             "out vec4 FragColor;\n"
                             "void main(){FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);}";

int main() {
    std::cout << "Hello, World!" << std::endl;
    CreateGLFW* glfw = new CreateGLFW();
    glfw->glfw_init(3,3,GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfw->createWindow(800,600,"My OpenGL Game");
    glfw->setGLClearColor(0,.5f,0.5f,1.0f);

    ViewportData* data = new ViewportData(0,0,800,600);
    CreateGLEW* glew = new CreateGLEW();
    if(glew->glewinit(true, data) == false){
        return  -1;
    }
    glew->setBufferData(GL_ARRAY_BUFFER,sizeof vertices,vertices,GL_STATIC_DRAW);


    glew->compileFragmentShader(&fragmentShader);
    glew->compileVertexShader(&vertexShader);
    glew->createShaderProgram();
    glew->enableVertexAttribArray();
    while (glfw->getWindowShouldClose() == false){
        glfw->run(glew);
    }

    glfw->close();
    return 0;
}

