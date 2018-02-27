#include <iostream>
#include "ClientManager.hpp"
#include "Room.hpp"

ClientManager::ClientManager(std::vector<Client> &clients, RoomManager &rooms) : _clientList(clients) , _rooms(rooms)
{
    this->_nbClient = 0;
    std::cout << "New ManageClient create" << std::endl;
}

ClientManager::~ClientManager()
{

}

int     ClientManager::getNbClient()
{
    return this->_nbClient;
}  

void    ClientManager::setNbClient(int i)
{
    this->_nbClient += i;
}

RoomManager  &ClientManager::getRoomManager() const
{
    return this->_rooms;
}
/*
void        ClientManager::setRoomManager(RoomManager &room)
{
    this->_rooms = room;
}*/

void    ClientManager::verifIfCreateARoom()
{
    std::cout << "Nb Client in ManageClient List : " << this->getNbClient() << std::endl;
    if (this->getNbClient() >= 4)
        {
            //Crée une nouvelle room avec les 4 clients! 
            std::cout << "Need to create a new room" << std::endl;
            this->getRoomManager().createRoom(this->_clientList);
            //Delete les 4 clients de la list 
            for (int i = 0; i < 4; i++)
               this->removeClientList();
        }
}

int     ClientManager::addClientList(Client &client)
{
    this->_clientList.push_back(client);
    this->setNbClient(1);
    this->verifIfCreateARoom();
    return 0;
}

int     ClientManager::removeClientList()
{
    this->setNbClient(-1);
    this->_clientList.pop_back();
    return 0;
}