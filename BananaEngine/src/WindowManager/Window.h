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
		int GetWidth() { return m_Width; }
		int GetHeight() { return m_Height; }
	private:
		GLFWwindow* m_Window;
		std::string m_Title;
		unsigned int m_Width;
		unsigned int m_Height;
	};
}
