#include "Main.h"

#include "BasicShader.h"


int main()
{
	glfwInit();
	//CREATE WINDOW
	Frame frame = {};
	GLFWwindow* glfWindow = frame.InitializeFrame();
	glfwSetFramebufferSizeCallback(glfWindow, Frame::Framebuffer_Size_Callback);
	//SET WINDOW AS CONTEXT
	glfwMakeContextCurrent(glfWindow);
	//CHECK IF GLAD CAN LOAD FUNCTION POINTERS
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD INITIALIZATION FAILED!\n";
	}



	//FRAME RATE HANDLING
	float* deltaTimePtr;
	float deltaTime = 0.0f;
	float currentFrame = 0.0f;
	float lastFrame = 0.0f;
	deltaTimePtr = &deltaTime;

	//CREATE CAMERA OBJECT
	Camera SceneCamera = {};

	//CREATE INPUT HANDLING
	Input input2(&SceneCamera);
	Input::currentInstance = &input2;
	glfwSetCursorPosCallback(glfWindow, Input::MouseCallback);
	glfwSetScrollCallback(glfWindow, Input::ScrollCallback);
	glfwSetInputMode(glfWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);;

	Shader basicShader("Shader/basicVertexShader.glsl", "Shader/basicFragmentShader.glsl");
	Shader lightShader("Shader/LightingVertexShader.glsl", "Shader/LightingFragmentShader.glsl");
	Shader lightSourceShader("Shader/LightSourceVertexShader.glsl", "Shader/LightSourceFragmentShader.glsl");

	glEnable(GL_DEPTH_TEST);
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

	};

	unsigned int indices[] = { 0,1,2,0,2,3 };

	glm::vec3 objectPositions[] =
	{
		glm::vec3(0.0f, 0.0f,0.0f),
		glm::vec3(1.0f, 1.0f,1.0f),
		glm::vec3(-1.0f, -1.0f,-1.0f),
		glm::vec3(1.5f, 0.0f,0.0f),
		glm::vec3(-1.5f, 0.0f,0.0f)
	};
	int sizeOfObjectArray = sizeof(objectPositions) / sizeof(objectPositions[0]);

	//IMAGE 1
	unsigned char* crate = Texture::LoadTexture("Images/container.jpg");
	//IMAGE 2
	unsigned char* cat = Texture::LoadTexture("Images/Garumak512.png");


	// ADD MESH 
	Mesh mesh = {};
	mesh.vertices = vertices3D;
	mesh.indices = indices;
	mesh.size = sizeof(vertices3D);
	mesh.AddMeshComponent();

	mesh.BindTexture(crate);
	mesh.BindTextureWithAlpha(cat);

	//SET TEXTURE ATTRIBUTE LOCATION IN SHADER
	glUniform1i(glGetUniformLocation(basicShader.programID, "ourTexture"), 0);
	glUniform1i(glGetUniformLocation(basicShader.programID, "texture2"), 1);


	//TRANSFORMATION MATRICES
	unsigned int modelLoc = glGetUniformLocation(basicShader.programID, "model");
	unsigned int viewLoc = glGetUniformLocation(basicShader.programID, "view");
	unsigned int projectionLoc = glGetUniformLocation(basicShader.programID, "projection");

	unsigned int modelLoc2 = glGetUniformLocation(lightSourceShader.programID, "model");
	unsigned int viewLoc2 = glGetUniformLocation(lightSourceShader.programID, "view");
	unsigned int projectionLoc2 = glGetUniformLocation(lightSourceShader.programID, "projection");


	//BIND TEXTURE TO UNIFORM LOCATION !
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh.material.textureId1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, mesh.material.textureId2);


	Light lightObject = {};
	Light::currentInstance = &lightObject;
	Light::CreateLightSource(&lightObject.objectID, vertices3D, indices, sizeof(vertices3D));



	//LIGHTING SHADER ATTRIBUTES
//	glm::vec3 objectColor = glm::vec3(1.0f, 0.5f, 0.31f);
//	glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
//	lightShader.Use();
//	glUniform3fv(glGetUniformLocation(lightShader.programID, "objectColor"), 1, glm::value_ptr(objectColor));
//	glUniform3fv(glGetUniformLocation(lightShader.programID, "lightColor"), 1, glm::value_ptr(lightColor));


	Matrix identityMatrix = {};

	//UPDATE
	while (!glfwWindowShouldClose(glfWindow))
	{
		//CLEAR SCREEN
		glClearColor(0.5f, 0.5f, 0.5f, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		basicShader.Use();
		//SET CAMERA POSITION
		identityMatrix.LookAt(viewLoc, SceneCamera.position, SceneCamera.forward, SceneCamera.upward);
		identityMatrix.Zoom(projectionLoc, glm::radians(SceneCamera.fov), 800.0f / 600.0f, 0.1f, 100.0f);
		glBindVertexArray(mesh.objectID);


		//DRAW OBJECTS
		for (int i = 0; i < sizeOfObjectArray; i++)
		{
			identityMatrix.values = glm::translate(identityMatrix.values, objectPositions[i]);
			identityMatrix.Rotate(modelLoc, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
		//identityMatrix.values = glm::translate(identityMatrix.values, glm::vec3(2.0f, -1.0f, 0.0f));
		//identityMatrix.Rotate(modelLoc, (float)glfwGetTime()* glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		//glDrawArrays(GL_TRIANGLES, 0, 36);


		//DRAW LIGHT SOURCE
		lightSourceShader.Use();
		identityMatrix.LookAt(viewLoc2, SceneCamera.position, SceneCamera.forward, SceneCamera.upward);
		identityMatrix.Zoom(projectionLoc2, glm::radians(SceneCamera.fov), 800.0f / 600.0f, 0.1f, 100.0f);
	
		identityMatrix.values = glm::translate(identityMatrix.values, glm::vec3(2.0f, -1.0f, 0.0f));
		identityMatrix.Rotate(modelLoc2, (float)glfwGetTime()* glm::radians(50.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glBindVertexArray(lightObject.objectID);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//CHECK FOR INPUT
		input2.ProcessInput(glfWindow, &SceneCamera.position, &SceneCamera.forward, &SceneCamera.upward, deltaTimePtr);
		glfwPollEvents();

		//DRAW ACTUAL SCREEN
		glfwSwapBuffers(glfWindow);

		//COUNT FRAME TIME
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
	}

	//EXIT
	glfwTerminate();
	return 0;
}