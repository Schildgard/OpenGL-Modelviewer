#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
class VBO
{
public:
	VBO(unsigned int& _adress, float* _vertexArray, GLsizeiptr _size);
private:

	unsigned int adress;
	float* vertexArray;
	GLsizeiptr size;

	void Initialize();
};
