#pragma once
#ifdef	_WIN32
#else
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <functional>
#include "ISocket.hpp"
#include "NetException.hpp"

//int	runUnixClient(const std::string &ip, int port);
//int	runUnixServer(int port);

class Socket : public ISocket //ASOcket qui hérite de ISocket ->sockaddr ->buffer
{
public:
  Socket(const std::string &ip, char *port, int side);
  virtual ~Socket();
  virtual bool openSocket() final;
  virtual bool bindSocket() final;
  virtual Packet* recvPacket() final; //unique pointer
  virtual bool sendPacket(void *data, std::size_t len) final;
  int getSocket();
  void setDest(struct sockaddr_in &dest);
private:
  NetException _exception;
  struct sockaddr_in _server;
  struct sockaddr_in _client;
  struct sockaddr_in _dest;
  char _buf[BUFLEN];
  socklen_t _len;
  int _socket;
  int _port;
};

#endif
