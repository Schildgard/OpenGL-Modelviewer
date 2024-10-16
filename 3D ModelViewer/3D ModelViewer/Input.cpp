#include "Input.h"

Input::Input()
{

}

void Input::ProcessInput(GLFWwindow* _window, glm::vec3* _camPos, glm::vec3* _camFront, glm::vec3* _camUp, float* _deltaTime)
{
	speed = 2.5f * (*_deltaTime);
	if(glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(_window, true);
	}
	 if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS)
	{
		//*camPosition += (speed * *camFront);
		 *_camPos += (speed * *_camFront);
	}
	 if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS)
	{
		*_camPos -= (speed * *_camFront);
	}
	if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS)
	{
		*_camPos -= glm::normalize(glm::cross(*_camFront, *_camUp)) * speed;

	}
	 if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS)
	{
		*_camPos += glm::normalize(glm::cross(*_camFront, *_camUp)) * speed;

	}
}

void Input::MouseCallBack(GLFWwindow* _window, double _xPos, double _yPos)
{
	//CALCULATE HOW MUCH THE MOUSE HAS MOVED
	float xOffset = _xPos - lastXPos;
	float yOffset = _yPos - lastYPos;
	// UPDATE LAST POSITION VALUES
	lastXPos = currentXPos;
	lastYPos = currentYPos;
	// SCALE OFFSET DOWN BY SENSIVITY PARAMETER
	xOffset *= sensivity;
	yOffset *= sensivity;
};
