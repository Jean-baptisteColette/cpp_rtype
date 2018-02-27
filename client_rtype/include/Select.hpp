#pragma once
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
class Select
{
  public:
    Select(int socket);
    ~Select();

    void mySelect(int socket);
    bool isNewMsg(int socket);

  private:
    fd_set _read_fds;
    fd_set _write_fds;
    int on = 1;
};