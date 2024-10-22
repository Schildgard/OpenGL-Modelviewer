#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 Normal;
out vec3 FragPosition;
out vec2 TexCoods;

void main()
{
	gl_Position = projection * view * model *vec4(aPos, 1.0f);
	//TRANSFORM FRAGMENT POSITION TO WORLDSPACE BY MULTIPLIYING VERTEX WITH MODEL MATRIX
	FragPosition = vec3(model * vec4(aPos, 1.0f));
	//THIS USES NORMAL ONLY IN LOCAL SPACE, HOWEVER FRAGMENT SHADER CALCULATIONS ARE DONE IN WORLD SPACE
	//Normal = aNormal;
	//TRANSFORM NORMAL DIRECTION TO WORLD SPACE BY USING A NORMAL MATRIX//THIS SHOULD BE AVOIDED OUTSIDE OF PRACTISE PURPOSE SINCE INVERSE TRANSLATION IS VERY
	//INEFFICIENT. IT ADVISED TO DO THIS ON THE CPU AND NOT ON THE GPU
	Normal = mat3(transpose(inverse(model))) * aNormal;
	TexCoods = aTexCoords;
}