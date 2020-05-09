#include <Engine/Core/Model/Input/KeyboardKeyEvent.hpp>

orb::KeyboardKeyEvent::KeyboardKeyEvent(orb::KeyboardKey key, orb::InputType type)
		: m_key(key), m_type(type)
{

}

orb::KeyboardKey orb::KeyboardKeyEvent::getKey() const
{
	return m_key;
}

orb::InputType orb::KeyboardKeyEvent::getType() const
{
	return m_type;
}
