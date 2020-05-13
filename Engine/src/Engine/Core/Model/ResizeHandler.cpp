#include <Engine/Core/Model/ResizeHandler.hpp>

orb::ResizeHandler::ResizeHandler(RenderApi &renderApi)
	:m_renderApi(renderApi)
{

}

void orb::ResizeHandler::onNext(orb::ResizeEvent &event)
{
	m_renderApi.get().setViewport(0, 0, event.getWidth(), event.getHeight());
}
