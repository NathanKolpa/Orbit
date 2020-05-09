#include <Engine/Core/Model/LayerStack.hpp>

void orb::LayerStack::pushLayer(Layer& layer)
{
	m_stack.emplace_back(layer);
}

void orb::LayerStack::popLayer()
{
	m_stack.pop_back();
}

void orb::LayerStack::onNext(orb::MouseMoveEvent &event)
{
	passEvent(event);
}

void orb::LayerStack::onNext(orb::KeyboardKeyEvent &event)
{
	passEvent(event);
}

void orb::LayerStack::onNext(orb::MouseButtonEvent &event)
{
	passEvent(event);
}
