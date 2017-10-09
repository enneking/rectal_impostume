#include "Input.h"

double Scrollbar_Value = 0.5; // should be replaced by an real scroll bar

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{

}

static void mouse_button_callback(GLFWwindow* window, int key, int action, int mods)
{

}

static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{

}

void RaptorEngine::Core::Input::init(GLFWwindow* window)
{
	m_window = window;
	//set the KeyCallback
	glfwSetKeyCallback(m_window, key_callback);
	//set the CursorCallback
	glfwSetCursorPosCallback(m_window, cursor_position_callback);
	//set the MouseButtonCallback
	glfwSetMouseButtonCallback(m_window, mouse_button_callback);
	//set the ScrollCallback
	glfwSetScrollCallback(m_window, scroll_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void RaptorEngine::Core::Input::update()
{
	//update cursor position
	glfwGetCursorPos(m_window, &m_mouseX, &m_mouseY);
	m_mouseCoords.x = (float)m_mouseX;
	m_mouseCoords.y = (float)m_mouseY;
}

bool RaptorEngine::Core::Input::isKeyPressed(int key)
{
	//get key state
	int state = glfwGetKey(m_window, key);

	if (state == GLFW_PRESS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool RaptorEngine::Core::Input::isKeyDown(int key)
{
	//get key state
	int state = glfwGetKey(m_window, key);

	if (state == GLFW_REPEAT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool RaptorEngine::Core::Input::isKeyReleased(int key)
{
	//get key state
	int state = glfwGetKey(m_window, key);

	if (state == GLFW_RELEASE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
