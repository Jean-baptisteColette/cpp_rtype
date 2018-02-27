#pragma once

#include <netinet/ip.h>
#include "Player.hpp"
#include "UnixSocket.hpp"

class Client
{
private:
    Player _player;
    struct sockaddr_in _ip;

public:
    Client(struct sockaddr_in);
    ~Client();
    Player              getPlayer();
    void                setPlayer(Player);
    struct sockaddr_in&  getIp();
    void                setIp(struct sockaddr_in);
};