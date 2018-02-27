#pragma once

#include <SFML/Graphics.hpp>

class Time
{
    public:
        Time();
        ~Time(){};

        sf::Clock   getClock() const &;

        sf::Time    getElapsedTimeParticle() const &;
        void        setElapsedTimeParticle();

        sf::Time    getElapsedTimeShoot() const &;
        void        setElapsedTimeShoot();

    private:
        sf::Clock _clock;
        sf::Time _elapsedParticle;
        sf::Time _elapsedShoot;
};