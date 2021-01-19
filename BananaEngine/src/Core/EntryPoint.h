#pragma once
#include "Core/ClientCallbacks.h"

int main(int argc, char** argv) {
	// Client callback
	::Main();

	Banana::Application::Get().Start();
	return 0;
}
