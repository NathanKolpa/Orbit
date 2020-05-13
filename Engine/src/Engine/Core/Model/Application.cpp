#include <Engine/Core/Model/Application.hpp>

orb::GameLoop &orb::Application::getLoop()
{
	return m_gameLoop;
}

orb::Application::Application(RenderApi& renderApi, GameWindow &window)
		: m_gameLoop(window), m_renderApi(renderApi), m_gameWindow(window)
{
}

void orb::Application::run(orb::Scene &scene)
{
	ResizeHandler resizeHandler(m_renderApi);

	auto resizeSub = m_gameWindow.get().getResizeObservable().subscribe(resizeHandler);

	getLoop().pushScene(scene);
}
