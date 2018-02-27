#pragma once

#include "AMissile.hpp"

#define MAX_AMO 10

class Laser : public AMissile
{
  public:
    Laser();
    ~Laser(){};

    virtual void setEntity(const std::string &, int rectLeft, int rectTop, int rectWidth, int rectHeight);

    virtual void setAttack();
    virtual void setAction();
    void moveLaser();

  protected:
    sf::Sprite _spriteAmo[MAX_AMO];
};