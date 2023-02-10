#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <opengl/shader.h>
#include <opengl/camera.h>
#include <opengl/utilitiy.h>
#include <iostream>
using namespace opengl;

// 屏幕大小
static int windowWidth = 1000;
static int windowHeight = 800;

float vertices[] = {
    // positions          // normals           // texture coords
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
    0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
    0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
    0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
    0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

    0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
    0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
    0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
    0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
    0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
    0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
    0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
    0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
    0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
    0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
};

glm::vec3 cubePositions[] = {
    glm::vec3( 0.0f,  0.0f,  0.0f),
    glm::vec3( 2.0f,  5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3( 2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f,  3.0f, -7.5f),
    glm::vec3( 1.3f, -2.0f, -2.5f),
    glm::vec3( 1.5f,  2.0f, -2.5f),
    glm::vec3( 1.5f,  0.2f, -1.5f),
    glm::vec3(-1.3f,  1.0f, -1.5f)
};

glm::vec3 pointLightPositions[] = {
    glm::vec3( 0.7f,  0.2f,  2.0f),
    glm::vec3( 2.3f, -3.3f, -4.0f),
    glm::vec3(-4.0f,  2.0f, -12.0f),
    glm::vec3( 0.0f,  0.0f, -3.0f)
};

float deltaTime = 0.0f; // 当前帧与上一帧的时间差
float lastFrame = 0.0f; // 上一帧的时间

// 鼠标信息
float lastX = windowWidth / 2;
float lastY = windowHeight / 2;
bool firstMouse = true;

// 摄像机
Camera camera;

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

int main()
{
    // 初始化 glfw
    glfwInit();
    // 配置 OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
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
    glfwSetFramebufferSizeCallback(window, opengl::frameBufferSizeCallback);
    glfwSetCursorPosCallback(window, opengl::mouseCallback);
    glfwSetScrollCallback(window, opengl::scrollCallback);

    // 初始化 GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }

    // 开启深度测试
    glEnable(GL_DEPTH_TEST);
    // 设置深度测试规则
    glDepthFunc(GL_LESS);
    // 开启模板测试
    glEnable(GL_STENCIL_TEST);
    // 设置模板测试规则
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    // 创建着色器程序
    Shader objectShader("./src/17-stencilTesting/shader/objectMixVs.glsl", "./src/17-stencilTesting/shader/objectMixFs.glsl");
    Shader lightShader("./src/17-stencilTesting/shader/lightVs.glsl", "./src/17-stencilTesting/shader/lightFs.glsl");
    Shader singleColorShader("./src/17-stencilTesting/shader/stenceilVs.glsl", "./src/17-stencilTesting/shader/stenceilFs.glsl");

    // 创建 VAO 与 VBO
    unsigned int objectVAO, objectVBO;
    glGenVertexArrays(1, &objectVAO);
    glGenBuffers(1, &objectVBO);
    glBindVertexArray(objectVAO);
    glBindBuffer(GL_ARRAY_BUFFER, objectVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // 创建光源 VAO
    unsigned int lightVAO, lightVBO;
    glGenVertexArrays(1, &lightVAO);
    glGenBuffers(1, &lightVBO);
    glBindVertexArray(lightVAO);
    glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 创建纹理
    unsigned int texture1 = opengl::loadTextureFromFile("./resources/textures/container2.png");
    unsigned int texture2 = opengl::loadTextureFromFile("./resources/textures/container2_specular.png");

    objectShader.use();
    objectShader.setInt("material.diffuse", 0);
    objectShader.setInt("material.specular", 1);
    objectShader.setFloat("material.shininess", 32.0f);
    // 设置平行光
    objectShader.setVec3("spotlight.ambient",  0.2f, 0.2f, 0.2f);
    objectShader.setVec3("spotlight.diffuse", 0.5f, 0.5f, 0.5f); 
    objectShader.setVec3("spotlight.specular", 1.0f, 1.0f, 1.0f);
    objectShader.setVec3("spotlight.position", lightPos);
    objectShader.setFloat("spotlight.constant",  1.0f);
    objectShader.setFloat("spotlight.linear",    0.09f);
    objectShader.setFloat("spotlight.quadratic", 0.032f);
    objectShader.setFloat("spotlight.cutOff",   glm::cos(glm::radians(12.5f)));
    objectShader.setFloat("spotlight.outCutOff",   glm::cos(glm::radians(17.5f)));
    // 设置点光
    objectShader.setVec3("pointLights[0].ambient",  0.2f, 0.2f, 0.2f);
    objectShader.setVec3("pointLights[0].diffuse", 0.5f, 0.5f, 0.5f); 
    objectShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
    objectShader.setVec3("pointLights[0].position", pointLightPositions[0]);
    objectShader.setFloat("pointLights[0].constant",  1.0f);
    objectShader.setFloat("pointLights[0].linear",    0.09f);
    objectShader.setFloat("pointLights[0].quadratic", 0.032f);

    objectShader.setVec3("pointLights[1].ambient",  0.2f, 0.2f, 0.2f);
    objectShader.setVec3("pointLights[1].diffuse", 0.5f, 0.5f, 0.5f); 
    objectShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
    objectShader.setVec3("pointLights[1].position", pointLightPositions[1]);
    objectShader.setFloat("pointLights[1].constant",  1.0f);
    objectShader.setFloat("pointLights[1].linear",    0.09f);
    objectShader.setFloat("pointLights[1].quadratic", 0.032f);

    objectShader.setVec3("pointLights[2].ambient",  0.2f, 0.2f, 0.2f);
    objectShader.setVec3("pointLights[2].diffuse", 0.5f, 0.5f, 0.5f); 
    objectShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
    objectShader.setVec3("pointLights[2].position", pointLightPositions[2]);
    objectShader.setFloat("pointLights[2].constant",  1.0f);
    objectShader.setFloat("pointLights[2].linear",    0.09f);
    objectShader.setFloat("pointLights[2].quadratic", 0.032f);

    // 平行光
    objectShader.setVec3("lineLight.ambient",  0.2f, 0.2f, 0.2f);
    objectShader.setVec3("lineLight.diffuse", 0.5f, 0.5f, 0.5f); 
    objectShader.setVec3("lineLight.specular", 1.0f, 1.0f, 1.0f);
    objectShader.setVec3("lineLight.direction", -0.2f, -1.0f, -0.3f);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);

    // 渲染循环
    while(!glfwWindowShouldClose(window))
    {
        // 计算时间间隔
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        opengl::processInput(window);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);    

        // view 矩阵
        glm::mat4 view = camera.getViewMatrix();
        // projection 矩阵
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(camera.fov()), (float)windowWidth / (float)windowHeight, 0.1f, 100.0f);

        // 开启光源着色器程序
        glBindVertexArray(lightVAO);
        glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
        glStencilMask(0x00);
        lightShader.use();
        lightShader.setMat4("projection", projection);
        lightShader.setMat4("view", view);

        // 绘制
        for (int i = 0; i < 4; ++i)
        {
            glm::mat4 lightModel = glm::mat4(1.0f);
            lightModel = glm::translate(lightModel, pointLightPositions[i]);
            lightModel = glm::scale(lightModel, glm::vec3(0.3f, 0.3f, 0.3f));
            lightShader.setMat4("model", lightModel);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        // 绘制完成的物体，测试总是通过
        glStencilFunc(GL_ALWAYS, 1, 0xFF);
        glStencilMask(0xFF);

        glBindVertexArray(objectVAO);
        glBindBuffer(GL_ARRAY_BUFFER, objectVBO);

        // 开启物体着色器程序
        objectShader.use();
        objectShader.setVec3("viewPos", camera.position()); 
        objectShader.setMat4("projection", projection);
        objectShader.setMat4("view", view);
        objectShader.setVec3("spotlight.position",  camera.position());
        objectShader.setVec3("spotlight.direction", camera.front());

        for (int i = 0; i < 10; ++i)
        {
            glm::mat4 objectModel = glm::mat4(1.0f);
            objectModel = glm::translate(objectModel, cubePositions[i]);
            float angle = 20.0f * i;
            objectModel = glm::rotate(objectModel, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            objectShader.setMat4("model", objectModel);
            // 绘制 
            glDrawArrays(GL_TRIANGLES, 0, 36);
        } 

        // 绘制边框，进行测试，不为 1 的才能通过，即没有被绘制的部分
        glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
        glStencilMask(0x00);
        glDisable(GL_DEPTH_TEST);

        glBindVertexArray(objectVAO);
        glBindBuffer(GL_ARRAY_BUFFER, objectVBO);

        singleColorShader.use();
        singleColorShader.setMat4("projection", projection);
        singleColorShader.setMat4("view", view);
        float scale = 1.1f;
        for (int i = 0; i < 10; ++i)
        {
            glm::mat4 objectModel = glm::mat4(1.0f);
            objectModel = glm::translate(objectModel, cubePositions[i]);
            float angle = 20.0f * i;
            objectModel = glm::rotate(objectModel, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            objectModel = glm::scale(objectModel, glm::vec3(scale, scale, scale));
            singleColorShader.setMat4("model", objectModel);
            // 绘制 
            glDrawArrays(GL_TRIANGLES, 0, 36);
        } 

        glStencilMask(0xFF);
        glEnable(GL_DEPTH_TEST);

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