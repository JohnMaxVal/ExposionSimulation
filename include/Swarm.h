#ifndef _SWARN_H_
#define _SWARN_H_

#include "Particle.h"

namespace explosion {

class Swarm {
public:
    const static int NPARTICLES = 5000;

private:
    Particle * m_Particles;
    int lastTime;

public:
    Swarm();
    virtual ~Swarm();
    void update(int elapsed);

    const Particle * const getParticles() { return m_Particles; }
};

}

#endif