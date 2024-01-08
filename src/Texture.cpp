//
// Created by Octa on 1/8/2024.
//

#include "../include/Texture.h"

// Constructorul Texture
Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
{
    type = texType;

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // Inversează textura pe axa Y
    unsigned char* data = stbi_load(image, &width, &height, &nrChannels, 0);

    if (data)
    {
        glGenTextures(1, &ID);
        glActiveTexture(slot);
        glBindTexture(texType, ID);

        glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(texType, 0, format, width, height, 0, format, pixelType, data);
        glGenerateMipmap(texType);
    }
    else
    {
        std::cout << "Eroare la încărcarea texturii: " << image << std::endl;
    }

    stbi_image_free(data);
}

// Metoda texUnit
void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{
    GLuint tex0Uni = glGetUniformLocation(shader.ID, uniform);
    shader.use();
    glUniform1i(tex0Uni, unit);
}

void Texture::Bind()
{
    glBindTexture(type, ID);
}

void Texture::Unbind()
{
    glBindTexture(type, 0);
}

void Texture::Delete()
{
    glDeleteTextures(1, &ID);
}