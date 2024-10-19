#version 330 core
in vec3 ourColor;
in vec2 texCood;
in vec3 FragPosition;
in vec3 Normal;

out vec4 FragColor;

uniform sampler2D ourTexture;
uniform sampler2D texture2;
uniform vec3 lightPosition;
uniform vec3 viewPosition;
uniform bool useTexture = true;

uniform vec3 lightColor;
float ambientIntesity = 0.1f;
float specularStrength = 0.5f;

void main()
{
	//CALCULATE AMBIENT COLOR
	vec3 ambient = lightColor * ambientIntesity;

	//CALCULTE DIFFUSE COLOR
	//1.normalize normal and direction vector
	vec3 norm = normalize(Normal);
	vec3 lightDirection = normalize(lightPosition - FragPosition);
	//2.calculate diffuse impact on color
	float impact = max(dot(norm, lightDirection),0.0f);
	vec3 diffuse = impact * lightColor;


	//SPECULAR
	//1.get normalized view Direction
	vec3 viewDirection = normalize(viewPosition - FragPosition);
	//2.get reflection Direction
	vec3 reflectDir = reflect(-lightDirection,norm);
	//3.calculate Specular
	float specularValue = pow(max(dot(viewDirection,reflectDir),0.0f), 32);
	vec3 specular = specularStrength * specularValue * lightColor;



	vec3 result = (ambient+diffuse+specular)*lightColor;

	if(useTexture)
	{
	FragColor = texture(ourTexture,texCood) * ((texture(texture2,texCood) * vec4(result,1.0f)));
	}
	else
	{
	FragColor = vec4(ourColor, 1.0f);
	}

}