#pragma once
#ifdef ORB_OPENGL

#include <Engine/Core/Renderer/Buffer/IndexBuffer.hpp>
#include <cstddef>

namespace orb
{
	class GlIndexBuffer : public IndexBuffer
	{
	public:
		static GlIndexBuffer* create(unsigned int *data, std::size_t allocatedVertices);
	public:
		~GlIndexBuffer();
	public:
		void bind() override;
		void unBind() override;
		void setData(unsigned int *data, std::size_t indices) override;
	private:
		explicit GlIndexBuffer(unsigned int eboI);
	private:
		unsigned int m_eboId;
		static unsigned int s_boundEbo;
	};
}

#endif