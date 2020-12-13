#pragma once

namespace Banana {

	struct WinInfo {
		const char* title;
		int width;
		int height;

		WinInfo(const char* Title="BananaEngine", int Width = 800, int Height = 600) :
			title(Title),
			width(Width),
			height(Height) {}
	};

	// Class for handling window and window events
	class Window {
	public:
		Window();
		~Window();
		void Init();
		int CreateWindow(int width, int height, const char* title);
		bool WindowShouldClose();
		void SwapBuffers();
		const char* GetTitle() { return m_WinInfo.title; }
		int GetWidth() { return m_WinInfo.width; }
		int GetHeight() { return m_WinInfo.height; }
	private:
		GLFWwindow* m_Window;
		WinInfo m_WinInfo;
	};
}
