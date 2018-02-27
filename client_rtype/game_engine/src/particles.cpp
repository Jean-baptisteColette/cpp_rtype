#include "../include/World.hpp"

ParticleSystem::ParticleSystem(unsigned int nb_particles, int x, int y, unsigned int speed, unsigned int lifetime) :
        m_particles(nb_particles),
        m_vertices(sf::Points, 10000),
        m_lifetime(sf::seconds(3)),
        m_emitter(x, y),
        _speed(speed),
        _lifetime(lifetime)
{
}

void ParticleSystem::resetParticle(std::size_t index)
{
    float angle = (std::rand() % 360) * 3.14f / 180.f;
    float speed = (std::rand() % 50) + _speed;
    m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
    m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + _lifetime);

    m_vertices[index].position = m_emitter;
}

void ParticleSystem::update(sf::Time elapsed)
{
    for (std::size_t i = 0; i < m_particles.size(); ++i)
    {
    Particle& p = m_particles[i];
    p.lifetime -= elapsed;

    if (p.lifetime <= sf::Time::Zero)
        resetParticle(i);

    m_vertices[i].position += p.velocity * elapsed.asSeconds();

    float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds() + 100;
    m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
    }
}
