#pragma once

#include <vector>
#include "Client.hpp"
#include <thread>
#include "UnixSocket.hpp"
class Room
{
private:
    Socket &_socket;
    int _id;
    std::vector<Client> _client;
    std::vector<char*> _instruction;

  public:
    Room(int, std::vector<Client>, Socket&);
    ~Room();
    int getId();
    void setId(int);
    void deleteClientToRoom(Client);
    std::shared_ptr<std::thread> spawnThread();
    void stopRoom();
    void pushInstruction(char*);
    bool isClient(const struct sockaddr_in &client);

};
