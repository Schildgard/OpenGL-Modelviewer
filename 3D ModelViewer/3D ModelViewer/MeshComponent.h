#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Material.h"
#include "Matrix.h"
#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Mesh
{
public:
	unsigned int objectID;

	float* vertices;
	unsigned int* indices;
	unsigned int size;

	Material material;

	unsigned int modelLocation;
	unsigned int viewLocation;
	unsigned int projectionLocation;

	Mesh();
	void AddMeshComponent();
	void AddMeshComponent(float* _vertices, unsigned int* _indices, unsigned int _size);
	//TEXTURE FUNCTIONS
	void BindTexture(Texture _texture);
	void BindTextureWithAlpha(Texture _texture);

	void BindTexture(Texture _texture, bool _freeImage);
	void BindTextureWithAlpha(Texture _texture, bool _freeImage);

	void DrawThisObject(glm::vec3 _lightPosition, Camera _sceneCameraPos);

	void AssignShaderProgram(Shader* _ShaderProgram);

	unsigned int FindNextTextureSlot();
};
