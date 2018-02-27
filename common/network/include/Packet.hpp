#pragma once
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Packet
{
public:
  Packet(char *buf, int len, struct sockaddr_in client);
  ~Packet();
  std::string getBuf();
  char *getBufChar();
  int getLen() const;
  //const struct t_packet &getPacket() const;
struct sockaddr_in  getClientIp() const;
private:
  char *_buf;
  int _len;
  struct sockaddr_in _client;
//  struct sockaddr_in _client;
};