#include <Engine/Core/Model/LayerStack.hpp>

orb::Layer& orb::LayerStack::pushLayer(RenderTarget& target)
{
	return m_stack.emplace_back(Layer(&target));
}

void orb::LayerStack::popLayer()
{
	m_stack.pop_back();
}
