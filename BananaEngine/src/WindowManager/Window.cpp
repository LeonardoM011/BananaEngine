#include "pch.h"
#include "Window.h"

namespace Banana {

	Window::Window() :
		m_Window(nullptr),
		m_WinInfo("", 800, 600) {
	}

	Window::~Window() {
		glfwTerminate();
	}

	void Window::Init() {
		// Initializing GLFW and setting compatibility with OpenGL 4.5
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
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

		// Set window user pointer to WinInfo so we can get and set data from withing lambda function
		glfwSetWindowUserPointer(m_Window, &m_WinInfo);

		// Setting callback for when window gets resized
		glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			// Get window user pointer from above and set WinInfo width and height to new width and height
			WinInfo& info = *(WinInfo*)glfwGetWindowUserPointer(window);
			info.width = width;
			info.height = height;

			// Specify window rectangle for renderings
			glViewport(0, 0, width, height);
		});

		// TODO: Create a callback to client from this function so the client can decide how to handle input
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			//printf("%d", key);
		});

		return 0;
	}

	bool Window::WindowShouldClose() {
		// TODO: Split this function into window and EngineTester Class, this should not be here this is just for testing purposes
		if(glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(m_Window, true);

		return glfwWindowShouldClose(m_Window);
	}

	void Window::SwapBuffers() {
		// Swap buffer and check for input events
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}
}
