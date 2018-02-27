#pragma once

#include "AAudio.hpp"

enum eMusic
{
    HOME,
    IN_GAME,
    GAME_OVER
};

class Music : public AAudio
{
  public:
    Music(std::vector<std::string> files) : AAudio(files) {}
    ~Music() {}

    bool loadSound(eMusic music);
    void playSound();
    void stopSound();
    void printDebug();
  private:
    sf::Music _music;
};