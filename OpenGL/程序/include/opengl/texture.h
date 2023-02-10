#ifndef __OPENGL_TEXTURE_HH__
#define __OPENGL_TEXTURE_HH__

#include <string>

namespace opengl
{
class Texture
{
public:
    Texture() = default;
    
    Texture(const std::string &filename, bool reverse,
                                 unsigned int sAroundWay,
                                 unsigned int tAroundWay,
                                 unsigned int minFilterWay, 
                                 unsigned int maxFilterWay);

    Texture(unsigned int index, unsigned int id);

    Texture(const Texture&) = default;

    ~Texture() noexcept;

    // 激活 _texIndex 纹理，并且绑定 texObject
    void bind(); 

private:
    unsigned int _texIndex;     // 纹理对象在整个系统坐标，TEXURE0、TEXURE1..
    unsigned int _texObject;    // 纹理对象，glGen 函数返回的值

public:
    unsigned int index() const
    { return this->_texIndex; }

    unsigned int id() const
    { return this->_texObject; }

    void setIndex(unsigned int index) 
    { this->_texIndex = index; }
};
}

#endif