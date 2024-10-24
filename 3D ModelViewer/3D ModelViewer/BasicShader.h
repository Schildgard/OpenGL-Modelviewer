#pragma once
#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	unsigned int programID;

	//CONSTRUCTOR
	Shader(const char* _vertexPath, const char* _fragmentPath)
	{
		//1.GET VERTEX INFORMATION FROM SOURCE CODE

		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;

		// ensure ifstream objects can throw exceptions:
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			//OPEN SHADER FILES
			vShaderFile.open(_vertexPath);
			fShaderFile.open(_fragmentPath);
			//DECLARE STRINGS
			std::stringstream vShaderStream;
			std::stringstream fShaderStream;
			// PUT CONTENT OF SHADER FILES IN STRING STREAM
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			//CLOSE FILES
			vShaderFile.close();
			fShaderFile.close();
			// CONVERT STREAM INTO STRING
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();

		}
		catch (std::ifstream::failure& e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ \n";
		}
		const char* vertexShaderCode = vertexCode.c_str();
		const char* fragmentShaderCode = fragmentCode.c_str();



		//2. COMPILE AND LINK SHADERS

		unsigned int vertexID;
		unsigned int fragmentID;
		int success;
		char infoLog[512];


		//VERTEX
		vertexID = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexID, 1, &vertexShaderCode, NULL);
		glCompileShader(vertexID);

		//TEST
		glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		};

		//FRAGMENT
		fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentID, 1, &fragmentShaderCode, NULL);
		glCompileShader(fragmentID);

		//TEST
		glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		};


		//SHADER PROGRAM
		programID = glCreateProgram();

		glAttachShader(programID, vertexID);
		glAttachShader(programID, fragmentID);
		glLinkProgram(programID);

		//TEST
		glGetProgramiv(programID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(programID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		glDeleteShader(vertexID);
		glDeleteShader(fragmentID);
	}


	void Use()
	{
		glUseProgram(programID);

	}

	void SetBool(const std::string &_name, bool _value) const
	{
		glUniform1i(glGetUniformLocation(programID, _name.c_str()), (int)_value);
	}

	void SetInt(const std::string& _name, int _value) const
	{
		glUniform1i(glGetUniformLocation(programID, _name.c_str()), _value);
	}

	void SetFloat(const std::string& _name, float _value) const
	{
		glUniform1f(glGetUniformLocation(programID, _name.c_str()), _value);
	}

};



