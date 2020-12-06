#pragma once
#include <BananaEngine.h>

class BaseGame : public Banana::Application {

public:
	BaseGame();
	~BaseGame();
private:
	// All callbacks have to be overriden here.
	void main() override;
	void Start() override;
	void Update() override;
};

// Returning pointer to base class application (this is mandatory)
Banana::Application* Banana::CreateApplication() {
	return new BaseGame();
}
