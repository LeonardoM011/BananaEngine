#include "pch.h"
#include "GraphicsContext.h"

namespace Banana {
	// Instantiating Instance to be null 
	GraphicsContext* GraphicsContext::s_Instance = nullptr;

	int GraphicsContext::Init() {
		// Load all GL functions
		if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			printf("Error: Glad could not be initialized!");
			glfwTerminate();
			return -1;
		}
		return 0;
	}

	void GraphicsContext::Prepare() {
		glClearColor(1.0f, 0.3f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}
