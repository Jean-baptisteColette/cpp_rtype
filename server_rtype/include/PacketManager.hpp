#pragma once

#include <iostream>
#include <memory>
#include "Data.hpp"
#include "Packet.hpp"
#include "ClientManager.hpp"
#include "UnixSocket.hpp"
class PacketManager
{
private:
    Socket &_socket;
    ClientManager &_clientM;
    void (PacketManager::*f[15])(std::shared_ptr<Packet> p);
    char _opcodes[15];

    void _key(std::shared_ptr<Packet> p);
    void _handShake(std::shared_ptr<Packet> p);

  public:
    PacketManager(Socket &_s, ClientManager &c);
    ~PacketManager();
    void handlePacket(std::shared_ptr<Packet> p);
};