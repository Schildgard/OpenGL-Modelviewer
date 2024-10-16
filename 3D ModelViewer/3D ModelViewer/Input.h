#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Input
{
public:
	Input(glm::vec3* _camPos, glm::vec3* _camFront, glm::vec3* _camUp, float* _deltaTime);
	glm::vec3* camPosition;
	glm::vec3* camFront;
	glm::vec3* camUp;
	float* deltaTime;
	float speed;

	double xPos;
	double yPos;

	void ProcessInput(GLFWwindow* _window);

	void MouseCallBack(GLFWwindow* _window, double _xPos, double _yPos);

};