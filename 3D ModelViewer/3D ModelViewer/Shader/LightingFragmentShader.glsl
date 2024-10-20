#version 330 core
out vec4 FragColor;
in vec3 Normal;
in vec3 FragPosition;

uniform vec3 objectColor;
uniform vec3 viewPosition;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 
  
uniform Material material;

struct Light {
	//POSITION WHERE THE LIGHT SOURCE COMES FROM
    vec3 position;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light; 





void main()
{

	//AFFECT LIGHTCOLOR BY AMBIENT INTESITY
	vec3 ambient =  light.ambient * material.ambient;

	//NORMALIZE NORMAL AND DIRECTION VECTOR
	vec3 norm = normalize(Normal);
	vec3 lightDirection = normalize(light.position - FragPosition);
	//CALCULATE IMPACT OF LIGHT ON THE FRAGMENT. MAX CLAMPS THE VALUE TO A MINIMUM OF 0.0, SO THE IMPACT DOES NOT GET NEGATIVE
	float impact = max(dot(norm,lightDirection), 0.0f);
	vec3 diffuse = light.diffuse * (impact * material.diffuse);

	//SPECULAR
	//1. get normalized view direction
	vec3 viewDirection = normalize(viewPosition - FragPosition);
	//2.get reflection between light and normal vector
	vec3 reflectDirection = reflect(-lightDirection, norm);
	//3. calculate specular. 32 is the value for shininess. the higher the value the more concentrated the specular gets
	float specValue = pow(max(dot(viewDirection,reflectDirection),0.0f), material.shininess);
	vec3 specular = light.specular * (specValue *material.specular);



	//APPLY
	vec3 result = (ambient+diffuse+specular)*objectColor;
	FragColor = vec4(result, 1.0f);

}