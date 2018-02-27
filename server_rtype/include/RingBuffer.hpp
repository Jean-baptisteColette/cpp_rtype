#include <iostream>
#include <vector>
class RingBuffer
{
  public:
    RingBuffer(std::size_t cap);
    ~RingBuffer();
    bool full() const;
    bool empty() const;

    void push(std::string &str);
    std::string &operator[](std::size_t pos);
    void print() const;
  private:
    std::vector<std::string> _buffer;
    std::size_t _first = 0;
    std::size_t _last = 0;
    std::size_t _sz = 0;
};