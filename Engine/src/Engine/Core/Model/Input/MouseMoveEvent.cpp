#include <Engine/Core/Model/Input/MouseMoveEvent.hpp>

orb::MouseMoveEvent::MouseMoveEvent(double x, double y, double lastX, double lastY)
		: m_newX(x), m_newY(y), m_lastX(lastX), m_lastY(lastY)
{

}

double orb::MouseMoveEvent::getDeltaX() const
{
	return m_lastX - m_newX;
}

double orb::MouseMoveEvent::getDeltaY() const
{
	return m_lastY - m_newY;
}

double orb::MouseMoveEvent::getX() const
{
	return m_newX;
}

double orb::MouseMoveEvent::getY() const
{
	return m_newY;
}

double orb::MouseMoveEvent::getLastX() const
{
	return m_lastX;
}

double orb::MouseMoveEvent::getLastY() const
{
	return m_lastY;
}
