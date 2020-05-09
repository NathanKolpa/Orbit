#pragma once

#include "Buffer/DynamicVertexBuffer.hpp"
#include "Buffer/Layout/BufferLayout.hpp"

namespace orb
{
	class RenderFactory
	{
	public:
		virtual DynamicVertexBuffer* createDynamicVertexBuffer(BufferLayout& layout, float* data, size_t dataSize) = 0;
	};
}