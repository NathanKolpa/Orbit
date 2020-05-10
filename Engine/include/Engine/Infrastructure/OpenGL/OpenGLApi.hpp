#pragma once

#include <Engine/Core/Renderer/RenderApi.hpp>
#include "GlVertexArray.hpp"

namespace orb
{
	class OpenGLApi : public RenderApi
	{
	public:
		static OpenGLApi create(RenderContext& context);
	public:
		const char *getVersionString() override;
		VertexArray *createVertexArray() override;
	private:
		OpenGLApi() = default;
	private:
	};
}