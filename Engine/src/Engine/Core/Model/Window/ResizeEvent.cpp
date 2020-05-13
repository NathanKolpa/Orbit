#include <Engine/Core/Model/Window/ResizeEvent.hpp>

orb::ResizeEvent::ResizeEvent(int width, int height)
	:m_width(width), m_height(height)
{

}

int orb::ResizeEvent::getWidth() const
{
	return m_width;
}

int orb::ResizeEvent::getHeight() const
{
	return m_height;
}
