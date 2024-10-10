#include "Main.h"



int main()
{
	//GLFW SET UP
	glfwInit();
	//SPECIFIZE TO USE GLFW VERSION 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//SPECIFY TO USE GLFW CORE PROFILE AND NOT IMMEDIATE
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);




	//CREATE WINDOW
	Window window = {};
	GLFWwindow* glfWindow = window.InitializeWindow();
	glfwMakeContextCurrent(glfWindow);


	//CHECK IF GLAD CAN LOAD FUNCTION POINTERS
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD INITIALIZATION FAILED!\n";
		return -1;
	}

	//SIZE OF RENDERING WINDOW. ARGUMENT 1&2: lower left corner, 1&3 width and height
	//glViewport(0, 0, 800, 600);




	return 0;
}