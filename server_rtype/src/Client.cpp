#include <iostream>
#include "Client.hpp"

Client::Client(struct sockaddr_in ip)
{
    this->_ip = ip;
    this->_player = Player();
    std::cout << "Client create" << std::endl;
}

Client::~Client()
{
}

Player              Client::getPlayer()
{
    return this->_player;
}

void                Client::setPlayer(Player player)
{
    this->_player = player;
}

struct sockaddr_in  &Client::getIp()
{
    return this->_ip;
}

void                Client::setIp(struct sockaddr_in ip)
{

}