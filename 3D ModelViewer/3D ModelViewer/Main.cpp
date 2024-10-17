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
	//glfwSetInputMode(glfWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);;

	Shader basicShader("Shader/basicVertexShader.glsl", "Shader/basicFragmentShader.glsl");
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

//	Object Object = {};
	Texture tex = {}; //TODO EXTRACT LOAD TEXTURE FUNCTION SO IT IS NOT PERFORMED BY AN OBJECT OF TEXTURE CLASS BUT BY ITS CLASS ITSELF
	//IMAGE 1
	unsigned char* crate = tex.LoadTexture("Images/container.jpg");
	//IMAGE 2
	unsigned char* cat = tex.LoadTexture("Images/Garumak512.png");


	//CREATE OBJECT
	unsigned int vao;

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


	//BIND TEXTURE TO UNIFORM LOCATION !
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, crateTextureID);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, catTextureID);


	Matrix identityMatrix = {};

	//UPDATE
	while (!glfwWindowShouldClose(glfWindow))
	{
		//CLEAR SCREEN
		glClearColor(0.5f, 0.5f, 0.5f, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		basicShader.Use();
		glBindVertexArray(vao);


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