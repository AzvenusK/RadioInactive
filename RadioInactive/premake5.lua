workspace "RadioInactive"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "RadioInactive"
	location "RadioInactive"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

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
		"%{prj.name}/vendor/spdlog/include"
	}
	
	links
	{
		"RadioInactive"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

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