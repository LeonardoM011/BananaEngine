#pragma once

namespace Banana {

	// We're Creating a simple Singleton Class.
	class GraphicsContext {
		// Everything goes in here
	public:
		int Init();
		void Prepare();
	private:

		// Things that make this function singleton
	public:
		// Marking Copy Constructor as a Delete for Safety Purposes.
		GraphicsContext(const GraphicsContext&) = delete;
		// Get's Purpose is to Get Instance of this Singleton Renderer Class So You Can Retrieve Functions and Data
		// Example: Renderer::Get().foo();
		static GraphicsContext& Get() {
			// If Instance Doesn't Exist Create One and return it
			if(!s_Instance)
				s_Instance = new GraphicsContext;
			return *s_Instance;
		}
	private:
		// Setting Constructor to Private so it can't be Instatianted.
		GraphicsContext() {}

		static GraphicsContext* s_Instance;
	};
}
