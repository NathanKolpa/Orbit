#pragma once

#include <Engine/Core/Renderer/RenderApi.hpp>
#include "GlVertexArray.hpp"
#include "GlVertexBuffer.hpp"

namespace orb
{
	class OpenGLApi : public RenderApi
	{
	public:
		static OpenGLApi create(RenderContext& context);
	public:
		void setViewport(int x, int y, int width, int height) override;
		const char *getVersionString() override;
		VertexArray *createVertexArray() override;
	private:
		OpenGLApi() = default;
	private:
	};
}