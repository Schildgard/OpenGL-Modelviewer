#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Camera.h"


class Input
{
public:
	static Input* currentInstance;

	Camera* cam;
	Input();
	Input(Camera* _cam);

	float speed;
	// MOUSE VARIABLES
	bool firstMouse;
	float sensitivity = 0.05f;
	// SET MOUSE POS AT MIDDLE OF THE SCREEN
	float lastXPos = 400.0f;
	float lastYPos = 300.0f;

	double currentXPos;
	double currentYPos;


	void ProcessInput(GLFWwindow* _window, glm::vec3* _camPos, glm::vec3* _camFront, glm::vec3* _camUp, float* _deltaTime);


	static void MouseCallback(GLFWwindow* _window, double _xPos, double _yPos);
	static void ScrollCallback(GLFWwindow* window, double _xOffset, double _yOffset);

	void HandleMouseInput(GLFWwindow* _window, double _xPos, double _yPos);
	void HandleScrollInput(GLFWwindow* _window, double _xOffset, double _yOffset);
};