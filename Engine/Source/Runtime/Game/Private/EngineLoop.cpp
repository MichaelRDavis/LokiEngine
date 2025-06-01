#include "Platform/Platform.h"
#include "Graphics/Renderer.h"

#ifdef LOKI_WINDOWS_PLATFORM
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	if (!CPlatform::CreateApplication())
	{
		return -1;
	}

	WindowDescription description;
	description.m_Title = "Game";
	description.m_Width = 1920;
	description.m_Height = 1080;

	if (!CPlatform::MakeWindow(description))
	{
		return -1;
	}

	RenderViewport viewport;
	viewport.m_ViewportWindow = CPlatform::m_PlatformData.m_Window;
	viewport.m_ViewportWidth = description.m_Width;
	viewport.m_ViewportHeight = description.m_Height;

	CRenderer renderer;
	renderer.CreateInstance();
	renderer.CreateRenderViewport(viewport);

	while (!CPlatform::m_PlatformData.m_Quit)
	{
		CPlatform::ProcessEvents();
	}

	return 0;
}
#endif