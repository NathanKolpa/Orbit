#pragma once

#include <Engine/Core/Model/Events/Observer.hpp>
#include <Engine/Core/Model/Input/MouseMoveEvent.hpp>
#include <Engine/Core/Model/Input/KeyboardKeyEvent.hpp>

namespace orb
{
	struct InputObserver : public Observer<MouseMoveEvent>, public Observer<KeyboardKeyEvent>
	{
		using Observer<KeyboardKeyEvent>::onNext;
		using Observer<MouseMoveEvent>::onNext;
	};
}