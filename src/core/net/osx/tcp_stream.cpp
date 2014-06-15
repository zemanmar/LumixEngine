#include "core/net/tcp_stream.h"

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

namespace Lux
{
	namespace Net
	{
		TCPStream::~TCPStream()
		{
			::close((int)m_socket);
		}
		
		bool TCPStream::readString(char* string, uint32_t max_size)
		{
			uint32_t len = 0;
			bool ret = true;
			ret &= read(len);
			ASSERT(len < max_size);
			ret &= read((void*)string, len);
			
			return ret;
		}
		
		bool TCPStream::writeString(const char* string)
		{
			uint32_t len = (uint32_t)strlen(string) + 1;
			bool ret = write(len);
			ret &= write((const void*)string, len);
			
			return ret;
		}
		
		bool TCPStream::read(void* buffer, size_t size)
		{
			int32_t to_receive = (int32_t)size;
			char* ptr = static_cast<char*>(buffer);
			
			do
			{
				ssize_t received = ::recv((int)m_socket, ptr, to_receive, 0);
				ptr += received;
				to_receive -= received;
				if(received <= 0)
				{
					if(errno == EAGAIN)
					{
						ptr -= received;
						to_receive += received;
					}
					else
					{
						return false;
					}
				}
			} while(to_receive > 0);
			return true;
		}
		
		bool TCPStream::write(const void* buffer, size_t size)
		{
			ssize_t send = ::send((int)m_socket, static_cast<const char*>(buffer), (int)size, 0);
			
			TODO("handle errors");
			
			return (size_t)send == size;
		}
	} // ~namespace Net
} // ~namespace Lux