#pragma once

#include "VertexBuffer.hpp"

namespace orb
{
	class DynamicVertexBuffer : public VertexBuffer
	{
	public:
		void setData(float[] data);
	};
}