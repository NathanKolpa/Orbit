#include <Engine/Core/Model/Application.hpp>

orb::GameLoop &orb::Application::getLoop()
{
	return m_gameLoop;
}

orb::Application::Application(RenderApi& renderApi, GameWindow &window)
		: m_gameLoop(window, renderApi), m_renderApi(renderApi), m_gameWindow(window)
{
}

void orb::Application::run(orb::Scene &scene)
{
	ResizeHandler resizeHandler(m_renderApi);

	auto resizeSub = m_gameWindow.get().getResizeObservable().subscribe(resizeHandler);
	auto mouseMoveSub = m_gameWindow.get().getMouseMoveObservable().subscribe(getLoop());
	auto keySub = m_gameWindow.get().getKeyboardKeyObservable().subscribe(getLoop());
	auto buttonSub = m_gameWindow.get().getMouseButtonEmitter().subscribe(getLoop());

	getLoop().pushScene(scene);
}
