/*
* Camera.cpp
*
*  Created on: Dec 4, 2015
*      Author: alexander
*/

#include "Camera.h"

#define PI 3.14159265



/**
* move around camera
*/
void RaptorEngine::Core::Camera::zoom(GLFWwindow* window) {

	glfwGetCursorPos(window, &m_cursorY, &m_cursorX);

	if (glfwGetKey(window, 'C') == GLFW_PRESS)
	{
		m_cameraSpeed += 0.0001f;
	}
	if (glfwGetKey(window, 'X') == GLFW_PRESS)
	{
		m_cameraSpeed -= 0.0001f;
	}

	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		m_cameraSpeed = 0.2f;
	}

	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
	{
		m_cameraSpeed = 0.05f;
	}

	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
	{
		m_cameraSpeed = 0.005f;
	}



	if (glfwGetKey(window, 'W') == GLFW_PRESS)
	{
		moveForward(m_cameraSpeed);
	}
	if (glfwGetKey(window, 'S') == GLFW_PRESS)
	{
		moveForward(-m_cameraSpeed);
	}
	if (glfwGetKey(window, 'A') == GLFW_PRESS)
	{
		strafeRight(-m_cameraSpeed);
	}
	if (glfwGetKey(window, 'D') == GLFW_PRESS)
	{
		strafeRight(m_cameraSpeed);
	}
	if (glfwGetKey(window, 'R') == GLFW_PRESS)
	{
		moveUpward(m_cameraSpeed);
	}
	if (glfwGetKey(window, 'F') == GLFW_PRESS)
	{
		moveUpward(-m_cameraSpeed);
	}
	rotateY(0.05*(m_prevCursorY - m_cursorY));
	rotateX(0.05*(m_prevCursorX - m_cursorX));
	if (glfwGetKey(window, 'Q') == GLFW_PRESS)
	{
		rotateZ(m_rotationSpeed * 10.0f);
	}
	if (glfwGetKey(window, 'E') == GLFW_PRESS)
	{
		rotateZ(-m_rotationSpeed * 10.0f);
	}



	//point at which the camera looks:
	glm::vec3 viewPoint = m_position + m_viewDir;
	m_viewMatrix = glm::lookAt(m_position, viewPoint, m_up);

	m_prevCursorX = m_cursorX;
	m_prevCursorY = m_cursorY;
}


void RaptorEngine::Core::Camera::move(glm::vec3 direction)
{
	m_position += direction;
}

void RaptorEngine::Core::Camera::rotateX(double angle)
{
	m_rX += angle;

	//Rotate viewdir around the right vector:
	m_viewDir = glm::normalize(m_viewDir * cos(angle * PI / 180.0f)
		+ m_up * sin(angle * PI / 180.0f));

	//now compute the new UpVector (by cross product)
	m_up = glm::cross(m_viewDir, m_right) * (-1.0f);
}

void RaptorEngine::Core::Camera::rotateY(double angle)
{
	m_rY += angle;

	//Rotate viewdir around the up vector:
	m_viewDir = glm::normalize(m_viewDir * cos(angle * PI / 180.0f)
		- m_right * sin(angle * PI / 180.0f));

	//now compute the new RightVector (by cross product)
	m_right = glm::cross(m_viewDir, m_up);
}

void RaptorEngine::Core::Camera::rotateZ(double angle)
{
	m_rZ += angle;

	//Rotate viewdir around the right vector:
	m_right = glm::normalize(m_right * cos(angle * PI / 180.0f)
		+ m_up * sin(angle * PI / 180.0f));

	//now compute the new UpVector (by cross product)
	m_up = glm::cross(m_viewDir, m_right) * (-1.0f);
}

void RaptorEngine::Core::Camera::moveForward(double distance)
{
	m_position += (m_viewDir * distance);
}

void RaptorEngine::Core::Camera::moveUpward(double distance)
{
	m_position += (m_up * distance);
}

void RaptorEngine::Core::Camera::strafeRight(double distance)
{
	m_position += (m_right * distance);
}

void RaptorEngine::Core::Camera::resizeCallback(float phiInDegree, float aspectRatio, float near, float far, GLsizei width, GLsizei height) {

	float phiHalfInRadians = 0.5f * phiInDegree * (3.14159265359f / 180.0f);
	float t = near * tan(phiHalfInRadians);
	float b = -t;
	float left = b * aspectRatio;
	float right = t * aspectRatio;

	glViewport(0, 0, width, height);
	m_projectionMatrix = glm::frustum(left, right, b, t, near, far);
}
