#include "core/lux.h"
#include "core/memory_tracker.h"
#include "core/log.h"
#include "core/map.h"
#include "core/math_utils.h"
#include "core/MT/spin_mutex.h"

#include <stdio.h>
#include <stdarg.h>

#ifdef MEM_TRACK

namespace Lux
{
	struct FileLineReport
	{
		const char *file;
		int32_t line;

		inline bool operator == (const FileLineReport &other) const { return file == other.file && line == other.line; }
		inline bool operator != (const FileLineReport &other) const { return !(*this == other); }

		inline bool operator < (const FileLineReport &other) const
		{
			if (NULL == file)
			{
				return NULL != other.file;
			}
			if (NULL == other.file)
			{
				return false;
			}
			
			int cmp = strcmp(file, other.file);
			if (0 != cmp)
			{
				return 0 > cmp;
			}
			return line < other.line;
		}

		inline bool operator > (const FileLineReport &other) const
		{
			if (NULL == file)
			{
				return NULL != other.file;
			}
			if (other.file == NULL)
			{
				return false;
			}
			
			int cmp = strcmp(file, other.file);
			if (0 != cmp)
			{
				return cmp > 0;
			}
			return line > other.line;
		}
	};

	typedef Map<uint32_t, MemoryTracker::Entry*, MemTrackAllocator> map_alloc_order;
	typedef Map<FileLineReport, size_t, MemTrackAllocator> file_line_map;
	typedef Map<const char *, size_t, MemTrackAllocator> file_map;
	typedef Map<FileLineReport, uint32_t, MemTrackAllocator> alloc_count_map;

#pragma init_seg(compiler)
	MemoryTracker MemoryTracker::s_instance;
	uint32_t MemoryTracker::s_alloc_counter = 0;

	MemoryTracker& MemoryTracker::getInstance()
	{
		return s_instance;
	}

	void MemoryTracker::add(void* p, const size_t size, const char* file, const int line)
	{
		if(!p) return;

		MT::SpinLock lock(m_spin_mutex);

		m_map.insert(p, Entry(file, line, size));
		m_allocated_memory += size;
	}

	void MemoryTracker::remove(void* p)
	{
		if(!p) return;

		MT::SpinLock lock(m_spin_mutex);

		EntryTable::iterator it = m_map.find(p);
		ASSERT(m_map.end() != it && "Allocated/Dealocated from different places?");
		if(m_map.end() != it)
		{
			m_allocated_memory -= (*it).size();
			m_map.erase(it);
		}
	}

	void MemoryTracker::dumpDetailed()
	{
		// Detected memory leaks!
		// Dumping objects ->
		// {147} normal block at 0x003AF7C0, 10 bytes long.
		// Data: <          > CD CD CD CD CD CD CD CD CD CD
		// d:\temp\zmazat\tt\tt\mainfrm.cpp(34) : {145} normal block at 0x003AF760, 30 bytes long.
		// Data: <               > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD
		//    Object dump complete.

		MT::SpinLock lock(m_spin_mutex);
		int32_t count = m_map.size();

		if (count)
		{
			log("Detected memory leaks!");
			log("Dumping objects ->");
		}
		else
		{
			log("No leaks detected!");
		}

		for (EntryTable::iterator it = m_map.begin(); it != m_map.end(); ++it)
		{
			char string[512];

			Entry& entry = *it;
			void* adr = it.key();

			if (entry.file() != NULL)
			{
				sprintf(string, "%s(%d): {%d} normal block at %p, %lu bytes long.", entry.file(), entry.line(), entry.allocID(), adr, entry.size());
			}
			else
			{
				sprintf(string, "{%d} normal block at %p, %lu bytes long.", entry.allocID(), adr, entry.size());
			}
			log("%s", string);

			int32_t str_len = Math::min(16, (int32_t)entry.size());
			char asci_buf[17];
			memset(asci_buf, 0, 17);
			memcpy(asci_buf, adr, str_len);

			sprintf(string, "Data: <%s>", asci_buf);
			for (int j = 0; j < str_len; j++)
			{
				char hex[4];
				memset (hex, 0, sizeof(hex));
				sprintf(hex, " %.2X", *((uint8_t*)adr + j));
				strcat(string, hex);
			}
			log("%s", string);
		}
		if(count)
		{
			log("	  Object dump complete.");
		}
	}

	void MemoryTracker::dumpSortedByAllocationOrder()
	{
		// Detected memory leaks!
		// Dumping objects ->
		// {147} normal block at 0x003AF7C0, 10 bytes long.
		// Data: <          > CD CD CD CD CD CD CD CD CD CD
		// d:\temp\zmazat\tt\tt\mainfrm.cpp(34) : {145} normal block at 0x003AF760, 30 bytes long.
		// Data: <               > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD
		//    Object dump complete.

		MT::SpinLock lock(m_spin_mutex);
		int count = m_map.size();

		if (count)
		{
			log("Detected memory leaks!");
			log("Dumping objects ->");
		}
		else
		{
			log("No leaks detected!");
		}

		map_alloc_order alloc_order_map;
		for (EntryTable::iterator it = m_map.begin(); it != m_map.end(); ++it)
		{
			Entry& entry = *it;
			alloc_order_map.insert(entry.allocID(), &entry);
		}

		for (map_alloc_order::iterator it = alloc_order_map.begin(); it != alloc_order_map.end(); ++it)
		{
			char string[512];
			Entry& entry = *(it.second());
			if (entry.file() != NULL)
			{
				sprintf(string, "%s(%d): {%d} normal block, %lu bytes long.", entry.file(), entry.line(), entry.allocID(), entry.size());
			}
			else
			{
				sprintf(string, "{%d} normal block, %lu bytes long.", entry.allocID(), entry.size());
			}

			log("%s", string);
		}

		if(count)
		{
			log("	  Object dump complete.");
		}
	}

