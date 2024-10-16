#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Frame
{
public:
	Frame();
	static Frame* currentInstance;

	GLFWwindow* InitializeFrame();
	GLFWwindow* HandleInitialization();


	static void Framebuffer_Size_Callback(GLFWwindow* _window, int _width, int _height);

private:
	int width;
	int height;
};
