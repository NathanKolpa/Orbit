#include <Engine/Core/Renderer/Renderer2D.hpp>

orb::Renderer2D::Renderer2D(orb::RenderApi &api)
	:m_renderApi(api)
{

}

void orb::Renderer2D::beginScene()
{

}

void orb::Renderer2D::endScene()
{
	flush();
}

void orb::Renderer2D::flush()
{

}

void orb::Renderer2D::drawQuad(const glm::vec2 &position, const glm::vec2 &size)
{

}

orb::RenderApi &orb::Renderer2D::getApi()
{
	return m_renderApi;
}
