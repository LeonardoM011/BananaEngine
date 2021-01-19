#pragma once
#include <iostream>

namespace Banana {
	// We're Creating a simple Singleton Class.
	class Renderer {
	// Everything goes in here
	public:

	private:

	// Things that make this function singleton
	public:
		// Marking Copy Constructor as a Delete for Safety Purposes.
		Renderer(const Renderer&) = delete;
		// Get's Purpose is to Get Instance of this Singleton Renderer Class So You Can Retrieve Functions and Data
		// Example: Renderer::Get().foo();
		static Renderer& Get() { 
			// If Instance Doesn't Exist Create One and return it
			if(!s_Instance)
				s_Instance = new Renderer;
			return *s_Instance; 
		}
	private:
		// Setting Constructor to Private so it can't be Instatianted.
		Renderer() {}

		static Renderer* s_Instance;
	};
}
