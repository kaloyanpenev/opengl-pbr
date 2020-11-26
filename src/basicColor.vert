#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;

uniform mat4 u_Projection;
uniform mat4 u_Model;
uniform mat4 u_View;

out vec2 v_TexCoords;
out vec3 v_Normal;
out vec3 v_FragPos;

void main()
{
    v_TexCoords = aTexCoords;    
    gl_Position = u_Projection * u_View * u_Model * vec4(aPos, 1.0);
}