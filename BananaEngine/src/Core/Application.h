#pragma once
#include "WindowManager/Window.h"

namespace Banana {
	// We're Creating a simple Singleton Application Class.
	// Application class is nothing more than a namespace that holds all the functions and variables in one place and keeps them organized
	class Application {
		// Everything goes in here
	public:
		void Start();
	private:
		void Init();
		void Run();
		void Close();
	private:
		bool isStarted = false;
		Window m_Window;
	public:
		// Things that make this function singleton
		// Marking Copy Constructor as a Delete for Safety Purposes.
		Application(const Application&) = delete;
		// Get's Purpose is to Get Instance of this Singleton Renderer Class So You Can Retrieve Functions and Data
		// Example: Renderer::Get().foo();
		static Application& Get() {
			// If instance doesn't exist create instance and return it
			if(!s_Instance)
				s_Instance = new Application;
			return *s_Instance;
		}
	private:
		// Setting Constructor to Private so it can't be Instatianted.
		Application() {}

		static Application* s_Instance;
	};
}