#pragma once
#include <iostream>
#include <exception>

class RoomException : public std::exception
{
    virtual const char *what() const throw()
    {
        return "No room found";
    }
};