#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include <iostream>

class Texture
{
public:
	static int width;
	static int height ;
	static int nrChannels;
	static unsigned char* LoadTexture(const char* _filepath);

	unsigned int size;
	float* textureCoods;


	void BindTexture(unsigned int& _objectID, unsigned char* _data, unsigned int& _textureID);
	void BindTextureWithAlpha(unsigned int& _objectID, unsigned char* _data, unsigned int& _textureID);

	void AddTextureComponent(unsigned int& _objectID);
	void AddTextureComponent(unsigned int& _objectID, unsigned int _size, float* _textureCoods);

};
