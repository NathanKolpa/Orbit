#pragma once
#ifdef ORB_OPENGL

#include <Engine/Core/Renderer/RenderApi.hpp>
#include "Engine/Infrastructure/RenderApi/OpenGL/Buffer/GlVertexArray.hpp"
#include "Engine/Infrastructure/RenderApi/OpenGL/Buffer/GlVertexBuffer.hpp"

namespace orb
{
	class OpenGLApi : public RenderApi
	{
	public:
		static OpenGLApi create();
	public:
		void setViewport(int x, int y, int width, int height) override;
		const char *getVersionString() override;
		VertexArray *createVertexArray() override;
	private:
		OpenGLApi() = default;
	private:
	};
}

#endif