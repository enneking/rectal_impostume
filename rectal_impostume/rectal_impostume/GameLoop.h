#pragma once

//opengl
#include <GL/glew.h>  
#include <GLFW/glfw3.h>

//std libs
#include <stdlib.h>
#include <stdio.h>
#include <chrono>

#include "windowManager.h"
#include "Input.h"
#include "Camera.h"

namespace RaptorEngine {
namespace Core{
	class GameLoop {
	public:
		// con-\destructor
		GameLoop();
		~GameLoop();

		void run();
		void initSystems();
		void loop();
		void drawScene();
		void g_exit();

	private:
		const float m_fDeltaTime = 1/60.0f;
		bool m_bRun = true;
		GLFWwindow* m_oWindow = nullptr;
		WindowManager m_oWindowManager;
		GLsizei m_iScreenWidth = 1280;
		GLsizei m_iScreenHeight = 720;
		Input m_oInput;
		Camera m_oCamera;
};
};
};

