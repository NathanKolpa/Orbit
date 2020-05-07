#pragma once
#include "GameLoop.hpp"

namespace orb
{
	class Application
	{
	public:
		GameLoop& getLoop();
	private:
		GameLoop m_gameLoop;
	};
}
