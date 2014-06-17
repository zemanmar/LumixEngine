#include "unit_tests/suite/lux_unit_tests.h"
#include "core/log.h"

#include "core/memory_tracker.h"

#include <stdio.h>

#ifdef WINDOWS_PLATFORM
#include <Windows.h>
#endif //~WINDOWS_PLATFORM

namespace Lux
{
	namespace UnitTest
	{
#ifdef WINDOWS_PLATFORM
		void outputToVS(const char* system, const char* message)
		{
			char tmp[2048];
			sprintf(tmp, "%s: %s\r", system, message);

			OutputDebugString(tmp);
		}
#endif //~WINDOWS_PLATFORM
		void outputToConsole(const char* system, const char* message)
		{
			printf("%s: %s\n", system, message);
		}

		void App::init()
		{
#ifdef WINDOWS_PLATFORM
			g_log_info.getCallback().bind<outputToVS>();
			g_log_warning.getCallback().bind<outputToVS>();
			g_log_error.getCallback().bind<outputToVS>();
#endif //~WINDOWS_PLATFORM

			g_log_info.getCallback().bind<outputToConsole>();
			g_log_warning.getCallback().bind<outputToConsole>();
			g_log_error.getCallback().bind<outputToConsole>();
			
			MemoryTracker::getInstance().getDebuggerLogCb().bind<outputToConsole>();
		}

		void App::run(int argc, const char *argv[])
		{
			Manager::instance().dumpTests();
			Manager::instance().runTests("");
			Manager::instance().dumpResults();
		}

		void App::exit()
		{
			Manager::release();
		}
	} //~UnitTest
} //~UnitTest