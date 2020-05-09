#include <Engine/Core/Model/Application.hpp>

orb::GameLoop &orb::Application::getLoop()
{
	return m_gameLoop;
}

orb::Application::Application(GameWindow &window, RenderApi &renderApi)
		: m_gameLoop(window), m_renderApi(renderApi)
{
}

void orb::Application::run(orb::Scene &scene)
{
	getLoop().pushScene(scene);
}
