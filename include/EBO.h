//
// Created by Octa on 1/8/2024.
//

#ifndef OPENGL_CLION_TEMPLATE_EBO_H
#define OPENGL_CLION_TEMPLATE_EBO_H
#include"glad/glad.h"

class EBO
{
public:
    // ID reference of Elements Buffer Object
    GLuint ID;
    // Constructor that generates a Elements Buffer Object and links it to indices
    EBO(GLuint* indices, GLsizeiptr size);

    // Binds the EBO
    void Bind();
    // Unbinds the EBO
    void Unbind();
    // Deletes the EBO
    void Delete();
};

#endif //OPENGL_CLION_TEMPLATE_EBO_H
