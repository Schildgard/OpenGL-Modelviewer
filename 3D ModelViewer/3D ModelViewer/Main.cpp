#include "Main.h"

#include "BasicShader.h"

void mouseCallBack(GLFWwindow* _window, double _xPos, double _yPos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

//MOUSE SETTINGS
// SET MOUSE POS AT MIDDLE OF THE SCREEN
bool firstMouse = true;
float lastXPos = 400;
float lastYPos = 300;
float sensitivity = 0.1f;

//CAMERA SETTINGS
glm::vec3 camPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 camFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 camUp = glm::vec3(0.0f, 1.0f, 0.0f);
float horizontal = -90.0f; // horizontal 0.0f points to the positive x axis, so -90f points towards negative z axis which is our forward direction
float vertical = 0.0f;
float fov = 45.0f;

int main()
{
	InitializeExternalLibraries();

	//CREATE WINDOW
	Frame windowFrame = {};
	GLFWwindow* glfWindow = windowFrame.InitializeFrame();
	glfwMakeContextCurrent(glfWindow);
	glfwSetCursorPosCallback(glfWindow, mouseCallBack);




	//FRAME RATE HANDLING
	float* deltaTimePtr;
	float deltaTime = 0.0f;
	float currentFrame = 0.0f;
	float lastFrame = 0.0f;
	deltaTimePtr = &deltaTime;

	//CREATE INPUT HANDLING
	Input input = {};
	glfwSetInputMode(glfWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);





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



	// CAMERA

	// DEFINE CAMERA POSITION AND DIRECTION
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 camTarget = glm::vec3(0.0f, 0.0f, 0.0f);
//glm::vec3 camDir = (cameraPos - camTarget);
//
//// DEFINE CAMERA X AND Y AXIS
//glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
//glm::vec3 camRight = glm::normalize(glm::cross(worldUp, camDir));
//glm::vec3 camUp = (glm::normalize(glm::cross(camDir, camRight)));




	//UPDATE
	while (!glfwWindowShouldClose(glfWindow))
	{
		//CLEAR SCREEN
		glClearColor(0.5f, 0.5f, 0.5f, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		basicShader.Use();
		//BIND OBJECT TO DRAW
		glBindVertexArray(vao);

		view2.LookAt(viewLoc, camPos, camFront, camUp);

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
		input.ProcessInput(glfWindow, &camPos, &camFront, &camUp, deltaTimePtr);
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



void mouseCallBack(GLFWwindow* _window, double _xPos, double _yPos)
{

	if (firstMouse)
	{
		lastXPos = _xPos;
		lastYPos = _yPos;
		firstMouse = false;
	}


	//CALCULATE HOW MUCH THE MOUSE HAS MOVED
	float xOffset = _xPos - lastXPos;
	float yOffset =  lastYPos - _yPos;
	// UPDATE LAST POSITION VALUES
	lastXPos = _xPos;
	lastYPos = _yPos;

	// SCALE OFFSET DOWN BY SENSIVITY PARAMETER
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	//SET HORIZONTAL AND VERTICAL POS TO OFFSET
	horizontal += xOffset;
	vertical += yOffset;

	// CLAMP VERTICAL CAMERA ANGLE
	if (vertical > 89.0f)
	{
		vertical = 89.0f;
	}
	else if (vertical < -89.0f)
	{
		vertical = -89.0f;
	}

	//CALCULATE ACTUAL DIRECTION VECTOR
	glm::vec3 direction;
	direction.x = cos(glm::radians(horizontal)) * cos(glm::radians(vertical));
	direction.y = sin(glm::radians(vertical));
	direction.z = sin(glm::radians(horizontal)) * cos(glm::radians(vertical));
	camFront = glm::normalize(direction);

}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{

}