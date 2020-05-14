#include <Engine/Engine.hpp>
#include "TestLayer.hpp"

void run();

int main()
{
	try
	{
		run();

		std::cout << "Exited gracefully" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exited with exception: " << e.what() << std::endl;
	}

}

void run()
{
	orb::GlfwGameWindow::initLibrary();
	orb::GlfwGameWindow gameWindow = orb::GlfwGameWindow::createGlfwWindow(1280, 720, "Hello World");

	orb::OpenGLApi opengl = orb::OpenGLApi::create(gameWindow);
	std::cout << "Using OpenGL version: [" << opengl.getVersionString() << "]" << std::endl;

	orb::Renderer2D renderer(opengl);
	orb::Application app(opengl, gameWindow);

	orb::Scene scene;
	TestLayer layer(renderer);
	scene.getLayers().pushLayer(layer);

	app.run(scene);

	orb::GlfwGameWindow::destroyLibrary();
}

/*

 TODO: test multiple layouts

*/