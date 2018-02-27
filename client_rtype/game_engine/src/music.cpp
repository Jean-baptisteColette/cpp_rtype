#include "../include/music.hpp"

bool    Music::loadSound(eMusic music)
{
    if (!_music.openFromFile("./media/audio/music/" + _files[music] + ".wav"))
    {
        std::cout << "Warning : Could not load music" << std::endl;
        return (false);
    }
    return (true);
}

void    Music::playSound()
{
    _music.play();
    _music.setVolume(100);
    _music.setLoop(true);
}

void    Music::stopSound()
{
    _music.setLoop(false);
    _music.stop();
}

void    Music::printDebug()
{
    std::cout << " " << _music.getDuration().asSeconds() << " seconds"       << std::endl;
    std::cout << " " << _music.getSampleRate()           << " samples / sec" << std::endl;
    std::cout << " " << _music.getChannelCount()         << " channels"      << std::endl;
}