#pragma once

namespace orb
{
	class ResizeEvent
	{
	public:
		ResizeEvent(int width, int height);
	public:
		int getWidth() const;
		int getHeight() const;
	private:
		int m_width, m_height;
	};
}