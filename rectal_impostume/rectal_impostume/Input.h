#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

/**
* InputManager based on GLFW
* Key functions may not register all
* keys if the polling in the Game-Loop
* runs to slow.
*
* Callback functions are implemented
* here and may be used if the key
* functions fail.
*/

namespace RaptorEngine {
	namespace Core {
		class Input
		{
		public:
			void init(GLFWwindow* window);   ///< initialize Inputmanager
			void update();                   ///< updates the InputManager
			bool isKeyPressed(int key);      ///< check if key was just pressed
			bool isKeyDown(int key);         ///< check if key is currently hold down
			bool isKeyReleased(int key);     ///< check if key was just released

											 //getters
			glm::vec2 getMouseCoords() const { return m_mouseCoords; } ///< returns the current mouse position

																	   /*
																	   * Functions to add additional pointers
																	   * in the InputManager go below here
																	   */
																	   //---Pointer Setters---

																	   //---------------------

		private:
			GLFWwindow* m_window = nullptr;             ///< pointer to the game window
			glm::vec2 m_mouseCoords = glm::vec2(0.0f);  ///< current mouse coords

														//used to update m_mouseCoords
			double m_mouseX;                            ///< current mouse X coord
			double m_mouseY;                            ///< current mouse Y coord

														/*
														* Pointers to objects, which need to
														* be manipulated in the callback
														* functions, go below here.
														*/
														//---Pointer Area---

														//------------------
		};
	};
};