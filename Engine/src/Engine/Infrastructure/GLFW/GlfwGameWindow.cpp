#include <Engine/Infrastructure/GLFW/GlfwGameWindow.hpp>
#include <GLFW/glfw3.h>

orb::GlfwGameWindow orb::GlfwGameWindow::createGlfwWindow(int width, int height, const char *title)
{
	GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window)
	{
		throw std::runtime_error("cannot create GLFW window");
	}

	return GlfwGameWindow(window, width, height, title);
}

orb::GlfwGameWindow::GlfwGameWindow(GLFWwindow *window, int width, int height, const char* title)
		: m_width(width), m_window(window), m_height(height), m_title(title)
{
}


orb::GlfwGameWindow::~GlfwGameWindow()
{
	glfwDestroyWindow(m_window);
}

void orb::GlfwGameWindow::bindContext()
{

}

void orb::GlfwGameWindow::unbindContext()
{

}

void orb::GlfwGameWindow::clear()
{

}

int orb::GlfwGameWindow::getWidth()
{
	return 0;
}

int orb::GlfwGameWindow::getHeight()
{
	return 0;
}

void orb::GlfwGameWindow::pollEvents()
{
	glfwPollEvents();
}

void orb::GlfwGameWindow::destroyLibrary()
{
	glfwTerminate();
}

void orb::GlfwGameWindow::initLibrary()
{
	if (!glfwInit())
	{
		throw std::runtime_error("cannot init GLFW");
	}
}

bool orb::GlfwGameWindow::isOpen()
{
	return !glfwWindowShouldClose(m_window);
}

void orb::GlfwGameWindow::display()
{
	glfwSwapBuffers(m_window);
}
