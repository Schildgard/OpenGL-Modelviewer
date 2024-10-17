#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "TextureComponent.h"

class Material
{ 
public:
	Material();
	//COLOR
	unsigned int size;
	float* colorArray;
	void AddColorAttributes(unsigned int& _objectID);

	//TEXTURE
	unsigned int textureSize;
	float* textureCoods;

	Texture texture;
};
