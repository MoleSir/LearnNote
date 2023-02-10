# OpenGL

OpenGL 是一个 API(Application Programming Interface，应用程序编程接口)，包含了一些列可以操作图形、图像的函数。然而，OpenGL 本身并不是一个 API，它仅仅是一个由 Khronos 组织制定并维护的规范。

OpenGL 规范严格规定了每个函数该如何执行，以及它们的输出值。至于内部具体每个函数是如何实现(Implement)的，将由 OpenGL 库的开发者自行决定，只要函数实现后满足 OpenGL 规范的规定即可。实际的OpenGL库的开发者通常是显卡的生产商。



## 核心模式与立即渲染模式

早期的 OpenGL 使用立即渲染模式(Immediate mode，固定渲染管线)，这个模式下绘制图形很方便，但效率太低。从OpenGL3.2开始，规范文档废弃立即渲染模式，鼓励开发者在 OpenGL 的核心模式(Core-profile)下进行开发。

当使用 OpenGL 的核心模式时，OpenGL 迫使用户使用现代的函数，现代函数的优势是更高的灵活性和效率，然而也更难于学习。

立即渲染模式从 OpenGL 实际运作中抽象掉了很多细节，因此它在易于学习的同时，也很难让人去把握 OpenGL 具体是如何运作的。现代函数要求使用者真正理解 OpenGL 和图形编程，它有一些难度，然而提供了更多的灵活性，更高的效率，更重要的是可以更深入的理解图形编程。



## 扩展

OpenGL的一大特性就是对扩展(Extension)的支持，当一个显卡公司提出一个新特性或者渲染上的大优化，通常会以扩展的方式在驱动中实现。

使用扩展的代码大多看上去如下：

````c++
if (GL_ARB_extension_name)
{
	// 使用硬件支持的全新现代规范
}
else
{
	// 不支持拓展，使用旧方法
}
````

使用 OpenGL3.3 时，很少需要使用扩展来完成大多数功能。



## 状态机

OpenGL 自身是一个巨大的状态机(State Machine)：一系列的变量描述 OpenGL 此刻应当如何运行（计算机本身就是对内存的状态机）。

OpenGL 的状态通常被称为 OpenGL 上下文(Context)。通常使用如下途径去更改OpenGL状态：设置选项，操作缓冲。最后，使用当前 OpenGL 上下文来渲染。

假设想告诉 OpenGL 去画线段而不是三角形，通过改变一些上下文变量来改变OpenGL 状态，从而告诉 OpenGL 如何去绘图。一旦改变了 OpenGL 的状态为绘制线段，下一个绘制命令就会画出线段而不是三角形。

使用OpenGL的时候，会遇到一些状态设置函数(State-changing Function)，这类函数将会改变上下文。以及状态使用函数(State-using Function)，这类函数会根据当前 OpenGL 的状态执行一些操作。

> 记住OpenGL本质上是个大状态机，就能更容易理解它的大部分特性。



## 对象

OpenGL 库是用C语言写的，同时也支持多种语言的派生，但其内核仍是一个 C 库。

由于 C 的一些语言结构不易被翻译到其它的高级语言，因此 OpenGL 开发的时候引入了一些抽象层。“对象(Object)”就是其中一个。

在 OpenGL 中一个对象是指一些选项的集合，它代表 OpenGL 状态的一个子集。比如，用一个对象来代表绘图窗口的设置，之后就可以设置它的大小、支持的颜色位数等等。可以把对象看做一个 C 风格的结构体(Struct)：

````c
struct object_name {
 	float option1;
    float option2;
    char[] name;
};
````

使用一个对象时，通常看起来像如下一样（把 OpenGL 上下文看作一个大的结构体）：

````c
struct OpenGL_Context {
	...
	object* object_Window_Target;
    ...
};
````

````c
// 创建对象
unsigned int objectId = 0;
glGenObject(1, &objectId);
// 绑定对象到上下文
glBindObject(GL_WINDOW_TARGET, objectId);
// 设置当前绑定到 GL_WINDOW_TARGET 的对象的一些选项
glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_WIDTH, 800);
glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_HEIGHT, 600);
// 将上下文对象设置默认
glBindObject(GL_WINDOW_TARGET, 0);
````

这一小段代码展现了你以后使用OpenGL时常见的工作流：

1. 首先创建一个对象，然后用一个 id 保存它的引用（`objectId` 也许是一个数组的下标？，传入其地址，函数就可以找到一个空闲的数组下标返回给 `objectId`）；
2. 将对象绑定至上下文的目标位置（例子中窗口对象目标的位置被定义成GL_WINDOW_TARGET）；
3. 设置窗口的选项；
4. 将目标位置的对象id设回 0，解绑这个对象（0 地址）。

设置的选项将被保存在 `objectId` 所引用的对象中，一旦重新绑定这个对象到 `GL_WINDOW_TARGET` 位置，这些选项就会重新生效（状态机！）。

使用对象的一个好处是在程序中，不止可以定义一个对象，并设置它们的选项，每个对象都可以是不同的设置。

执行一个使用 OpenGL 状态的操作的时候，只需要绑定含有需要的设置的对象即可。

拥有数个这样的对象允许指定多个模型，在想画其中任何一个的时候，直接将对应的对象绑定上去，便不需要再重复设置选项了。