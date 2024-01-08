//
// Created by Octa on 1/8/2024.
//

#ifndef OPENGL_CLION_TEMPLATE_VAO_H
#define OPENGL_CLION_TEMPLATE_VAO_H
#include"glad/glad.h"
#include "VBO.h"


class VAO
{
public:
    // ID reference for the Vertex Array Object
    GLuint ID;
    // Constructor that generates a VAO ID
    VAO();

    // Links a VBO Attribute such as a position or color to the VAO
    void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
    // Binds the VAO
    void Bind();
    // Unbinds the VAO
    void Unbind();
    // Deletes the VAO
    void Delete();
};


#endif //OPENGL_CLION_TEMPLATE_VAO_H
