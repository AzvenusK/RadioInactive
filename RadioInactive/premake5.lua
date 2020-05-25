workspace "RadioInactive"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories related to their root directories (solution folder)
IncludeDir = {}
IncludeDir["GLFW"] = "vendor/glfw"

include "vendor/glfw"

project "RadioInactive"
	location "RadioInactive"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "RIPCH.h"
	pchsource "RadioInactive/Source/RIPCH.cpp"

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/Source",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RI_PLATFORM_WINDOWS",
			"RI_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/RetDabba")
		}

	filter "configurations:Debug"
		defines "RI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RI_DIST"
		optimize "On"


project "RetDabba"
	location "RetDabba"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}
	
	includedirs
	{
		"RadioInactive/vendor/spdlog/include",
		"RadioInactive/Source"
	}

	links
	{
		"RadioInactive"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RI_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RI_DIST"
		optimize "On"