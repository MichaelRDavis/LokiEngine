#include "Graphics/Renderer.h"

CRenderer::CRenderer()
{
	m_Instance = VK_NULL_HANDLE;
}

CRenderer::~CRenderer()
{

}

void CRenderer::CreateInstance()
{
	// Get SDL vulkan extension names
	uint32 instanceExtensionsCount = 0;
	const char* const* instanceExtensions = SDL_Vulkan_GetInstanceExtensions(&instanceExtensionsCount);
	if (instanceExtensions == nullptr)
	{
		return;
	}
	int32 extensionsCount = instanceExtensionsCount + 1;
	m_Extensions.reserve(extensionsCount);
	m_Extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
	for (uint32 i = 0; i < instanceExtensionsCount; i++)
	{
		m_Extensions.push_back(instanceExtensions[i]);
	}

	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Game";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "Loki";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	createInfo.enabledExtensionCount = m_Extensions.size();
	createInfo.ppEnabledExtensionNames = m_Extensions.data();
	createInfo.enabledLayerCount = 0;

	if (vkCreateInstance(&createInfo, nullptr, &m_Instance) != VK_SUCCESS)
	{
		return;
	}
}

void CRenderer::DestroyInstance()
{
	if (m_Instance != VK_NULL_HANDLE)
	{
		vkDestroyInstance(m_Instance, nullptr);
	}
}

void CRenderer::CreateRenderViewport(const RenderViewport& viewport)
{
	m_RenderViewport = viewport;

	if (!SDL_Vulkan_CreateSurface(m_RenderViewport.m_ViewportWindow, nullptr, nullptr, nullptr))
	{
		return;
	}
}
