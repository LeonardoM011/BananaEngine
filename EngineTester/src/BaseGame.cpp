#pragma once
#include <iostream>
#include <BananaEngine.h>

// Functions should return 0 if everything went well
// If it returns something else it is considered to be an error

// Main gets called before everything else
void Main() {
	std::cout << "BananaEngine: Version 0.2.1-alpha" << std::endl;
}

// Start gets called just before main game loop when everything else is initialized
int Start() {
	//std::cout << "Start\n";
	return 0;
}

// Update gets called every frame
int Update() {
	//std::cout << "Update\n";
	return 0;
}

// OnWindowCreation gets called just before creating a window so we can set some peramaters
int OnWindowCreation(std::string& title, unsigned int& width, unsigned int& height) {
	title = "BananaEngine: Version 0.2.1-alpha";
	width = 800;
	height = 600;
	//std::cout << "OnWindowCreation\n";
	return 0;
}

int OnKeyPress(int key, int scancode, int action, int mods) {
	std::cout << key << std::endl;
	return 0;
}
