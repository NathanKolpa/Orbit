#include <Engine/Core/Model/Input/Event.hpp>

void orb::Event::consume()
{
	m_isConsumed = true;
}

bool orb::Event::isConsumed() const
{
	return m_isConsumed;
}
