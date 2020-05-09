#pragma once

#include "Obervable.hpp"

namespace orb
{
	template<typename T>
	class EventEmitter : public Observable<T>
	{
	public:
		Unsubscriber<T> subscribe(Observer<T> &observer) override
		{
			m_observers.push_back(&observer);

			return Unsubscriber<T>(observer, m_observers);
		}

		void emit(T &event)
		{
			for (auto &observer : m_observers)
			{
				observer->onNext(event);
			}
		}

	private:
		std::vector<Observer<T> *> m_observers;
	};
}