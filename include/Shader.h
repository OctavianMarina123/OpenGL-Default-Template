//
// Created by Octa on 1/8/2024.
//

#ifndef OPENGL_CLION_TEMPLATE_SHADER_H
#define OPENGL_CLION_TEMPLATE_SHADER_H

#include"glad/glad.h"
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>
#include "glm/glm.hpp"
class Shader
{
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    void use() const;
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec2(const std::string &name, const glm::vec2 &value) const;
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setVec4(const std::string &name, const glm::vec4 &value) const;
    void setMat2(const std::string &name, const glm::mat2 &mat) const;
    void setMat3(const std::string &name, const glm::mat3 &mat) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;


private:
    void checkCompileErrors(unsigned int shader, std::string type);
};


#endif //OPENGL_CLION_TEMPLATE_SHADER_H
