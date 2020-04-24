#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace RadioInactive
{
	class RI_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
//Core Log MACROS
#define RI_CORE_TRACE(...)    ::RadioInactive::Log::GetCoreLogger()->trace(__VA_ARGS__) 
#define RI_CORE_INFO(...)     ::RadioInactive::Log::GetCoreLogger()->info(__VA_ARGS__) 
#define RI_CORE_WARN(...)     ::RadioInactive::Log::GetCoreLogger()->warn(__VA_ARGS__) 
#define RI_CORE_ERROR(...)    ::RadioInactive::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RI_CORE_FATAL(...)    ::RadioInactive::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//CLient Log MACROS
#define RI_TRACE(...)    ::RadioInactive::Log::GetClientLogger()->trace(__VA_ARGS__) 
#define RI_INFO(...)     ::RadioInactive::Log::GetClientLogger()->info(__VA_ARGS__) 
#define RI_WARN(...)     ::RadioInactive::Log::GetClientLogger()->warn(__VA_ARGS__) 
#define RI_ERROR(...)    ::RadioInactive::Log::GetClientLogger()->error(__VA_ARGS__)
#define RI_FATAL(...)    ::RadioInactive::Log::GetClientLogger()->fatal(__VA_ARGS__)
