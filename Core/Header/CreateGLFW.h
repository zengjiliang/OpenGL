//
// Created by zengjiliang on 2022/5/2.
//

#ifndef OPENGL_CREATEGLFW_H
#define OPENGL_CREATEGLFW_H
#include "CreateGLEW.h"
#include "GLFW/glfw3.h"
#include <iostream>

class CreateGLFW {
private:
    GLFWwindow* window;
    float r,g,b,a;
public:
    /*
     * @versionMajor
     * @versionMinor
     */
    void glfw_init(int versionMajor,int versionMinor,int openglProfile,int openglCodeProfile);
    /*
     * 创建窗口
     * @width 宽
     * @height 高
     * @title 标题
     */
    bool createWindow(int width,int height,const char* title);
    /*
     * 设置背景颜色
     */
    void setGLClearColor(float red,float green,float blue,float alpha);
    /*
     * 检测该窗口是否关闭
     */
    bool getWindowShouldClose();
    /*
     * 执行
     */
    void run(CreateGLEW* glew);
    void close();


    ~CreateGLFW();
private:
    /*
     * 按键监听函数
     */
    void processInput();
};


#endif //OPENGL_CREATEGLFW_H
