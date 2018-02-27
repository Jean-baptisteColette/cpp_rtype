#include <iostream>
#include "MsgHandler.hpp"

MsgHandler::MsgHandler(Socket &s, std::shared_ptr<World> w, std::shared_ptr<EntityContainer> e) : _socket(s), _world(w), _entityContainer(e)
{
    this->_opcodes[0] = HELLO_FROM_SERVER;
    this->_opcodes[1] = START_GAME;
    this->_opcodes[2] = MOVE_ENTITY;
    this->_opcodes[3] = CREATE_ENTITY;
    this->_opcodes[4] = DIE_ENTITY;
    this->f[0] = &MsgHandler::_connection;
    this->f[1] = &MsgHandler::_newGame;
    this->f[2] = &MsgHandler::_move;
    this->f[3] = &MsgHandler::_createEntity;
    this->f[4] = &MsgHandler::_die;
}

MsgHandler::~MsgHandler()
{
}

void MsgHandler::handler(const std::shared_ptr<Packet> p)
{
    int i = 0;
    while (i < 5)
    {
        if (p->getBuf().at(0) == this->_opcodes[i])
        {
            (this->*f[i])(p);
        }
        i++;
    }
}

bool MsgHandler::getIsCurrentGame() const { return this->_isCurrentGame; }
bool MsgHandler::getIsConnected() const { return this->_isConnected; }
void MsgHandler::setIsConnected(bool i) { this->_isConnected = i; }
void MsgHandler::setIsCurrentGame(bool i) { this->_isCurrentGame = i; }

void MsgHandler::_connection(const std::shared_ptr<Packet> p)
{
    this->_isConnected = true;
    std::cout << "Connected" << std::endl;
}
void MsgHandler::_createEntity(const std::shared_ptr<Packet> p)
{
    struct t_create *c = reinterpret_cast<struct t_create *>(p->getBufChar());

    if (c->typeEntity == 1)
    {
        if (c->idEntity == this->_entityContainer->getMyId())
        {
            std::shared_ptr<SpacecraftEntities> e = std::make_shared<SpacecraftEntities>("me", c->idEntity, 50, 50, 400, 5);
            e->setEntity("r-typesheet42", 32, 0, 32, 16);
            e->setPosition(c->x, c->y);
            this->_entityContainer->pushSpaceCraftEntity(e);
        }
        else
        {
            std::shared_ptr<SpacecraftEntities> e = std::make_shared<SpacecraftEntities>("me", c->idEntity, 50, 50, 400, 5);
            e->setEntity("r-typesheet42", 32, 20, 32, 16);
            e->setPosition(c->x, c->y);
            this->_entityContainer->pushSpaceCraftEntity(e);
        }
        
    }
    else
    {
        std::shared_ptr<SpacecraftEntities> e = std::make_shared<SpacecraftEntities>("me", c->idEntity, 50, 50, 400, 5);
            e->setEntity("r-typesheet42", 32, 20, 32, 16);
            e->setPosition(c->x, c->y);
            this->_entityContainer->pushSpaceCraftEntity(e);
    }
}

void MsgHandler::_die(const std::shared_ptr<Packet> p) {
    struct t_die *m = reinterpret_cast<struct t_die *>(p->getBufChar());
    this->_entityContainer->killEntity(m->idPlayer);

}
void MsgHandler::_move(const std::shared_ptr<Packet> p)
{
    struct t_move *m = reinterpret_cast<struct t_move *>(p->getBufChar());
    this->_entityContainer->MoveEntityById(*m);
}

void MsgHandler::_newGame(const std::shared_ptr<Packet> p)
{
    this->_isCurrentGame = true;
    t_newGame *t = reinterpret_cast<struct t_newGame *>(p->getBufChar());
    this->_entityContainer->setMyId(t->id);
}