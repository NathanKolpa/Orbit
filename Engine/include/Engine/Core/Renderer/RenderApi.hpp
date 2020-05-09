#pragma once

#include "RenderContext.hpp"

namespace orb
{
	class RenderApi
	{
	public:
		virtual const char* getVersionString() = 0;
	};
}