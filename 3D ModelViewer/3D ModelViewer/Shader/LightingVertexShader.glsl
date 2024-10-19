#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 3) in vec3 aNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 Normal;
out vec3 FragPosition;

void main()
{
	gl_Position = projection * view * model *vec4(aPos, 1.0f);
	//TRANSFORM FRAGMENT POSITION TO WORLDSPACE BY MULTIPLIYING VERTEX WITH MODEL MATRIX
	FragPosition = vec3(model * vec4(aPos, 1.0f));
	Normal = aNormal;
}