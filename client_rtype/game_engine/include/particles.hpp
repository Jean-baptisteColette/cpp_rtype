#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class ParticleSystem
{
public:
    ParticleSystem(unsigned int nb_particles, int x, int y, unsigned int speed, unsigned int lifetime);
    ~ParticleSystem(){};
    void    update(sf::Time elapsed);

    sf::VertexArray const &getParticles() const { return m_vertices; }

private:

        struct Particle
            {
                    sf::Vector2f velocity;
                    sf::Time lifetime;
            };

        void    resetParticle(std::size_t index);

        std::vector<Particle> m_particles;
        sf::VertexArray m_vertices;
        sf::Time m_lifetime;
        sf::Vector2f m_emitter;
        unsigned int _speed;
        unsigned int _lifetime;
};
