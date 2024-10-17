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
};
