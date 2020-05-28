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
		int getTotalSizeInBytes() const;
		std::vector<BufferElement>& getElements();
		const std::vector<BufferElement>& getElements() const;
	private:
		std::vector<BufferElement> m_elements;
	};
}
