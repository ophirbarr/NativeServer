#if !defined(SOCKET_LISTENER__INCLUDED_)
#define SOCKET_LISTENER__INCLUDED_

#include "CThread.h"
#include "SocketSender.h"
#include "string.h"

#define DEFAULT_BUFLEN 512

class SocketListener : public CThread {
protected:
    WSADATA wsaData;
    SOCKET ClientSocket;
    struct addrinfo *result, hints;
    char recvbuf[DEFAULT_BUFLEN];
    int iResult, iSendResult;
    int recvbuflen;
	BOOL listening;
	BOOL reading;
	SocketSender* sender;

public:
	SocketListener(SOCKET socket);
	void setSender(SocketSender* sender);
	DWORD m_ThreadFunc();

protected:
	void HandleMessage(const char* xml);
};

#endif
