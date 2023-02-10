#version 330 core

in vec3 result;

out vec4 outColor;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
    outColor = vec4(result, 1.0);
}