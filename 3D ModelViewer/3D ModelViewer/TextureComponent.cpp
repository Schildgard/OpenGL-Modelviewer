#include "TextureComponent.h"


int Texture::width = 0;
int Texture::height = 0;
int Texture::nrChannels = 0;



unsigned char* Texture::LoadTexture(const char* _filepath)
{
	unsigned char* data = stbi_load(_filepath, &width, &height, &nrChannels, 0);
	if (data == nullptr) {
		std::cout << "Failed to load texture 1" << std::endl;
	}
	else

		return data;
}


