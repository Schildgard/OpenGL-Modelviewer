#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Color
{
public:

	unsigned int size;
	float* colorArray;

	void AddColorAttributes(unsigned int& _objectID);
	void AddColorAttributes(unsigned int& _objectID, unsigned int _size, float* _colorArray);
};