#ifdef _WIN32
#include "WindowsSocket.hpp"
#else
#include "UnixSocket.hpp"
#endif
#include <ctype.h>
#include <string.h>

#include "Data.hpp"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <memory>

#include "World.hpp"
#include "Game.hpp"

int main(int ac, char **av)
{
  if (ac != 3)
  {
    std::cout << "Error on usage : ./client_rtype IP PORT" << std::endl;
    return (1);
  }
  try
  {
    Socket socket(av[1], av[2], 1);
    if (socket.openSocket() == false)
      std::cout << "error open" << std::endl;
    t_connection t;
    t.opcode = 0x0A;
    if (socket.sendPacket(&t, sizeof(t_connection)) == true)
    {
      std::cout << "msg envoyé" << std::endl;
    }
    Game g(socket);
    g.connection();
    g.play();
  }
  catch (const std::invalid_argument &ia)
  {
    std::cerr << "wrong port\n";
  }
  return 0;
}
