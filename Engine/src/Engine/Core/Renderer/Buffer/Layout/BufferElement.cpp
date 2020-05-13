#include <Engine/Core/Renderer/Buffer/Layout/BufferElement.hpp>

orb::BufferElement::BufferElement(int elementIndex, int elementCount)
		: m_elementCount(elementCount), m_elementIndex(elementIndex)
{

}

int orb::BufferElement::getElementCount() const
{
	return m_elementCount;
}

int orb::BufferElement::getSizeInBytes() const
{
	return m_elementCount * (int)sizeof(float);
}

int orb::BufferElement::getElementIndex() const
{
	return m_elementIndex;
}
