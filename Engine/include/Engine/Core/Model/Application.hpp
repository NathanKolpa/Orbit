#pragma once
#include "GameLoop.hpp"
#include "Events/Obervable.hpp"
#include <Engine/Core/Renderer/RenderApi.hpp>

namespace orb
{
	class Application
	{
	public:
		Application(GameWindow& window);
	public:
		void run(Scene& scene);
		GameLoop& getLoop();
	private:
		GameLoop m_gameLoop;
	};
}
