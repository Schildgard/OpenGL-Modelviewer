#include "MeshComponent.h"

Mesh::Mesh()
{

}


void Mesh::AddMeshComponent()
{
	//SET VALUES FOR STANDARD MATERIAL STANDARD MATERIAL
	material.size = 3 * size;
	material.textureSize = 2 * size;


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
	glBufferData(GL_ARRAY_BUFFER, 2 * size, material.textureCoods, GL_STATIC_DRAW);
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
	glBufferData(GL_ARRAY_BUFFER, 2 * size, material.textureCoods, GL_STATIC_DRAW);

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

void Mesh::DrawThisObject()
{

	for (int i = 0; i < 16; i++) //hardcoded value of 15 represents the maximum count of texture IDs in the material
	{
		if (material.textureIds[i] != 0)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, material.textureIds[i]);
		}
		else return; //MAYBE REMOVE THIS LATER
	}
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
