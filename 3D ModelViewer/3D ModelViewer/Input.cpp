#include "Input.h"

void Input::ProcessInput(GLFWwindow* _window)
{
	if(glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(_window, true);
	}
}
