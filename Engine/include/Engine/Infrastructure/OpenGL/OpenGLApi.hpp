#pragma once

#include <Engine/Core/Renderer/RenderApi.hpp>

namespace orb
{
	class OpenGLApi : public RenderApi
	{
	public:
		static OpenGLApi create(RenderContext& context);
	public:
		const char *getVersionString() override;
	private:
		OpenGLApi() = default;
	private:
	};
}