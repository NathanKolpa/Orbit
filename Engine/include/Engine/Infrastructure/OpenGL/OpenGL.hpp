#pragma once

#include <Engine/Core/Renderer/RenderApi.hpp>
#include "OpenGLFactory.hpp"

namespace orb
{
	class OpenGL : public RenderApi
	{
	public:
		void init(RenderContext &context) override;
		void destroy() override;
		RenderFactory &getFactory() override;
		const char *getVersionString() override;
	private:
		OpenGLFactory m_factory;
	};
}