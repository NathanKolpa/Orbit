#pragma once

namespace orb
{
	class Event
	{
	public:
		void consume();
		bool isConsumed() const;
	private:
		bool m_isConsumed = false;
	};
}