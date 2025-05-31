#include "Platform/Platform.h"

PlatformData CPlatform::m_PlatformData;

void CPlatform::CreateConsole()
{
    
}

bool CPlatform::CreateApplication()
{
    uint32 subsystemFlags = SDL_INIT_VIDEO;
    if (!SDL_Init(subsystemFlags))
    {
        return false;
    }

    return true;
}

void CPlatform::DestroyApplication()
{
    m_PlatformData.m_Quit = true;
    if (m_PlatformData.m_Window != nullptr)
    {
        SDL_DestroyWindow(m_PlatformData.m_Window);
    }
    SDL_Quit();
}

bool CPlatform::MakeWindow(const WindowDescription& description)
{
    uint32 subsystemFlags = SDL_INIT_VIDEO;
    if (!SDL_WasInit(subsystemFlags))
    {
        return false;
    }

    uint32 windowFlags = SDL_WINDOW_VULKAN;
    m_PlatformData.m_Window = SDL_CreateWindow(description.m_Title, description.m_Width, description.m_Height, windowFlags);
    if (m_PlatformData.m_Window == nullptr)
    {
        return false;
    }

    return true;
}

void CPlatform::ProcessEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            DestroyApplication();
        }
    }
}
