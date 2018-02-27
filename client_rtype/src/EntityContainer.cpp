#include "EntityContainer.hpp"

EntityContainer::EntityContainer(std::shared_ptr<World> w) : _world(w) {}
EntityContainer::~EntityContainer() {}

void EntityContainer::pushSpaceCraftEntity(std::shared_ptr<SpacecraftEntities> s)
{
    this->_spaceList.push_back(s);
}

void EntityContainer::pushSpaceCraftEntityEnemy(std::shared_ptr<SpacecraftEntities> s)
{
    this->_enemieList.push_back(s);
}

void EntityContainer::drawEntities()
{
    for (std::shared_ptr<SpacecraftEntities> &value : this->_spaceList)
    {
        _world->drawEntity(value);
    }
    for (std::shared_ptr<SpacecraftEntities> &value : this->_enemieList)
    {
        _world->drawEntity(value);
    }
}

void EntityContainer::MoveEntityById(t_move &e)
{
    for (std::shared_ptr<SpacecraftEntities> &value : _spaceList)
    {
        if (value)
        {
            if (e.idEntity == value->getId())
            {
                value->setPosition(e.x, e.y);
            }
        }
    }
}

void EntityContainer::setMyId(int id)
{
    this->_myId = id;
}

int EntityContainer::getMyId() const
{
    return _myId;
}

void EntityContainer::killEntity(int id)
{
    if (id >= 1 && id <= 4)
    {
        for (std::vector<std::shared_ptr<SpacecraftEntities>>::iterator it = _spaceList.begin(); it != _spaceList.end(); ++it)
        {
            if (it->get()->getId() == id)
            {
                _spaceList.erase(it);
            }
        }
    }
}