#include <Engine/Core/Model/GameLoop.hpp>

void orb::GameLoop::runScene(Scene& scene)
{
	scene.load();

	while(scene.shouldRun() && m_shouldRun && m_nextScene == nullptr)
	{
		for(auto& layer : scene.getLayers())
		{
			layer.update(TimeStep());
		}

		for(auto& layer : scene.getLayers())
		{
			layer.render();
		}
	}

	scene.unload();

	if(m_nextScene != nullptr)
	{
		runScene(*m_nextScene);

		delete m_nextScene;
		m_nextScene = nullptr;
	}
}

void orb::GameLoop::stop()
{
	m_shouldRun = false;
}

void orb::GameLoop::swapScene(orb::Scene *scene)
{
	m_nextScene = scene;
}
