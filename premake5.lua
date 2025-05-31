workspace "LokiEngine"
    startproject "Game"

    configurations
    {
        "DebugGame",
        "ReleaseGame"
    }

    platforms
    {
        "Windows"
    }

    filter "platforms:Windows"
        system "windows"
        architecture "x86_64"

    group "Engine"
        project "Core"
        project "Game"

project "Core"
    location "Engine/Source/Runtime/Core"
    kind "SharedLib"
    language "C++"
    cppdialect "C++11"
    objdir "Engine/Intermediate"

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "LOKI_CORE_DLLEXPORT"
    }

    files 
    {
        "Engine/Source/Runtime/Core/Public/**.h",
        "Engine/Source/Runtime/Core/Private/**.cpp"
    }

    includedirs
    {
        "Engine/Source/Runtime/Core/Public",

        "Engine/ThirdPartySDKs/SDL3-3.2.14/include",
        "C:/VulkanSDK/1.4.304.1/Include"
    }

    libdirs
    {
        "Engine/ThirdPartySDKs/SDL3-3.2.14/lib/x64",
        "C:/VulkanSDK/1.4.304.1/Lib"
    }

    links
    {
        "SDL3",
        "vulkan-1"
    }

    filter "configurations:DebugGame"
        defines {"LOKI_BUILD_DEBUG", "LOKI_BUILD_GAME"}
        optimize "Debug"
        symbols "On"
        targetdir "Engine/Binaries/Debug"

    filter "configurations:ReleaseGame"
        defines {"LOKI_BUILD_RELEASE", "LOKI_BUILD_GAME"}
        optimize "Full"
        symbols "Off"
        targetdir "Engine/Binaries/Release"

project "Game"
    location "Engine/Source/Runtime/Game"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++11"
    objdir "Engine/Intermediate"
    
    files 
    {
        "Engine/Source/Runtime/Game/Public/**.h",
        "Engine/Source/Runtime/Game/Private/**.cpp"
    }
    
    includedirs
    {
        "Engine/Source/Runtime/Core/Public",
        "Engine/Source/Runtime/Game/Public",

        "Engine/ThirdPartySDKs/SDL3-3.2.14/include"
    }

    libdirs
    {
        "Engine/ThirdPartySDKs/SDL3-3.2.14/lib/x64"
    }

    links
    {
        "Core",

        "SDL3"
    }
    
    filter "configurations:DebugGame"
        defines {"LOKI_BUILD_DEBUG", "LOKI_BUILD_GAME"}
        optimize "Debug"
        symbols "On"
        targetdir "Engine/Binaries/Debug"
        libdirs
        {
            "Engine/Binaries/Debug"
        }
    filter "configurations:ReleaseGame"
        defines {"LOKI_BUILD_RELEASE", "LOKI_BUILD_GAME"}
        optimize "Full"
        symbols "Off"
        targetdir "Engine/Binaries/Release"
        libdirs
        {
            "Engine/Binaries/Release"
        }

    filter "platforms:Windows"
        kind "WindowedApp"