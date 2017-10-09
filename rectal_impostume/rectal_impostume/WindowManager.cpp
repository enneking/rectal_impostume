#include "WindowManager.h"

#include <stdlib.h>
#include <stdio.h>

//GLFW needs this
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

void RaptorEngine::Core::WindowManager::init()
{
	//initialize glfw
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
}

GLFWwindow* RaptorEngine::Core::WindowManager::createGLFWwindow(int width, int height,
	const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{

	//declare a new window
	GLFWwindow* window;

	//create a new window
	window = glfwCreateWindow(width, height, title, monitor, share);

	//errorcheck
	if (!window)
	{
		fprintf(stderr, "Failed to create GLFW window! \n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//window created
	return window;
}


