#pragma once

#include <Engine/Core/pch.hpp>

namespace orb
{
	template<typename T>
	class Observer
	{
	public:
		virtual void onNext(T& event) = 0;
	};
}