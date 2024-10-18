#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Material.h"
class Light
{
public:
	static Light* currentInstance;

	unsigned int objectID;
	Material material;

	//VARTEX VALUES
	float* vertices;
	unsigned int* indices;
	unsigned int size;

	Light();
	static void CreateLightSource(unsigned int* _objectID, float* _vertices, unsigned int* _indices, unsigned int _size);
	void HandleLightSourceCreation(unsigned int* _objectID, float* _vertices, unsigned int* _indices, unsigned int _size);


	static void CreateLightSource();
	void HandleLightSourceCreation();
};

