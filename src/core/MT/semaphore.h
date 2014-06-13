#pragma once
#include "core/lux.h"

#ifdef OSX
#include <semaphore.h>
#endif //~OSX

namespace Lux
{
	namespace MT
	{
#ifdef PC
		typedef void* SemaphoreHandle;
#endif //~PC

#ifdef OSX
		typedef sem_t* SemaphoreHandle;
#endif //~OSX
		
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
#ifdef OSX
			char name[255];
#endif //~OSX
		};
	}; // ~namespac MT
}; //~namespace Lux