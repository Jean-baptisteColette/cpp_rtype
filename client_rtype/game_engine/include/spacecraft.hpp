#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "AEntity.hpp"
#include "sound.hpp"
#include "Laser.hpp"

class Spacecraft : public AEntity
{
public:
  virtual ~Spacecraft(){};

  virtual void setAttack() = 0;
  virtual void setMissile() = 0;

  virtual void setAction() = 0;

  virtual unsigned short getAmo() const & { return _amo; }
  sf::Sprite getSpacecraft() const & { return _entity; }

  std::shared_ptr<Laser> getLaser() const & {return _laser;}

  virtual void playSound(eSound sound);
  virtual void printDebug() const;

protected:
  unsigned short _amo;

  std::shared_ptr<Laser> _laser;
  std::shared_ptr<Sound> _sound;
  std::vector<std::string> _soundFiles;
  sf::Vector2f _size;
};
