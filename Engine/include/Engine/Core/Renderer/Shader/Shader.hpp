#pragma once

namespace orb
{
	class Shader
	{
	public:
		virtual void bind() = 0;
		virtual void unBind() = 0;
	};
}