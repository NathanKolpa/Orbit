#pragma once
#ifdef ORB_OPENGL

#include <Engine/Core/Renderer/Buffer/IndexBuffer.hpp>
#include <cstddef>

namespace orb
{
	class GlIndexBuffer : public IndexBuffer
	{
	public:
		static GlIndexBuffer* create(unsigned int *data, size_t allocatedVertices);
	public:
		~GlIndexBuffer();
	public:
		void bind() override;
		void unBind() override;
		void setData(unsigned int *data, size_t indices) override;
	private:
		explicit GlIndexBuffer(unsigned int eboId);
	private:
		size_t m_vertexCount;
		unsigned int m_eboId;
		static unsigned int s_boundEbo;
	};
}

#endif