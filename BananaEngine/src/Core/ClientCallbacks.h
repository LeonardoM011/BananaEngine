#pragma once

// Extern defs for client callback functions
extern void Main();
extern int Start();
extern int Update();
extern int OnWindowCreation(std::string& title, unsigned int& width, unsigned int& height);
extern int OnKeyPress(int key, int scancode, int action, int mods);