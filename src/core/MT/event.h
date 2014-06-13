#pragma once

#ifdef OSX
#include <pthread.h>
#endif //~OSX

namespace  Lux
{
	namespace MT
	{
		struct EventFlags
		{
			enum Value
			{
				SIGNALED	= 0x1,
				MANUAL_RESET	= SIGNALED << 1,
			};

			EventFlags(Value _value) : value(_value) { }
			EventFlags(int _value) : value(_value) { }
			operator Value() const { return (Value)value; }
			int value;
		};
		
		class LUX_CORE_API Event
		{
		public:
			explicit Event(EventFlags flags);
			~Event();

			void reset();

			void trigger();

			void wait();
			bool poll();

		private:
#ifdef PC
			void* m_id;
#endif //~PC
			
#ifdef OSX
			pthread_mutex_t m_mutex;
			pthread_cond_t m_cond;
			unsigned int m_waiting_thrads;
			bool m_manual_reset;
			bool m_signaled;
#endif //~OSX
		};
	}; // ~namespace MT
}; // ~namespace Lux