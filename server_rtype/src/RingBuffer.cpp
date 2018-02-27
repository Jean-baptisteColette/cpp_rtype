#include "RingBuffer.hpp"

RingBuffer::RingBuffer(std::size_t cap) : _buffer(cap)
{
}

RingBuffer::~RingBuffer()
{
}

void RingBuffer::push(std::string &str)
{
    if (this->_last >= this->_buffer.size())
        this->_last = 0;
    this->_buffer[this->_last] = str;
    ++this->_last;
    if (this->full())
        this->_first = (this->_first + 1) % this->_buffer.size();
    else
        ++this->_sz;
}

void RingBuffer::print() const
{
    if (_first < _last)
        for (std::size_t i = _first; i < _last; ++i)
            std::cout << _buffer[i] << ' ';
    else
    {
        for (std::size_t i = _first; i < _buffer.size(); ++i)
            std::cout << _buffer[i] << ' ';
        for (std::size_t i = 0; i < _last; ++i)
            std::cout << _buffer[i] << ' ';
    }
}

std::string &RingBuffer::operator[](std::size_t pos)
{
    std::size_t p = (this->_first + pos) % this->_buffer.size();
    return this->_buffer[p];
}

bool RingBuffer::empty() const
{
    return this->_sz == 0;
}

bool RingBuffer::full() const
{
    return this->_sz == this->_buffer.size();
}