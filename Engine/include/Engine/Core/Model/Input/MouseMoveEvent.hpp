#pragma once

#include "Event.hpp"

namespace orb
{
	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(double x, double y, double lastX, double lastY);
	public:
		double getX() const;
		double getY() const;
		double getLastX() const;
		double getLastY() const;

		double getDeltaX() const;
		double getDeltaY() const;
	private:
		double m_newX;
		double m_newY;
		double m_lastX;
		double m_lastY;
	};
}