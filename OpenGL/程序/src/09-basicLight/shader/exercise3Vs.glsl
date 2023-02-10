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
    // 传入 片段着色器 的是观察空间坐标
    fragPos = vec3(view * model * vec4(inPos, 1.0));
    normal = mat3(view * model) * inNormal;

    gl_Position = projection * view * model * vec4(inPos, 1.0);
}