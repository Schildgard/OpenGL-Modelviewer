#include "Main.h"



int main()
{
	float vertices[] =
	{
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f,0.0f,
		0.0f, 0.5f, 0.0f


	};

	//VERTEX SHADER CODE
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	//FRAGMENT SHADER CODE
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n"
		"\0";

	InitializeExternalLibraries();






	//CREATE WINDOW
	Frame windowFrame = {};
	GLFWwindow* glfWindow = windowFrame.InitializeFrame();
	glfwMakeContextCurrent(glfWindow);

	//CREATE INPUT HANDLING
	Input input = {};

	//CHECK IF GLAD CAN LOAD FUNCTION POINTERS
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD INITIALIZATION FAILED!\n";
		return -1;
	}



	//GENERATE VBO
	unsigned int vbo;
	VBO bufferobject = {vbo, vertices, sizeof(vertices) };
	//MUSS DAS BUFFEROBJECT DANACH WIEDER GELÖSCHT WERDEN???



	//CREATE ID TO REFER TO SHADER
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//BIND SHADER SOURCE CODE TO VERTEX SHADER
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);


	//CHECK IF SHADER CREATION WAS SUCCESSFULL
	int success;
	char infoLog[512];//DEFINE MEMORY SPACE FOR ERROR LOG
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << "\n";
	}
	else
	{
		std::cout << "VertexShader was compiled successfully \n";
	}

	//REPEAT THE SAME FOR FRAGMENT SHADER
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);


	//int success;
	//char infoLog[512];//DEFINE MEMORY SPACE FOR ERROR LOG
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << "\n";
	}
	else
	{
		std::cout << "FragmentShader was compiled successfully \n";
	}


	//CREATE SHADER PROGRAM AND ATTACH FRAGMENT AND VERTEX SHADER TO IT. ACTIVATE IT AND DELETE THE SHADER AFTERWARDS SINCE THEY ARE STORED IN THE SHADER PROGRAM ANYWAY.
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	//TELL GPU HOW TO INTERPRET VERTEX DATA
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);




	//VAO
	unsigned int vao;
	VAO VertexArrayObject = { vao };


	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);





	//UPDATE
	while (!glfwWindowShouldClose(glfWindow))
	{
		//CLEAR SCREEN
		glClearColor(0.5f, 0.5f, 0.5f, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		//CHECK FOR INPUT
		input.ProcessInput(glfWindow);

		//CHECK FOR OTHER INPUT EVENTS
		glfwPollEvents();

		//DRAW ACTUAL SCREEN
		glfwSwapBuffers(glfWindow);
	}



	//EXIT
	glfwTerminate();
	return 0;
}

//NEXT STEP READ SHADER FILES AS STRING