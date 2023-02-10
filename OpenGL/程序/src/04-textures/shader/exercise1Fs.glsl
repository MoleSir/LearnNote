#version 330 core

in vec3 ourColor;
in vec2 ourTexCoord; 

out vec4 FragColor;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    vec2 turnTexCoord = vec2(-1.0 * ourTexCoord.x, ourTexCoord.y);
    FragColor = mix(texture(texture1, ourTexCoord), texture(texture2, turnTexCoord), 0.5);
}