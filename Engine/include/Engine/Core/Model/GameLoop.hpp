#pragma once

#include "Scene.hpp"
#include "Window/GameWindow.hpp"

namespace orb
{
	class GameLoop
	{
	public:
		GameLoop(GameWindow& window);
	public:
		void popScene();
		void pushScene(Scene& scene);
		void swapScene(Scene& scene);

		void stop();
	private:
		bool m_shouldRun = true;
		bool m_shouldPop = false;
		std::optional<Scene> m_nextScene;
		GameWindow* m_gameWindow;
	};
}