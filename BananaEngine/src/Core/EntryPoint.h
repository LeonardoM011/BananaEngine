#pragma once

int main(int argc, char** argv) {
	// *** Callback Class ***
	Banana::Callback cb;
	cb.main();
	// *** Window Class ***
	Banana::Window window;
	window.Init();
	Banana::WinInfo wInfo;
	wInfo =	cb.OnWindowCreation();
	window.CreateWindow(wInfo.width, wInfo.height, wInfo.title);
	// Creating context
	Banana::GraphicsContext context;
	context.Init();
	// Main Game Loop
	cb.Start();
	while(!window.WindowShouldClose()) {
		context.Prepare();

		cb.Update();

		window.SwapBuffers();
	}
	return 0;
}
