#pragma once

#include <Engine/Core/pch.hpp>
#include <Engine/Core/Model/Events/Obervable.hpp>
#include "ResizeEvent.hpp"
#include <Engine/Core/Model/Input/KeyboardKeyEvent.hpp>
#include <Engine/Core/Model/Input/MouseMoveEvent.hpp>
#include <Engine/Core/Model/Input/MouseButtonEvent.hpp>

namespace orb
{
	class GameWindow
	{
	public:
		virtual int getWidth() = 0;
		virtual int getHeight() = 0;
		virtual void pollEvents() = 0;
		virtual bool isOpen() = 0;
		virtual void display() = 0;
		virtual void clearBuffer() = 0;

		virtual Observable<KeyboardKeyEvent>& getKeyboardKeyObservable() = 0;
		virtual Observable<MouseMoveEvent>& getMouseMoveObservable() = 0;
		virtual Observable<MouseButtonEvent>& getMouseButtonEmitter() = 0;
		virtual Observable<ResizeEvent>& getResizeObservable() = 0;
	};
}