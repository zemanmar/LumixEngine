#include "core/lux.h"
#include "core/fs/os_file.h"

#include <assert.h>
#include <stdio.h>

namespace Lux
{
	namespace FS
	{
		struct OsFileImpl
		{
			FILE* m_file;
		};

		OsFile::OsFile()
		{
			m_impl = NULL;
		}

		OsFile::~OsFile()
		{
			ASSERT(NULL == m_impl);
		}

		bool OsFile::open(const char* path, Mode mode)
		{
			FILE* file = NULL;
			if(Mode::OPEN & mode)
			{
				file = ::fopen(path, "r+");
			}
			else if(Mode::OPEN_OR_CREATE & mode)
			{
				file = ::fopen(path, "w+");
			}
			else if(Mode::RECREATE & mode)
			{
				file = ::fopen(path, "w+");
			}
			else
			{
				return false;
			}

			if(NULL != file)
			{
				TODO("lock-free free list");
				OsFileImpl* impl = LUX_NEW(OsFileImpl); 
				impl->m_file = file;
				m_impl = impl;

				return true;
			}

			return false;
		}

		void OsFile::close()
		{
			if (NULL != m_impl)
			{
				::fclose(m_impl->m_file);
				LUX_DELETE(m_impl);
				m_impl = NULL;
			}
		}

		bool OsFile::write(const void* data, size_t size)
		{
			ASSERT(NULL != m_impl);
			size_t written = ::fwrite(data, 1, size, m_impl->m_file);
			return size == written;
		}

		bool OsFile::read(void* data, size_t size)
		{
			ASSERT(NULL != m_impl);
			size_t read = ::fread(data, 1, size, m_impl->m_file);
			return size == read;
		}

		size_t OsFile::size()
		{
			ASSERT(NULL != m_impl);
			fpos_t pos;
			fgetpos(m_impl->m_file, &pos);
			fseek(m_impl->m_file, 0, SEEK_END);
			size_t size = ftell(m_impl->m_file);
			fsetpos(m_impl->m_file, &pos);
			
			return size;
		}

		size_t OsFile::pos()
		{
			ASSERT(NULL != m_impl);
			return ftell(m_impl->m_file);
		}

		size_t OsFile::seek(SeekMode base, size_t pos)
		{
			ASSERT(NULL != m_impl);
			int dir = 0;
			switch(base)
			{
			case SeekMode::BEGIN:
				dir = SEEK_SET;
				break;
			case SeekMode::END:
				dir = SEEK_END;
				break;
			case SeekMode::CURRENT:
				dir = SEEK_CUR;
				break;
			}

			return fseek(m_impl->m_file, pos, dir);
		}

		void OsFile::writeEOF()
		{
		}
	} // ~namespace FS
} // ~namespace Lux
