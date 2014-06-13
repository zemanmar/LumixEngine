#include "core/lux.h" 
#include "core/MT/atomic.h"
#include <libkern/OSAtomic.h>

namespace Lux
{
	namespace MT
	{
		int32_t atomicIncrement(int32_t volatile* value)
		{
			return OSAtomicIncrement32(value);
		}

		int32_t atomicDecrement(int32_t volatile* value)
		{
			return OSAtomicDecrement32(value);
		}

		int32_t atomicAdd(int32_t volatile* addend, int32_t value)
		{
			return OSAtomicAdd32(value, addend);
		}

		int32_t atomicSubtract(int32_t volatile* addend, int32_t value)
		{
			return OSAtomicAdd32(-value, addend);
		}

		bool compareAndExchange(int32_t volatile* dest, int32_t exchange, int32_t comperand)
		{
			return OSAtomicCompareAndSwap32Barrier(comperand, exchange, dest);
		}

		bool compareAndExchange64(int64_t volatile* dest, int64_t exchange, int64_t comperand)
		{
			return OSAtomicCompareAndSwap64Barrier(comperand, exchange, dest);
		}
	} // ~namespace MT
} // ~namespace Lux