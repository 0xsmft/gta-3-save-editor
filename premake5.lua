workspace "GTAIIISaveEditor"
	architecture "x64"
	startproject "GTA3SaveEd"
	warnings "Default"

	configurations { "Debug", "Release", "Dist" }

	flags { "MultiProcessorCompile" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["ImGui"] = "GTA3SaveEd/vendor/imgui"
IncludeDir["vma"] = "GTA3SaveEd/vendor/vma/src"

group "Dependencies"
	include "GTA3SaveEd/vendor/imgui"

group "App"
project "GTA3SaveEd"
	location "GTA3SaveEd"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++23"
	warnings "Default"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sppch.h"
	pchsource "GTA3SaveEd/src/sppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/vulkan/**.h",
		"%{prj.name}/vendor/vma/src/**.cpp",
		"%{prj.name}/vendor/vma/src/**.h",
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/vulkan/include",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.vma}",
	}

	defines
	{
		"XY_RBY_INCLUDE_VULKAN",
	}

	links 
	{
		"ImGui"
	}

	filter "system:linux"
		systemversion "latest"

		links 
		{
			"vulkan"
		}

		defines
		{
			"XY_PLAFORM_LINUX"
		}


	filter "system:windows"
		systemversion "latest"

		links 
		{
			"GTA3SaveEd/vendor/vulkan/bin/vulkan-1"
		}

		defines
		{
			"XY_PLATFORM_WINDOWS",
			"_CRT_SECURE_NO_WARNINGS"
		}
		
		filter "configurations:Debug"
			defines "XY_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "XY_RELEASE"
			runtime "Release"
	
		filter "configurations:Dist"
			defines "XY_DIST"
			runtime "Release"
			optimize "on"
			symbols "off"
			kind "WindowedApp"

---------------------------------------------------------------------------------------------------------------------------
