#pragma once

#include <vector>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "Room.hpp"
#include "UnixSocket.hpp"
class RoomManager
{
private:
  Socket &_socket;
  std::vector<std::shared_ptr<Room>> _roomList;
  std::vector<std::shared_ptr<std::thread>> _threadList;
public:
  RoomManager(Socket &s);
  ~RoomManager();
  std::vector<std::shared_ptr<Room>> getRoomList();
  void createRoom(std::vector<Client>);
  void deleteRoom(int);
  std::shared_ptr<Room> getRoomFromClient(const struct sockaddr_in &); /**TODO**/


};