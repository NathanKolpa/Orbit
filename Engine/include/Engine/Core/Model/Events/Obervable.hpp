#pragma once

#include <Engine/Core/pch.hpp>
#include "Observer.hpp"
#include "Unsubscriber.hpp"

namespace orb
{
	template<typename T, typename = std::enable_if<std::is_base_of<Event, T>::value>>
	class Observable
	{
	public:
		Unsubscriber<T> subscribe(Observer<T> &observer)
		{
			m_observers.push_back(&observer);

			return Unsubscriber<T>(observer, m_observers);
		}

	protected:
		void sendMessage(T &event)
		{
			for (auto &observer : m_observers)
			{
				observer->onNext(event);

				if (event.isConsumed())
					break;
			}
		}

	private:
		std::vector<Observer<T> *> m_observers;
	};
}