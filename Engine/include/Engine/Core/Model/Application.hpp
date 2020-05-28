#pragma once
#include "GameLoop.hpp"
#include "Events/Obervable.hpp"
#include <Engine/Core/Renderer/RenderApi.hpp>
#include "ResizeHandler.hpp"

namespace orb
{
	class Application
	{
	public:
		Application(RenderApi& renderApi, GameWindow& window);
	public:
		void run(Scene& scene);
		GameLoop& getLoop();
	private:
		GameLoop m_gameLoop;
		std::reference_wrapper<RenderApi> m_renderApi;
		std::reference_wrapper<GameWindow> m_gameWindow;
	};
}
