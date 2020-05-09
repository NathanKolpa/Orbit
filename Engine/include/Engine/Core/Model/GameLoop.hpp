#pragma once

#include "Scene.hpp"
#include "Window/GameWindow.hpp"

namespace orb
{
	class GameLoop : public Observer<MouseMoveEvent>
	{
	public:
		GameLoop(GameWindow& window);
	public:
		void popScene();
		void pushScene(Scene& scene);
		void swapScene(Scene& scene);

		void stop();
		Scene& getCurrentScene();

		void onNext(MouseMoveEvent &event) override;
	private:
		bool m_shouldRun = true;
		bool m_shouldPop = false;
		std::optional<Scene> m_nextScene;
		Scene* m_topScene = nullptr;
		GameWindow* m_gameWindow;
	};
}