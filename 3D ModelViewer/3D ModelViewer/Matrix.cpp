#include "Matrix.h"

Matrix::Matrix()
{
	valuePtr = &values;
	values = glm::mat4(1.0f);
}

void Matrix::Rotate(unsigned int* _uniformAdress, float _rotationValue, glm::vec3 _axis)
{
	glm::rotate(*valuePtr, _rotationValue, _axis);
	glUniformMatrix4fv(*_uniformAdress, 1, GL_FALSE, glm::value_ptr(*valuePtr));
	values = glm::mat4(1.0f);
}

void Matrix::Translate(unsigned int& _uniformAdress, glm::vec3 _movementVector)
{
	glm::translate(values, _movementVector);
	glUniformMatrix4fv(_uniformAdress, 1, GL_FALSE, glm::value_ptr(values));
	values = glm::mat4(1.0f);
}
