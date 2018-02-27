#pragma once
#include <vector>
#include <memory>
#include "World.hpp"
#include "Data.hpp"
class EntityContainer
{
  public:
    EntityContainer(std::shared_ptr<World> w);
    ~EntityContainer();

    void pushSpaceCraftEntity(std::shared_ptr<SpacecraftEntities> s);
    void pushSpaceCraftEntityEnemy(std::shared_ptr<SpacecraftEntities> s);

    void drawEntities();
    void MoveEntityById(t_move &e);
    void setMyId(int id);
    int getMyId() const;
    void killEntity(int id);

  private:
    std::shared_ptr<World> _world;
    std::vector<std::shared_ptr<SpacecraftEntities>> _spaceList;
    std::vector<std::shared_ptr<SpacecraftEntities>> _enemieList;
    int _myId;
};