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
	basicShader.Use();
	float vertices3D[]
	{
	-0.5f, -0.5f, -0.5f,
	 0.5f, -0.5f, -0.5f,
	 0.5f,  0.5f, -0.5f,
	 0.5f,  0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f,
	-0.5f, -0.5f, -0.5f,

	-0.5f, -0.5f,  0.5f,
	 0.5f, -0.5f,  0.5f,
	 0.5f,  0.5f,  0.5f,
	 0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	-0.5f, -0.5f,  0.5f,

	-0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f, -0.5f,
	-0.5f, -0.5f, -0.5f,
	-0.5f, -0.5f, -0.5f,
	-0.5f, -0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,

	 0.5f,  0.5f,  0.5f,
	 0.5f,  0.5f, -0.5f,
	 0.5f, -0.5f, -0.5f,
	 0.5f, -0.5f, -0.5f,
	 0.5f, -0.5f,  0.5f,
	 0.5f,  0.5f,  0.5f,

	-0.5f, -0.5f, -0.5f,
	 0.5f, -0.5f, -0.5f,
	 0.5f, -0.5f,  0.5f,
	 0.5f, -0.5f,  0.5f,
	-0.5f, -0.5f,  0.5f,
	-0.5f, -0.5f, -0.5f,

	-0.5f,  0.5f, -0.5f,
	 0.5f,  0.5f, -0.5f,
	 0.5f,  0.5f,  0.5f,
	 0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f, -0.5f,
	};

	float textureCoods[]
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

	float colorArray[]
	{
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
	};

	unsigned int indices[] = { 0,1,2,0,2,3 };

	Object Object = {};
	Texture tex = {}; //TODO EXTRACT LOAD TEXTURE FUNCTION SO IT IS NOT PERFORMED BY AN OBJECT OF TEXTURE CLASS BUT BY ITS CLASS ITSELF



	//IMAGE 1
	unsigned char* crate = tex.LoadTexture("Images/container.jpg");
	//IMAGE 2
	stbi_set_flip_vertically_on_load(true);
	unsigned char* smiley = tex.LoadTexture("Images/awesomeface.png");







	//CREATE OBJECT
	unsigned int vao;
	Object.CreateObject(vao);

	// ADD MESH 
	Mesh mesh = {};
	//mesh.AddMeshComponent(vao, vertices3D, indices, sizeof(vertices3D));
	mesh.vertices = vertices3D;
	mesh.indices = indices;
	mesh.size = sizeof(vertices3D);
	mesh.AddMeshComponent(vao);

	//ADD COLOR
	Color color = {};
	//color.AddColorAttributes(vao, sizeof(colorArray), colorArray);
	color.colorArray = colorArray;
	color.size = sizeof(colorArray);
	color.AddColorAttributes(vao);


	//ADD TEXTURES
	//tex.AddTextureComponent(vao, sizeof(textureCoods), textureCoods);
	tex.textureCoods = textureCoods;
	tex.size = sizeof(textureCoods);
	tex.AddTextureComponent(vao);

	unsigned int crateTextureID;
	tex.BindTexture(vao, crate, crateTextureID);
	unsigned int smileyTextureID;
	tex.BindTextureWithAlpha(vao, smiley, smileyTextureID);

	//SET TEXTURE ATTRIBUTE LOCATION IN SHADER
	glUniform1i(glGetUniformLocation(basicShader.programID, "ourTexture"), 0);
	glUniform1i(glGetUniformLocation(basicShader.programID, "texture2"), 1);


	//TRANSFORMATION MATRICES
	unsigned int modelLoc = glGetUniformLocation(basicShader.programID, "model");
	unsigned int viewLoc = glGetUniformLocation(basicShader.programID, "view");
	unsigned int projectionLoc = glGetUniformLocation(basicShader.programID, "projection");


	float offset = 0.001f;
	//BIND TEXTURE TO UNIFORM LOCATION !
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, crateTextureID);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, smileyTextureID);


	//WHY DOES THE MODEL MATRIX LOOKS LIKE THIS ?
	glm::mat4 model = glm::mat4(1.0f);
	//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	Matrix model2 = {};
	Matrix view2 = {};


	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);


	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));


	glEnable(GL_DEPTH_TEST);
	//UPDATE
	while (!glfwWindowShouldClose(glfWindow))
	{
		//CLEAR SCREEN
		glClearColor(0.5f, 0.5f, 0.5f, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//BIND OBJECT TO DRAW
		glBindVertexArray(vao);

		//OBJECT 1 MANIPULATION
		model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		model = glm::mat4(1.0f);
		//model2.Rotate(&modelLoc, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		//view2.Translate(viewLoc, glm::vec3(0.1f + offset, 0.0f, -5.0 + offset));

		view = glm::translate(view, glm::vec3(0.1f + offset, 0.0f, -5.0 + offset));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		view = glm::mat4(1.0f);

		glDrawArrays(GL_TRIANGLES, 0, 36);

		//model2.values = glm::mat4(1.0f);
		//view2.values = glm::mat4(1.0f);


		//OBJECT 2 MANIPULATION
		model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		model = glm::mat4(1.0f);

		view = glm::translate(view, glm::vec3(0.1f - offset, 0.0f, -5.0 - offset));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		view = glm::mat4(1.0f);

		glDrawArrays(GL_TRIANGLES, 0, 36);



		//OBJECT 3 MANIPULATION
		model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		model = glm::mat4(1.0f);

		view = glm::translate(view, glm::vec3(0.0f, -0.0f + offset, -5.0));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		view = glm::mat4(1.0f);

		glDrawArrays(GL_TRIANGLES, 0, 36);



		//OBJECT 4 MANIPULATION
		model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		model = glm::mat4(1.0f);

		view = glm::translate(view, glm::vec3(0.0f, 0.0f - offset, -5.0));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		view = glm::mat4(1.0f);

		glDrawArrays(GL_TRIANGLES, 0, 36);


		//CHECK FOR INPUT
		input.ProcessInput(glfWindow);
		glfwPollEvents();

		//DRAW ACTUAL SCREEN
		glfwSwapBuffers(glfWindow);

		offset += 0.01f;
		if (offset >= 2.5f)
		{
			offset *= -1;
		}
	}


	//EXIT
	glfwTerminate();
	return 0;
}