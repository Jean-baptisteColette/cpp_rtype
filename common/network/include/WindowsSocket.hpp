#pragma once

#ifdef _WIN32

#include <ws2tcpip.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib") //Winsock Library

#include <iostream>
#include <functional>
#include "ISocket.hpp"
#include "NetException.hpp"

int runClient(const std::string &ip, int port);

class WindowsSocket : public ISocket
{
  public:
	WindowsSocket(const std::string &ip, int port, int side);
	virtual ~WindowsSocket();
	virtual bool openSocket() final;
	virtual bool bindSocket() final;
	virtual Packet *recvPacket() final;
	virtual bool sendPacket() final;

  private:
	NetException _exception;
	struct sockaddr_in _server;
	struct sockaddr_in _client;
	char _buf[BUFLEN];
	socklen_t _len;
	int _socket;
	WSADATA _wsa;
};

#else
#endif