#pragma once
#include "core/lux.h"

#ifdef OSX_PLATFORM
#include <pthread.h>
#endif //~OSX_PLATFORM

namespace Lux
{
	namespace MT
	{
#ifdef WINDOWS_PLATFORM
		typedef void* MutexHandle;
#elif OSX_PLATFORM
		typedef pthread_mutex_t MutexHandle;
#else //~OSX_PLATFORM
#error Unsupported platform!
#endif 
		
		class LUX_CORE_API Mutex
		{
		public:
			explicit Mutex(bool locked);
			~Mutex();

			void lock();
			bool poll();

			void unlock();

		private:
			MutexHandle m_id;
		};

		class Lock
		{
		public:
			Lock(Mutex& mutex) : m_mutex(mutex) { mutex.lock(); }
			~Lock() { m_mutex.unlock(); }

		private:
			void operator=(const Lock&);
			Mutex& m_mutex;
		};
	} // ~namespace MT
}; // ~namespace Lux