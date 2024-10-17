#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Material
{ 
public:
	Material();
	unsigned int size;
	float* colorArray;

	void AddColorAttributes(unsigned int& _objectID);
};
