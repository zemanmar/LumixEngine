#include "core/net/tcp_connector.h"
#include "core/net/tcp_stream.h"

#ifndef DISABLE_NETWORK

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

namespace Lux
{
	namespace Net
	{
		TCPConnector::~TCPConnector()
		{
			::close((int)m_socket);
		}
		
		TCPStream* TCPConnector::connect(const char* ip, uint16_t port)
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
			
			if (::connect(socket, (const struct sockaddr*)&sin, sizeof(sin)) != 0)
			{
				::close(socket);
				return NULL;
			}
			
			m_socket = socket;
			return LUX_NEW(TCPStream)(socket);
		}
	} // ~namespace Net
} // ~namespace Lux

#endif //DISABLE_NETWORK
