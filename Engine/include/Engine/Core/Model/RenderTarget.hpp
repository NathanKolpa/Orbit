#pragma once

namespace orb
{
	class RenderTarget
	{
	public:
		virtual void bindContext() = 0;
		virtual void unbindContext() = 0;
	};
}

