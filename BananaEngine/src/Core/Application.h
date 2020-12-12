#pragma once

namespace Banana {

	// This is a parent interface class for client main class.
	// You have to add pure virtual functions manually for every callback also like in Callback.h
	class Application {
	public:
		// Pure virtual functions to add manually (also add in Callback.h):
		virtual void main() = 0;
		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual WinInfo OnWindowCreation() = 0;
		// ------------
	};

	// To be defined in client header file (mandatory).
	Application* CreateApplication();
}
