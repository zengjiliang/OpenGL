//
// Created by zengjiliang on 2022/5/2.
//

#ifndef OPENGL_CREATEGLEW_H
#define OPENGL_CREATEGLEW_H
#define GLEW_STATIC
#include "GL/glew.h"
#include <iostream>

struct ViewportData{
public:
    GLint x,y;
    GLsizei width,height;
public:
    ViewportData(GLint gx,GLint gy,GLsizei gwidth,GLsizei gheight){
        x = gx;
        y = gy;
        width = gwidth;
        height = gheight;
    }
};

class CreateGLEW {
private:
    unsigned int vbo,vao,vertexShader,fragmentShader,shaderProgram;
public:
    bool glewinit(bool experimental,const ViewportData* data);
    /*
     * 设置顶点数据
     */
    void setBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
    /*
     * 编译 fragment shader
     * @source 代码
     */
    void compileFragmentShader(const GLchar *const* source);
    /*
     * 编译vertex shader
     * @source 代码
     */
    void compileVertexShader(const GLchar *const* source);
    /*
     * 创建shader program
     */
    void createShaderProgram();
    void enableVertexAttribArray();
    /*
     * 绘制 shader
     * @mode 绘制方式
     * @first 从哪个位置开始绘制
     * @count 绘制几个
     */
    void drawArrays(GLenum mode, GLint first, GLsizei count);
    ~CreateGLEW();
private:
    /*
     * vbo 绑定
     */
    void BindBuffer();
    /*
     * vao 绑定
     */
    void BindVertex();
    void compileShader(unsigned int& shaderId,GLenum type,const GLchar *const* source);
};


#endif //OPENGL_CREATEGLEW_H
