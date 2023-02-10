#version 330 core

in vec3 normal;
in vec3 fragPos;

out vec4 outColor;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform mat4 view;

void main()
{
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // 转为观察空间
    vec3 viewlightPos = vec3(view * vec4(lightPos, 1.0));
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(viewlightPos - fragPos); 

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // 观察空间 viewPos 为原点
    float specularStrength = 0.5;
    vec3 viewDir = normalize(-fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;   

    vec3 result = (ambient + diffuse + specular) * objectColor;
    outColor = vec4(result, 1.0);
}