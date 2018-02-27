#include "PacketManager.hpp"

PacketManager::PacketManager(Socket &s, ClientManager &clientM) :  _socket(s), _clientM(clientM)
{
    this->_opcodes[0] = HELLO_FROM_CLIENT;
    this->_opcodes[1] = KEY_EVENT;
    this->f[0] = &PacketManager::_handShake;
    this->f[1] = &PacketManager::_key;
}

PacketManager::~PacketManager()
{
}

void PacketManager::_handShake(std::shared_ptr<Packet> p)
{
    Client c(p->getClientIp());
    this->_clientM.addClientList(c);
    this->_socket.setDest(c.getIp());
    t_connection t;
    t.opcode = 0x0B;
    if (this->_socket.sendPacket(&t, sizeof(t_connection)) == true)
    {
        std::cout << "send hello to client" << std::endl;
    }
    else
    {
        std::cout << "i can't say hello\n";
    }
}
void PacketManager::_key(std::shared_ptr<Packet> p)
{
    try
    {
        std::shared_ptr<Room> tmp = this->_clientM.getRoomManager().getRoomFromClient(p->getClientIp());
        tmp->pushInstruction(p->getBufChar());
        std::cout << "Action recu\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void PacketManager::handlePacket(std::shared_ptr<Packet> p)
{
    int i = 0;
    while (i < 15)
    {
        if (p->getBuf().at(0) == this->_opcodes[i])
        {
            (this->*f[i])(p);
        }
        i++;
    }
}