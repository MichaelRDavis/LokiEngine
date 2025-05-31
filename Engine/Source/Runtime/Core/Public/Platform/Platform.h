#pragma once

#include "Core.h"

struct WindowDescription
{
	const char* m_Title;
	uint32 m_Width;
	uint32 m_Height;
};

struct LOKI_COREAPI PlatformData
{
	SDL_Window* m_Window;
	bool m_Quit;

	PlatformData()
	{
		m_Window = nullptr;
		m_Quit = false;
	}
};

class LOKI_COREAPI CPlatform
{
public:
	static void CreateConsole();

	static bool CreateApplication();

	static void DestroyApplication();

	static bool MakeWindow(const WindowDescription& description);

	static void ProcessEvents();

	static PlatformData m_PlatformData;
};