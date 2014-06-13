#include "core/MT/spin_mutex.h"

namespace Lux
{
	namespace MT
	{
		SpinMutex::SpinMutex(bool locked)
		{
			m_id = PTHREAD_MUTEX_INITIALIZER;
			pthread_mutex_init(&m_id, NULL);
			
			if (locked)
			{
				lock();
			}
		}
		
		SpinMutex::~SpinMutex()
		{
			pthread_mutex_destroy(&m_id);
		}
		
		void SpinMutex::lock()
		{
			pthread_mutex_lock(&m_id);
		}
		
		bool SpinMutex::poll()
		{
			unsigned int res = pthread_mutex_trylock(&m_id);
			return 0 == res;
		}
		
		void SpinMutex::unlock()
		{
			pthread_mutex_unlock(&m_id);
		}
	} // ~namespace MT
} // ~namespace Lux