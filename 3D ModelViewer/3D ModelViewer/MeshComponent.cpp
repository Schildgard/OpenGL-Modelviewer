#include "MeshComponent.h"

Mesh::Mesh()
{

}


void Mesh::AddMeshComponent()
{
	//SET VALUES FOR STANDARD MATERIAL STANDARD MATERIAL
	material.size = 3 * size;
	material.texture.size = 2 * size;


	//CREATE AND BIND OBJECT
	glGenVertexArrays(1, &objectID);
	glBindVertexArray(objectID);

	unsigned int vbo;
	unsigned int ebo;

	//CREATE BUFFER AND STORE VERTICES IN IT
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, (vertices), GL_STATIC_DRAW);
	//POSITION ATTRIB
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//NORMAL POSITION ATTRIB
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(3);

	//COLOR ATTRIB
	unsigned int colorBuffer;
	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, (3 * size), material.colorArray, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);



	//SET ELEMENT BUFFER FOR INDICES
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

void Mesh::AddMeshComponent(float* _vertices, unsigned int* _indices, unsigned int _size)
{

	glGenVertexArrays(1, &objectID);
	glBindVertexArray(objectID);


	unsigned int vbo;
	unsigned int ebo;

	//CREATE BUFFER AND STORE VERTICES IN IT
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, (vertices), GL_STATIC_DRAW);


	//POSITION ATTRIB
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//NORMAL POSITION ATTRIB
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(3);


	//COLOR ATTRIB
	unsigned int colorBuffer;
	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, 3 * size, material.colorArray, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);


	//SET ELEMENT BUFFER FOR INDICES
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}


void Mesh::BindTexture(Texture _texture)
{
	material.texture = _texture;
	//TEXTURE ATTRIB
	unsigned int textureBuffer1;
	glGenBuffers(1, &textureBuffer1);
	glBindBuffer(GL_ARRAY_BUFFER, textureBuffer1);
	glBufferData(GL_ARRAY_BUFFER, 2 * size, material.texture.textureCoods, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(2);

	//TEST
	unsigned int freeTextureSlotIndex = FindNextTextureSlot();
	glGenTextures(1, &material.textureIds[freeTextureSlotIndex]);
	glBindTexture(GL_TEXTURE_2D, material.textureIds[freeTextureSlotIndex]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, material.texture.width, material.texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, material.texture.image);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(material.texture.image);

}

void Mesh::BindTextureWithAlpha(Texture _texture)
{
	material.texture = _texture;
	//TEXTURE ATTRIB
	unsigned int textureBuffer2;
	glGenBuffers(1, &textureBuffer2);
	glBindBuffer(GL_ARRAY_BUFFER, textureBuffer2);
	glBufferData(GL_ARRAY_BUFFER, 2 * size, material.texture.textureCoods, GL_STATIC_DRAW);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(2);

	//TEST
	unsigned int freeTextureSlotIndex = FindNextTextureSlot();
	glGenTextures(1, &material.textureIds[freeTextureSlotIndex]);
	glBindTexture(GL_TEXTURE_2D, material.textureIds[freeTextureSlotIndex]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, material.texture.width, material.texture.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, material.texture.image);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(material.texture.image);

}

void Mesh::BindTexture(Texture _texture, bool _freeImage)
{
	material.texture = _texture;
	//TEXTURE ATTRIB
	unsigned int textureBuffer1;
	glGenBuffers(1, &textureBuffer1);
	glBindBuffer(GL_ARRAY_BUFFER, textureBuffer1);
	glBufferData(GL_ARRAY_BUFFER, 2 * size, material.texture.textureCoods, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(2);

	//TEST
	unsigned int freeTextureSlotIndex = FindNextTextureSlot();
	glGenTextures(1, &material.textureIds[freeTextureSlotIndex]);
	glBindTexture(GL_TEXTURE_2D, material.textureIds[freeTextureSlotIndex]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, material.texture.width, material.texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, material.texture.image);
	glGenerateMipmap(GL_TEXTURE_2D);

	if (_freeImage == true)
	{
		stbi_image_free(material.texture.image);

	}

}

void Mesh::BindTextureWithAlpha(Texture _texture, bool _freeImage)
{
	material.texture = _texture;
	//TEXTURE ATTRIB
	unsigned int textureBuffer2;
	glGenBuffers(1, &textureBuffer2);
	glBindBuffer(GL_ARRAY_BUFFER, textureBuffer2);
	glBufferData(GL_ARRAY_BUFFER, 2 * size, material.texture.textureCoods, GL_STATIC_DRAW);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(2);

	//TEST
	unsigned int freeTextureSlotIndex = FindNextTextureSlot();
	glGenTextures(1, &material.textureIds[freeTextureSlotIndex]);
	glBindTexture(GL_TEXTURE_2D, material.textureIds[freeTextureSlotIndex]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, material.texture.width, material.texture.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, material.texture.image);
	glGenerateMipmap(GL_TEXTURE_2D);

	if (_freeImage == true)
	{
	stbi_image_free(material.texture.image);

	}

}









void Mesh::DrawThisObject(glm::vec3 _lightPosition, Camera _SceneCamera)
{

	unsigned int currentProgram;
	//ACTIVATE SHADER
	material.assignedShader->Use();
	glGetIntegerv(GL_CURRENT_PROGRAM, (GLint*)&currentProgram);
	if (currentProgram == material.assignedShader->programID) {
	//	std::cout << "Correct ShaderProgramm" << std::endl;
	}
	else {
		std::cout << "Wrong Shader Program." << std::endl;
	}


	//ASSIGN TEXTURES OF MATERIAL TO OPENGL
	for (int i = 0; i < 16; i++) //hardcoded value of 15 represents the maximum count of texture IDs in the material
	{
		if (material.textureIds[i] != 0)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, material.textureIds[i]);
		}
		else return; //MAYBE REMOVE THIS LATER
	}
	// SET LIGHT AND SCENE CAMERA POSITION
	glUniform3fv(glGetUniformLocation(material.assignedShader->programID, "light.position"), 1, glm::value_ptr(_lightPosition));
	glUniform3fv(glGetUniformLocation(material.assignedShader->programID, "viewPosition"), 1, glm::value_ptr(_SceneCamera.position));

	//SET THE SHADER UNIFORMS TO THE PROPERTIES OF THE OBJECT
	modelLocation = glGetUniformLocation(material.assignedShader->programID, "model");
	viewLocation = glGetUniformLocation(material.assignedShader->programID, "view");
	projectionLocation = glGetUniformLocation(material.assignedShader->programID, "projection");

	Matrix identityMatrix = {};
	identityMatrix.LookAt(viewLocation, _SceneCamera.position, _SceneCamera.forward, _SceneCamera.upward);
	identityMatrix.Zoom(projectionLocation, glm::radians(_SceneCamera.fov), 800.0f / 600.0f, 0.1f, 100.0f);


	glBindVertexArray(objectID);
}

void Mesh::AssignShaderProgram(Shader* _ShaderProgram)
{
	material.assignedShader = _ShaderProgram;
}

unsigned int Mesh::FindNextTextureSlot()
{
	for (int i = 0; i < 16; i++)
	{
		if (material.textureIds[i] == 0)
		{
			return i;
		}
	}

}
