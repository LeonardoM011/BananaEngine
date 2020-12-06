#pragma once


namespace Banana {
	extern Application* CreateApplication();

	// This class is made for the callback functions for the client class.
	// When creating callbacks you have to add all functions here manually like in Application.h
	class Callback {
	public:
		Callback() {
			m_App = CreateApplication();
		}
		~Callback() {
			delete m_App;
		}

		// Callbacks to add manually (also add in Application.h)
		void main() { m_App->main(); }
		void Start() { m_App->Start(); }
		void Update() { m_App->Update(); }
		// ------------

	private:
		Application* m_App;
	};
}
