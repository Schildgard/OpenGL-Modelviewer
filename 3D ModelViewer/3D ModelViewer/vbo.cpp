#include "vbo.h"


VBO::VBO(unsigned int& _adress, float* _vertexArray, GLsizeiptr _size)
{
    adress = _adress;
    vertexArray = _vertexArray;
    size = _size;
}



void VBO::Initialize()
{
    glGenBuffers(1, &adress);
    glBindBuffer(GL_ARRAY_BUFFER, adress);
    //FILL VBO WITH VERTICES ARRAY (glBufferData fills the currently bound buffer!)
    glBufferData(GL_ARRAY_BUFFER, size, vertexArray, GL_STATIC_DRAW);
   
}
