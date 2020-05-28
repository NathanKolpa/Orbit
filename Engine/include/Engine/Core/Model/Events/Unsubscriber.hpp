#pragma once

#include <Engine/Core/pch.hpp>

namespace orb
{
	template<typename T>
	class Unsubscriber
	{
	public:
		Unsubscriber(Observer<T>& observer, std::vector<Observer <T>*>& observers)
			:m_observers(&observers), m_observer(&observer)
		{

		}

		~Unsubscriber()
		{
			m_observers->erase(std::remove(m_observers->begin(), m_observers->end(), m_observer), m_observers->end());
		}
	private:
		Observer <T> *m_observer;
		std::vector<Observer < T>*>* m_observers;
	};
}