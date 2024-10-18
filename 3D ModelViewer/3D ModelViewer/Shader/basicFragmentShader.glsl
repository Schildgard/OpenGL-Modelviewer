#version 330 core
in vec3 ourColor;
in vec2 texCood;
out vec4 FragColor;

uniform sampler2D ourTexture;
uniform sampler2D texture2;
uniform bool useTexture = true;

uniform vec3 lightColor;
float ambientIntesity = 0.5f;

void main()
{
	vec3 ambient = lightColor * ambientIntesity;
	vec3 result = ambient*ourColor;

	if(useTexture)
	{
	//FragColor = texture(ourTexture,texCood) * ((texture(texture2,texCood) * vec4(ourColor,1.0f)));
	FragColor = texture(ourTexture,texCood) * ((texture(texture2,texCood) * vec4(result,1.0f)));
	}
	else
	{
	FragColor = vec4(ourColor, 1.0f);
	}

}