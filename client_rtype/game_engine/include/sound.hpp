#pragma once

#include "AAudio.hpp"

enum eSound
{
  SHOOT,
  CRASH
};

class Sound : public AAudio
{
public:
  Sound(std::vector<std::string> files) : AAudio(files) {}
  ~Sound() {}

  bool loadSound(eSound sound);
  void playSound();
  void stopSound();
  void printDebug();

private:
  sf::SoundBuffer _buffer;
  sf::Sound _sound;
};