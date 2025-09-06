#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <string>

class App {
private:
	int width;
	int height;
	std::string title;
	GLFWwindow* window;

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

public:
	App(std::string title, int width, int height);
	~App();

	bool shouldClose();
	void processInput();
	void poolEvents();
};

