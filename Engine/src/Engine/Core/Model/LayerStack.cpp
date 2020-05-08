#include <Engine/Core/Model/LayerStack.hpp>

void orb::LayerStack::pushLayer(Layer& layer)
{
	m_stack.emplace_back(layer);
}

void orb::LayerStack::popLayer()
{
	m_stack.pop_back();
}
