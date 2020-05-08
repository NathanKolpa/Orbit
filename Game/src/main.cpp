#include <Engine/Engine.hpp>
#include "TestLayer.hpp"

int main()
{
	orb::GlfwGameWindow::initLibrary();
	{
		orb::GlfwGameWindow gameWindow = orb::GlfwGameWindow::createGlfwWindow(1280, 720, "Hello World");

		orb::Application app(gameWindow);
		orb::Scene scene;

		TestLayer layer(gameWindow);
		scene.getLayers().pushLayer(layer);

		auto unsub = gameWindow.subscribe(scene.getLayers());

		app.getLoop().pushScene(scene);
	}
	orb::GlfwGameWindow::destroyLibrary();
}