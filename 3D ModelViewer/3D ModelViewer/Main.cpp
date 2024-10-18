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
	basicShader.Use();
	glEnable(GL_DEPTH_TEST);


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


	//BIND TEXTURE TO UNIFORM LOCATION !
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh.material.textureId1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, mesh.material.textureId2);


	//LIGHT
	unsigned int lightVao;
	unsigned int lightVbo;
	unsigned int lightEbo;
	glGenVertexArrays(1, &lightVao);
	glBindVertexArray(lightVao);

	glGenBuffers(1, &lightVbo);
	glBindBuffer(GL_ARRAY_BUFFER, lightVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3D), vertices3D, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &lightEbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lightEbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);





	//LIGHTING SHADER ATTRIBUTES
	glm::vec3 objectColor = glm::vec3(1.0f, 0.5f, 0.31f);
	glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	lightShader.Use();
	glUniform3fv(glGetUniformLocation(lightShader.programID, "objectColor"), 1, glm::value_ptr(objectColor));
	glUniform3fv(glGetUniformLocation(lightShader.programID, "lightColor"), 1, glm::value_ptr(lightColor));



	Matrix identityMatrix = {};

	//UPDATE
	while (!glfwWindowShouldClose(glfWindow))
	{
		//CLEAR SCREEN
		glClearColor(0.5f, 0.5f, 0.5f, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glBindVertexArray(mesh.objectID);


		//SET CAMERA POSITION
		identityMatrix.LookAt(viewLoc, SceneCamera.position, SceneCamera.forward, SceneCamera.upward);
		identityMatrix.Zoom(projectionLoc, glm::radians(SceneCamera.fov), 800.0f / 600.0f, 0.1f, 100.0f);


		//DRAW OBJECTS
		for (int i = 0; i < sizeOfObjectArray; i++)
		{
			identityMatrix.values = glm::translate(identityMatrix.values, objectPositions[i]);
			identityMatrix.Rotate(modelLoc, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

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