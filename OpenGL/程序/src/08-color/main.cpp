#include <stb_image.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <opengl/shader.h>
#include <opengl/camera.h>
#include <iostream>
using namespace opengl;

// 屏幕大小
static int windowWidth = 1000;
static int windowHeight = 800;

float vertices[] = {
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,

    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,

    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
};

float deltaTime = 0.0f; // 当前帧与上一帧的时间差
float lastFrame = 0.0f; // 上一帧的时间

// 鼠标信息
float lastX = windowWidth / 2;
float lastY = windowHeight / 2;
bool firstMouse = true;

// 摄像机
Camera camera;

glm::vec3 lightPos(0.5f, 2.0f, 1.0f);

// 更新视口大小回调函数
static void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// 判断输入为 esc
static void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.processKeyboard(CameraMovement::FORWARD, deltaTime);
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.processKeyboard(CameraMovement::BACKWARD, deltaTime);
    else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.processKeyboard(CameraMovement::LEFT, deltaTime);
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.processKeyboard(CameraMovement::RIGHT, deltaTime);
}

// 鼠标回调
float sensitivity = 0.05f;
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

int main()
{
    // 初始化 glfw
    glfwInit();
    // 配置 OpenGL 版本为 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // 配置 OpenGL 模式为核心模式
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 创建窗口对象
    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create CLFW window\n";
        glfwTerminate();
        return -1;
    }   

    // 选择新建的窗口显示
    glfwMakeContextCurrent(window);
    // 开启鼠标捕捉
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    // 注册回调函数
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
    glfwSetCursorPosCallback(window, mouseCallback);
    glfwSetScrollCallback(window, scrollCallback);

    // 初始化 GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }

    // 创建着色器程序
    Shader objectShader("./src/08-color/shader/vs.glsl", "./src/08-color/shader/objectFs.glsl");
    Shader lightShader("./src/08-color/shader/vs.glsl", "./src/08-color/shader/lightFs.glsl");

    // 创建 VAO 与 VBO
    unsigned int objectVAO, objectVBO;
    glGenVertexArrays(1, &objectVAO);
    glGenBuffers(1, &objectVBO);
    glBindVertexArray(objectVAO);
    glBindBuffer(GL_ARRAY_BUFFER, objectVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 创建光源 VAO
    unsigned int lightVAO, lightVBO;
    glGenVertexArrays(1, &lightVAO);
    glGenBuffers(1, &lightVBO);
    glBindVertexArray(lightVAO);
    glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 创建物体着色器程序
    objectShader.use();
    // 设置颜色向量
    unsigned int objColorLoc = glGetUniformLocation(objectShader.id(), "objectColor");
    unsigned int lightColorLoc = glGetUniformLocation(objectShader.id(), "lightColor");
    glUniform3fv(objColorLoc, 1, glm::value_ptr(glm::vec3(1.0f, 0.5f, 0.31f)));
    glUniform3fv(lightColorLoc, 1, glm::value_ptr(glm::vec3(1.0f, 1.0f, 1.0f)));
    // 变换矩阵位置
    unsigned int objModelLocation = glGetUniformLocation(objectShader.id(), "model");
    unsigned int objViewLocation = glGetUniformLocation(objectShader.id(), "view");
    unsigned int objProjectionLocation = glGetUniformLocation(objectShader.id(), "projection");

    // 颜色着色器程序
    lightShader.use();
    // 变换矩阵位置
    unsigned int lgtModelLocation = glGetUniformLocation(lightShader.id(), "model");
    unsigned int lgtViewLocation = glGetUniformLocation(lightShader.id(), "view");
    unsigned int lgtProjectionLocation = glGetUniformLocation(lightShader.id(), "projection");

    glEnable(GL_DEPTH_TEST);
    // 渲染循环
    while(!glfwWindowShouldClose(window))
    {
        // 计算时间间隔
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    

        // view 矩阵
        glm::mat4 view = camera.getViewMatrix();
        // projection 矩阵
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(camera.fov()), (float)windowWidth / (float)windowHeight, 0.1f, 100.0f);

        // 开启物体着色器程序
        objectShader.use(); 

        // 赋值 view 矩阵
        glUniformMatrix4fv(objViewLocation, 1, GL_FALSE, glm::value_ptr(view));
        // 赋值 projection 矩阵
        glUniformMatrix4fv(objProjectionLocation, 1, GL_FALSE, glm::value_ptr(projection));
        // model 矩阵
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0, 0.0, 0.0));
        glUniformMatrix4fv(objModelLocation, 1, GL_FALSE, glm::value_ptr(model));
 
        // 绘制
        glBindVertexArray(objectVAO);
        glBindBuffer(GL_ARRAY_BUFFER, objectVBO); 
        glDrawArrays(GL_TRIANGLES, 0, 36);
    
        // 开启光源着色器程序
        lightShader.use();   

        // 赋值 view 矩阵
        glUniformMatrix4fv(lgtViewLocation, 1, GL_FALSE, glm::value_ptr(view));
        // 赋值 projection 矩阵
        glUniformMatrix4fv(lgtProjectionLocation, 1, GL_FALSE, glm::value_ptr(projection));
        // model 矩阵
        model = glm::mat4(1.0f);
        model = glm::translate(model, lightPos);
        model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
        glUniformMatrix4fv(lgtModelLocation, 1, GL_FALSE, glm::value_ptr(model));
 
        // 绘制
        glBindVertexArray(lightVAO);
        glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glDeleteVertexArrays(1, &lightVAO);
    glDeleteBuffers(1, &lightVBO);
    glDeleteVertexArrays(1, &objectVAO);
    glDeleteBuffers(1, &objectVBO);

    glfwTerminate();
    return 0;
}