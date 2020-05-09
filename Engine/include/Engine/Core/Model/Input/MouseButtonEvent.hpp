#pragma once

#include "MouseButton.hpp"
#include "InputType.hpp"
#include "Event.hpp"

namespace orb
{
	class MouseButtonEvent : public Event
	{
	public:
		MouseButtonEvent(MouseButton button, InputType type);
	public:
		MouseButton getButton() const;
		InputType getType() const;
	private:
		MouseButton m_button;
		InputType m_type;
	};
}