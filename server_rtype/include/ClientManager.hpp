#pragma once

#include <vector>
#include "Client.hpp"
#include "RoomManager.hpp"

class ClientManager
{
private:
    std::vector<Client>         &_clientList;
    int                         _nbClient;
    RoomManager                 &_rooms;

public:
    ClientManager(std::vector<Client>&, RoomManager&);
    ~ClientManager();
    int         getNbClient();
    void        setNbClient(int);
    RoomManager& getRoomManager() const;
   // void        setRoomManager(RoomManager&);// pas utile
    int         addClientList(Client&);
    int         removeClientList();
    void        verifIfCreateARoom();
   
    /**TODO **/
    /**
     * Room &getRoomFromClient(const struct sockaddr_in &) const;
     * 
     * 
     * 
     * 
     * **/

};