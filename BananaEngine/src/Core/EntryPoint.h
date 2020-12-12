#pragma once

int main(int argc, char** argv) {
	// *** Callback Class ***
	Banana::Callback cb;
	cb.main();
	// *** Window Class ***
	Banana::Window window;
	Banana::WinInfo wInfo;
	wInfo =	cb.OnWindowCreation();
	window.CreateWindow(wInfo.width, wInfo.height, wInfo.title);
	// Main Game Loop
	cb.Start();
	while(!window.WindowShouldClose()) {
		// Prepare context for rendering
		glClearColor(1.0f, 0.3f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		cb.Update();
	
		window.SwapBuffers();
	}
	return 0;
}
