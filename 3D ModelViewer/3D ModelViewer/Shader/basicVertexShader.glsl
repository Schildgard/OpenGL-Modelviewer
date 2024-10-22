#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in vec3 aNormal;

out vec3 ourColor;
out vec3 Normal;
out vec3 FragPosition;
out vec2 texCood;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main()
{
	gl_Position = projection * view * model *vec4(aPos, 1.0f);
	FragPosition = vec3(model*vec4(aPos, 1.0f));

	ourColor = aColor;
	texCood = aTexCoord;

	//THIS USES NORMAL ONLY IN LOCAL SPACE, HOWEVER FRAGMENT SHADER CALCULATIONS ARE DONE IN WORLD SPACE
	//Normal = aNormal;
	//TRANSFORM NORMAL DIRECTION TO WORLD SPACE BY USING A NORMAL MATRIX.//THIS SHOULD BE AVOIDED OUTSIDE OF PRACTISE PURPOSE SINCE INVERSE TRANSLATION IS VERY
	//INEFFICIENT. IT ADVISED TO DO THIS ON THE CPU AND NOT ON THE GPU.
	Normal = mat3(transpose(inverse(model))) * aNormal;
}