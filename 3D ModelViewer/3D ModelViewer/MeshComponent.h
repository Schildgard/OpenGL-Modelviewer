#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Material.h"

class Mesh
{
public:
	unsigned int objectID;

	//VBO
	float* vertices;
	unsigned int* indices;
	unsigned int size;

	Material material;

	Mesh();
	void AddMeshComponent();
	void AddMeshComponent(float* _vertices, unsigned int* _indices, unsigned int _size);
	//TEXTURE FUNCTIONS
	void BindTexture(unsigned char* _data);
	void BindTextureWithAlpha(unsigned char* _data);
};
