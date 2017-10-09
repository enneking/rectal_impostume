#include "GameLoop.h"


#include <iostream>

//constructor
RaptorEngine::Core::GameLoop::GameLoop()
{
	//empty
}

//destructor
RaptorEngine::Core::GameLoop::~GameLoop()
{
	//empty
}

void RaptorEngine::Core::GameLoop::run()
{
	//initialize the game
	initSystems();

	//start the game loop
	loop();
}

void RaptorEngine::Core::GameLoop::initSystems()
{
	m_oWindowManager.init();

	glfwWindowHint(GLFW_SAMPLES, 4); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_oWindow = m_oWindowManager.createGLFWwindow(m_iScreenWidth,
		m_iScreenHeight, "Game");

	glfwMakeContextCurrent(m_oWindow);
	glfwSwapInterval(1);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		exit(EXIT_FAILURE);
	}

	m_oInput.init(m_oWindow);

	m_oCamera.resizeCallback(70.0f, m_iScreenWidth / static_cast<float>(m_iScreenHeight), 0.1f, 100.0f, m_iScreenWidth, m_iScreenHeight);
}

void RaptorEngine::Core::GameLoop::loop()
{

	const float dt = m_fDeltaTime;

	std::chrono::system_clock::time_point CurrentTime = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point NewTime;
	std::chrono::duration<double> LagTime;
	double accumulator = dt;

	//GAME-LOOP
	while (m_bRun == true)
	{

		//update the InputManager
		m_oInput.update();

		//Game loop body

		NewTime = std::chrono::system_clock::now();
		LagTime = std::chrono::duration_cast<std::chrono::duration<float>>(NewTime - CurrentTime);
		if (LagTime.count() > 0.25)
			accumulator += 0.25;
		CurrentTime = NewTime;
		accumulator += LagTime.count();

		while (accumulator >= dt)
		{
			accumulator -= dt;
			//physics
		}

		//draw the current screen
		m_oCamera.zoom(m_oWindow);

		drawScene();

		//opengl and glfw stuff
		glfwSwapBuffers(m_oWindow);
		glfwPollEvents();

		//Should game exit
		if (glfwWindowShouldClose(m_oWindow))
		{
			m_bRun = false;
		}
	}

	//Clean-Up
	g_exit();

}

void RaptorEngine::Core::GameLoop::drawScene()
{


	//draw code goes here
	glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//render our game objects

}


void RaptorEngine::Core::GameLoop::g_exit()
{
	//cleanup glfw
	glfwDestroyWindow(m_oWindow);
	glfwTerminate();
}

