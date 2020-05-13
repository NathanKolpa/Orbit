#pragma once

#include "VertexBuffer.hpp"
#include "Layout/BufferLayout.hpp"

namespace orb
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;
	public:
		virtual void bind() = 0;
		virtual void unBind() = 0;
		virtual void draw(int vertices) = 0;
		virtual VertexBuffer* addVertexBuffer(const BufferLayout& layout, float* data, size_t allocatedVertices) = 0;
	};
}