#pragma once
#include "RenderTarget.hpp"
#include "Engine/Core/Model/Timing/TimeStep.hpp"
#include "Engine/Core/Model/Input/InputObserver.hpp"

namespace orb
{
	class Layer : public InputObserver
	{
	public:
		explicit Layer(RenderTarget& target);
	public:
		virtual void load();
		virtual void unload();

		virtual void render();
		virtual void update(TimeStep& step);

		RenderTarget& getRenderTarget();

		void stop();
		bool shouldRun() const;

		void onNext(MouseMoveEvent &event) override;
		void onNext(KeyboardKeyEvent &event) override;
		void onNext(MouseButtonEvent &event) override;
	private:
		RenderTarget* m_renderTarget;
		bool m_shouldRun = true;
	};
}