#include <ctype.h>
#include <string.h>
#include <iostream>
#include <stdexcept>
#include "Server.hpp"
#include "ClientManager.hpp"

int main(int ac, char **av)
{
  if (ac != 3)
  {
    std::cout << "Error on usage : ./server_rtype IP PORT" << std::endl;
    return (1);
  }

  try
  {
    std::vector<Client> clients;
    Socket socket(av[1], av[2], SERVER);
    RoomManager   manageRoom(socket);
    ClientManager manageClient(clients, manageRoom);
    
    Server  srv(socket, manageClient);
    if (socket.openSocket() == false)
      std::cout << "error open" << std::endl;
    if (socket.bindSocket() == false)
      std::cout << "error bind" << std::endl;

      srv.run();
  }
  catch (const std::invalid_argument &ia)
  {
    std::cerr << "wrong port\n";
  }

  return (0);
}
