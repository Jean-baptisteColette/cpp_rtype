#ifdef _WIN32
#else
#include "include/UnixSocket.hpp"

Socket::Socket(const std::string &ip, char *port, int side)
{
    int p;

    p = std::stoi(port);

    this->_len = sizeof(this->_client);
    this->_server.sin_family = AF_INET;
    this->_server.sin_port = htons(p);
    if (side == 0)
        this->_server.sin_addr.s_addr = htonl(INADDR_ANY);
    else
    {

        struct hostent *s;
        s = gethostbyname(ip.c_str());
        if (s == NULL)
        {
            fprintf(stderr, "ERROR, no such host as %s\n", ip.c_str());
            exit(0);
        }

        bzero((char *)&_server, sizeof(_server));
        _server.sin_family = AF_INET;
        bcopy((char *)s->h_addr,
              (char *)&_server.sin_addr.s_addr, s->h_length);
        _server.sin_port = htons(p);

        this->_dest = this->_server;
        /* if (inet_aton(ip.c_str(), &_client.sin_addr) == 0)
        {
            fprintf(stderr, "inet_aton() failed\n");
            exit(1);
        }*/
    }
}

Socket::~Socket()
{
}
/*
int Server::checkArgs(char *port)
{
    for (size_t i = 0; i < strlen(port); i++)
    {
        if (!isdigit(port[i]))
        {
            std::cout << "Wrong port" << std::endl;
            return (-1);
        }
    }
    std::stoi(port)
    return (0);
}
*/

bool Socket::openSocket()
{
    if ((this->_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        throw this->_exception;
        return false;
    }
    return true;
}

bool Socket::bindSocket()
{
    if (bind(this->_socket, (struct sockaddr *)&_server, sizeof(this->_server)) == -1)
        return false;
    return true;
}

Packet *Socket::recvPacket()
{
    int rcvLen = 0;
    if ((rcvLen = recvfrom(this->_socket, this->_buf, BUFLEN, 0, (struct sockaddr *)&this->_client, &this->_len)) == -1)
        throw this->_exception;
    return new Packet(this->_buf, rcvLen, this->_client);
}

void Socket::setDest(struct sockaddr_in &dest)
{
    this->_server = dest;
}

bool Socket::sendPacket(void *data, std::size_t len)
{
    int sendLen = 0;
    if ((sendLen = sendto(this->_socket, data, len, 0, (struct sockaddr *)&this->_server, this->_len)) == -1)
        return false;
    return true;
}

int Socket::getSocket()
{
    return this->_socket;
}

#endif
