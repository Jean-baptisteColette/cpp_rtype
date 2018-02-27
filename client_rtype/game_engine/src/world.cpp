#include "../include/World.hpp"

World::World()
{
}

void World::playMusic(eMusic music)
{
    this->_window->playMusic(music);
}

void World::createWindow(int width, int height)
{
    _window = std::make_shared<Window>(width, height);
    _window->create();
}

void World::createSpacecraftPlayer(std::string name, unsigned short id,
                                   int width, int height, float speed,
                                   unsigned int amo)
{
    _spacecraftPlayer = std::make_shared<SpacecraftPlayer>(name, id, width, height, speed, amo);
}

void World::createSpacecraftEntity(std::string name, unsigned short id,
                                   int width, int height, float speed,
                                   unsigned int amo)
{
     _spacecraftEntity = std::make_shared<SpacecraftEntities>(name, id, width, height, speed, amo);
   
    }
    
void World::createParticles(unsigned int nb_particles, int x, int y, unsigned int speed, unsigned int lifetime)
{
    _particles = std::make_shared<ParticleSystem>(nb_particles, x, y, speed, lifetime);
}

void World::createTime()
{
    _time = std::make_shared<Time>();
}

void World::createScroller()
{
    _scroller = std::make_shared<Scroller>();
    _scroller->loadSkin();
}

void World::windowEvents()
{
    _window->pollEvent(_event);
}

void World::draw()
{
    _window->clear(0, 0, 0);
    _window->drawParticles(_particles);
    _window->drawScroll(_scroller);
    _window->drawSpacecraftPlayer(_spacecraftPlayer);
   // _window->drawSpacecraftEntity(_spacecraftEntity);
    scrollView();
}

void World::drawEntity(std::shared_ptr<SpacecraftEntities> e)
{
    _window->drawSpacecraftEntity(e);
}
void World::scrollView()
{
    _scroller->moveSprite();
}

void World::spacecraftEvents()
{
    _spacecraftPlayer->setAction();
    //_spacecraftPlayer->printDebug();
}