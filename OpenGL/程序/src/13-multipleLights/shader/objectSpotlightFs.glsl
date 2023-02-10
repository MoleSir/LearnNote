#version 330 core
struct Material 
{
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 

struct SpotLight 
{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    // 光照因子
    float constant;
    float linear;
    float quadratic;

    // 手电筒
    vec3  direction;
    float cutOff;
    float outCutOff;
};

in vec3 normal;
in vec3 fragPos;
in vec2 texCoords;

out vec4 outColor;

uniform vec3 viewPos;
uniform Material material;
uniform SpotLight light;

vec3 calcSpotLight(SpotLight light, vec3 normal, vec3 viewDir, vec3 fragPos)
{
    // 漫反射
    vec3 lightDir = normalize(light.position - fragPos);
    float diffScale = max(dot(lightDir, normal), 0.0);
    // 反射系数
    vec3 reflectDir = reflect(-lightDir, normal);
    float specScale = pow(max(dot(reflectDir, viewDir), 0.0), material.shininess);

    vec3 color = vec3(texture(material.diffuse, texCoords));
    // 环境光分量
    vec3 ambient = light.ambient * color;
    // 漫反射分量
    vec3 diffuse = light.diffuse * diffScale * color;
    // 反射光分量
    vec3 specular = light.specular * specScale * vec3(texture(material.specular, texCoords));

    // 范围衰减
    float theta = dot(lightDir, normalize(-light.direction));
    float epsilon = light.cutOff - light.outCutOff;
    float intensity = clamp((theta - light.outCutOff) / epsilon, 0.0, 1.0);
    diffuse *= intensity;
    specular *= intensity;

    return ambient + diffuse + specular;
}

void main()
{
    vec3 norm = normalize(normal);
    vec3 viewDir = normalize(viewPos - fragPos);
    
    vec3 result = calcSpotLight(light, norm, viewDir, fragPos);
    outColor = vec4(result, 1.0);       
}