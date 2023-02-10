#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <opengl/shader.h>
#include <string>
#include <vector>

namespace opengl
{

#define MAX_BONE_INFLUENCE 4

struct Vertex {
    // position
    glm::vec3 position;
    // normal
    glm::vec3 normal;
    // texCoords
    glm::vec2 texCoords;
    // tangent
    glm::vec3 tangent;
    // bitangent
    glm::vec3 bitangent;
	//bone indexes which will influence this vertex
	int boneIDs[MAX_BONE_INFLUENCE];
	//weights from each bone
	float weights[MAX_BONE_INFLUENCE];
};

// 避免名称冲突
struct MeshTexture {
    unsigned int id;
    std::string type;
    std::string path;
};

class Mesh {
public:
    // constructor
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<MeshTexture> textures);

    // destructor
    ~Mesh() noexcept;

    // render the mesh
    void draw(Shader &shader);

private:
    // mesh Data
    std::vector<Vertex>       _vertices;
    std::vector<unsigned int> _indices;
    std::vector<MeshTexture>      _textures;
    unsigned int _VAO, _VBO, _EBO;

    // initializes all the buffer objects/arrays
    void setup();

public:
    unsigned int VAO() const 
    { return this->_VAO; }

    std::vector<unsigned int>& indices()
    { return this->_indices; }
};
}

#endif