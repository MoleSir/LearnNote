#version 330 core
struct Material 
{
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 

struct Light 
{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 normal;
in vec3 fragPos;
in vec2 texCoords;

out vec4 outColor;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    // 用贴图颜色代表
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, texCoords));

    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(light.position - fragPos); 
    float diff = max(dot(norm, lightDir), 0.0);
    // 用贴图颜色代表
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texCoords));

    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // 使用镜面贴图
    vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoords));   

    vec3 result = ambient + diffuse + specular;
    outColor = vec4(result, 1.0);
}