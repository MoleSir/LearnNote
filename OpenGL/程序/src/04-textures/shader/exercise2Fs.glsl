#version 330 core

in vec3 ourColor;
in vec2 ourTex1Coord;
in vec2 ourTex2Coord;

out vec4 FragColor;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform sampler2D ourTexture;

void main()
{
    FragColor = mix(texture(texture1, ourTex1Coord), texture(texture2, ourTex2Coord), 0.3);
}