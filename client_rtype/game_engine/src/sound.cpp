#include "../include/sound.hpp"

bool Sound::loadSound(eSound sound)
{
    if (!_buffer.loadFromFile("./media/audio/sound/" + _files[sound] + ".wav"))
    {
        std::cout << "Warning : Could not load sound" << std::endl;
        return (false);
    }
    _sound.setBuffer(_buffer);
    return (true);
}

void Sound::playSound()
{
    _sound.play();
    _sound.setVolume(50);
}

void Sound::stopSound()
{
    _sound.stop();
}

void Sound::printDebug()
{
    std::cout << " " << _buffer.getDuration().asSeconds() << " seconds" << std::endl;
    std::cout << " " << _buffer.getSampleRate() << " samples / sec" << std::endl;
    std::cout << " " << _buffer.getChannelCount() << " channels" << std::endl;
}