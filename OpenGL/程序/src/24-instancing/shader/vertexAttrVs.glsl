#version 330 core

layout (location = 0) in vec2 inPos;
layout (location = 1) in vec3 inColor;
layout (location = 2) in vec2 offset;

out vec3 color;

void main()
{
    color = inColor;
    gl_Position = vec4(inPos + offset, 0.0, 1.0);
}