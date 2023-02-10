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
uniform Light light;

void main()
{
    // 环境
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, texCoords));

    // 漫反射
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(light.position - fragPos); 
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texCoords));

    // 反射
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoords)); 
    
    // 衰减
    float theta = dot(lightDir, normalize(-light.direction));
    float epsilon = light.cutOff - light.outCutOff;
    float intensity = clamp((theta - light.outCutOff) / epsilon, 0.0, 1.0);  
    diffuse *= intensity;
    specular *= intensity;

    // 与光源的距离
    float distance = length(light.position - fragPos);
    // 衰减因子
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * distance * distance);
    
    vec3 result = attenuation * (ambient + diffuse + specular);
    outColor = vec4(result, 1.0);       
}