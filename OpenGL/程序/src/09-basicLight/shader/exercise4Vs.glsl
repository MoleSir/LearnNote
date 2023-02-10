#version 330 core

layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 objectColor;

out vec3 result;

void main()
{
    vec3 fragPos = vec3(model * vec4(inPos, 1.0));
    vec3 normal = mat3(model) * inNormal;

    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - fragPos); 

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;   

    result = (ambient + diffuse + specular) * objectColor;

    gl_Position = projection * view * model * vec4(inPos, 1.0);
}