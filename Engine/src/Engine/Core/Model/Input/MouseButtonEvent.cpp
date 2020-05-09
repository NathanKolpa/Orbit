#include <Engine/Core/Model/Input/MouseButtonEvent.hpp>

orb::MouseButtonEvent::MouseButtonEvent(MouseButton button, InputType type)
	:m_button(button), m_type(type)
{

}

orb::MouseButton orb::MouseButtonEvent::getButton() const
{
	return m_button;
}

orb::InputType orb::MouseButtonEvent::getType() const
{
	return m_type;
}
