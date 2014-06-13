#include "core/MT/semaphore.h"

#include <stdio.h>
#include <errno.h>
#include <unistd.h>

namespace Lux
{
	namespace MT
	{
		Semaphore::Semaphore(int init_count, int max_count)
		{
			snprintf(name, 255, "%d/%p", getpid(), this);
			m_id = ::sem_open(name, O_CREAT | O_EXCL, 0666, init_count);
			if (SEM_FAILED == m_id)
			{
				TODO("Resolve posible name colisions");
				printf("sem_open name '%s' failed! Reason: %d\n", name, errno);
				ASSERT(0);
			}
		}
		
		Semaphore::~Semaphore()
		{
			::sem_close(m_id);
			::sem_unlink(name);
		}
		
		void Semaphore::signal()
		{
			::sem_post(m_id);
		}
		
		void Semaphore::wait()
		{
			int ret = ::sem_wait(m_id);
		}
		
		bool Semaphore::poll()
		{
			return 0 == ::sem_trywait(m_id);
		}
	}; // ~namespac MT
} // ~namespace Lux
