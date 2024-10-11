#include "Main.h"

#include "BasicShader.h"


int main()
{

	float vertices2[] =
	{					//Colors
	-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
	-0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // top left
	 0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // top right
	 0.5f, -0.5f, 0.0f, 1.0f, 1.0f,0.0f, // bottom right

	//ADDITIONAL TEST TRIANGLE
		-0.25f, 0.5f,0.0f, 1.0f, 0.0f, 0.0f,
		0.25f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,  0.0f, 0.0f, 1.0f,

	};
	unsigned int indices[] = { 0,1,2,0,2,3,4,5,6 };





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

	Shader basicShader("D:\\Leon\\3DModelView\\3D ModelViewer\\3D ModelViewer\\Shader\\basicVertexShader.glsl","D:\\Leon\\3DModelView\\3D ModelViewer\\3D ModelViewer\\Shader\\basicFragmentShader.glsl");





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
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);



	basicShader.Use();


	//UPDATE
	while (!glfwWindowShouldClose(glfWindow))
	{
		//CLEAR SCREEN
		glClearColor(0.5f, 0.5f, 0.5f, 0);
		glClear(GL_COLOR_BUFFER_BIT);


		//SET UNIFORM VARIABLE
		//float timeValue = glfwGetTime();
		//float greenValue = (sin(timeValue) / 2.0f + 0.5f);
		//int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
		//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);





		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

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