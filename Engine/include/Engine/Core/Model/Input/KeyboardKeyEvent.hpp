#pragma once

#include "KeyboardKey.hpp"
#include "InputType.hpp"
#include "Event.hpp"

namespace orb
{
	class KeyboardKeyEvent : public Event
	{
	public:
		KeyboardKeyEvent(KeyboardKey key, InputType type);
	public:
		KeyboardKey getKey() const;
		InputType getType() const;
	private:
		KeyboardKey  m_key;
		InputType m_type;
	};
}