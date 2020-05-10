#include <Engine/Core/Model/Layer.hpp>

void orb::Layer::unload()
{
}

void orb::Layer::load()
{
}

void orb::Layer::render()
{
}

void orb::Layer::update(orb::TimeStep& step)
{
}

void orb::Layer::stop()
{
	m_shouldRun = false;
}

bool orb::Layer::shouldRun() const
{
	return m_shouldRun;
}

void orb::Layer::onNext(orb::MouseMoveEvent &event)
{

}

void orb::Layer::onNext(orb::KeyboardKeyEvent &event)
{

}

void orb::Layer::onNext(orb::MouseButtonEvent &event)
{

}
