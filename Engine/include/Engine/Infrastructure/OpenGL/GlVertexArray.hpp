#pragma once

#include <Engine/Core/Renderer/Buffer/VertexArray.hpp>
#include <Engine/Core/Renderer/Buffer/Layout/BufferLayout.hpp>

namespace orb
{
	class GlVertexArray : public VertexArray
	{
	public:
		static GlVertexArray *create();
	public:
		~GlVertexArray() override;
	public:
		void bind() override;
		void unBind() override;
		void draw() override;
		void draw(int vertexCount) override;

	private:
		explicit GlVertexArray(unsigned int vaoId);
	private:
		unsigned int m_vaoId;
	};
}