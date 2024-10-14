#include "ColorComponent.h"

void Color::AddColorAttributes(unsigned int& _objectID, float* _colorValues, unsigned int* _indices)
{
	glBindVertexArray(_objectID);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 4 * 8 * sizeof(float), _colorValues, GL_STATIC_DRAW);

	//COLOR ATTRIB
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	unsigned int ebo;
	//SET ELEMENT BUFFER FOR INDICES
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), _indices, GL_STATIC_DRAW);

}
