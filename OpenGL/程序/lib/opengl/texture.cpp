#include <opengl/texture.h>
#include <opengl/utilitiy.h>
#include <glad/glad.h>
#include <iostream>

namespace opengl
{
Texture::Texture(const std::string &filename, bool reverse,
                                 unsigned int sAroundWay,
                                 unsigned int tAroundWay,
                                 unsigned int minFilterWay, 
                                 unsigned int maxFilterWay) :
    _texIndex(0), _texObject(loadTextureFromFile(filename, reverse, sAroundWay, tAroundWay, minFilterWay, maxFilterWay))
{}

Texture::Texture(unsigned int index, unsigned int id):
    _texIndex(index), _texObject(id) {}

Texture::~Texture() noexcept 
{}

// 激活 _texIndex 纹理，并且绑定 texObject
void Texture::bind()
{
    std::cout << "active texture: " << this->_texIndex << ", bind texture" << this->_texObject << std::endl;
    glActiveTexture(GL_TEXTURE0 + this->_texIndex);
    glBindTexture(GL_TEXTURE_2D, this->_texObject);
}

}