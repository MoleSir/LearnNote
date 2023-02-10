#include <mc/application.h>

int main()
{
    // 创建窗口
    mc::Application* app = mc::Application::instance();
    // 初始化资源
    app->init();
    // 渲染循环
    app->exec();
    return 0;
}
