#include "TextureComponent.h"

unsigned char* Texture::LoadTexture(const char* _filepath)
{
	unsigned char* data = stbi_load(_filepath, &width, &height, &nrChannels, 0);
	if (data == nullptr) {
		std::cout << "Failed to load texture 1" << std::endl;
	}
	else

		return data;
}

void Texture::BindTexture(unsigned int& _objectID, unsigned char* _data, unsigned int& _textureID)
{
	glBindVertexArray(_objectID);

	glGenTextures(1, &_textureID);
	glBindTexture(GL_TEXTURE_2D, _textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, _data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(_data);

}

void Texture::BindTextureWithAlpha(unsigned int& _objectID, unsigned char* _data, unsigned int& _textureID)
{
	glBindVertexArray(_objectID);

	glGenTextures(1, &_textureID);
	glBindTexture(GL_TEXTURE_2D, _textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(_data);

}



void Texture::AddTextureComponent(unsigned int& _objectID)
{
	glBindVertexArray(_objectID);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, textureCoods, GL_STATIC_DRAW);

	//TEXTURE ATTRIB
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(2);

}


void Texture::AddTextureComponent(unsigned int& _objectID, unsigned int _size, float* _textureCoods)
{

	size = _size;
	textureCoods = _textureCoods;

	glBindVertexArray(_objectID);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, textureCoods, GL_STATIC_DRAW);

	//TEXTURE ATTRIB
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(2);

}


