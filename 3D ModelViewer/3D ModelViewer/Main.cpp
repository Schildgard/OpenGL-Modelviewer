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


	//stbi_set_flip_vertically_on_load(true);
	int x;
	int y;
	int channels;

	unsigned char* smiley = tex.LoadTexture("Images/awesomeface.png");

	unsigned char* cat = tex.LoadTexture("Images/Garumak512.png");









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
	unsigned int catTextureID;
	tex.BindTextureWithAlpha(vao, cat, catTextureID);

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
	glBindTexture(GL_TEXTURE_2D, catTextureID);


	//WHY DOES THE MODEL MATRIX LOOKS LIKE THIS ?
	glm::mat4 model = glm::mat4(1.0f);
	//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	Matrix model2 = {};
	Matrix view2 = {};

	glm::mat4 projection = glm::mat4(1.0f);


	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));



	// CAMERA

	// DEFINE CAMERA POSITION AND DIRECTION
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 camTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 camDir = (cameraPos - camTarget);
	// DEFINE CAMERA X AND Y AXIS
	glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 camRight = glm::normalize(glm::cross(worldUp, camDir));
	glm::vec3 camUp = (glm::normalize(glm::cross(camDir, camRight)));


	glm::mat4 camView = glm::lookAt
	(
		glm::vec3(0.0f, 0.0f, 3.0f),//POSITION 
		glm::vec3(0.0f, 0.0f, 0.0f),//TARGET
		glm::vec3(0.0f, 1.0f, 0.0f)//WORLD UP
	);


	glEnable(GL_DEPTH_TEST);


	const float radius = 10.0f;
	float camX = sin(glfwGetTime()) * radius;
	float camZ = cos(glfwGetTime()) * radius;
	//glm::mat4 moveCamView = glm::mat4(1.0f);
	//moveCamView = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));


	//UPDATE
	while (!glfwWindowShouldClose(glfWindow))
	{
		//CLEAR SCREEN
		glClearColor(0.5f, 0.5f, 0.5f, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		basicShader.Use();

		camX = (float)(sin(glfwGetTime()) * radius);
		camZ = (float)(cos(glfwGetTime()) * radius);
		glm::mat4 moveCamView = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(moveCamView));

		//BIND OBJECT TO DRAW
		glBindVertexArray(vao);


		//OBJECT 1 MANIPULATION
		model2.Rotate(modelLoc, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		//view2.Translate(viewLoc, glm::vec3(0.0f + offset, 0.0f, -5.0 + offset));
		glDrawArrays(GL_TRIANGLES, 0, 36);



		camX = sin(glfwGetTime()) * radius;
		camZ = cos(glfwGetTime()) * radius;
		moveCamView = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(moveCamView));

	////OBJECT 2 MANIPULATION
	//
	//camX = sin(glfwGetTime()) * radius;
	//camZ = cos(glfwGetTime()) * radius;
	//moveCamView = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
	//
	//model2.Rotate(modelLoc, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
	//view2.Translate(viewLoc, glm::vec3(0.0f - offset, 0.0f, -5.0 - offset));
	//glDrawArrays(GL_TRIANGLES, 0, 36);
	//
	////OBJECT 3 MANIPULATION
	//
	//camX = sin(glfwGetTime()) * radius;
	//camZ = cos(glfwGetTime()) * radius;
	//moveCamView = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
	//
	//model2.Rotate(modelLoc, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
	//view2.Translate(viewLoc, glm::vec3(0.0f, -0.0f + offset, -5.0));
	//glDrawArrays(GL_TRIANGLES, 0, 36);
	//
	////OBJECT 4 MANIPULATION
	//
	//camX = sin(glfwGetTime()) * radius;
	//camZ = cos(glfwGetTime()) * radius;
	//moveCamView = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
	//
	//model2.Rotate(modelLoc, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
	//view2.Translate(viewLoc, glm::vec3(0.0f, 0.0f - offset, -5.0));
	//glDrawArrays(GL_TRIANGLES, 0, 36);




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