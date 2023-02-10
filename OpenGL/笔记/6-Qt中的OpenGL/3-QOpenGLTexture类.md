# QOpenGLTexture 类

Qt 对 OpenGL 中的纹理做了封装为 QOPenGLTexture 类



## 创建纹理

直接给 `QOpenGLTexture` 的构造函数传入一个 `QImage`：

```c++
this->_texureWall = new QOpenGLTexture(QImage(":/textures/textures/container.jpg").mirrored());
```

通常这个图形使用项目中的资源中的图片。



## 设置纹理属性

### 设置环绕方式

````c++
void setWrapMode(WrapMode mode);
void setWrapMode(CoordinateDirection direction, WrapMode mode);
````

环绕方式有以下四种：

````c++
enum WrapMode {
    Repeat         = 0x2901, // GL_REPEAT
    MirroredRepeat = 0x8370, // GL_MIRRORED_REPEAT
    ClampToEdge    = 0x812F, // GL_CLAMP_TO_EDGE
    ClampToBorder  = 0x812D  // GL_CLAMP_TO_BORDER
};
````

如果调用第一个只有一个参数的重载版本，设置的环绕方式会应用在纹理所有轴。而调用第二个两个参数的重载版本则可以指定某个轴的环绕方式，有三个方向枚举：

````c++
enum CoordinateDirection {
    DirectionS = 0x2802, // GL_TEXTURE_WRAP_S
    DirectionT = 0x2803, // GL_TEXTURE_WRAP_T
    DirectionR = 0x8072  // GL_TEXTURE_WRAP_R
};
````

### 设置过滤方式

设置缩小过滤方式：

````c++
void setMinificationFilter(Filter filter);
````

设置放大过滤方式：

````c++
void setMagnificationFilter(Filter filter);
````

其中过滤方式有：

````c++
enum Filter {
    Nearest                 = 0x2600,   // GL_NEAREST
    Linear                  = 0x2601,   // GL_LINEAR
    NearestMipMapNearest    = 0x2700,   // GL_NEAREST_MIPMAP_NEAREST
    NearestMipMapLinear     = 0x2702,   // GL_NEAREST_MIPMAP_LINEAR
    LinearMipMapNearest     = 0x2701,   // GL_LINEAR_MIPMAP_NEAREST
    LinearMipMapLinear      = 0x2703    // GL_LINEAR_MIPMAP_LINEAR
}
````



## 绑定纹理单元

调用 `bind` 成员函数绑定纹理单元：

````c++
    void bind();
    void bind(uint unit, TextureUnitReset reset = DontResetTextureUnit);
````

### 无参版本

不传入参数的 `bind` 函数相当于直接调用 `glBindTexture` 将纹理绑定到上下文，具体绑定要哪个纹理单元，要看当前激活的是哪个。

### 有参版本

通常只使用第一个参数，表示要激活几号纹理单元，相当于多执行一步：

````c++
glActiveTexture(GL_TEXTURE0 + unit);
````

再绑定当前纹理，相当于这个纹理对应了 `unit` 号纹理单元。

即：

```c++
glActiveTexture(GL_TEXTURE0 + unit);
texure->bind();
```

相当于：

````c++
texure->bind(unit);
````



