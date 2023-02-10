#include "opengl/camera.h"
#include <cmath>
#include <utility>

namespace opengl
{

// 使用向量构造
Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch):
    _position(std::move(position)),
    _fornt(glm::vec3(0.0f, 0.0f, -1.0f)), 
    _up(),
    _right(),
    _worldUp(std::move(up)),
    _yaw(yaw),
    _pitch(pitch),
    _moveSpeed(SPEED), 
    _moveSensitivity(SENSITIVITY), 
    _zoom(ZOOM) 
{
    this->update();
}

// 使用值构造
Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch):
    _position(glm::vec3(posX, posY, posZ)),
    _fornt(glm::vec3(0.0f, 0.0f, -1.0f)), 
    _up(),
    _right(),
    _worldUp(glm::vec3(upX, upY, upZ)),
    _yaw(yaw),
    _pitch(pitch),
    _moveSpeed(SPEED), 
    _moveSensitivity(SENSITIVITY), 
    _zoom(ZOOM)
{
    this->update();
}

// 键盘控制
void Camera::processKeyboard(CameraMovement direction, float deltaTime)
{
    float velocity = this->_moveSpeed * deltaTime;
    if (direction == FORWARD)
        this->_position += this->_fornt * velocity;
    if (direction == BACKWARD)
        this->_position -= this->_fornt * velocity;
    if (direction == LEFT)
        this->_position -= this->_right * velocity;
    if (direction == RIGHT)
        this->_position += this->_right * velocity;
    //this->_position.y = 0.0f;
}

// 鼠标控制
void Camera::processMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
    xoffset *= this->_moveSensitivity;
    yoffset *= this->_moveSensitivity;

    this->_yaw += xoffset;
    this->_pitch += yoffset;

    if (constrainPitch)
    {
        if (this->_pitch > 89.0f)
            this->_pitch  = 89.0f;
        if (this->_pitch  < -89.0f)
            this->_pitch  = -89.0f;
    }

    this->update();
}

// 鼠标滚轮
void Camera::processMouseScroll(float yoffset)
{
    this->_zoom -= (float)yoffset;
    if (this->_zoom < 1.0f)
        this->_zoom = 1.0f;
    if (this->_zoom > 45.0f)
        this->_zoom = 45.0f;
}

// 更新摄像机状态
void Camera::update()
{
    glm::vec3 front;
    front.x = cos(glm::radians(this->_yaw)) * cos(glm::radians(this->_pitch));
    front.y = sin(glm::radians(this->_pitch));
    front.z = sin(glm::radians(this->_yaw)) * cos(glm::radians(this->_pitch));
    this->_fornt = glm::normalize(front);

    this->_right = glm::normalize(glm::cross(this->_fornt, this->_worldUp));
    this->_up = glm::normalize(glm::cross(this->_right, this->_fornt));
}

}