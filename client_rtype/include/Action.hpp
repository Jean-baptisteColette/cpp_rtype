#pragma once
#include "World.hpp"
#include "UnixSocket.hpp"
#include "EntityContainer.hpp"
class Action{
public:
    Action(Socket &s, std::shared_ptr<EntityContainer> a);
    ~Action();

    void ActionOnKey(const eAction &action);
private:
    Socket  &_socket;
    std::shared_ptr<EntityContainer> _entityContainer;
    int _inc = 0;
};