#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Input
{
public:
	GLFWwindow* frame;

	//Camera* cam;
	Input();
	//Input(Camera* _cam);
	float speed;

	// MOUSE VARIABLES
	bool firstMouse;
	float sensitivity = 0.01f;
	// SET MOUSE POS AT MIDDLE OF THE SCREEN
	float lastXPos = 400.0f;
	float lastYPos = 300.0f;

	double currentXPos;
	double currentYPos;


	void ProcessInput(GLFWwindow* _window, glm::vec3* _camPos, glm::vec3* _camFront, glm::vec3* _camUp, float* _deltaTime);


	void MouseCallBack(GLFWwindow* _window, double _xPos, double _yPos);
};