#pragma once

#include <Engine/Core/pch.hpp>
#include "Observer.hpp"
#include "Unsubscriber.hpp"

namespace orb
{
	template<typename T>
	class Observable
	{
	public:
		virtual Unsubscriber<T> subscribe(Observer<T> &observer) = 0;
	};
}