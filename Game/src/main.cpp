#include <Engine/Engine.hpp>
#include "TestLayer.hpp"

int main()
{
	orb::GlfwGameWindow::initLibrary();
	orb::GlfwGameWindow gameWindow = orb::GlfwGameWindow::createGlfwWindow(1280, 720, "Hello World");
	orb::OpenGLApi opengl = orb::OpenGLApi::create(gameWindow);

	std::cout << "Using OpenGL version: [" << opengl.getVersionString() << "]" << std::endl;

	orb::Renderer2D renderer(opengl);

	orb::Application app(gameWindow);

	// TODO: deze code uit de main
	auto mouseMoveSub = gameWindow.getMouseMoveObservable().subscribe(app.getLoop());
	auto keySub = gameWindow.getKeyboardKeyObservable().subscribe(app.getLoop());
	auto buttonSub = gameWindow.getMouseButtonEmitter().subscribe(app.getLoop());

	orb::Scene scene;
	TestLayer layer(renderer);
	scene.getLayers().pushLayer(layer);

	app.run(scene);

	orb::GlfwGameWindow::destroyLibrary();
}