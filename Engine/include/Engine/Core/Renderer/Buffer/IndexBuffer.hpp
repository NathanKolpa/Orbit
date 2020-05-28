#pragma once

#include <Engine/Core/pch.hpp>

namespace orb
{
	class IndexBuffer
	{
	public:
		~IndexBuffer() = default;
	public:
		virtual void bind() = 0;
		virtual void unBind() = 0;
		virtual void setData(unsigned int* data, std::size_t indices) = 0;
	};
}