	void MemoryTracker::dumpTruncatedPerFileLine()
	{
		log("Dumping objects ->");

		file_line_map report_map;
		{
			MT::SpinLock lock(m_spin_mutex);
			for (EntryTable::iterator it = m_map.begin(); it != m_map.end(); ++it)
			{
				Entry& entry = *it;

				FileLineReport r;
				r.file = entry.file();
				r.line = entry.line();

				file_line_map::iterator rit = report_map.find(r);
				if(rit != report_map.end())
					rit.second() += entry.size();
				else
					report_map.insert(r, entry.size());
			}
		}

		for (file_line_map::iterator it = report_map.begin(); it != report_map.end(); ++it)
		{
			char string[512];

			const FileLineReport &rep = it.first();
			size_t size = it.second();

			const char *file = rep.file ? rep.file : "unknown";

			if(size >= 1000000)
				sprintf(string, "%30s(%5d) : %2lu %03lu %03lu", file, rep.line, size / 1000000, (size % 1000000) / 1000, (size & 1000));
			else if(size >= 1000)
				sprintf(string, "%30s(%5d) : %6lu %03lu", file, rep.line, size / 1000, size % 1000);
			else
				sprintf(string, "%30s(%5d) : %10lu", file, rep.line, size);

			log("%s", string);
		}

		log("Object dump complete.");
	}

	void MemoryTracker::dumpTruncatedPerFile()
	{
		log("Dumping objects ->");

		file_map report_map;
		{
			MT::SpinLock lock(m_spin_mutex);
			for (EntryTable::iterator it = m_map.begin(); it != m_map.end(); ++it)
			{
				Entry& entry = *it;


				file_map::iterator rit = report_map.find(entry.file());
				if(rit != report_map.end())
					rit.second() += entry.size();
				else
					report_map.insert(entry.file(), entry.size());
			}
		}

		for (file_map::iterator it = report_map.begin(); it != report_map.end(); ++it)
		{
			char string[512];

			size_t size = it.second();
			const char *file = it.first();

			if(size >= 1000000)
				sprintf(string, "%30s : %2lu %03lu %03lu", file, size / 1000000, (size % 1000000) / 1000, (size & 1000));
			else if(size >= 1000)
				sprintf(string, "%30s : %6lu %03lu", file, size / 1000, size % 1000);
			else
				sprintf(string, "%30s : %10lu", file, size);

			log("%s", string);
		}

		log("Object dump complete.");
	}

	void MemoryTracker::markAll()
	{
		MT::SpinLock lock(m_spin_mutex);

		for (EntryTable::iterator it = m_map.begin(); it != m_map.end(); ++it)
		{
			(*it).mark();
		}
		++m_mark;
	}

	void MemoryTracker::dumpUnmarked()
	{
		// Detected memory leaks!
		// Dumping objects ->
		// {147} normal block at 0x003AF7C0, 10 bytes long.
		// Data: <          > CD CD CD CD CD CD CD CD CD CD
		// d:\temp\zmazat\tt\tt\mainfrm.cpp(34) : {145} normal block at 0x003AF760, 30 bytes long.
		// Data: <               > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD
		//    Object dump complete.

		//	Lock lock(m_lock);

		MT::SpinLock lock(m_spin_mutex);

		size_t size = 0;

		log("Dumping objects ->");

		for (EntryTable::iterator it = m_map.begin(); it != m_map.end(); ++it)
		{
			char string[512];

			Entry& entry = *it;
			void* adr = it.key();

			if (0 == entry.getMark() || m_mark == entry.getMark())
				continue;

			size += entry.size();

			if (entry.file() != NULL)
			{
				sprintf(string, "%s(%d) : {%d} normal block at %p, %lu bytes long.", entry.file(), entry.line(), entry.allocID(), adr, entry.size());
			}
			else
			{
				sprintf(string, "{%d} normal block at %p, %lu bytes long.", entry.allocID(), adr, entry.size());
			}

			log("%s", string);

			int str_len = Math::min(16, (int)entry.size());
			char asci_buf[17];
			memset(asci_buf, 0, 17);
			memcpy(asci_buf, adr, str_len);

			sprintf(string, "Data: <%s>", asci_buf);
			for (int j = 0; j < str_len; j++)
			{
				char hex[4];
				memset (hex, 0, sizeof(hex));
				sprintf(hex, " %.2X", *((uint8_t*)adr + j));
				strcat(string, hex);
			}

			log("%s", string);
		}

		if (0 < size) {
			log("Size of all objects: %u", size);
		}
	}

	MemoryTracker::MemoryTracker()
		: m_spin_mutex(false)
		, m_mark(0)
		, m_allocated_memory(0)
	{
	}

	MemoryTracker::~MemoryTracker()
	{
		Lux::MemoryTracker::getInstance().dumpDetailed();
	}
	
	void MemoryTracker::log(const char* message, ...) const
	{
		if (m_debugger_log.isValid())
		{
			char tmp[1024];
			va_list args;
			va_start(args, message);
			vsnprintf(tmp, 1021, message, args);
			va_end(args);
			
			m_debugger_log.invoke("MemoryTracker", tmp);
		}
	}

} //~namespace Lux

#endif //~MEM_TRACK
