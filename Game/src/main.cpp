#include <Engine/Engine.hpp>
#include "TestLayer.hpp"

void run();

int main()
{
	try
	{
		orb::GlfwGameWindow::initLibrary();
		run();
		orb::GlfwGameWindow::destroyLibrary();

		std::cout << "Exited gracefully" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exited with exception: " << e.what() << std::endl;
	}

}

void run()
{
	orb::GlfwGameWindow glfwWindow = orb::GlfwGameWindow::createGlfwWindow(1280, 720, "Hello World");
	glfwWindow.setContext();

	orb::OpenGLApi opengl = orb::OpenGLApi::create();
	std::cout << "Using OpenGL version: [" << opengl.getVersionString() << "]" << std::endl;

	orb::Renderer2D renderer(opengl);
	orb::Application app(opengl, glfwWindow);

	orb::Scene scene;
	TestLayer layer(renderer);
	scene.getLayers().pushLayer(layer);

	app.run(scene);
}

/*

 TODO: test multiple buffer layouts

*/