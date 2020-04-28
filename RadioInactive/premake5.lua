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
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	include
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "10.0 (latest installed version)"

	defines
	{
		"RI_PLATFORM_WINDOWS",
		"RI_BUILD_DLL"
	}