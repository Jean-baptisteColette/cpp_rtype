#pragma once

#include <memory>
#include "SpacecraftPlayer.hpp"
#include "SpacecraftEntities.hpp"
#include "window.hpp"
#include "time.hpp"
#include "scroller.hpp"

class World
{
  public:
    World();
    ~World(){};

    void createWindow(int width, int height);
    void createSpacecraftPlayer(std::string name, unsigned short id, int width, int height, float speed, unsigned int amo);
    void createSpacecraftEntity(std::string name, unsigned short id, int width, int height, float speed, unsigned int amo);
    void createParticles(unsigned int nb_particles, int x, int y, unsigned int speed, unsigned int lifetime);
    void createScroller();
    void createEnnemi();
    void createTime();

    void playMusic(eMusic music);

    void scrollView();

    void windowEvents();
    void spacecraftEvents();
    void draw();
    void drawEntity(std::shared_ptr<SpacecraftEntities> );
    std::shared_ptr<Window> getWindow() const & { return _window; }
    std::shared_ptr<SpacecraftPlayer> getSpacecraftPlayer() const & { return _spacecraftPlayer; }
    std::shared_ptr<SpacecraftEntities> getSpacecraftEntity() const & { return _spacecraftEntity; }
    std::shared_ptr<ParticleSystem> getParticleSystem() const & { return _particles; }
    std::shared_ptr<Time> getTime() const & { return _time; }
    std::shared_ptr<Scroller> getScroller() const & { return _scroller; }


  private:
    std::shared_ptr<Window> _window;
    std::shared_ptr<SpacecraftPlayer> _spacecraftPlayer;

    std::shared_ptr<SpacecraftEntities> _spacecraftEntity;
    
    std::shared_ptr<ParticleSystem> _particles;
    std::shared_ptr<Time> _time;
    std::shared_ptr<Scroller> _scroller;
    sf::Event _event;
};