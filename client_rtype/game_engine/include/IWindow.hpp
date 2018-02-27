#pragma once

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720

#include <SFML/Graphics.hpp>
#include <memory>

class IWindow
{
public:
  virtual ~IWindow(){};
  virtual void create() = 0;
  virtual bool isOpen() = 0;
  virtual void close(sf::Event event) = 0;
  virtual void clear(int, int, int) = 0;
  virtual void display() = 0;
  virtual void pollEvent(sf::Event event) = 0;
};
