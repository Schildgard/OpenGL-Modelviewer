#include "Object.h"

void Object::CreateObject(unsigned int& _objectID)
{
	glGenVertexArrays(1, &_objectID);
}
