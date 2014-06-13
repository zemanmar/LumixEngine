#include "core/lux.h"
#include "core/timer.h"
#include <mach/mach_time.h>

namespace Lux
{
	class TimerImpl : public Timer
	{
	public:
		TimerImpl()
			: m_first_tick(mach_absolute_time())
			, m_frequency(1000)
		{
			m_last_tick = m_first_tick;
		}
		
		float getTimeSinceStart()
		{
			uint64_t tick = mach_absolute_time();
			float delta = static_cast<float>((double)(tick - m_first_tick) / (double)m_frequency);
			return delta;
		}
		
		float tick()
		{
			uint64_t tick = mach_absolute_time();
			float delta = static_cast<float>((double)(tick - m_first_tick) / (double)m_frequency);
			m_last_tick = tick;
			return delta;
		}
	private:
		uint64_t m_frequency;
		uint64_t m_last_tick;
		uint64_t m_first_tick;
	};
	
	
	
	Timer* Timer::create()
	{
		return static_cast<Timer*>(LUX_NEW(TimerImpl)());
	}
	
	
	void Timer::destroy(Timer* timer)
	{
		LUX_DELETE(static_cast<TimerImpl*>(timer));
	}
} // ~namespace Lux