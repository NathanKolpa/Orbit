#include <Engine/Core/Model/Scene.hpp>

void orb::Scene::load()
{

}

void orb::Scene::unload()
{
}

orb::LayerStack &orb::Scene::getLayers()
{
	return m_layerStack;
}

bool orb::Scene::shouldRun() const
{
	for(auto& layer : m_layerStack)
	{
		if(!layer.shouldRun())
		{
			return false;
		}
	}

	return true;
}
