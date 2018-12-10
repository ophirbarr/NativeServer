#include "stdafx.h"
#include "SocketSender.h"
#include <iostream>
#include <fstream>
#include <string>

#include "defines.hpp"
#include "ProcessingOptions.hpp"
#include "Processor.hpp"


SocketSender::SocketSender(SOCKET client) {
	this->clientSocket = client;
}


void SocketSender::sendProcessResponse(const char* msg) {

	// DEBUG ------------------------------------------------------------------------------
	std::cout << "Running algorithm..." << std::endl;

	// Set OpenCFU options
	ProcessingOptions opts;
	opts.setImage("assets\\test.jpg");
	opts.setThr(3);
	opts.setThrMode(OCFU_THR_INV);
	opts.setMinMaxRad(std::make_pair(30, 200));
	opts.setTrainedClassifierPath(TRAINED_CLASSIFIER_PATH);
	opts.setTrainedClassifierPSPath(TRAINED_CLASSIFIER_PS_PATH);

	// Run OpenCFU
	Processor processor(opts);
	processor.runAll();
	processor.writeResult();

	// send message to client
	// sendXMLToClient(response);
	// DEBUG ------------------------------------------------------------------------------




	/*

	+++TODO+++
		1. PARSE MESSAGE (EXTRACT PARAMETERS)
		2. SET PARAMETERS IN OPTIONS
		3. RUN PROCESSOR
		4. PREPARE RESPONSE
		5. SEND RESPONSE TO CLIENT

	*/
}


void SocketSender::sendXmlResponse() {
	//char buffer[200000];
	std::string buffer = "";
	char line_buffer[512];
	line_buffer[0] = '\0';
	buffer[0] = '\0';

	std::ifstream instream("assets\\file.xml");
	while (instream.get(line_buffer, 512))
		//strcat(buffer, line_buffer);
		buffer.append(line_buffer);
	instream.close();

	sendMsgToClient(buffer.c_str());
}



void SocketSender::sendHostnameResponse() {
	char hostname[32];
	gethostname(hostname, 32);

	char buffer[512];
	buffer[0] = 0;
	sprintf_s( 
		buffer, 
		"<Response><Name>HostnameResponse</Name><Hostname>%s</Hostname></Response>\n", hostname);

	sendMsgToClient(buffer);
}


void SocketSender::sendMemoryResponse() {
	MEMORYSTATUS memory;
	GlobalMemoryStatus(&memory);

	char buffer[512];
	buffer[0] = 0;
	sprintf_s( 
		buffer, 
		"<Response><Name>MemoryResponse</Name><TotalPhysicalMemory>%i</TotalPhysicalMemory></Response>\n", 
		memory.dwTotalPhys);

	sendMsgToClient(buffer);
}


void SocketSender::sendRandomNumberResponse() {
	char buffer[512];
	buffer[0] = 0;

	srand(GetTickCount());
	int num = rand();

	sprintf_s(buffer, "<Response><Name>RandomNumberResponse</Name><Number>%i</Number></Response>\n", num);
	sendMsgToClient(buffer);
}


void SocketSender::sendMsgToClient(const char* msg) {
	// Send some string to the client
	int len = strlen(msg);
    int sent = send( clientSocket, msg, len, 0 );

    if ( sent == SOCKET_ERROR ) {
        printf( "send failed\n");
        closesocket( clientSocket );
        return;
    }

	printf( "%i bytes sent to client\n", sent);
}