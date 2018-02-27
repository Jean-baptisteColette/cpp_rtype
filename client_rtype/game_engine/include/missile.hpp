#pragma once

#include "AMissile.hpp"

class Missile : public AMissile
{
public:
    Missile();
    ~Missile();

    virtual void setPosition(float x, float y);
    virtual sf::Vector2f getPosition() const &;

    virtual void setMovement();

    virtual void setEntity(const std::string &);
    virtual bool loadSkin(const std::string &);

    virtual bool isDestructible() const &;

    virtual bool isEnnemy() const &;
    virtual bool isDead() const &;

    virtual unsigned short getId() const &;
    virtual eMissile getTypeMissile() const &;

private:
    eMissile    _missileType;
    unsigned short _id;
    unsigned int _amo;
    float _speed;
    
    bool _makeShoot;
    bool _isDestructible;
    bool _isEnnemy;
    bool _isDead;
};