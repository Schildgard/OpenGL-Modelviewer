#include "Frame.h"


Frame::Frame()
{
	width = 800;
	height = 600;
}

Frame* Frame::currentInstance = nullptr;


GLFWwindow* Frame::InitializeFrame()
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
		//SPECIFIZE TO USE GLFW VERSION 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		//SPECIFY TO USE GLFW CORE PROFILE AND NOT IMMEDIATE
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		return window;
	}
}

void Frame::Framebuffer_Size_Callback(GLFWwindow* _window, int _width, int _height)
{
		glViewport(0, 0, _width, _height);
}



