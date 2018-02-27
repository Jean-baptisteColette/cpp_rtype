#include "Laser.hpp"

Laser::Laser()
{
    this->_isDestructible = true;
    this->_isDead = false;
}

void Laser::setEntity(const std::string &filename, int rectLeft, int rectTop, int rectWidth, int rectHeight)
{
    loadSkin(filename, rectLeft, rectTop, rectWidth, rectHeight);
    _entity.setTexture(_texture); //spriteAmo
    this->_type = LASER;
}

void Laser::setAttack()
{

}

void Laser::setAction()
{

}

void Laser::moveLaser()
{
    _entity.move(_speed, 0);
}