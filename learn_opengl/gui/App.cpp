#include "App.hpp"

#include <iostream>

void App::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

App::App(std::string title, int width, int height) {
	this->title = title;
	this->width = width;
	this->height = height;

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(window);
	if (!gladLoaderLoadGL()) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		exit(1);
	}

	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(window, this->framebuffer_size_callback);
}

App::~App() {
	glfwTerminate();
}

bool App::shouldClose() {
	return glfwWindowShouldClose(window);
}

void App::processInput() {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void App::poolEvents() {
	glfwPollEvents();
	glfwSwapBuffers(window);
}
