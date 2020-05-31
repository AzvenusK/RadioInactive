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

#ifdef RI_ENABLE_ASSERTS
	#define RI_ASSERT(x, ...) { if(!(x)) {RI_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RI_CORE_ASSERT(x, ...) { if(!(x)) {RI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RI_ASSERT(x, ...)
	#define RI_CORE_ASSERT(x, ...)
#endif // RI_ENABLE_ASSERTS


#define BIT(x) (1 << x)