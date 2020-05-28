#pragma once

#include "Events/Observer.hpp"
#include "Window/ResizeEvent.hpp"
#include  <Engine/Core/Renderer/RenderApi.hpp>

namespace orb
{
	class ResizeHandler : public Observer<ResizeEvent>
	{
	public:
		explicit ResizeHandler(RenderApi& renderApi);
	public:
		void onNext(ResizeEvent &event) override;
	private:
		std::reference_wrapper<RenderApi> m_renderApi;
	};
}