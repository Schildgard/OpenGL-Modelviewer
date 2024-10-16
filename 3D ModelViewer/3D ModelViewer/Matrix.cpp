#include "Matrix.h"

Matrix::Matrix()
{
	values = glm::mat4(1.0f);
}

void Matrix::Rotate(unsigned int& _uniformAdress, float _rotationValue, glm::vec3 _axis)
{
	values = glm::rotate(values, _rotationValue, _axis);
	glUniformMatrix4fv(_uniformAdress, 1, GL_FALSE, glm::value_ptr(values));
	values = glm::mat4(1.0f);
}

void Matrix::Translate(unsigned int& _uniformAdress, glm::vec3 _movementVector)
{
	values = glm::translate(values, _movementVector);
	glUniformMatrix4fv(_uniformAdress, 1, GL_FALSE, glm::value_ptr(values));
	values = glm::mat4(1.0f);
}

void Matrix::LookAt(unsigned int& _uniformAdress, glm::vec3 _position, glm::vec3 _target, glm::vec3 _worldUp)
{
	values = glm::lookAt(_position, _position + _target, _worldUp);
	glUniformMatrix4fv(_uniformAdress, 1, GL_FALSE, glm::value_ptr(values));
	values = glm::mat4(1.0f);
}


