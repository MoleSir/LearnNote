#version 330 core
struct Material 
{
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 

struct PointLight 
{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    // 光照因子
    float constant;
    float linear;
    float quadratic;
};

in vec3 normal;
in vec3 fragPos;
in vec2 texCoords;

out vec4 outColor;

uniform vec3 viewPos;
uniform Material material;
uniform PointLight light;

vec3 calcPointLight(PointLight light, vec3 normal, vec3 viewDir, vec3 fragPos)
{
    // 光照方向
    vec3 lightDir = normalize(light.position - fragPos);
    
    // 计算漫反射系数
    float diffScale = max(dot(lightDir, normal), 0.0);
    // 计算反射系数
    vec3 reflectDir = reflect(-lightDir, normal);
    float specScale = pow(max(dot(reflectDir, viewDir), 0.0), material.shininess);

    // 计算衰减因子
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * distance * distance);

    vec3 color = vec3(texture(material.specular, texCoords));
    // 计算环境光分量
    vec3 ambient = light.ambient * color;
    // 计算漫反射光分量
    vec3 diffuse = light.diffuse * diffScale * color;
    // 计算反射光分量
    vec3 specular = light.specular * specScale * vec3(texture(material.specular, texCoords));

    // 合并分量 * 衰减因子
    return attenuation * (specular + diffuse + ambient);
}

void main()
{
    vec3 norm = normalize(normal);

    vec3 viewDir = normalize(viewPos - fragPos);

    vec3 result = calcPointLight(light, norm, viewDir, fragPos);
    outColor = vec4(result, 1.0);
}