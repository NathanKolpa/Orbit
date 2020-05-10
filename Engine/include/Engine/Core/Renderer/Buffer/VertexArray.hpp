#pragma once

namespace orb
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;
	public:
		virtual void bind() = 0;
		virtual void unBind() = 0;
		virtual void draw() = 0;
		virtual void draw(int vertexCount) = 0;
	};
}