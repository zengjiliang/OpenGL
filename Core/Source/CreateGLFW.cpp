//
// Created by zengjiliang on 2022/5/2.
//

#include "../Header/CreateGLFW.h"

void CreateGLFW::glfw_init(int versionMajor, int versionMinor, int openglProfile, int openglCodeProfile) {
    r = 0.3f;
    g = 0.2f;
    b = 0.3f;
    a = 1.0f;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,versionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,versionMinor);
    glfwWindowHint(openglProfile,openglCodeProfile);
}

bool CreateGLFW::createWindow(int width, int height, const char *title) {
    window = glfwCreateWindow(width,height,title, nullptr, nullptr);
    if(nullptr == window){
        std::cout << "Failed to create glfw window" << std::endl;
        close();
        return false ;
    }
    glfwMakeContextCurrent(window);
    return true;
}

void CreateGLFW::close() {
    std::cout << getWindowShouldClose() << std::endl;
    if(getWindowShouldClose() == true)
        glfwTerminate();
}

void CreateGLFW::run(CreateGLEW* glew) {
        processInput();
        glClearColor(r,g,b,a);
        glClear(GL_COLOR_BUFFER_BIT);
        glew->drawArrays(GL_TRIANGLES,0,3);
        glfwSwapBuffers(window);
        glfwPollEvents();

}

void CreateGLFW::setGLClearColor(float red, float green, float blue, float alpha) {
    r= red;
    g = green;
    b = blue;
    a = alpha;
}

void CreateGLFW::processInput() {
    if (GLFW_PRESS == glfwGetKey(window,GLFW_KEY_ESCAPE)){
        glfwSetWindowShouldClose(window, true);
    }
    //close();
}

bool CreateGLFW::getWindowShouldClose() {
    return glfwWindowShouldClose(window);
}
