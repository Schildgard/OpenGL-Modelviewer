#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include <iostream>

class Texture
{
public:
	int width;
	int height;
	int nrChannels;

	unsigned char* LoadTexture(const char* _filepath);

	void BindTexture(unsigned int& _objectID, unsigned char* _data, unsigned int& _textureID);
	void BindTextureWithAlpha(unsigned int& _objectID, unsigned char* _data, unsigned int& _textureID);

	void AddTextureComponent(unsigned int& _objectID, float* _textureCoods, unsigned int* _indices);

};
