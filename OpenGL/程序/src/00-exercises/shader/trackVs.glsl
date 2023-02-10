#version 330 core

layout (location = 1) in vec3 inPosition;
layout (location = 0) in vec3 lastPosition

out VS_OUT
{
    vec4 lastPos;
} vs_out;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    vs_out.lastPos = projection * view * vec4(lastPosition, 1.0);
    gl_Position = projection * view * vec4(inPosition, 1.0);
}