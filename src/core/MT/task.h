#pragma once

namespace Lux
{
	namespace MT
	{
		class LUX_CORE_API Task
		{
		public:
			Task();
			~Task();

			virtual int task() = 0;

			bool create(const char* name);
			bool run();
			bool destroy();

			void setAffinityMask(uint32_t affinity_mask);
			void setPriority(uint32_t priority);

			uint32_t getAffinityMask() const;
			uint32_t getPriority() const;
			uint32_t getExitCode() const;

			bool isRunning() const;
			bool isFinished() const;
			bool isForceExit() const;

			void forceExit(bool wait);
			void exit(int32_t exit_code);

		private:
			struct TaskImpl* m_implementation;
		};	
	} // ~namespace MT
} // ~namespace Lux
