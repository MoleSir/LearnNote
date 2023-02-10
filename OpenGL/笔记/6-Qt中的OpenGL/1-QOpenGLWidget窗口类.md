# QOpenGLWidget 窗口类

Qt 中封装好了 OpenGL 窗口，不需要下载 OpenGL 库，并且很多代码都不需要自己写。

QOpenGLWidget 就相当于 GLFW 库中创建的 GLFWwindow 窗口对象，本身就可以现实出一个黑色的窗口。

使用的时候跟 Qt 其他窗口类一样，需要定义一个新的 class 来继承 QOpenGLWidget，对其进行补充。特别注意，除了继承 QOpenGLWidget，还需要继承 QOpenGLFunctions_x_x_Core 类，其中两个 x 表示 OpenGL 版本号，比如 OpenGL 3.3：QOpenGLFunctions_3_3_Core。

QOpenGLWidget 中定义了三个重要的虚函数：

````c++
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
````

分别对应三个重要的功能：

- `initializeGL`：初始化 OpenGL，此函数会在创建一个 QOpenGLWidget 对象时自动调用（也许是在其构造函数中调用？）;
- `resizeGL`：调整视口大小回调函数；
- `paintGL`：渲染函数。



## `initalizeGL` 函数

在这个函数中，首先需要调用 `initializeOpenGLFunctions()` 函数，类似配置 GLAD 的作用。

这个函数中通常进行 VAO、VBO 对象的创建、着色器的创建。即执行在渲染循环之前的内容。



## `resizeGL` 函数

每当 QOpenGLWidget 窗口大小被调整，自动调用这个函数，填入参数 `w` 与 `h` 表示新窗口的宽、长。



## `paintGL` 函数

这个函数相当于一次渲染循环，Qt 会不断调用这个函数进行渲染。

如果需要从 `paintGL` 函数之外的位置触发重新绘制（比如使用计时器设置场景动画），则应该调用 `update` 函数来安排更新。

> 调用 QOpenGLWidget 成员函数 `update()` 通知 OpenGL 重新执行渲染循环

类似调用 `paintGL()`、`resizeGL()`、`initializeGL()` 时，Qt 会自动先调用 `QOpenGLWdiget` 成员函数 `makeCurrent()` 将 OpenGL 呈现上下文将变成当前，调用完毕还需要调用 `doneCurrent()` 。

> 如果需要从其他位置调用标准 OpenGL API 函数，则需要手动调用 `makeCurrent()` 与 `doneCurrent()`



## 总结

在 Qt 中使用 OpenGL 可以省略很多细节。主要流程：

1. 新建一个窗口类，继承 QOpenGLWidget 与 QOpenGLFunctions_x_x_Core；
2. 在 QOpenGLWidget 的虚函数 `initalizeGL` 首先调用 `initializeOpenGLFunctions` 函数，配置 OpenGL 函数指针；
3. 实现两个虚函数（`resizeGL` 倒不是必要的），创建对象、渲染循环。

省略了创建 GLFWwindow 窗口对象的过程。

在 0-HelloWidget 中使用 QOpenGLWidget 绘制了一个简单的矩形，并且使用 Qt 的控件做控制。