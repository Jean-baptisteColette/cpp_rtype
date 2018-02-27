#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Scroller
{
  public:
    Scroller();
    ~Scroller(){};
    bool    loadSkin();
    void    moveSprite();

    sf::Sprite getScroller() const & { return _backgroundSprite; }

  private:
    sf::Texture _backgroundTexture;
    sf::Sprite  _backgroundSprite;
    sf::Vector2i _position;
};     