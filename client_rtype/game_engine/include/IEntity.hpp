#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

enum eAction
{
    NO_ACTION,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE
};

class IEntity
{
  public:
    virtual ~IEntity() {}

    virtual void setPosition(float x, float y) = 0;
    virtual sf::Vector2f getPosition() const & = 0;

    virtual eAction getAction() const & = 0;
    virtual void setAction() = 0;

    virtual bool canShoot() const & = 0;
    virtual bool canFly() const & = 0;
    virtual bool isDestructible() const & = 0;

    virtual bool getIsEnnemy() const & = 0;
    virtual bool getIsDead() const & = 0;

    virtual void setId(unsigned short value) = 0;
    virtual void checkForId(unsigned short toCheck) = 0;

    virtual unsigned short getId() const & = 0;
    virtual std::string getName() const & = 0;

    virtual bool loadSkin(const std::string &filename, int rectLeft, int rectTop, int rectWidth, int rectHeight) = 0;
};