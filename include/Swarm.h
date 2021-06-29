#ifndef _SWARN_H_
#define _SWARN_H_

#include "Particle.h"

namespace explosion {

class Swarm {
public:
    const static int NPARTICLES = 5000;

private:
    Particle * m_Particles;

public:
    Swarm();
    virtual ~Swarm();

    const Particle * const getParticles() { return m_Particles; }
};

}

#endif