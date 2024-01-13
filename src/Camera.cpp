//
// Created by Octa on 1/8/2024.
//

#include "../include/Camera.h"

Camera::Camera(int SCR_WIDTH, int SCR_HEIGHT, glm::vec3 position, glm::vec3 up, float yaw, float pitch)
        : Front(glm::vec3(0.0f, 0.0f, -1.0f)),
          MovementSpeed(2.5f),
          MouseSensitivity(0.1f),
          Fov(45.0f)
{
    this->SCR_WIDTH = SCR_WIDTH;
    this->SCR_HEIGHT = SCR_HEIGHT;
    lastX = SCR_WIDTH / 2.0;
    lastY = SCR_HEIGHT / 2.0;
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(Position, Position + Front, Up);
}

void Camera::ProcessKeyboard(GLFWwindow *window, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        Position += Front * velocity;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        Position -= Front * velocity;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        Position -= Right * velocity;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        Position += Right * velocity;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    if (constrainPitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

    updateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset)
{
    ScrollOffsetY += yoffset;
}

void Camera::updateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up = glm::normalize(glm::cross(Right, Front));
}

void Camera::update(GLFWwindow *window, float deltaTime, Shader &shaderProgram)
{
    // Actualizează FOV-ul bazat pe scroll
    Fov -= ScrollOffsetY;
    if (Fov < 1.0f) Fov = 1.0f;
    if (Fov > 45.0f) Fov = 45.0f;

    // Resetare scroll offset după ajustare
    ScrollOffsetY = 0.0f;

    glm::mat4 view = GetViewMatrix();
    glm::mat4 projection = glm::perspective(glm::radians(Fov), (float) SCR_WIDTH / (float) SCR_HEIGHT, 0.1f, 100.0f);

    shaderProgram.setMat4("view", view);
    shaderProgram.setMat4("projection", projection);

    // Verifică dacă butonul stâng al mouse-ului este apăsat
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        if (firstMouse)
        {
            glfwSetCursorPos(window, SCR_WIDTH / 2.0, SCR_HEIGHT / 2.0);
            lastX = SCR_WIDTH / 2.0;
            lastY = SCR_HEIGHT / 2.0;
            firstMouse = false;
        }

        // Obține poziția curentă a cursorului mouse-ului
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        // Calculează schimbarea de poziție a cursorului mouse-ului
        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos; // Coordonatele y sunt inversate

        lastX = xpos;
        lastY = ypos;

        // Procesează mișcarea mouse-ului
        ProcessMouseMovement(xoffset, yoffset);
    }
    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
    {
        firstMouse = true;
    } //get current mouse position
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    //calculate the change in mouse position
    if(firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    lastX = xpos;
    lastY = ypos;

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // Coordonatele y sunt inversate

    ProcessMouseMovement(xoffset, yoffset);
    ProcessKeyboard(window, deltaTime);


}