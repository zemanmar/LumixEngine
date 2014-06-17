#include "core/lux.h"
#include "core/mt/task.h"
#include "core/mt/thread.h"

#include <pthread.h>

namespace Lux
{
	namespace MT
	{
		struct TaskImpl
		{
			pthread_t m_id;
			uint32_t m_affinity_mask;
			uint32_t m_priority;
			volatile bool m_is_running;
			volatile bool m_force_exit;
			volatile bool m_exited;
			const char* m_thread_name;
			Task* m_owner;
			uint32_t m_exit_code;
		};
		
		static void* threadFunction(void* ptr)
		{
			uint32_t ret = 0xffffFFFF;
			struct TaskImpl* impl =  reinterpret_cast<TaskImpl*>(ptr);
			pthread_setname_np(impl->m_thread_name);
			
			if(!impl->m_force_exit)
			{
				ret = impl->m_owner->task();
			}
			impl->m_exited = true;
			impl->m_is_running = false;
			impl->m_exit_code = ret;
			pthread_exit(&ret);
		}
		
		Task::Task()
			: m_implementation(NULL)
		{
		}
		
		Task::~Task()
		{
			ASSERT(NULL == m_implementation);
		}
		
		bool Task::create(const char* name)
		{
			TaskImpl* impl = LUX_NEW(TaskImpl);
			impl->m_affinity_mask = getProccessAffinityMask();
			impl->m_priority = 0;//::GetThreadPriority(GetCurrentThread());
			impl->m_is_running = false;
			impl->m_force_exit = false;
			impl->m_exited = false;
			impl->m_thread_name = name;
			impl->m_owner = this;
			
			m_implementation = impl;
			return true;
		}
		
		bool Task::run()
		{
			ASSERT(NULL != m_implementation);
			if(0 == pthread_create(&m_implementation->m_id, NULL, &threadFunction, m_implementation))
			{
				m_implementation->m_is_running = true;
				return true;
			}
			return false;
		}
		
		bool Task::destroy()
		{
			void* exit_value = NULL;
			int ret = pthread_join(m_implementation->m_id, &exit_value);
			LUX_DELETE(m_implementation);
			m_implementation = NULL;
			return ret;
		}
		
		void Task::setAffinityMask(uint32_t affinity_mask)
		{
			ASSERT(NULL != m_implementation);
			m_implementation->m_affinity_mask = affinity_mask;
//			if (m_implementation->m_handle)
//			{
//				::SetThreadIdealProcessor(m_implementation->m_handle, affinity_mask);
//			}
		}
		
		void Task::setPriority(uint32_t priority)
		{
			ASSERT(NULL != m_implementation);
			m_implementation->m_priority = priority;
//			if (m_implementation->m_handle)
//			{
//				::SetThreadPriority(m_implementation->m_handle, priority);
//			}
		}
		
		uint32_t Task::getAffinityMask() const
		{
			ASSERT(NULL != m_implementation);
			return m_implementation->m_affinity_mask;
		}
		
		uint32_t Task::getPriority() const
		{
			ASSERT(NULL != m_implementation);
			return m_implementation->m_priority;
		}
		
		uint32_t Task::getExitCode() const
		{
			return 0;
		}
		
		bool Task::isRunning() const
		{
			return m_implementation && m_implementation->m_is_running;
		}
		
		bool Task::isFinished() const
		{
			return m_implementation && m_implementation->m_exited;
		}
		
		bool Task::isForceExit() const
		{
			ASSERT(NULL != m_implementation);
			return m_implementation->m_force_exit;
		}
		
		void Task::forceExit(bool wait)
		{
			ASSERT(NULL != m_implementation);
			m_implementation->m_force_exit = true;
			
			while (!isFinished() && wait)
			{
				yield();
			}
		}
		
		void Task::exit(int32_t exit_code)
		{
			ASSERT(NULL != m_implementation);
			m_implementation->m_exited = true;
			m_implementation->m_is_running = false;
			m_implementation->m_exit_code = exit_code;
			pthread_exit(&exit_code);
		}

	} // ~namespace MT
} // ~namespace Lux
