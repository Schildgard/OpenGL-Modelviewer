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

	Shader basicShader("Shader/basicVertexShader.glsl", "Shader/basicFragmentShader.glsl");


	float vertices[] =
	{
		// positions          // colors           // texture coords
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 4.0f,    // top left 
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   4.0f, 4.0f,   // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   4.0f, 0.0f,   // bottom right

	};

	unsigned int indices[] = { 0,1,2,0,2,3 };


	Object Object = {};

	Mesh mesh = {};
	Color color = {};
	Texture tex = {};

	//IMAGE 1
	unsigned char* data = tex.LoadTexture("Images/container.jpg");
	//IMAGE 2
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data2 = tex.LoadTexture("Images/awesomeface.png");





	//CREATE OBJECT
	unsigned int vao;
	Object.CreateObject(vao);
	// ADD COMPONENTS
	mesh.AddMeshAttributes(vao, vertices, indices);
	color.AddColorAttributes(vao, vertices, indices);

	unsigned int texture;
	tex.AddTextureComponent(vao, vertices, indices);
	tex.BindTexture(vao, data, texture);
	unsigned int texture2;
	tex.BindTextureWithAlpha(vao, data2, texture2);


	basicShader.Use();
	//SET TEXTURE ATTRIBUTE LOCATION IN SHADER
	glUniform1i(glGetUniformLocation(basicShader.programID, "ourTexture"), 0);
	glUniform1i(glGetUniformLocation(basicShader.programID, "texture2"), 1);

	//IDENTITY MATRIX
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
	//trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0, 0.0, 1.0));
	trans = glm::translate(trans, glm::vec3(-1.0f, 0.0f, 0.0f));

	unsigned int transformLoc = glGetUniformLocation(basicShader.programID, "transform");

	float offset = 0.001f;
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);

	//UPDATE
	while (!glfwWindowShouldClose(glfWindow))
	{
		//CLEAR SCREEN
		glClearColor(0.5f, 0.5f, 0.5f, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		//BIND OBJECT TO DRAW
		glBindVertexArray(vao);


		//TRANSFORM MATRIX
		trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
		trans = glm::translate(trans, glm::vec3(0.0f + offset, 0.0f, 0.0f));
		// SET MATRIX VALUE TO TRANSFORM UNIFORM
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
		//DRAW OBJECT
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//RESET MATRIX
		trans = glm::mat4(1.0f);


		//REPEAT FOR SECOND BOX
		trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
		trans = glm::translate(trans, glm::vec3(0.0f - offset, 0.0f, 0.0f));
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		trans = glm::mat4(1.0f);


		//CHECK FOR INPUT
		input.ProcessInput(glfWindow);
		glfwPollEvents();

		//DRAW ACTUAL SCREEN
		glfwSwapBuffers(glfWindow);

		offset += 0.01f;
		if (offset >= 2.5f)
		{
			offset = -2.5f;
		}
	}


	//EXIT
	glfwTerminate();
	return 0;
}