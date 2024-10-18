#version 330 core
out vec4 FragColor;

float ambientIntesity = 0.5f;

uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{
	vec3 ambient = ambientIntesity * lightColor;

	vec3 result = ambient*objectColor;

	FragColor = vec4((result), 1.0f);
}