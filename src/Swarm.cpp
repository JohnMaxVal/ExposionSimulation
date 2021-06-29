#include "Swarm.h"

namespace explosion {

Swarm::Swarm() {
    m_Particles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
    delete[] m_Particles;
}

}