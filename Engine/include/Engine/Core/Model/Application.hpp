#pragma once
#include "GameLoop.hpp"

namespace orb
{
	class Application
	{
	public:
		Application(GameWindow& window);
	public:
		GameLoop& getLoop();
	private:
		GameLoop m_gameLoop;
	};
}
