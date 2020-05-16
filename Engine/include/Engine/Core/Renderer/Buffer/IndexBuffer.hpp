#pragma once

namespace orb
{
	class IndexBuffer
	{
	public:
		~IndexBuffer() = default;
	public:
		virtual void bind() = 0;
		virtual void unBind() = 0;
		virtual void setData(unsigned int* data, size_t indices) = 0;
	};
}