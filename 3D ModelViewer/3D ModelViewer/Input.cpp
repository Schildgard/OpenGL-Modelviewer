#include "Input.h"

Input::Input(glm::vec3* _camPos, glm::vec3* _camFront, glm::vec3* _camUp, float* _deltaTime)
{
	camPosition = _camPos;
	camFront = _camFront;
	camUp = _camUp;
	deltaTime = _deltaTime;

}

void Input::ProcessInput(GLFWwindow* _window)
{
	speed = 2.5f * (*deltaTime);
	if(glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(_window, true);
	}
	 if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS)
	{
		*camPosition += (speed * *camFront);
	}
	 if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS)
	{
		*camPosition -= (speed * *camFront);
	}
	if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS)
	{
		*camPosition -= glm::normalize(glm::cross(*camFront, *camUp)) * speed;

	}
	 if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS)
	{
		*camPosition += glm::normalize(glm::cross(*camFront, *camUp)) * speed;

	}
}

void Input::MouseCallBack(GLFWwindow* _window, double _xPos, double _yPos) {};
