#pragma once
#include <thread>
#include <memory>
#include "World.hpp"
#include "UnixSocket.hpp"
#include "Select.hpp"
#include "MsgHandler.hpp"
#include "EntityContainer.hpp"
#include "Action.hpp"

enum eColor : int
{
    BLUE = 0,
    PINK = 20,
    GREEN = 40,
    RED = 60,
    DARK_BLUE = 80
};

class Game {
public:
    Game(Socket &s);
    ~Game();

    void connection();
    void play();
    void start();
    void spawnThread();
private:
    std::shared_ptr<World> _world;
    std::shared_ptr<Select> _select;
    std::shared_ptr<MsgHandler> _msgHandler;
    std::shared_ptr<EntityContainer> _entityContainer;
    std::shared_ptr<Action> _action;
    Socket &_socket;
    bool _isConnected = false;
    bool _isCurrentGame = false;
    std::shared_ptr<std::thread> _t;

};