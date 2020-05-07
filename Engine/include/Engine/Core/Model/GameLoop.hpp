#pragma once

#include "Scene.hpp"

namespace orb
{
	class GameLoop
	{
	public:
		void runScene(Scene& scene);
		void swapScene(Scene& scene);

		void stop();
	private:
		bool m_shouldRun = true;
		std::optional<Scene> m_nextScene;
	};
}