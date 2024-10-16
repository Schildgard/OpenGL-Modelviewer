#include "Main.h"

#include "BasicShader.h"

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void Framebuffer_Size_Callback(GLFWwindow* _window, int _width, int _height);

//WINDOW SETTINGS
int width = 800;
int height = 600;

//MOUSE SETTINGS
// SET MOUSE POS AT MIDDLE OF THE SCREEN
bool firstMouse = true;
float lastXPos = 400;
float lastYPos = 300;
float sensitivity = 0.1f;


int main()
{
	InitializeExternalLibraries();

	//CREATE WINDOW
	GLFWwindow* glfWindow = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	if (glfWindow == NULL)
	{
		std::cout << "Window creation failed miserably!\n";
		return -1;
	}
	else
	{
		std::cout << "Window creation sucessfull!\n";
		//SPECIFIZE TO USE GLFW VERSION 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		//SPECIFY TO USE GLFW CORE PROFILE AND NOT IMMEDIATE
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//DEFINE FRAME SCALABILITY
		glfwSetFramebufferSizeCallback(glfWindow, Framebuffer_Size_Callback);
	}
	glfwMakeContextCurrent(glfWindow);




	//FRAME RATE HANDLING
	float* deltaTimePtr;
	float deltaTime = 0.0f;
	float currentFrame = 0.0f;
	float lastFrame = 0.0f;
	deltaTimePtr = &deltaTime;


	Camera SceneCamera = {};
	//CREATE INPUT HANDLING
	Input input2(&SceneCamera);
	Input::currentInstance = &input2;
	glfwSetCursorPosCallback(glfWindow, Input::MouseCallBack);
	glfwSetInputMode(glfWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);;






	//CHECK IF GLAD CAN LOAD FUNCTION POINTERS
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD INITIALIZATION FAILED!\n";
		return -1;
	}

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

	Object Object = {};
	Texture tex = {}; //TODO EXTRACT LOAD TEXTURE FUNCTION SO IT IS NOT PERFORMED BY AN OBJECT OF TEXTURE CLASS BUT BY ITS CLASS ITSELF
	//IMAGE 1
	unsigned char* crate = tex.LoadTexture("Images/container.jpg");
	//IMAGE 2
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
	//glm::mat4 model = glm::mat4(1.0f);
	//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	Matrix model2 = {};
	Matrix view2 = {};

	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));




	//UPDATE
	while (!glfwWindowShouldClose(glfWindow))
	{
		//CLEAR SCREEN
		glClearColor(0.5f, 0.5f, 0.5f, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		basicShader.Use();
		//BIND OBJECT TO DRAW
		glBindVertexArray(vao);

		//view2.LookAt(viewLoc, camPos, camFront, camUp);
		view2.LookAt(viewLoc, SceneCamera.position, SceneCamera.forward, SceneCamera.upward);

		//OBJECT 1 MANIPULATION
		model2.values = glm::translate(model2.values, glm::vec3(0.0f, 0.0f, 0.0f));
		model2.Rotate(modelLoc, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//OBJECT 2 MANIPULATION
		model2.values = glm::translate(model2.values, glm::vec3(1.0f));
		model2.Rotate(modelLoc, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//OBJECT 3 MANIPULATION
		model2.values = glm::translate(model2.values, glm::vec3(-1.0f));
		model2.Rotate(modelLoc, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//OBJECT 4 MANIPULATION
		model2.values = glm::translate(model2.values, glm::vec3(1.5f, 0.0f, 0.0f));
		model2.Rotate(modelLoc, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//OBJECT 5 MANIPULATION
		model2.values = glm::translate(model2.values, glm::vec3(-1.5f, 0.0f, 0.0f));
		model2.Rotate(modelLoc, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		glDrawArrays(GL_TRIANGLES, 0, 36);





		//CHECK FOR INPUT
		//input2.ProcessInput(glfWindow, &camPos, &camFront, &camUp, deltaTimePtr);
		input2.ProcessInput(glfWindow, &SceneCamera.position, &SceneCamera.forward, &SceneCamera.upward, deltaTimePtr);
		glfwPollEvents();

		//DRAW ACTUAL SCREEN
		glfwSwapBuffers(glfWindow);

		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;


		if (offset >= 2.0f)
		{
			offset *= -1;
		}
	}

	//EXIT
	glfwTerminate();
	return 0;
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{

}
void Framebuffer_Size_Callback(GLFWwindow* _window, int _width, int _height)
{
	glViewport(0, 0, _width, _height);
}