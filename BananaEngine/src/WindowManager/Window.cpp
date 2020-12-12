#include "pch.h"
#include "Window.h"

namespace Banana {

	Window::Window() :
		m_Window(nullptr),
		m_WinInfo("", 800, 600) {

		// Initializing GLFW and setting compatibility with OpenGL 3.3
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	Window::~Window() {
		glfwTerminate();
	}

	int Window::CreateWindow(int width, int height, const char* title) {
		m_WinInfo = WinInfo(title, width, height);

		m_Window = glfwCreateWindow(width, height, title, NULL, NULL);

		if(m_Window == NULL) {
			printf("Error: Window could not be created!");
			glfwTerminate();
			return -1;
		}

		// Make the context of the current window current on the calling thread
		glfwMakeContextCurrent(m_Window);
		//  Setting callback for when window gets resized
		glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			// TODO: Fix this lambda function and change WinInfo
			/*m_WinInfo.width = width;
			m_WinInfo.height = height;*/


			// Specify window rectangle for renderings
			glViewport(0, 0, width, height);
		});

		// TODO: Create seperate class for opengl initialization
		// Load all GL functions
		if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			printf("Error: Glad could not be initialized!");
			glfwTerminate();
			return -2;
		}

		return 0;
	}

	bool Window::WindowShouldClose() {
		return glfwWindowShouldClose(m_Window);

		// TODO: Split this function into window and EngineTester Class, this should not be here this is just for testing purposes
		if(glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(m_Window, true);
	}

	void Window::SwapBuffers() {
		// Swap buffer and check for input events
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}
}
