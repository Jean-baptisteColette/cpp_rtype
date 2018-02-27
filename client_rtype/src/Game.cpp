#include "Game.hpp"
#include "Packet.hpp"
#include "Data.hpp"

Game::Game(Socket &s) : _socket(s)
{
    this->_world = std::make_shared<World>();
    this->_select = std::make_shared<Select>(s.getSocket());


    this->_entityContainer = std::make_shared<EntityContainer>(this->_world);
this->_action = std::make_shared<Action>(_socket, this->_entityContainer);
    this->_msgHandler = std::make_shared<MsgHandler>(s, _world, _entityContainer);
    _world->createWindow(1080, 720);
    _world->createSpacecraftPlayer("Focon", 1, 50, 50, 400, 5);
     _world->createParticles(500, 1180, 720 / 2, 10, 100000);
    _world->createScroller();
    _world->playMusic(IN_GAME);
    _world->createTime();
    _world->getSpacecraftPlayer()->setEntity("r-typesheet42", 32, BLUE, 32, 16);
 
    this->spawnThread();
    this->_t->detach();
}
Game::~Game()
{
    std::cout << "destroy game\n";
}

void Game::spawnThread()
{
    this->_t = std::make_shared<std::thread>([this] {
        while (true)
        {
            this->_select->mySelect(this->_socket.getSocket());
            if (this->_select->isNewMsg(this->_socket.getSocket()) == true)
            {
                std::shared_ptr<Packet> res(_socket.recvPacket());
                this->_msgHandler->handler(res);
            }
        }
    });
}

void Game::connection()
{
    while (_world->getWindow()->isOpen() == true && this->_msgHandler->getIsConnected() == false)
    {
        _world->getTime()->setElapsedTimeParticle();
        _world->getParticleSystem()->update(_world->getTime()->getElapsedTimeParticle());
        _world->windowEvents();
        _world->draw();
        _world->getWindow()->display();
    }
}

void Game::play()
{
    
    while (_world->getWindow()->isOpen() == true)
    {
            _world->getTime()->setElapsedTimeParticle();
            _world->getParticleSystem()->update(_world->getTime()->getElapsedTimeParticle());
            _world->windowEvents();
            _world->spacecraftEvents();
            _world->draw();
            this->_entityContainer->drawEntities();
            _world->getWindow()->display();

            if (_world->getSpacecraftPlayer()->getAction() != 0)
            {
                _action->ActionOnKey(_world->getSpacecraftPlayer()->getAction());
            }
    }
}
void Game::start() {}