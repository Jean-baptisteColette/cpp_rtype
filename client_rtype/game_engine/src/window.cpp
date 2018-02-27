#include "../include/window.hpp"
#include <thread>
#include <mutex>

Window::Window(int width, int height)
{
    this->_width = width;
    this->_height = height;
    //    this->_title = title;
}

void Window::printInfo()
{
    std::cout << "[WINDOW] Width = " << this->_width << std::endl;
    std::cout << "[WINDOW] Height = " << this->_height << std::endl;
}

void Window::playMusic(eMusic music)
{
    _music->loadSound(music);
    _music->playSound();
}

void Window::createMusicVector()
{
    _musicFiles.push_back("home");
    _musicFiles.push_back("in_game");
}

void Window::create()
{
    sf::VideoMode desk = sf::VideoMode::getDesktopMode();
    std::cout << "Window created" << std::endl;
    this->_window.create(sf::VideoMode(this->_width, this->_height, 32), "R-Type", sf::Style::Titlebar | sf::Style::Close);
    this->_window.setPosition(sf::Vector2i(desk.width / 2 - _window.getSize().x / 2, desk.height / 2 - _window.getSize().y / 2));
    createMusicVector();
    _music = std::make_shared<Music>(_musicFiles);
}

bool Window::isOpen()
{
    if (this->_window.isOpen() == false)
        return (false);
    return (true);
}

void Window::clear(int red, int blue, int green)
{
    this->_window.clear(sf::Color(red, blue, green));
}

void Window::display()
{
    this->_window.display();
}

void Window::drawSpacecraftPlayer(std::shared_ptr<SpacecraftPlayer> space)
{
    this->_window.draw(space->getSpacecraft());
    if (space->getHasShoot() == true)
    {
        if (space->getLaser()->getIsDead() == false)
        {
            this->_window.draw(space->getLaser()->getEntity());
            space->getLaser()->moveLaser();
        }
    }
}

void Window::drawSpacecraftEntity(std::shared_ptr<SpacecraftEntities> entity)
{
    this->_window.draw(entity->getSpacecraft());
}

void Window::drawParticles(std::shared_ptr<ParticleSystem> particles)
{
    this->_window.draw(particles->getParticles());
}

void Window::drawScroll(std::shared_ptr<Scroller> _scroller)
{
    this->_window.draw(_scroller->getScroller());
}

void Window::close(sf::Event event)
{
    if ((event.type == sf::Event::Closed) ||
        ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
    {
        this->_window.close();
        std::cout << "Close window" << std::endl;
    }
}

void Window::pollEvent(sf::Event event)
{
    while (this->_window.pollEvent(event))
    {
        close(event);
    }
}