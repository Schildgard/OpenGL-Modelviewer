#include "vao.h"

VAO::VAO(unsigned int& _adress)
{
    adress = _adress;
}

void VAO::Initialize()
{

    glGenVertexArrays(1, &adress);
    glBindVertexArray(adress);

}
