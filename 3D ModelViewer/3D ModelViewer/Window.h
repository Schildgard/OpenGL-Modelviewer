#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window 
{
public:
	//STANDARD CONSTRUCTOR
	Window();

	GLFWwindow* InitializeWindow();

private:
	int width;
	int height;
};
