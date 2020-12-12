#pragma once

namespace Banana {

	struct WinInfo {
		const char* title;
		int width;
		int height;

		WinInfo(const char* Title, int Width, int Height) :
			title(Title),
			width(Width),
			height(Height) {}
		
		WinInfo() :
			title(""),
			width(0),
			height(0) {}
	};

	// Class for handling window and window events
	class Window {
	public:
		Window();
		~Window();
		int CreateWindow(int width, int height, const char* title);
		bool WindowShouldClose();
		void SwapBuffers();
	private:
		GLFWwindow* m_Window;
		WinInfo m_WinInfo;
	};
}
