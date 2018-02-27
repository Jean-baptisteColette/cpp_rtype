#include "../include/World.hpp"

Time::Time()
{

}

sf::Clock    Time::getClock() const &
{
    return (_clock);
}

sf::Time    Time::getElapsedTimeParticle() const &
{
    return (_elapsedParticle);
}

void    Time::setElapsedTimeParticle()
{
    this->_elapsedParticle = this->_clock.restart();
}

sf::Time    Time::getElapsedTimeShoot() const &
{
    return (this->_clock.getElapsedTime() - _elapsedShoot);
}

void    Time::setElapsedTimeShoot()
{
    this->_elapsedShoot = this->_clock.getElapsedTime();
}

