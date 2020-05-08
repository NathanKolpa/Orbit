#pragma once
#include "RenderTarget.hpp"
#include "Engine/Core/Model/Timing/TimeStep.hpp"
#include "Events/Observer.hpp"
#include "Input/MouseMoveEvent.hpp"

namespace orb
{
	class Layer : public Observer<MouseMoveEvent>
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
	private:
		RenderTarget* m_renderTarget;
		bool m_shouldRun = true;
	};
}