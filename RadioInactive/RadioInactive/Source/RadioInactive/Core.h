#pragma once

#ifdef RI_PLATFORM_WINDOWS
	#ifdef RI_BUILD_DLL
		#define RI_API __declspec(dllexport)
	#else 
		#define RI_API __declspec(dllimport)
	#endif // RI_BUILD_DLL
#else
	#error RadioInactive is only for Windows!
#endif // RI_PLATFORM_WINDOWS
