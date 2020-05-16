#pragma once
#ifdef ORB_OPENGL

#include <Engine/Core/Renderer/Buffer/VertexBuffer.hpp>
#include <Engine/Core/Renderer/Buffer/Layout/BufferLayout.hpp>

namespace orb
{
	class GlVertexBuffer : public VertexBuffer
	{
	public:
		static GlVertexBuffer* create(const BufferLayout& layout, float* data, size_t allocatedVertices);
	public:
		~GlVertexBuffer();
	public:
		void bindAttribs();
		void unBindAttribs();
		void bind() override;
		void unBind() override;
		void setData(float *data, size_t vertices) override;
	private:
		GlVertexBuffer(unsigned int m_vboId, std::vector<int> attribArray, int vertexSize);
	private:
		std::vector<int> m_attribArray;
		unsigned int m_vboId;
		static unsigned int s_boundVboId;
		int m_vertexSize;
	};
}

#endif