#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

class Camera
{
public:
	Camera() {};
	// DEFAULT CAMERA SETTINGS
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 forward = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 upward = glm::vec3(0.0f, 1.0f, 0.0f);
	float horizontal = -90.0f; // horizontal 0.0f points to the positive x axis, so -90f points towards negative z axis which is our forward direction
	float vertical = 0.0f;
	float fov = 45.0f;
};



