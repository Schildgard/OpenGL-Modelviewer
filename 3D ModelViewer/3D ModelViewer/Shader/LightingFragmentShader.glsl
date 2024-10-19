#version 330 core
out vec4 FragColor;
in vec3 Normal;
//THE SHADER NEEDS TO KNOW THE VERTEX WORLD POSITION TO CALCULATE IT WITH THE LIGHT DIRECTION
in vec3 FragPosition;

float ambientIntesity = 0.1f;

uniform vec3 objectColor;
uniform vec3 lightColor;
//POSITION WHERE THE LIGHT SOURCE COMES FROM
uniform vec3 lightPosition;

void main()
{
	//AFFECT LIGHTCOLOR BY AMBIENT INTESITY
	vec3 ambient = ambientIntesity * lightColor;
	//NORMALIZE NORMAL AND DIRECTION VECTOR
	vec3 norm = normalize(Normal);
	vec3 lightDirection = normalize(lightPosition - FragPosition);
	//CALCULATE IMPACT OF LIGHT ON THE FRAGMENT. MAX CLAMPS THE VALUE TO A MINIMUM OF 0.0, SO THE IMPACT DOES NOT GET NEGATIVE
	float impact = max(dot(norm,lightDirection), 0.0f);
	vec3 diffuse = impact * lightColor;


	vec3 result = (ambient+diffuse)*objectColor;
	FragColor = vec4(result, 1.0f);

}