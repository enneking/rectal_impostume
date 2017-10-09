#pragma once

#include <GLFW/glfw3.h>

namespace RaptorEngine {
	namespace Core {
		class WindowManager
		{
		public:
			void init();
			GLFWwindow* createGLFWwindow(int width, int height,
				const char* title,
				GLFWmonitor* monitor = NULL,
				GLFWwindow* share = NULL);
		};
	};
};