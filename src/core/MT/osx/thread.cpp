#include "core/lux.h"
#include "core/mt/thread.h"

#include <pthread.h>
#include <unistd.h>

namespace Lux
{
	namespace MT
	{
		void sleep(uint32_t miliseconds) { usleep(miliseconds * 1000); }
		
		uint32_t getCPUsCount()
		{
			return (uint32_t)sysconf(_SC_NPROCESSORS_ONLN);
		}
		
		ThreadID getCurrentThreadID()
		{
			ThreadID tid;
			pthread_t id = pthread_self();
			pthread_threadid_np(id, &tid);
			return tid;
		}
		
		uint32_t getProccessAffinityMask()
		{
//			PROCESSOR_NUMBER proc_number;
//			BOOL ret = ::GetThreadIdealProcessorEx(::GetCurrentThread(), &proc_number);
//			ASSERT(ret);
//			return proc_number.Number;
			return 0;
		}
		
		bool isMainThread() { return pthread_main_np() > 0; }
		void setMainThread() { }
	}
}
