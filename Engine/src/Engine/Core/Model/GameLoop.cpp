#include <Engine/Core/Model/GameLoop.hpp>

void orb::GameLoop::pushScene(Scene &scene)
{
	scene.load();

	while (scene.shouldRun() && !m_shouldPop && m_shouldRun && !m_nextScene.has_value())
	{
		for (auto &layer : scene.getLayers())
		{
			layer.update(TimeStep());
		}

		for (auto &layer : scene.getLayers())
		{
			layer.render();
		}
	}

	scene.unload();

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
