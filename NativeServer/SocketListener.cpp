#include "stdafx.h"
#include "SocketListener.h"

SocketListener::SocketListener(SOCKET socket) {
	recvbuflen = DEFAULT_BUFLEN;
	this->ClientSocket = socket;
}

DWORD SocketListener::m_ThreadFunc()
{
	listening = true;
	while (listening)
	{
		int len = 0;
		//char buffer[524288]; // 500 KB
		//char buffer[819200]; // 800 KB
		std::string buffer = "";

		buffer[0] = '\0';
		reading = true;
		while (reading)
		{
			int iResult = recv(ClientSocket, recvbuf, recvbuflen - 1, 0);
			len += iResult;
			if (iResult > 0)
			{
				printf("Bytes received: %d\n", iResult);
				recvbuf[iResult] = '\0';

				//strcat(buffer, recvbuf);
				buffer.append(recvbuf);

				if (strstr(recvbuf, "</Request>"))
				{
					buffer[len] = '\0';
					printf("Total bytes received: %d\n", len);
					reading = false;
					HandleMessage(buffer.c_str());
				}
			}
			else
			{
				printf("Client connection closing\n");
				closesocket(ClientSocket);
				return 1;
			}
		}
	}

	return 0;
}


void SocketListener::setSender(SocketSender* sender) {
	this->sender = sender;
}


char* strstri(const char* t, char* s) {
	int i, j;

	//	for ( i = 0; t[i] != '\0'; i++ ) {		// No-limit search --- replaced
	for (i = 0; (i < 100) && (t[i] != '\0'); i++) {
		for (j = 0; s[j] != '\0'; j++) {
			if (toupper(s[j]) == toupper(t[i + j]))
				continue;
			else
				break;
		}

		// if the whole string was successfully compared, exit the loop
		if (s[j] == '\0')
			break;
	}


	if (s[j] == '\0') {
		// returns a pointer to the first occurrence 
		// of s within t, just like the original strstr
		return ((char*)(i + t));

	}

	// Not found
	return 0;
}


void SocketListener::HandleMessage(const char* msg) {

	/*
	if ( this->sender == NULL )
		return;
	*/


	if (strstri(msg, "RequestProcess") != 0) {
		printf("Client sent 'RequestProcess' request message\n");
		if (sender != NULL)
			sender->sendProcessResponse(msg);
	}
	
	else if (strstri(msg, "GetXML") != 0) {
		printf("Client sent 'XML' request message\n");
		if (sender != NULL)
			sender->sendXmlResponse();
	}
	
	else if ( strstri(msg, "GetHostname") != 0 ) {
		printf("Client sent 'GetHostname' request message\n");
		if ( sender != NULL )
			sender->sendHostnameResponse();
	}

	else if ( strstri(msg, "GetMemory") != 0 ) {
		printf("Client sent 'GetMemory' request message\n");
		if ( sender != NULL )
			sender->sendMemoryResponse();
	}

	else if ( strstri(msg, "GetRandomNumber" ) != NULL ) {
		printf("Client sent 'GetRandomNumber' request message\n");
		if ( sender != NULL )
			sender->sendRandomNumberResponse();
	}
}

