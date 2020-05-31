#pragma once

#include "Engine/Core/Renderer/Buffer/VertexArray.hpp"
#include "Engine/Core/Renderer/Buffer/VertexBuffer.hpp"
#include "Buffer/Layout/BufferLayout.hpp"
#include "Shader/ShaderResource.hpp"
#include "Shader/Shader.hpp"

namespace orb
{
	class RenderApi
	{
	public:
		virtual void clear() = 0;
		virtual void setViewport(int x, int y, int width, int height) = 0;
		virtual const char* getVersionString() = 0;

		virtual VertexArray *createVertexArray() = 0;
		virtual Shader* createShader(const ShaderResource& source) = 0;
	};
}