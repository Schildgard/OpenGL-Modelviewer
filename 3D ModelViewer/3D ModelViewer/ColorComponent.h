#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Color
{
public:
	void AddColorAttributes(unsigned int& _objectID, float* _colorValues, unsigned int* _indices);
};