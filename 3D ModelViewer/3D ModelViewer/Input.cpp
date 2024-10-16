#include "Input.h"


Input::Input()
{

}

Input::Input(Camera* _cam)
{
	cam = _cam;
}

Input* Input::currentInstance = nullptr;

void Input::ProcessInput(GLFWwindow* _window, glm::vec3* _camPos, glm::vec3* _camFront, glm::vec3* _camUp, float* _deltaTime)
{
	speed = 2.5f * (*_deltaTime);
	if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
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
	 if(currentInstance)
	 {
		 currentInstance->HandleMouseInput(_window, _xPos, _yPos);
	 }


}
 void Input::HandleMouseInput(GLFWwindow* _window, double _xPos, double _yPos)
 {
	 if (firstMouse)
	 {
		 lastXPos = _xPos;
		 lastYPos = _yPos;
		 firstMouse = false;
	 }


	 //CALCULATE HOW MUCH THE MOUSE HAS MOVED
	 float xOffset = _xPos - lastXPos;
	 float yOffset = lastYPos - _yPos;
	 // UPDATE LAST POSITION VALUES
	 lastXPos = _xPos;
	 lastYPos = _yPos;

	 // SCALE OFFSET DOWN BY SENSIVITY PARAMETER
	 xOffset *= sensitivity;
	 yOffset *= sensitivity;

	 //SET HORIZONTAL AND VERTICAL POS TO OFFSET
	 cam[0].horizontal += xOffset;
	 cam[0].vertical += yOffset;

	 // CLAMP VERTICAL CAMERA ANGLE
	 if (cam[0].vertical > 89.0f)
	 {
		 cam[0].vertical = 89.0f;
	 }
	 else if (cam[0].vertical < -89.0f)
	 {
		 cam[0].vertical = -89.0f;
	 }

	 //CALCULATE ACTUAL DIRECTION VECTOR
	 glm::vec3 direction;
	 direction.x = cos(glm::radians(cam[0].horizontal)) * cos(glm::radians(cam[0].vertical));
	 direction.y = sin(glm::radians(cam[0].vertical));
	 direction.z = sin(glm::radians(cam[0].horizontal)) * cos(glm::radians(cam[0].vertical));
	 cam[0].forward = glm::normalize(direction);
 }
 
