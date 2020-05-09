#include <Engine/Core/Model/GameLoop.hpp>

void orb::GameLoop::pushScene(Scene &scene)
{
	Scene* lastScene = m_topScene;
	m_topScene = &scene;

	scene.load();

	{
		while (scene.shouldRun() && !m_shouldPop && m_shouldRun && !m_nextScene.has_value() && m_gameWindow->isOpen())
		{
			m_gameWindow->pollEvents();

			scene.update(TimeStep());

			scene.render();

			m_gameWindow->display();
		}
	}

	scene.unload();

	m_topScene = lastScene;

	if (m_nextScene.has_value())
	{
		pushScene(m_nextScene.value());
		m_nextScene.reset();
	}

	if(m_shouldPop)
	{
		m_shouldPop = false;
	}
}

void orb::GameLoop::stop()
{
	m_shouldRun = false;
}

void orb::GameLoop::swapScene(orb::Scene &scene)
{
	m_nextScene = scene;
}

void orb::GameLoop::popScene()
{
	m_shouldPop = true;
}

orb::GameLoop::GameLoop(orb::GameWindow &window)
	:m_gameWindow(&window)
{

}

orb::Scene &orb::GameLoop::getCurrentScene()
{
	return *m_topScene;
}

void orb::GameLoop::onNext(orb::MouseMoveEvent &event)
{
	if(m_topScene)
	{
		m_topScene->getLayers().onNext(event);
	}
}

void orb::GameLoop::onNext(orb::KeyboardKeyEvent &event)
{
	if(m_topScene)
	{
		m_topScene->getLayers().onNext(event);
	}
}

void orb::GameLoop::onNext(orb::MouseButtonEvent &event)
{
	if(m_topScene)
	{
		m_topScene->getLayers().onNext(event);
	}
}
