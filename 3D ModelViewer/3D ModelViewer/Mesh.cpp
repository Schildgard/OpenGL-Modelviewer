#include "Mesh.h"

Mesh::Mesh()
{

}

void Mesh::AddMeshAttributes(unsigned int& _objectID, float* _vertices, unsigned int* _indices)
{

	glBindVertexArray(_objectID);
	vertices = _vertices;
	indices = _indices;

	unsigned int vbo;
	unsigned int ebo;

	//CREATE BUFFER AND STORE VERTICES IN IT
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 4 * 8 * sizeof(float), (vertices), GL_STATIC_DRAW);


	//POSITION ATTRIB
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);




	//SET ELEMENT BUFFER FOR INDICES
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}
