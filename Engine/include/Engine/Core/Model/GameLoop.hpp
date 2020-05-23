#pragma once

#include <Engine/Core/Renderer/RenderApi.hpp>
#include "Scene.hpp"
#include "Window/GameWindow.hpp"

namespace orb
{
	class GameLoop : public InputObserver
	{
	public:
		GameLoop(GameWindow& window, RenderApi& api);
	public:
		void popScene();
		void pushScene(Scene& scene);
		void swapScene(Scene& scene);

		void stop();
		Scene& getCurrentScene();

		void onNext(MouseMoveEvent &event) override;
		void onNext(KeyboardKeyEvent &event) override;
		void onNext(MouseButtonEvent &event) override;
	private:
		bool m_shouldRun = true;
		bool m_shouldPop = false;
		std::optional<Scene> m_nextScene;
		Scene* m_topScene = nullptr;
		GameWindow* m_gameWindow;
		std::reference_wrapper<RenderApi> m_renderApi;
	};
}