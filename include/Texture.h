//
// Created by Octa on 1/8/2024.
//

#ifndef OPENGL_CLION_TEMPLATE_TEXTURE_H
#define OPENGL_CLION_TEMPLATE_TEXTURE_H
#include "stb_image.h"
#include"glad/glad.h"
#include "Shader.h"

class Texture
{
public:
    GLuint ID;
    GLenum type;
    Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

    // Assigns a texture unit to a texture
    void texUnit(Shader& shader, const char* uniform, GLuint unit);
    // Binds a texture
    void Bind();
    // Unbinds a texture
    void Unbind();
    // Deletes a texture
    void Delete();
};

#endif //OPENGL_CLION_TEMPLATE_TEXTURE_H
