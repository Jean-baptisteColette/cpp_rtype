#include "../include/scroller.hpp"

Scroller::Scroller()
{
    _position.x = 0;
    _position.y = 265;
}

bool    Scroller::loadSkin()
{
    if (!_backgroundTexture.loadFromFile("./media/sprites/r-typesheet_background.png",  sf::IntRect(0, 265, 2068, 512)))
    {
        std::cout << "Warning : Could not load texture for the scroller" << std::endl;
        return (false);
    }
    _backgroundSprite.setTexture(_backgroundTexture);
    _backgroundSprite.setPosition(800, 0);
    _backgroundSprite.setScale(sf::Vector2f(3.5, 3.5));
    return (true);
}

void    Scroller::moveSprite()
{
    _backgroundSprite.move(-0.008f,0);
}