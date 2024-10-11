#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VAO
{
public:
	VAO(unsigned int& _adress);
private:

	unsigned int adress;
	void Initialize();
};
