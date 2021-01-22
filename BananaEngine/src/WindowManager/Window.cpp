#include "pch.h"
#include "Window.h"
#include "Core/ClientCallbacks.h"

namespace Banana {

	Window::Window() :
		m_Window(nullptr),
		m_Title(""),
		m_Width(0),
		m_Height(0) {}

	Window::~Window() {
		glfwTerminate();
	}

	void Window::Init() {
		// Initializing GLFW and setting compatibility with OpenGL 4.5
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_FunctionCallbackFn.push_back([]()->void {
			std::cout << "Hey";
		});
	}

	int Window::GenerateWindow(int width, int height, const char* title/*, Callback* callback*/) {
		m_Title = title;
		m_Width = width;
		m_Height = height;

		m_Window = glfwCreateWindow(width, height, title, NULL, NULL);

		if(m_Window == NULL) {
			printf("Error: Window could not be created!");
			glfwTerminate();
			return -1;
		}

		// Make the context of the current window current on the calling thread
		glfwMakeContextCurrent(m_Window);

		// Pass pointer to this class so we can use it from inside lambdas
		glfwSetWindowUserPointer(m_Window, this);

		// If window gets resized this lambda function gets called
		glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			// Get pointer to this class window then change width and height 
			Window& windowpt = *(Window*)glfwGetWindowUserPointer(window);
			windowpt.SetWidth(width);
			windowpt.SetHeight(height);

			// Specify window rectangle for renderings
			glViewport(0, 0, width, height);
		});

		// Callback that handles key input
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			// Get pointer to this class window
			Window& windowpt = *(Window*)glfwGetWindowUserPointer(window);
			// Call callback function
			windowpt.OnKeyPressCallback(key, scancode, action, mods);
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

	void Window::OnKeyPressCallback(int key, int scancode, int action, int mods) {
		// TODO: Do error checking and return value
		// TODO: Replace key codes with key names
		::OnKeyPress(key, scancode, action, mods);
	}
}
