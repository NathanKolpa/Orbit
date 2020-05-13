#pragma once

#include "RenderContext.hpp"
#include "Engine/Core/Renderer/Buffer/VertexArray.hpp"
#include "Engine/Core/Renderer/Buffer/VertexBuffer.hpp"
#include "Buffer/Layout/BufferLayout.hpp"

namespace orb
{
	class RenderApi
	{
	public:
		virtual const char* getVersionString() = 0;
		virtual VertexArray *createVertexArray() = 0;
	};
}