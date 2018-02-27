#pragma once

#include <iostream>

class Player
{
private:
    int     _posX;
    int     _posY;
    int     _lifePoint;
    int     _id;

public:
    Player();
    ~Player();
    int     getPosX();
    void    setPosX(int);
    int     getPosY();
    void    setPosY(int);
    int     getId();
    void    setId(int);
    int     getLifePoint();
    void    setLifePoint(int);
    void    moove(int, int);
    void    shoot();
    void    losseOfLife(int);
};