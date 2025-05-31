#pragma once

#ifdef LOKI_CORE_DLLEXPORT
	#define LOKI_COREAPI __declspec(dllexport)
	#else
	#define LOKI_COREAPI __declspec(dllimport)
#endif

class LOKI_COREAPI CTest
{
public:
	CTest();
	~CTest();
};