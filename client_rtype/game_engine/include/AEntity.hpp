#pragma once

#include "IEntity.hpp"


class AEntity : public IEntity
{
  public:
    virtual void setPosition(float x, float y) { _entity.setPosition(x, y); }
    virtual sf::Vector2f getPosition() const & { return (_entity.getPosition()); }

    virtual sf::Sprite getEntity() const & { return _entity;}
    virtual void setEntity(const std::string &, int rectLeft, int rectTop, int rectWidth, int rectHeight) = 0;

    virtual void setSpeed(float value) { _speed = value; }
    virtual eAction getAction() const & { return _action; }
    virtual void setAction() = 0;

    virtual sf::Texture getTexture() const & { return _texture;}
    virtual bool canShoot() const & { return _canShoot; }
    virtual bool canFly() const & { return _canFly; }
    virtual bool isDestructible() const & { return _isDestructible; }

    virtual bool getIsEnnemy() const & { return _isEnnemy; }
    virtual bool getIsDead() const & { return _isDead; }
    virtual bool getHasShoot() const & { return _hasShoot;}

    virtual void setId(unsigned short value) { _id = value; }
    virtual void checkForId(unsigned short toCheck)
    {
        (void) toCheck;
    }

    virtual unsigned short getId() const & { return _id; }
    virtual std::string getName() const & { return _name; }

    virtual bool loadSkin(const std::string &filename, int rectLeft, int rectTop, int rectWidth, int rectHeight)
    {
        if (!_texture.loadFromFile("./media/sprites/" + filename + ".png", sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight)))
        {
            std::cout << "Warning : Could not load the skin for " << _name << " | " << _id << "." << std::endl;
            return (false);
        }
        _texture.setSmooth(true);
        return (true);
    }

  protected:
    std::string _name;
    unsigned short _id;
    float _speed;

    bool _canShoot;
    bool _canFly;
    bool _isDestructible;
    bool _isEnnemy;
    bool _isDead;
    bool _hasShoot;
    eAction _action;

    sf::Vector2f _position;
    sf::Texture _texture;
    sf::Sprite _entity;
};