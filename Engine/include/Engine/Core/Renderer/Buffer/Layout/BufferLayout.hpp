#pragma once

#include "BufferElement.hpp"
#include <Engine/Core/pch.hpp>

namespace orb
{
	class BufferLayout
	{
	public:
		BufferLayout(std::vector<BufferElement> elements);
		BufferLayout() = default;
	public:
		int getTotalElements() const;
		std::vector<BufferElement>& getElements();
	private:
		std::vector<BufferElement> m_elements;
	};
}
