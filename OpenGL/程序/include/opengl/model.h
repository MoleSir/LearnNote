#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h> 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <opengl/mesh.h>
#include <opengl/shader.h>

#include <string>
#include <vector>

namespace opengl
{

class Model 
{
public:
    // constructor, expects a filepath to a 3D model.
    Model(std::string const &path, bool gamma = false);

    // draws the model, and thus all its meshes
    void draw(Shader &shader);
    
private:
    // loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
    void loadModel(std::string const &path);

    // processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
    void processNode(aiNode *node, const aiScene *scene);

    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

    // checks all material textures of a given type and loads the textures if they're not loaded yet.
    // the required info is returned as a Texture struct.
    std::vector<MeshTexture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);

private:
    // model data 
    std::vector<MeshTexture> _texturesLoaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    std::vector<Mesh>    _meshes;
    std::string _directory;
    bool _gammaCorrection;

public:
    std::vector<Mesh>& meshes()
    { return this->_meshes; }
    
    std::vector<MeshTexture>& texturesLoaded()
    { return this->_texturesLoaded; } 
};

}

#endif