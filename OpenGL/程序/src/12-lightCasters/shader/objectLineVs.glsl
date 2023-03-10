#version 330 core

layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 inTexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 normal;
out vec3 fragPos;
out vec2 texCoords;

void main()
{
    fragPos = vec3(model * vec4(inPos, 1.0));
    normal = mat3(model) * inNormal;
    texCoords = inTexCoords;

    gl_Position = projection * view * model * vec4(inPos, 1.0);
}