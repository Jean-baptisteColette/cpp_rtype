#include "SpacecraftEntities.hpp"
#include "IWindow.hpp"

SpacecraftEntities::SpacecraftEntities(std::string name, unsigned short id,
                                       int width, int height, float speed,
                                       unsigned int amo)
{
    this->_name = name;
    this->_id = id;
    this->_speed = speed;
    this->_size.x = width;
    this->_size.y = height;
    this->_amo = amo;
    this->_canShoot = true;
    this->_canFly = true;
    this->_isDestructible = true;
    this->_isEnnemy = false;
    this->_isDead = false;
    this->_hasShoot = false;
}

void SpacecraftEntities::setEntity(const std::string &filename, int rectLeft, int rectTop, int rectWidth, int rectHeight)
{
    _entity.setOrigin(_size / 2.f);
    _entity.setPosition(20 + _size.x / 2, WINDOW_HEIGHT / 2);
    loadSkin(filename, rectLeft, rectTop, rectWidth, rectHeight);
    _entity.setTexture(_texture);
    _entity.setScale(sf::Vector2f(1.5, 1.5));
}

void SpacecraftEntities::setMissile()
{
    /*    unsigned short id;

    id = checkForId();*/
    _laser->setEntity("r-typesheet43", 0, 40, 50, 5); //ID TO CHANGE
    _laser->setPosition(_entity.getPosition().x + 10, _entity.getPosition().y - 23);
    _laser->setTypeMissile(LASER);
    _laser->setSpeed(2);
}

void SpacecraftEntities::setAttack()
{
}

void SpacecraftEntities::setAction()
{
}