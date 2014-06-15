#pragma once

#ifdef OSX
#include <pthread.h>
#endif //~OSX

namespace Lux
{
	namespace MT
	{
#ifdef WINDOWS_PLATFORM
		typedef uint32_t ThreadID;
#elif OSX_PLATFORM
		typedef uint64_t ThreadID;
#else //~OSX_PLATFORM
#error Unsupported platform!
#endif 
		
		LUX_CORE_API void sleep(uint32_t miliseconds);
		LUX_CORE_API inline void yield() { sleep(0); }
		
		LUX_CORE_API uint32_t getCPUsCount();
		
		LUX_CORE_API ThreadID getCurrentThreadID();
		LUX_CORE_API uint32_t getProccessAffinityMask();
		
		LUX_CORE_API bool isMainThread();
		LUX_CORE_API void setMainThread();
	}
}
