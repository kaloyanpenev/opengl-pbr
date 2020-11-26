#version 330 core
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;    
    float shininess;
}; 

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 v_FragPos;  
in vec3 v_Normal;  
in vec2 v_TexCoord;
  
uniform vec3 viewPosition;
uniform Material material;
uniform Light light;

void main()
{
    // ambient
    vec3 ambient = light.ambient * texture(material.diffuse, v_TexCoord).rgb;
  	
    // diffuse 
    vec3 norm = normalize(v_Normal);
    vec3 lightDir = normalize(light.position - v_FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, v_TexCoord).rgb;  
    
    // specular
    vec3 viewDir = normalize(viewPosition - v_FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * texture(material.specular, v_TexCoord).rgb;  
        
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
} 