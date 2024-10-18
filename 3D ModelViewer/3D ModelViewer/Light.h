#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Material.h"
class Light
{
public:
	unsigned int objectID;

	static Light* currentInstance;
	Material material;

	float* vertices;
	unsigned int* indices;
	unsigned int size;

	Light();
	static void CreateLightSource(unsigned int _objectID, float* _vertices, unsigned int* _indices, unsigned int _size);
	void HandleLightSourceCreation(unsigned int _objectID, float* _vertices, unsigned int* _indices, unsigned int _size);
};

