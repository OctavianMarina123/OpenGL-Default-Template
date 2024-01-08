//
// Created by Octa on 1/8/2024.
//

#ifndef OPENGL_CLION_TEMPLATE_CAMERA_H
#define OPENGL_CLION_TEMPLATE_CAMERA_H

#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"
#include"glm/gtx/rotate_vector.hpp"
#include"glm/gtx/vector_angle.hpp"
#include "Shader.h"

// Camera.h

#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

class Camera
{
public:
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    float ScrollOffsetY = 0.0f;
    float Yaw;
    float Pitch;
    float MovementSpeed;
    float MouseSensitivity;
    float Fov;
    int SCR_WIDTH;
    int SCR_HEIGHT;

    Camera(
            int SCR_WIDTH,
            int SCR_HEIGHT,
            glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
            float yaw = -90.0f,
            float pitch = 0.0f);

    glm::mat4 GetViewMatrix();
    void update(GLFWwindow *window, float deltaTime, Shader &shaderProgram);

    void ProcessKeyboard(GLFWwindow* window, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
    void ProcessMouseScroll(float yoffset);

private:
    bool firstMouse = true;
    double lastX;
    double lastY;
    void updateCameraVectors();
};

#endif


#endif //OPENGL_CLION_TEMPLATE_CAMERA_H
