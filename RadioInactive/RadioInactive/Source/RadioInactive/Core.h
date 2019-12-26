#pragma once

#ifdef RI_PLATFORM_WINDOWS
	#ifdef RI_BUILD_DLL
		#define __declspec(dllexport)
	#else 
		#define __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif
