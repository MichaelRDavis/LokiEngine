#include "Graphics/Renderer.h"

void CRenderer::CreateRenderViewport(const RenderViewport& viewport)
{
	m_RenderViewport = viewport;

	if (!SDL_Vulkan_CreateSurface(m_RenderViewport.m_ViewportWindow, nullptr, nullptr, nullptr))
	{
		return;
	}
}
