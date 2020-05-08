#pragma once

#include <Engine/Core/pch.hpp>

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
	};
}