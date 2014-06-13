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
		typedef void* MutexHandle;
#endif
		
#ifdef OSX
		typedef pthread_mutex_t MutexHandle;
#endif //~OSX
		
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