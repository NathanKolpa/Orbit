#include <Engine/Core/Renderer/Buffer/Layout/BufferElement.hpp>

orb::BufferElement::BufferElement(int elementCount)
		: m_elementCount(elementCount)
{

}

int orb::BufferElement::getElementCount() const
{
	return m_elementCount;
}

int orb::BufferElement::getSizeInBytes() const
{
	return m_elementCount * sizeof(float);
}
