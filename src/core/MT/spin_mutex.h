#pragma once

#include "core/lux.h"

#ifdef OSX_PLATFORM
#include <pthread.h>
#endif //~OSX

namespace Lux
{
	namespace MT
	{
		
#ifdef WINDOWS_PLATFORM
		typedef volatile int32_t SpinMutexHandle;
#elif OSX_PLATFORM
		typedef pthread_mutex_t SpinMutexHandle;
#else //~OSX_PLATFORM
#error Unsupported platform!
#endif 

		class LUX_CORE_API SpinMutex
		{
		public:
			explicit SpinMutex(bool locked);
			~SpinMutex();

			void lock();
			bool poll();

			void unlock();

		private:
			SpinMutexHandle m_id;
		};

		class SpinLock
		{
		public:
			SpinLock(SpinMutex& mutex) : m_mutex(mutex) { mutex.lock(); }
			~SpinLock() { m_mutex.unlock(); }

		private:
			void operator=(const SpinLock&);
			SpinMutex& m_mutex;
		};
	}; // ~namespace MT
}; // ~namespace Lux