#pragma once

#include "RenderApi.hpp"
#include <Engine/Core/pch.hpp>
#include "Buffer/VertexArray.hpp"

namespace orb
{
	class Renderer2D
	{
	public:
		explicit Renderer2D(RenderApi& api);
		~Renderer2D();
	public:
		void beginScene();
		void endScene();

		void drawQuad(const glm::vec2& position, const glm::vec2& size);

		RenderApi& getApi();

		int getTotalDrawCalls() const;
	private:
		void flush();
	private:
		std::reference_wrapper<RenderApi> m_renderApi;
		VertexArray* m_vao;
		VertexBuffer* m_vbo;
		IndexBuffer* m_ebo;

		int m_vertexCount = 0;
		int m_indexCount = 0;

		unsigned int m_indexArray[20000 * 6];
		float m_vertexArray[20000 * 4];

		const size_t m_maxIndices = 20000 * 6;
		const size_t m_maxVertices = 20000 * 4;

		const int m_vertexSize = 2;

		unsigned int m_drawCalls = 0;
	};
}