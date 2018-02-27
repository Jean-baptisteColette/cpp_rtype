#pragma once
#include <iostream>
#include <exception>

class NetException : public std::exception
{
    virtual const char *what() const throw()
    {
        return "ERROR on network : ";
    }
};