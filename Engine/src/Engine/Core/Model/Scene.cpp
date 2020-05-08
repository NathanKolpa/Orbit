#include <Engine/Core/Model/Scene.hpp>

void orb::Scene::load()
{
	for (auto &layer : m_layerStack)
	{
		layer.get().load();
	}
}

void orb::Scene::unload()
{
	for (auto &layer : m_layerStack)
	{
		layer.get().unload();
	}
}

orb::LayerStack &orb::Scene::getLayers()
{
	return m_layerStack;
}

bool orb::Scene::shouldRun() const
{
	for(auto& layer : m_layerStack)
	{
		if(!layer.get().shouldRun())
		{
			return false;
		}
	}

	return true;
}

void orb::Scene::update(TimeStep step)
{
	for (auto &layer : m_layerStack)
	{
		layer.get().update(step);
	}
}

void orb::Scene::render()
{
	for (auto &layer : m_layerStack)
	{
		layer.get().render();
	}
}
