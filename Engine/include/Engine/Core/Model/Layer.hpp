#pragma once
#include "RenderTarget.hpp"
#include "Engine/Core/Model/Timing/TimeStep.hpp"

namespace orb
{
	class Layer
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
	private:
		RenderTarget* m_renderTarget;
		bool m_shouldRun = true;
	};
}