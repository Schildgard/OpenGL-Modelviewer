#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Frame
{
public:
	//STANDARD CONSTRUCTOR
	Frame();

	GLFWwindow* frame;
	GLFWwindow* InitializeFrame();

	//void Framebuffer_Size_Callback(GLFWwindow* _window, int _width, int _height);

private:
	int width;
	int height;
};
