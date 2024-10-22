#version 330 core
in vec3 ourColor;
in vec2 texCood;
in vec3 FragPosition;
in vec3 Normal;

out vec4 FragColor;

uniform vec3 lightPosition;
uniform vec3 viewPosition;
uniform bool useTexture = true;

uniform vec3 lightColor;



struct Material
{
sampler2D diffuse;
sampler2D specular;
float shininess;
};
uniform Material material;
uniform Material material2;

struct Light
{
vec3 position;
vec3 ambient;
vec3 diffuse;
vec3 specular;
};

uniform Light light;






void main()
{
	//CALCULATE AMBIENT COLOR
	vec3 ambient = light.ambient * (vec3(texture(material.diffuse, texCood)) * vec3(texture(material2.diffuse,texCood))) ;

	//CALCULTE DIFFUSE COLOR
	//1.normalize normal and direction vector
	vec3 norm = normalize(Normal);
	vec3 lightDirection = normalize(light.position - FragPosition);
	//2.calculate diffuse impact on color
	float impact = max(dot(norm, lightDirection),0.0f);
	vec3 diffuse = light.diffuse * (vec3(impact * texture(material.diffuse,texCood))* vec3(texture(material2.diffuse,texCood)));


	//SPECULAR
	//1.get normalized view Direction
	vec3 viewDirection = normalize(viewPosition - FragPosition);
	//2.get reflection Direction
	vec3 reflectDir = reflect(-lightDirection,norm);
	//3.calculate Specular
	float specularValue = pow(max(dot(viewDirection,reflectDir),0.0f), material.shininess);
	vec3 specular = light.specular * vec3(specularValue * (texture(material.specular, texCood)) * texture(material2.specular, texCood));



	vec3 result = (ambient+diffuse+specular);

	if(useTexture)
	{
	FragColor = vec4(result,1.0f);
	}
	else
	{
	FragColor = vec4(ourColor, 1.0f);
	}

}