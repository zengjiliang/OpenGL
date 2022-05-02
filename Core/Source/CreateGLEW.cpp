//
// Created by zengjiliang on 2022/5/2.
//

#include "../Header/CreateGLEW.h"



bool CreateGLEW::glewinit(bool experimental,const ViewportData * data) {
    glewExperimental = experimental;
    if(GLEW_OK != glewInit()){
        std::cout << " init glew failed." << std::endl;
        return false ;
    }
    glViewport(data->x,data->y,data->width,data->height);
    return true;
}

void CreateGLEW::setBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage) {
    BindBuffer();
    BindVertex();

    glBufferData(target,size,data,usage);
}

void CreateGLEW::BindBuffer() {
    glGenBuffers(1,&vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

}

void CreateGLEW::BindVertex() {
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);
}

void CreateGLEW::compileFragmentShader(const GLchar *const* source) {
//    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader,1,source, nullptr);
//    glCompileShader(fragmentShader);
    compileShader(fragmentShader,GL_FRAGMENT_SHADER,source);
}

void CreateGLEW::compileShader(unsigned int &shaderId, GLenum type, const GLchar *const *source) {
    shaderId = glCreateShader(type);
    glShaderSource(shaderId,1,source, nullptr);
    glCompileShader(shaderId);
}

void CreateGLEW::compileVertexShader(const GLchar *const *source) {
    compileShader(vertexShader,GL_VERTEX_SHADER,source);
}

void CreateGLEW::createShaderProgram() {
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram,vertexShader);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);
}

void CreateGLEW::drawArrays(GLenum mode, GLint first, GLsizei count) {
    glBindVertexArray(vao);
    glUseProgram(shaderProgram);
    glDrawArrays(mode,first,count);
}

void CreateGLEW::enableVertexAttribArray() {
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof (float) ,(void*)0);
    glEnableVertexAttribArray(0);
}




