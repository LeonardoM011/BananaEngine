#include "BaseGame.h"

BaseGame::BaseGame() {
}

BaseGame::~BaseGame() {

}

// Function main is the first thing that's being called in the program
void BaseGame::main() {
	std::cout << "BananaEngine: Version 0.1.2-alpha" << std::endl;
}

// Start gets called just before main game loop
void BaseGame::Start() {
	
}

// Update gets called every frame
void BaseGame::Update() {

}

// OnWindowCreation gets called just before creating a window so we can set some peramaters
Banana::WinInfo BaseGame::OnWindowCreation() {
	return Banana::WinInfo("BananaEngine: Version 0.1.2-alpha", 800, 600);
}
