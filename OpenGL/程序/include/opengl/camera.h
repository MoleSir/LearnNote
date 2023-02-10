#ifndef __CAMERA_HH__
#define __CAMERA_HH__

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace opengl
{

// 摄像机移动方向
enum CameraMovement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// 摄像机常量
const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;


// 摄像机类
class Camera
{
public:
    // 使用向量构造
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);

    // 使用值构造
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

    // 返回 lookAd 矩阵
    glm::mat4 getViewMatrix() const
    { return glm::lookAt(this->_position, this->_position + this->_fornt, this->_up); }

    // 键盘控制
    void processKeyboard(CameraMovement direction, float deltaTime);

    // 鼠标控制
    void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

    // 鼠标滚轮
    void processMouseScroll(float yoffset);

private:
    // 更新摄像机状态
    void update();

private:
    // 摄像机属性
    glm::vec3 _position;
    glm::vec3 _fornt;
    glm::vec3 _up;
    glm::vec3 _right;
    glm::vec3 _worldUp;
    // 角度
    float _yaw;
    float _pitch;
    // 摄像机选项
    float _moveSpeed;
    float _moveSensitivity;
    float _zoom;

public:
    // 属性
    float fov() const
    { return this->_zoom; }

    glm::vec3& position()
    { return this->_position; }

    glm::vec3& front()
    { return this->_fornt; } 
};

}

#endif