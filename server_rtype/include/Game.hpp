#pragma once

#include "Entity.hpp"

class Game
{
private:
  std::vector<Entity> objects;

public:
  // Constructor
  Game()
  {
  };
  // Destructor
  ~Game()
  {
  };

  std::vector<Entity> &getObjects(){
    return (objects);
  };
};
