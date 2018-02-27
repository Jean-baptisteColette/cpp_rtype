#pragma once

#include <SFML/Audio.hpp>
#include <iostream>

class   AAudio
{
    public:
    AAudio(std::vector<std::string> files) : _files(files){}
    virtual ~AAudio(){}

    virtual void playSound() = 0;
    virtual void stopSound() = 0;
    virtual void printDebug() = 0;
    virtual void setVolume(int value) { _volume = value ;}

    protected:
    std::vector<std::string> _files;
    int _volume;
};