#include "core/lux.h" 
#include "core/MT/event.h"

namespace  Lux
{
	namespace MT
	{
		Event::Event(EventFlags flags)
		{
			m_mutex = PTHREAD_MUTEX_INITIALIZER;
			m_cond = PTHREAD_COND_INITIALIZER;
			
			pthread_mutex_init(&m_mutex, NULL);
			pthread_cond_init(&m_cond, NULL);
			m_waiting_thrads = 0;
			m_manual_reset = !!(flags & EventFlags::MANUAL_RESET);
			m_signaled = !!(flags & EventFlags::SIGNALED);
		}
		
		Event::~Event()
		{
			pthread_mutex_destroy(&m_mutex);
			pthread_cond_destroy(&m_cond);
		}
		
		void Event::reset()
		{
			pthread_mutex_lock(&m_mutex);
			m_signaled = false;
			pthread_mutex_unlock(&m_mutex);
		}
		
		void Event::trigger()
		{
			pthread_mutex_lock(&m_mutex);
			if(m_manual_reset)
			{
				m_signaled = true;
				pthread_cond_broadcast(&m_cond);
			}
			else
			{
				if (m_waiting_thrads == 0)
				{
					m_signaled = true;
				}
				else
				{
					pthread_cond_signal(&m_cond);
				}
			}
			pthread_mutex_unlock(&m_mutex);
		}
		
		void Event::wait()
		{
			pthread_mutex_lock(&m_mutex);
			if (m_signaled)
			{
				if (false == m_manual_reset)
				{
					m_signaled = false;
				}
			}
			else
			{
				m_waiting_thrads++;
				pthread_cond_wait(&m_cond, &m_mutex);
				m_waiting_thrads--;
			}
			pthread_mutex_unlock(&m_mutex);
		}
		
		bool Event::poll()
		{
			bool ret = false;
			pthread_mutex_lock(&m_mutex);
			if (m_signaled)
			{
				if (false == m_manual_reset)
				{
					m_signaled = false;
				}
				
				ret = true;
			}
			pthread_mutex_unlock(&m_mutex);
			
			return ret;
		}
	}; // ~namespace MT
}; // ~namespace Lux
