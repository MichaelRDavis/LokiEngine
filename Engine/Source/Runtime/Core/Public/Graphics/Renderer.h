#pragma once

#include "Core.h"

struct RenderViewport
{
	SDL_Window* m_ViewportWindow;
	uint32_t m_ViewportWidth;
	uint32_t m_ViewportHeight;
};

class LOKI_COREAPI CRenderer
{
public:
	void CreateRenderViewport(const RenderViewport& viewport);

private:
	RenderViewport m_RenderViewport;
};