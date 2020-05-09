#pragma once

namespace orb
{
	class VertexBuffer
	{
	public:
		virtual void bind() = 0;
		virtual void unBind() = 0;
		virtual void draw() = 0;
		virtual void draw(int vertexCount) = 0;
	};
}