#include "pch.h"
#include "Application.h"
#include "Base.h"
#include "ClientCallbacks.h"
#include "Renderer/GraphicsContext.h"

namespace Banana {
	// Instantiating instance to be null 
	Application* Application::s_Instance = nullptr;

	void Application::Start() {
		// If Start already called throw an error because there can't be more than one application in the program
		BN_THROW_ERROR("Critical", !isStarted, "Application function Start already called.");
		isStarted = true;

		Init();
		// Client callback
		::Start();
		Run();
		Close();
	}

	// Function for initiating our programs
	void Application::Init() {
		
		// Creating and setting parameters for window
		m_Window.Init();
		
		std::string title = "";
		unsigned int width = 400;
		unsigned int height = 200;

		// Client callback
		::OnWindowCreation(title, width, height);
		
		m_Window.GenerateWindow(width, height, title.c_str());

		GraphicsContext::Get().Init();
	}

	// Function that takes care of main game loop
	void Application::Run() {
		
		while(!m_Window.WindowShouldClose()) {
			GraphicsContext::Get().Prepare();

			// Client callback
			::Update();

			m_Window.SwapBuffers();
		}

	}

	// Mainly a cleanup function
	void Application::Close() {
		
	}
	
}
