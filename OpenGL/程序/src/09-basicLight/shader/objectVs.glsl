#version 330 core

layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 normal;
out vec3 fragPos;

void main()
{
    fragPos = vec3(model * vec4(inPos, 1.0));
    normal = mat3(model) * inNormal;

    gl_Position = projection * view * model * vec4(inPos, 1.0);
}