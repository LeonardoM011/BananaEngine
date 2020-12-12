#include "BaseGame.h"

BaseGame::BaseGame() {
}

BaseGame::~BaseGame() {

}

void BaseGame::main() {
	std::cout << "BananaEngine: Version 0.1.1-alpha" << std::endl;
}

void BaseGame::Start() {
	
}

void BaseGame::Update() {

}

Banana::WinInfo BaseGame::OnWindowCreation() {
	return Banana::WinInfo("BananaEngine: Version 0.1.1-alpha", 800, 600);
}
