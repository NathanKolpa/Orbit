#pragma once

#include <Engine/Core/pch.hpp>

namespace orb
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;
	public:
		virtual void bind() = 0;
		virtual void unBind() = 0;
		virtual void setData(float* data, std::size_t vertices) = 0;
	};
}