#include <Engine/Core/Model/Application.hpp>

orb::GameLoop &orb::Application::getLoop()
{
	return m_gameLoop;
}

orb::Application::Application(GameWindow &window)
		: m_gameLoop(window)
{
}

void orb::Application::run(orb::Scene &scene)
{
	getLoop().pushScene(scene);
}
