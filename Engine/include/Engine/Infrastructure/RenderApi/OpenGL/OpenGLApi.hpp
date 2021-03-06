#pragma once
#ifdef ORB_OPENGL

#include <Engine/Core/Renderer/RenderApi.hpp>
#include "Engine/Infrastructure/RenderApi/OpenGL/Buffer/GlVertexArray.hpp"
#include "Engine/Infrastructure/RenderApi/OpenGL/Buffer/GlVertexBuffer.hpp"
#include "Engine/Infrastructure/RenderApi/OpenGL/Shader/GlShader.hpp"

namespace orb
{
	class OpenGLApi : public RenderApi
	{
	public:
		static OpenGLApi create();
	public:
		void clear() override;
		void setViewport(int x, int y, int width, int height) override;
		const char *getVersionString() override;

		VertexArray *createVertexArray() override;
		Shader *createShader(const ShaderResource &source) override;
	private:
		OpenGLApi() = default;
	private:
	};
}

#endif