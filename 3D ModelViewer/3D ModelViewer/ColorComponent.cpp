#include "ColorComponent.h"

void Color::AddColorAttributes(unsigned int& _objectID, unsigned int _size, float* _colorArray)
{
	size = _size;
	colorArray = _colorArray;

	glBindVertexArray(_objectID);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, _colorArray, GL_STATIC_DRAW);

	//COLOR ATTRIB
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
}
