#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include <iostream>

class Texture
{
public:
	int width;
	int height ;
	int nrChannels;

	unsigned char* image;

	static unsigned char* LoadTexture(Texture& _texture, const char* _filepath);
	void LoadTexture(const char* _filepath);
};
