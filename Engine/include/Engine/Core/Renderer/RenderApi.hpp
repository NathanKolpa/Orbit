#pragma once

#include "RenderContext.hpp"
#include "RenderFactory.hpp"

namespace orb
{
	class RenderApi
	{
	public:
		virtual void init(RenderContext& context) = 0;
		virtual void destroy() = 0;

		virtual RenderFactory& getFactory() = 0;

		virtual const char* getVersionString() = 0;
	};
}