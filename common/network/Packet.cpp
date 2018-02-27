#include "Packet.hpp"

Packet::Packet(char *buf, int len, struct sockaddr_in client) : _buf(buf), _len(len), _client(client)
{
}

Packet::~Packet()
{
}

std::string Packet::getBuf()
{
    return this->_buf;
}

int Packet::getLen() const
{
    return this->_len;
}

struct sockaddr_in  Packet::getClientIp() const{
    return this->_client;
}

char *Packet::getBufChar(){
    return this->_buf;
}

/*

vector<room> rooms
rooms[i].pushInstrcerrfer(void*)
vector<int, clients> clients


ClientManager clientM(&clients, &rooms)
//RoomManager roomM(&rooms)

*/