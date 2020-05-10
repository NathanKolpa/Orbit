#pragma once

#include "RenderApi.hpp"
#include <Engine/Core/pch.hpp>

namespace orb
{
	class Renderer2D
	{
	public:
		explicit Renderer2D(RenderApi& api);
	public:
		void beginScene();
		void endScene();

		void drawQuad(const glm::vec2& position, const glm::vec2& size);

		RenderApi& getApi();
	private:
		void flush();
	private:
		std::reference_wrapper<RenderApi> m_renderApi;
	};
}