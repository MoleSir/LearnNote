#ifndef __UTILITIY_HH__
#define __UTILITIY_HH__

#include <string>
#include <vector>
struct GLFWwindow;

namespace opengl
{
// 初始化 OpenGL 
GLFWwindow* initialOpenGL(int width, int height, const char *title);

// 更新视口大小回调函数
void frameBufferSizeCallback(GLFWwindow* window, int width, int height);

// 键盘输入
void processInput(GLFWwindow* window);

// 鼠标回调
void mouseCallback(GLFWwindow* window, double xpos, double ypos);

// 鼠标滚轮回调
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

// 加载纹理
unsigned int loadTextureFromFile(const char *path, const std::string &directory, bool reverse = true,
                                 unsigned int sAroundWay = 0x2901,
                                 unsigned int tAroundWay = 0x2901,
                                 unsigned int minFilterWay = 0x2601, 
                                 unsigned int maxFilterWay = 0x2601);
unsigned int loadTextureFromFile(const std::string &filename, bool reverse = true,
                                 unsigned int sAroundWay = 0x2901,
                                 unsigned int tAroundWay = 0x2901,
                                 unsigned int minFilterWay = 0x2601, 
                                 unsigned int maxFilterWay = 0x2601);

// 加载立方体贴图
unsigned int loadCubemapFromFiles(const std::vector<std::string>& faces, bool reverse = true);

// 计算两帧时间差
void calFrameDelTime();

}

#endif