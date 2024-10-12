#version 330 core
in vec3 ourColor;
in vec2 texCood;
out vec4 FragColor;

uniform sampler2D ourTexture;
uniform sampler2D texture2;

void main()
{
	//FragColor = vec4(ourColor, 1.0f);
	//FragColor = texture(ourTexture,texCood) *vec4(ourColor, 1.0f);

	FragColor = mix(texture(ourTexture,texCood), texture(texture2,texCood), 0.2f);
}