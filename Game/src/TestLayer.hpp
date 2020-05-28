#pragma once

#include <Engine/Engine.hpp>

class TestLayer : public orb::Layer
{
public:
	TestLayer(orb::Renderer2D& renderer);
public:
	void onNext(orb::KeyboardKeyEvent &event) override;
	void render() override;

	void unload() override;
	void load() override;
private:
	std::reference_wrapper<orb::Renderer2D> m_renderer;
	orb::VertexArray* m_vertexArray;
	orb::VertexBuffer* m_vertexBuffer;
	orb::IndexBuffer* m_indexBuffer;

	float m_xOffset = 0, m_yOffset = 0;
};


