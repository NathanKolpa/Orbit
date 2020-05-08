#include <Engine/Engine.hpp>

int main()
{
	orb::GlfwGameWindow::initLibrary();
	{
		orb::GlfwGameWindow gameWindow = orb::GlfwGameWindow::createGlfwWindow(1280, 720, "Hello World");

		orb::Application app(gameWindow);
		orb::Scene scene;
		orb::Layer layer(gameWindow);
		scene.getLayers().pushLayer(layer);

		app.getLoop().pushScene(scene);
	}
	orb::GlfwGameWindow::destroyLibrary();
}