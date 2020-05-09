#include <Engine/Core/Renderer/Buffer/Layout/BufferLayout.hpp>
#include <numeric>

std::vector<orb::BufferElement> &orb::BufferLayout::getElements()
{
	return m_elements;
}

orb::BufferLayout::BufferLayout(std::vector<BufferElement> elements)
		: m_elements(elements)
{

}

int orb::BufferLayout::getTotalElements() const
{
	return std::accumulate(m_elements.begin(), m_elements.end(), 0, [&](int acc, const BufferElement& el)
	{
		return acc += el.getElementCount();
	});
}
