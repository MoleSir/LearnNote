#version 330 core
struct Material 
{
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 

struct LineLight 
{
    vec3 direction;

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
uniform LineLight light;

vec3 calcLineLight(LineLight light, vec3 normal, vec3 viewDir)
{
    // 光照方向
    vec3 lightDir = normalize(-light.direction);
    // 漫反射系数
    float diffScale = max(dot(lightDir, normal), 0.0);
    // 反射系数
    vec3 reflectDir = reflect(-lightDir, normal);
    float specScale = pow(max(dot(reflectDir, viewDir), 0.0), material.shininess);  
    
    // 颜色
    vec3 color = vec3(texture(material.diffuse, texCoords));
    // 环境光分量
    vec3 ambient = light.ambient * color;
    // 漫反射分量
    vec3 diffuse = light.diffuse * diffScale * color;
    // 反射分量
    vec3 specular = light.specular * specScale * vec3(texture(material.specular, texCoords));

    // 合并三种分量
    return ambient + diffuse + specular;
}

void main()
{
    vec3 norm = normalize(normal);
    vec3 viewDir = normalize(viewPos - fragPos); 

    vec3 result = calcLineLight(light, norm, viewDir);
    
    outColor = vec4(result, 1.0);
}