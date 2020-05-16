#pragma once

namespace orb
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;
	public:
		virtual void bind() = 0;
		virtual void unBind() = 0;
		virtual void setData(float* data, size_t vertices) = 0;
	};
}