#include "core/MT/mutex.h"
#include <pthread.h>

namespace Lux
{
	namespace MT
	{
		Mutex::Mutex(bool locked)
		{
			m_id = PTHREAD_MUTEX_INITIALIZER;
			pthread_mutex_init(&m_id, NULL);
			
			if (locked)
			{
				lock();
			}
		}
		
		Mutex::~Mutex()
		{
			pthread_mutex_destroy(&m_id);
		}
		
		void Mutex::lock()
		{
			pthread_mutex_lock(&m_id);
		}
		
		bool Mutex::poll()
		{
			unsigned int res = pthread_mutex_trylock(&m_id);
			return 0 == res;
		}
		
		void Mutex::unlock()
		{
			pthread_mutex_unlock(&m_id);
		}
	} // ~namespace MT
} // ~namespace Lux
