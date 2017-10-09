#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

// OpenGL Math:
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace RaptorEngine {
	namespace Core {
		class Camera {

		public:

			void zoom(GLFWwindow* window); ///< enables to move and rotate the camera around of its axes
			glm::mat4 getViewMatrix() { return m_viewMatrix; } ///< get the look at matrix from the current camera data
			glm::vec3 getEyePos() { return m_position; }
			glm::vec3 getLookatPoint() { return m_viewDir; }
			glm::mat4 getProjectionMatrix() { return m_projectionMatrix; }
			void resizeCallback(float phiInDegree, float aspectRatio, float near, float far, GLsizei width, GLsizei height);

		private:
			double m_cursorX;
			double m_cursorY;
			double m_prevCursorX = 0;
			double m_prevCursorY = 0;
			double m_cameraSpeed = 0.05f;
			double m_rotationSpeed = 0.5f;
			glm::vec3 m_viewDir = glm::vec3(0.5f, -0.5f, 0.0f);
			glm::vec3 m_right = glm::vec3(1.0f, 0.0f, 0.0f);;
			glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);
			glm::vec3 m_position = glm::vec3(0.5f, -0.5f, 1.5f);
			glm::mat4 m_viewMatrix = glm::lookAt(m_position, m_position + m_viewDir, m_up); ///< view matrix
			glm::mat4 m_projectionMatrix;
			double m_rX = 0.0f, m_rY = 0.0f, m_rZ = 0.0f;
			bool m_pressed = false;

			void move(glm::vec3 direction);
			void rotateX(double angle);
			void rotateY(double angle);
			void rotateZ(double angle);

			void moveForward(double distance);
			void moveUpward(double distance);
			void strafeRight(double distance);


		};
	};
};

