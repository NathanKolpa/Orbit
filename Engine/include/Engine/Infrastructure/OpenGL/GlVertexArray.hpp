#pragma once

#include <Engine/Core/Renderer/Buffer/VertexArray.hpp>
#include <Engine/Core/Renderer/Buffer/Layout/BufferLayout.hpp>
#include "GlVertexBuffer.hpp"
#include "GlIndexBuffer.hpp"

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
		void draw(int vertices) override;
		VertexBuffer* addVertexBuffer(const BufferLayout &layout, float *data, size_t allocatedVertices) override;

		IndexBuffer *setIndexBuffer(unsigned int *data, size_t allocatedVertices) override;
		IndexBuffer *getIndexBuffer() override;
	private:
		explicit GlVertexArray(unsigned int vaoId);
	private:
		static unsigned int s_boundVaoId;
		unsigned int m_vaoId;
		std::vector<GlVertexBuffer*> m_vboArray;
		GlIndexBuffer* m_indexBuffer = nullptr;
	};
}