#include <Engine/Core/Model/Layer.hpp>

orb::Layer::Layer(orb::RenderTarget& target)
		: m_renderTarget(&target)
{
}

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

orb::RenderTarget &orb::Layer::getRenderTarget()
{
	return *m_renderTarget;
}

void orb::Layer::stop()
{
	m_shouldRun = false;
}

bool orb::Layer::shouldRun() const
{
	return m_shouldRun;
}
