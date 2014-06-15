#include "core/net/tcp_acceptor.h"
#include "core/net/tcp_stream.h"

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

namespace Lux
{
	namespace Net
	{
		TCPAcceptor::~TCPAcceptor()
		{
			::close((int)m_socket);
		}
		
		bool TCPAcceptor::start(const char* ip, uint16_t port)
		{			
			int socket = ::socket(PF_INET, SOCK_STREAM, 0);
			if(socket < 0)
			{
				return NULL;
			}
			
			struct sockaddr_in sin;
			memset (&sin, 0, sizeof(sin));
			sin.sin_family = AF_INET;
			sin.sin_port = htons(port);
			
			::inet_pton(AF_INET, ip, &sin);
			
			int retVal = ::bind(socket, (struct sockaddr*)&sin, sizeof(sin));
			if(retVal < 0)
			{
				::close(socket);
				return false;
			}
			
			m_socket = socket;
			
			return ::listen(socket, 10) == 0;
		}
		
		TCPStream* TCPAcceptor::accept()
		{
			int socket = ::accept((int)m_socket, NULL, NULL);
			return LUX_NEW(TCPStream)(socket);
		}
	} // ~namespace Net
} // ~namespace Lux