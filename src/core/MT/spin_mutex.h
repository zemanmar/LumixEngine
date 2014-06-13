#pragma once

#include "core/lux.h"

#ifdef OSX
#include <pthread.h>
#endif //~OSX

namespace Lux
{
	namespace MT
	{
		
#ifdef PC
		typedef volatile int32_t SpinMutexHandle;
#endif //~PC
		
#ifdef OSX
		typedef pthread_mutex_t SpinMutexHandle;
#endif //~OSX

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