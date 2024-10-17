#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Material.h"

class Mesh
{
public:

	Material material;
	//VAO
	unsigned int objectID;
	//VBO
	float* vertices;
	unsigned int* indices;
	unsigned int size;

	Mesh();
	void AddMeshComponent();
	void AddMeshComponent(float* _vertices, unsigned int* _indices, unsigned int _size);


	void BindTexture(unsigned int& _objectID, unsigned char* _data, unsigned int& _textureID);
	void BindTextureWithAlpha(unsigned int& _objectID, unsigned char* _data, unsigned int& _textureID);
};
