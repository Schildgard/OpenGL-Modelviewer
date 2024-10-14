#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Object
{
public:
	unsigned int objectID;

	void CreateObject(unsigned int& _objectID);
};
