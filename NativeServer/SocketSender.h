#if !defined(SOCKET_SENDER__INCLUDED_)
#define SOCKET_SENDER__INCLUDED_

#define DEFAULT_BUFLEN 512
#define TRAINED_CLASSIFIER_PATH "assets\\trainedClassifier.xml"
#define TRAINED_CLASSIFIER_PS_PATH "assets\\trainedClassifierPS.xml"

class SocketSender {
protected:
    WSADATA wsaData;
    SOCKET clientSocket;
    struct addrinfo *result, hints;
    char recvbuf[DEFAULT_BUFLEN];
    int iResult, iSendResult;
    int recvbuflen;

public:
	SocketSender(SOCKET client);

	void sendProcessResponse(const char* msg);
	void sendXmlResponse();
	void sendHostnameResponse();
	void sendMemoryResponse();
	void sendRandomNumberResponse();

protected:
	void sendMsgToClient(const char* msg);
};

#endif