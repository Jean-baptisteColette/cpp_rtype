#pragma once
#include <memory>
#include "UnixSocket.hpp"
#include "Data.hpp"
#include "World.hpp"
#include "EntityContainer.hpp"
class MsgHandler
{
  public:
    MsgHandler(Socket &s, std::shared_ptr<World> w, std::shared_ptr<EntityContainer> e);
    ~MsgHandler();
    void handler(const std::shared_ptr<Packet> p);
    bool getIsCurrentGame() const;
    bool getIsConnected() const;
    void setIsConnected(bool i);
    void setIsCurrentGame(bool i);

  private:
    Socket &_socket;
    std::shared_ptr<World> _world;
std::shared_ptr<EntityContainer> _entityContainer;
    void (MsgHandler::*f[15])(const std::shared_ptr<Packet> p);
    char _opcodes[15];
    bool _isConnected = false;
    bool _isCurrentGame = false;
    void _connection(const std::shared_ptr<Packet> p);
    void _createEntity(const std::shared_ptr<Packet> p);
    void _die(const std::shared_ptr<Packet> p);
    void _move(const std::shared_ptr<Packet> p);
    void _newGame(const std::shared_ptr<Packet> p);
};