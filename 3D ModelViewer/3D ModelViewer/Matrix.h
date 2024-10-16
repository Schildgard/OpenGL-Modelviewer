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
	void LookAt(unsigned int& _uniformAdress, glm::vec3 _position, glm::vec3 _target, glm::vec3 _worldUp);
	void Zoom(unsigned int& _unfiromAdress, float _distance, float _widthDivheight, float _minDistance, float _maxDistance);
};
