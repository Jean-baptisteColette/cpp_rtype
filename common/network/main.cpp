#include "./include/UnixSocket.hpp"

int main(int ac, char **av)
{
    UnixSocket socket("127.0.0.1", 9930, 0);
    try
    {
        if (socket.openSocket() == false)
            std::cout << "error open" << std::endl;
        if (socket.bindSocket() == false)
            std::cout << "error open" << std::endl;
        while (true)
        {
            if (socket.recvPacket() == false)
                std::cout << "error open" << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "openSocket()" << std::endl;
    }

    return 0;
}
