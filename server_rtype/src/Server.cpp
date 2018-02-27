#include <memory>
#include "Server.hpp"

Server::Server(Socket &socket,ClientManager &clientM) : _socket(socket), _clientM(clientM)
{
    _packetManager = std::make_shared<PacketManager>(_socket, _clientM);
}

Server::~Server()
{
    std::cout << "destroy server\n";
}

void Server::run()
{

    while (true)
    {
        std::shared_ptr<Packet> res(_socket.recvPacket());
        std::cout << res->getClientIp().sin_family << "     " << res->getClientIp().sin_port << std::endl;
        this->handleMsg(res);
        this->_clientM.getRoomManager().deleteRoom(0);
    }
}

void Server::handleMsg(std::shared_ptr<Packet> p)
{
    int i;
    int j;
    _packetManager->handlePacket(p);
}
