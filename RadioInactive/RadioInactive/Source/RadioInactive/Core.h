#pragma once

#ifdef RI_PLATFORM_WINDOWS
	#ifdef RI_BUILD_DLL
		#define RI_API __declspec(dllexport)
	#else 
		#define RI_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif

#define BIT(x) (1 << x)