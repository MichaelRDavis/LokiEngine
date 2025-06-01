#pragma once

#include "Core.h"

struct RenderViewport
{
	SDL_Window* m_ViewportWindow;
	uint32_t m_ViewportWidth;
	uint32_t m_ViewportHeight;

	RenderViewport()
	{
		m_ViewportWindow = nullptr;
		m_ViewportWidth = 0;
		m_ViewportHeight = 0;
	}
};

class LOKI_COREAPI CRenderer
{
public:
	// Default constructor
	CRenderer();

	// Default destructor
	~CRenderer();

	void CreateInstance();

	void DestroyInstance();

	void CreateRenderViewport(const RenderViewport& viewport);

private:
	// Vulkan instance
	VkInstance m_Instance;

	// Viewport to renderer to
	RenderViewport m_RenderViewport;

	// List of instance extensions
	std::vector<const char*> m_Extensions;
};