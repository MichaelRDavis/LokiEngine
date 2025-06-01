#pragma once

// Detect compiler type
#if defined(_MSC_VER)
	#define LOKI_MSVC_COMPILER
	#define LOKI_MSVC_COMPILER_VER _MSC_VER
	#define LOKI_DLLEXPORT __declspec(dllexport)
	#define LOKI_DLLIMPORT __declspec(dllimport)
	#define LOKI_INLINE __inline
	#define LOKI_FORCEINLINE __forceinline
#else
	#error "Compiler type not supported!"
#endif

// Define data types 
#ifdef LOKI_MSVC_COMPILER
	typedef __int8 int8;
	typedef unsigned __int8 uint8;
	typedef __int16 int16;
	typedef unsigned __int16 uint16;
	typedef __int32 int32;
	typedef unsigned __int32 uint32;
	typedef __int64 int64;
	typedef unsigned __int64 uint64;
#else
	#error "Compiler type not supported!"
#endif

// Check size of data types 
static_assert(sizeof(int8) == 1, "int8 not 1 byte!");
static_assert(sizeof(uint8) == 1, "uint8 not 1 byte!");
static_assert(sizeof(int16) == 2, "int16 not 2 bytes!");
static_assert(sizeof(uint16) == 2, "uint16 not 2 bytes!");
static_assert(sizeof(int32) == 4, "int32 not 4 bytes!");
static_assert(sizeof(uint32) == 4, "uint32 not 4 bytes!");
static_assert(sizeof(int64) == 8, "int64 not 8 bytes!");
static_assert(sizeof(uint64) == 8, "uint64 not 8 bytes!");

// Detect platform type
#if defined(_WIN32)
	#if defined(_WIN64)
		#define LOKI_WINDOWS_PLATFORM
	#else
		#error "WIN32 builds are not supported!"
	#endif
#endif

// Define Core export 
#ifdef LOKI_CORE_DLLEXPORT
	#define LOKI_COREAPI LOKI_DLLEXPORT
#else
	#define LOKI_COREAPI LOKI_DLLIMPORT
#endif

// Windows platform includes 
#ifdef LOKI_WINDOWS_PLATFORM
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
#endif

// ThirdParty includes 
#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>
#include <vulkan/vulkan.h>

// C++ STD includes
#include <vector>