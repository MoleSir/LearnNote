#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <opengl/shader.h>
#include <opengl/camera.h>
#include <opengl/mesh.h>
#include <opengl/utilitiy.h>
#include <iostream>
#include <vector>
#include <string>

// 屏幕大小
static int windowWidth = 1000;
static int windowHeight = 800;

std::vector<opengl::Vertex> vertices = {
    // positions          // normals           // texture coords
    opengl::Vertex(-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f),
    opengl::Vertex(0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f),
    opengl::Vertex(0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f),
    opengl::Vertex(0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f),
    opengl::Vertex(-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f),
    opengl::Vertex(-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f),

    opengl::Vertex(-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f),
    opengl::Vertex(0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f),
    opengl::Vertex(0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f),
    opengl::Vertex(0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f),
    opengl::Vertex(-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f),
    opengl::Vertex(-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f),

    opengl::Vertex(-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f),
    opengl::Vertex(-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f),
    opengl::Vertex(-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f),
    opengl::Vertex(-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f),
    opengl::Vertex(-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f),
    opengl::Vertex(-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f),

    opengl::Vertex(0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f),
    opengl::Vertex(0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f),
    opengl::Vertex(0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f),
    opengl::Vertex(0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f),
    opengl::Vertex(0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f),
    opengl::Vertex(0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f),

    opengl::Vertex(-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f),
    opengl::Vertex(0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f),
    opengl::Vertex(0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f),
    opengl::Vertex(0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f),
    opengl::Vertex(-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f),
    opengl::Vertex(-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f),

    opengl::Vertex(-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f),
    opengl::Vertex(0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f),
    opengl::Vertex(0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f),
    opengl::Vertex(0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f),
    opengl::Vertex(-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f),
    opengl::Vertex(-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f),
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
opengl::Camera camera;

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

    glEnable(GL_DEPTH_TEST);

    // 创建着色器程序
    opengl::Shader objectShader("./src/14-mesh/shader/objectMixVs.glsl", "./src/14-mesh/shader/objectMixFs.glsl");
    opengl::Shader lightShader("./src/14-mesh/shader/lightVs.glsl", "./src/14-mesh/shader/lightFs.glsl");

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

    // 创建 Mesh
    std::vector<unsigned int> indices;
    std::vector<opengl::Texture> textures;
    textures.push_back(opengl::Texture(
        opengl::loadTextureFromFile("./resources/textures/container2.png"), 
        "textureDiffuse",
        aiString()));
    textures.push_back(opengl::Texture(
        opengl::loadTextureFromFile("./resources/textures/container2_specular.png"), 
        "textureSpecular",
        aiString()));
    for (unsigned int i = 0; i < 36; ++i)
        indices.push_back(i);
    opengl::Mesh objectMesh(vertices, indices, std::move(textures));
    opengl::Mesh lightMesh(std::move(vertices), std::move(indices), {});

    // 渲染循环
    while(!glfwWindowShouldClose(window))
    {
        // 计算时间间隔
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        opengl::processInput(window);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    

        // view 矩阵
        glm::mat4 view = camera.getViewMatrix();
        // projection 矩阵
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(camera.fov()), (float)windowWidth / (float)windowHeight, 0.1f, 100.0f);

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
            
            objectMesh.draw(objectShader);
        } 
    
        // 开启光源着色器程序
        lightShader.use();
        lightShader.setMat4("projection", projection);
        lightShader.setMat4("view", view);

        for (int i = 0; i < 4; ++i)
        {
            glm::mat4 lightModel = glm::mat4(1.0f);
            lightModel = glm::translate(lightModel, pointLightPositions[i]);
            lightModel = glm::scale(lightModel, glm::vec3(0.3f, 0.3f, 0.3f));
            lightShader.setMat4("model", lightModel);
            
            lightMesh.draw(lightShader);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}