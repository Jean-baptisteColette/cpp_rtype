#pragma once

#include "spacecraft.hpp"
#include "time.hpp"
#include <memory>

class SpacecraftPlayer : public Spacecraft
{
public:
  SpacecraftPlayer(std::string name, unsigned short id, int width, int height, float speed, unsigned int amo);
  
  virtual void setMissile();
  virtual void setEntity(const std::string &, int rectLeft, int rectTop, int rectWidth, int rectHeight);

  virtual void setAttack();
  virtual void setAction();

private:
  sf::Clock _clock;

  std::shared_ptr<Time> _time;
};