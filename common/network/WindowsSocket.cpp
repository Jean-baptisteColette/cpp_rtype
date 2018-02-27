#ifdef _WIN32

#include "WindowsSocket.hpp"

WindowsSocket::WindowsSocket(const std::string &ip, int port, int side)
{
	this->_len = sizeof(this->_client);
	this->_client.sin_family = AF_INET;
	this->_client.sin_port = htons(port);
	this->_client.sin_addr.s_addr = INADDR_ANY;
	std::cout << "[WINDOWS]" << std::endl;
	if (WSAStartup(MAKEWORD(2, 2), &_wsa) != 0)
	{
		std::cout << "Error Code :" << WSAGetLastError() << std::endl;
		throw this->_exception;
	}
}

WindowsSocket::~WindowsSocket()
{
	WSACleanup();
}

bool WindowsSocket::openSocket()
{
	if ((this->_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		throw this->_exception;
		return false;
	}
	return true;
}

bool WindowsSocket::bindSocket()
{
	if (bind(this->_socket, (struct sockaddr *)&_server, sizeof(this->_server)) == -1)
		return false;
	return true;
}

Packet * WindowsSocket::recvPacket()
{
    int rcvLen = 0;
    if ((rcvLen = recvfrom(this->_socket, this->_buf, BUFLEN, 0, (struct sockaddr *)&this->_client, &this->_len)) == -1)
            throw this->_exception;
   
    return new Packet(this->_buf);
}

bool WindowsSocket::sendPacket()
{
	int sendLen = 0;
	if ((sendLen = sendto(this->_socket, this->_buf, BUFLEN, 0, (struct sockaddr *)&this->_client, this->_len)) == -1)
		return false;
	return true;
}
#else
#endif
