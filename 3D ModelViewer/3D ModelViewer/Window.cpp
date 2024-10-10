#include "Window.h"


Window::Window()
{
	width = 800;
	height = 600;
}


GLFWwindow* Window::InitializeWindow()
{
	GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Window creation failed miserably!\n";
		return nullptr;
	}
	else
	{
		std::cout << "Window creation sucessfull!\n";
		return window;
	}
}


