#pragma once

namespace orb
{
	class BufferElement
	{
	public:
		BufferElement(int elementIndex, int elementCount);
	public:
		int getElementCount() const;
		int getSizeInBytes() const;
		int getElementIndex() const;
	private:
		int m_elementCount, m_elementIndex;
	};
}