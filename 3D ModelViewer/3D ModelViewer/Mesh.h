#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Mesh
{
public:

	float* vertices;
	unsigned int* indices;

	Mesh();

	void AddMeshAttributes(unsigned int& _objectID, float* _vertices, unsigned int* _indices);
};
