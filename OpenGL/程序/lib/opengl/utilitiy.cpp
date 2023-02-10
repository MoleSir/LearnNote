#include "opengl/utilitiy.h"
#include <stb_image.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <opengl/camera.h>
#include <iostream>
#include <string>
#include <vector>

extern opengl::Camera camera;

float deltaTime = 0.0f; // 当前帧与上一帧的时间差
float lastFrame = 0.0f; // 上一帧的时间
float lastX = 400;
float lastY = 300;
bool firstMouse = true;

namespace opengl
{
GLFWwindow* initialOpenGL(int width, int height, const char *title)
{
    // 初始化 glfw
    glfwInit();
    // 配置 OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 创建窗口对象
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create CLFW window\n";
        glfwTerminate();
        return nullptr;
    }   

    // 选择新建的窗口显示
    glfwMakeContextCurrent(window);
    // 开启鼠标捕捉
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    // 注册回调函数
    glfwSetFramebufferSizeCallback(window, opengl::frameBufferSizeCallback);
    glfwSetCursorPosCallback(window, opengl::mouseCallback);
    glfwSetScrollCallback(window, opengl::scrollCallback);

    // 初始化 GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return nullptr;
    }
    return window;
}

// 更新视口大小回调函数
void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// 判断输入为 esc
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.processKeyboard(opengl::CameraMovement::FORWARD, deltaTime);
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.processKeyboard(opengl::CameraMovement::BACKWARD, deltaTime);
    else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.processKeyboard(opengl::CameraMovement::LEFT, deltaTime);
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.processKeyboard(opengl::CameraMovement::RIGHT, deltaTime);
}

// 鼠标回调
void mouseCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    // 计算位置差
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    camera.processMouseMovement(xoffset, yoffset);
}

// 鼠标滚轮回调
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.processMouseScroll(yoffset);
}

// 加载纹理
unsigned int loadTextureFromFile(const char *path, const std::string &directory, bool reverse, 
                                 unsigned int sAroundWay,
                                 unsigned int tAroundWay,
                                 unsigned int minFilterWay, 
                                 unsigned int maxFilterWay)
{
    std::string filename = std::string(path);
    filename = directory + '/' + filename;

    return loadTextureFromFile(filename, reverse, sAroundWay, tAroundWay, minFilterWay, maxFilterWay);
}

unsigned int loadTextureFromFile(const std::string &filename, bool reverse,
                                 unsigned int sAroundWay,
                                 unsigned int tAroundWay,
                                 unsigned int minFilterWay, 
                                 unsigned int maxFilterWay)
{
    stbi_set_flip_vertically_on_load(reverse);
    
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, sAroundWay);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, tAroundWay);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilterWay);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, maxFilterWay);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at file: " << filename << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

// 加载天空盒
unsigned int loadCubemapFromFiles(const std::vector<std::string>& faces, bool reverse)
{
    stbi_set_flip_vertically_on_load(reverse);

    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    int width, height, nrChannels;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 
                         0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
            );
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}

// 计算两帧时间差
void calFrameDelTime()
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

}