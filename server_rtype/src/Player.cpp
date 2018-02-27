#include "Player.hpp"

Player::Player()
{
    this->_posX = 100;
    this->_posY = 120;
    this->_lifePoint = 100;
    this->_id = 1;
}

Player::~Player()
{}

int     Player::getPosX()
{
    return this->_posX;
}

void    Player::setPosX(int val)
{
    this->_posX = val;
}

int     Player::getPosY()
{
    return this->_posY;
}

void    Player::setPosY(int val)
{
    this->_posY = val;
}

int     Player::getId()
{
    return this->_id;
}

void    Player::setId(int id)
{
    this->_id = id;
}

int     Player::getLifePoint()
{
    return this->_lifePoint;
}

void    Player::setLifePoint(int val)
{
    this->_lifePoint -= val;
}

void    Player::moove(int x, int y)
{
    this->setPosX(x);
    this->setPosY(y);
}

void    Player::shoot()
{

}

void    Player::losseOfLife(int val)
{
    this->setLifePoint(val);
}