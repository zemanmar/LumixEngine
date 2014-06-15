#pragma once
#include "core/lux.h"

#ifdef OSX
#include <semaphore.h>
#endif //~OSX

namespace Lux
{
	namespace MT
	{
#ifdef WINDOWS_PLATFORM
		typedef void* SemaphoreHandle;
#elif OSX_PLATFORM
		typedef sem_t* SemaphoreHandle;
#else //~OSX_PLATFORM
#error Unsupported platform!
#endif 
		
		class LUX_CORE_API Semaphore
		{
		public:
			Semaphore(int init_count, int max_count);
			~Semaphore();

			void signal();

			void wait();
			bool poll();

		private:
			SemaphoreHandle m_id;
#ifdef OSX_PLATFORM
			char name[255];
#endif //~OSX
		};
	}; // ~namespac MT
}; //~namespace Lux