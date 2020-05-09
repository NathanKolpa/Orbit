#include <Engine/Infrastructure/GLFW/GlfwGameWindow.hpp>
#include <GLFW/glfw3.h>

orb::GlfwGameWindow orb::GlfwGameWindow::createGlfwWindow(int width, int height, const char *title)
{
	GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window)
	{
		throw std::runtime_error("cannot create GLFW window");
	}


	return GlfwGameWindow(window, width, height, title);
}

orb::GlfwGameWindow::GlfwGameWindow(GLFWwindow *window, int width, int height, const char *title)
		: m_width(width), m_window(window), m_height(height), m_title(title)
{
	glfwSetWindowUserPointer(window, this);

	glfwSetCursorPosCallback(window, [](GLFWwindow *window, double x, double y)
	{
		auto &self = *static_cast<GlfwGameWindow *>(glfwGetWindowUserPointer(window));

		MouseMoveEvent event(x, y, self.m_lastMouseX, self.m_lastMouseY);
		self.m_mouseMoveEmitter.emit(event);

		self.m_lastMouseX = x;
		self.m_lastMouseY = y;
	});

	glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scanCode, int action, int mods)
	{
		auto &self = *static_cast<GlfwGameWindow *>(glfwGetWindowUserPointer(window));

		try
		{
			KeyboardKeyEvent event(self.m_keyMapper.getKey(key), self.m_inputTypeMapper.getType(action));
			self.m_keyboardKeyEmitter.emit(event);
		}
		catch (std::invalid_argument &e)
		{
			std::wcerr << e.what() << std::endl;
		}
	});

	glfwSetMouseButtonCallback(window, [](GLFWwindow *window, int button, int action, int mods)
	{
		auto &self = *static_cast<GlfwGameWindow *>(glfwGetWindowUserPointer(window));

		try
		{
			MouseButtonEvent event(self.m_buttonMapper.getButton(button), self.m_inputTypeMapper.getType(action));
			self.m_mouseButtonEmitter.emit(event);
		}
		catch (std::invalid_argument &e)
		{
			std::wcerr << e.what() << std::endl;
		}
	});
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

orb::Observable<orb::KeyboardKeyEvent> &orb::GlfwGameWindow::getKeyboardKeyObservable()
{
	return m_keyboardKeyEmitter;
}

orb::Observable<orb::MouseMoveEvent> &orb::GlfwGameWindow::getMouseMoveObservable()
{
	return m_mouseMoveEmitter;
}

orb::Observable<orb::MouseButtonEvent> &orb::GlfwGameWindow::getMouseButtonEmitter()
{
	return m_mouseButtonEmitter;
}

void orb::GlfwGameWindow::setContext()
{
	glfwMakeContextCurrent(m_window);
}
