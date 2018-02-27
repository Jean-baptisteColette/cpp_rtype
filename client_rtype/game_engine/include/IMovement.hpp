#pragma once

enum eMovement
{
  UP,
  DOWN,
  RIGHT,
  LEFT
};

class IMovement
{
  public:
    ~IMovement(){};
    virtual bool    moveUp() = 0;
    virtual bool    moveDown() = 0;
    virtual bool    moveRight() = 0;
    virtual bool    moveLeft() = 0;
};
