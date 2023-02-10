#version 330 core

layout (location = 0) in vec2 inPos;
layout (location = 1) in vec3 inColor;

out vec3 color;

uniform vec2 offsets[100];

void main()
{
    color = inColor;
    gl_Position = vec4(inPos + offsets[gl_InstanceID], 0.0, 1.0);
}