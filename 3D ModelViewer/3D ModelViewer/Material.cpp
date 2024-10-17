#include "Material.h"


Material::Material()
{
	textureCoods = new float[2 * 36]
		{
				0.0f, 0.0f,
				1.0f, 0.0f,
				1.0f, 1.0f,
				1.0f, 1.0f,
				0.0f, 1.0f,
				0.0f, 0.0f,

				0.0f, 0.0f,
				1.0f, 0.0f,
				1.0f, 1.0f,
				1.0f, 1.0f,
				0.0f, 1.0f,
				0.0f, 0.0f,

				1.0f, 0.0f,
				1.0f, 1.0f,
				0.0f, 1.0f,
				0.0f, 1.0f,
				0.0f, 0.0f,
				1.0f, 0.0f,

				1.0f, 0.0f,
				1.0f, 1.0f,
				0.0f, 1.0f,
				0.0f, 1.0f,
				0.0f, 0.0f,
				1.0f, 0.0f,

				0.0f, 1.0f,
				1.0f, 1.0f,
				1.0f, 0.0f,
				1.0f, 0.0f,
				0.0f, 0.0f,
				0.0f, 1.0f,

				0.0f, 1.0f,
				1.0f, 1.0f,
				1.0f, 0.0f,
				1.0f, 0.0f,
				0.0f, 0.0f,
				0.0f, 1.0f
		};
};
void Material::AddColorAttributes(unsigned int& _objectID)
{

}


