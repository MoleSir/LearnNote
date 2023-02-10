#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex1Coord;
layout (location = 3) in vec2 aTex2Coord;

out vec3 ourColor;
out vec2 ourTex1Coord;
out vec2 ourTex2Coord;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor;
    ourTex1Coord = aTex1Coord;
    ourTex2Coord = aTex2Coord;
}