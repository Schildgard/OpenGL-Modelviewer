#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Matrix
{
public:
	glm::mat4 values;
	Matrix();

	void Rotate(unsigned int& _uniformAdress, float _rotationValue, glm::vec3 _axis);
	void Translate(unsigned int& _uniformAdress, glm::vec3 _movementVector);
};
