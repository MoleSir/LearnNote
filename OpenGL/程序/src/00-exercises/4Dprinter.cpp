#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <opengl/shader.h>
#include <opengl/camera.h>
#include <opengl/utilitiy.h>
#include <iostream>
#include <vector>

// 屏幕大小
static int windowWidth = 1000;
static int windowHeight = 800;

float deltaTime = 0.0f; // 当前帧与上一帧的时间差
float lastFrame = 0.0f; // 上一帧的时间

// 鼠标信息
float lastX = windowWidth / 2;
float lastY = windowHeight / 2;
bool firstMouse = true;

// 摄像机
opengl::Camera camera;

float maxCoord = 2.0f;
float minCoord = -1.0f;
float coordVerties[] = {
    // x
    0.0f, 0.0f, maxCoord, 0.0f, 0.0f, minCoord,
    // y
    maxCoord, 0.0f, 0.0f, minCoord, 0.0f, 0.0f,
    // z
    0.0f, maxCoord, 0.0f, 0.0f, minCoord, 0.0f,
};

std::vector<glm::vec3> trackVerties{
    glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f),
};

glm::vec3 position = glm::vec3(1.0f, 1.0f, 1.0f);

void processInput(GLFWwindow* window);
unsigned int trackVAO, trackVBO;

int main()
{
    GLFWwindow* window = opengl::initialOpenGL(windowWidth, windowHeight, "MC!");
    if (window == nullptr)
        return -1;

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    // 着色器
    opengl::Shader coordShader("./src/00-exercises/shader/coordVs.glsl", "./src/00-exercises/shader/coordFs.glsl");
    opengl::Shader trackShader("./src/00-exercises/shader/coordVs.glsl", "./src/00-exercises/shader/trackFs.glsl");

    // 创建坐标对象
    unsigned int coordVAO, coordVBO;
    glGenVertexArrays(1, &coordVAO);
    glGenBuffers(1, &coordVBO);
    glBindVertexArray(coordVAO);
    glBindBuffer(GL_ARRAY_BUFFER, coordVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(coordVerties), coordVerties, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 创建轨迹对象
    //unsigned int trackVAO, trackVBO;
    glGenVertexArrays(1, &trackVAO);
    glGenBuffers(1, &trackVBO);
    glBindVertexArray(trackVAO);
    glBindBuffer(GL_ARRAY_BUFFER, trackVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(trackVerties.data()), trackVerties.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //track.reserve(100);

    // 渲染循环
    while(!glfwWindowShouldClose(window))
    {
        // 计算时间间隔
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   

        glm::mat4 projection = glm::perspective(glm::radians(camera.fov()), (float)windowWidth / (float)windowHeight, 0.1f, 100.0f);
        glm::mat4 view = camera.getViewMatrix();

        // 渲染坐标
        coordShader.use();
        coordShader.setMat4("projection", projection);
        coordShader.setMat4("view", view);
        glBindVertexArray(coordVAO);
        glDrawArrays(GL_LINES, 0, 6);

        // 渲染轨迹
        trackShader.use();
        trackShader.setMat4("projection", projection);
        trackShader.setMat4("view", view);
        glBindVertexArray(trackVAO);
        glDrawArrays(GL_LINES, 0, trackVerties.size());
        std::cout << trackVerties.size() << std::endl;

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}

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
    else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        position.y += deltaTime;
        trackVerties.push_back(trackVerties.back());    
        trackVerties.push_back(position);
        glBindBuffer(GL_ARRAY_BUFFER, trackVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(trackVerties.data()), trackVerties.data(), GL_STATIC_DRAW);
    }
    else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        position.y -= deltaTime;
        trackVerties.push_back(trackVerties.back());    
        trackVerties.push_back(position);
        glBindBuffer(GL_ARRAY_BUFFER, trackVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(trackVerties.data()), trackVerties.data(), GL_STATIC_DRAW);
    }
    else if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
    {
        position.x -= deltaTime;
        trackVerties.push_back(trackVerties.back());    
        trackVerties.push_back(position);
        glBindBuffer(GL_ARRAY_BUFFER, trackVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(trackVerties.data()), trackVerties.data(), GL_STATIC_DRAW);   
    }
    else if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
    {
        
    }
    else if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
    {
        
    }
    else if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
    {
        
    }
}