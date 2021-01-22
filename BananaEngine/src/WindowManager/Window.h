#pragma once

namespace Banana {


	class Window {
	public:
		Window();
		~Window();
		void Init();
		int GenerateWindow(int width, int height, const char* title);
		bool WindowShouldClose();
		void SwapBuffers();
		std::string GetTitle() { return m_Title; }
		unsigned int GetWidth() { return m_Width; }
		void SetWidth(unsigned int width) { m_Width = width; }
		unsigned int GetHeight() { return m_Height; }
		void SetHeight(unsigned int height) { m_Height = height; }

	public:
		// These functions are used for glfw callbacks
		void OnKeyPressCallback(int key, int scancode, int action, int mods);
	private:
		GLFWwindow* m_Window;
		std::string m_Title;
		unsigned int m_Width;
		unsigned int m_Height;
		std::vector<std::function<void(void)>> m_FunctionCallbackFn;
	};
}
