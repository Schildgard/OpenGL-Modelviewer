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


// Default camera values
const float yaw = -90.0f;
const float pitch = 0.0f;
const float speed = 2.5f;
const float sensivity = 0.1f;
const float zoom = 45.0f;


class Camera
{
public:

	Camera() {};
	// CAMERA ATTRIBUTES
	glm::vec3 camPos;
	glm::vec3 camForward;
	glm::vec3 camUp;
	glm::vec3 camRight;
	glm::vec3 worldUp;

	//EULER ANGLES
	float horizontal;
	float vertical;

	//CAMERA OPTIONS
	float movementSpeed;
	float mouseSensivity;
	float camZoom;


};



