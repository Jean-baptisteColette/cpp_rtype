#include <iostream>
#include <sys/ioctl.h>
#include "Select.hpp"

Select::Select(int socket)
{
    int rc  = ioctl(socket, FIONBIO, (char*)&on);
    if (rc < 0){
        std::cout << "ioctl error" << std::endl;
    }
}

Select::~Select()
{
}

void Select::mySelect(int socket)
{
    FD_ZERO(&_read_fds);
    FD_SET(socket, &_read_fds);
    int n = select(socket + 1, &_read_fds, &_write_fds, 0, 0);
    if (n < 0)
    {
        std::cout << "error select\n";
        return;
    }
}

bool Select::isNewMsg(int socket)
{
    if (FD_ISSET(socket, &_read_fds))
        return true;
    else
        return false;
}