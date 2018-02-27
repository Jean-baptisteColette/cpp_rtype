#include "SpacecraftPlayer.hpp"
#include "IWindow.hpp"

SpacecraftPlayer::SpacecraftPlayer(std::string name, unsigned short id,
                                   int width, int height, float speed,
                                   unsigned int amo)
{
    this->_name = name;
    this->_id = id;
    this->_speed = speed;
    this->_size.x = width;
    this->_size.y = height;
    this->_amo = amo;
    this->_canShoot = true;
    this->_canFly = true;
    this->_isDestructible = true;
    this->_isEnnemy = false;
    this->_isDead = false;
    this->_hasShoot = false;
    this->_id = 1; ///////////// TO CHANGE !!!
}

void SpacecraftPlayer::setEntity(const std::string &filename, int rectLeft, int rectTop, int rectWidth, int rectHeight)
{
    _entity.setOrigin(_size / 2.f);
    _entity.setPosition(20 + _size.x / 2, WINDOW_HEIGHT / 2);
    loadSkin(filename, rectLeft, rectTop, rectWidth, rectHeight);
    _entity.setTexture(_texture);
    _entity.setScale(sf::Vector2f(1.5, 1.5));
    _time = std::make_shared<Time>();
    _time->setElapsedTimeShoot();
    _laser = std::make_shared<Laser>();
}

void SpacecraftPlayer::setMissile()
{
    _laser->setEntity("r-typesheet43", 0, 40, 50, 5);
    _laser->setPosition(_entity.getPosition().x + 10, _entity.getPosition().y - 23);
    _laser->setTypeMissile(LASER);
    _laser->setSpeed(2);
}

void SpacecraftPlayer::setAttack()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _time->getElapsedTimeShoot().asMilliseconds() > 100 && _amo > 0)
    {
        this->_hasShoot = true;
        _action = SPACE;
        _time->setElapsedTimeShoot();
        setMissile();
        playSound(SHOOT);
        _amo--;
        std::cout << "Spacecraft " << this->_name << " shooted at position" << getPosition().x << "! [" << _amo << "] left" << std::endl;
    }
    if (_amo < 5 && _time->getElapsedTimeShoot().asMilliseconds() > 500)
    {
        _amo++;
    }
}

void SpacecraftPlayer::setAction()
{
    float deltaTime = _clock.restart().asSeconds();

    _action = NO_ACTION;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
        (_entity.getPosition().y - _size.y / 2 > 30.f))
    {
        _entity.move(0.f, -_speed * deltaTime);
        _action = UP;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
        (_entity.getPosition().y + _size.y / 2 < WINDOW_HEIGHT + 10))
    {
        _entity.move(0.f, _speed * deltaTime);
        _action = DOWN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        (_entity.getPosition().x - _size.x / 2 < WINDOW_WIDTH - _size.x - 10.f))
    {
        _entity.move(_speed * deltaTime, 0.f);
        _action = RIGHT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        (_entity.getPosition().x - _size.x / 2 > 10.f))
    {
        _entity.move(-_speed * deltaTime, 0.f);
        _action = LEFT;
    }
    setAttack();
}
