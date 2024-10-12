#include "Main.h"

#include "BasicShader.h"



int main()
{
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

	Shader basicShader("D:/Repository/3DModelView/3D ModelViewer/3D ModelViewer/Shader/basicVertexShader.glsl", "D:/Repository/3DModelView/3D ModelViewer/3D ModelViewer/Shader/basicFragmentShader.glsl");

	float vertices[] =
	{					
	// positions          // colors           // texture coords
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 4.0f,    // top left 
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   4.0f, 4.0f,   // top right
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   4.0f, 0.0f,   // bottom right

	};

	unsigned int indices[] = { 0,1,2,0,2,3 };

	int width;
	int height;
	int nrChannels;
	unsigned char* data = stbi_load("C:/Users/Leon/Desktop/container.jpg", &width, &height, &nrChannels, 0);


	int width2;
	int height2;
	int nrChannels2;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data2 = stbi_load("C:/Users/Leon/Desktop/awesomeface.png", &width2, &height2, &nrChannels2, 0);


	//Declare Buffer Objects
	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;

	//DEFINE BUFFER OBJECTS
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
	//BIN VAO
	glBindVertexArray(vao);


	//BIND VBO
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	//VAO2
	unsigned int vao2;
	unsigned int vbo2;
	unsigned int ebo2;

	glGenVertexArrays(1, &vao2);
	glGenBuffers(1, &vbo2);
	glGenBuffers(1, &ebo2);

	glBindVertexArray(vao2);

	glBindBuffer(GL_ARRAY_BUFFER, vbo2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//POSITION ATTRIB
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//COLOR ATTRIB
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	//TEXTURE ATTRIB
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);


	stbi_image_free(data);

	unsigned int texture2;
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width2, height2, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data2);

	basicShader.Use();
	glUniform1i(glGetUniformLocation(basicShader.programID, "ourTexture"),0);
	glUniform1i(glGetUniformLocation(basicShader.programID, "texture2"), 1);
	

	//UPDATE
	while (!glfwWindowShouldClose(glfWindow))
	{
		//CLEAR SCREEN
		glClearColor(0.5f, 0.5f, 0.5f, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		//ACTIVATE SHADERPROGRAM



		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);

		glBindVertexArray(vao2);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);



		//CHECK FOR INPUT
		input.ProcessInput(glfWindow);
		glfwPollEvents();

		//DRAW ACTUAL SCREEN
		glfwSwapBuffers(glfWindow);
	}


	//EXIT
	glfwTerminate();
	return 0;
}