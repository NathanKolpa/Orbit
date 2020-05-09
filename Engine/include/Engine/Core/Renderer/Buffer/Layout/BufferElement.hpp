#pragma once

namespace orb
{
	class BufferElement
	{
	public:
		BufferElement(int elementCount);
	public:
		int getElementCount() const;
	private:
		int m_elementCount;
	};
}