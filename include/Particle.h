#ifndef _PARTICLE_H_
#define _PARTICLE_H_

namespace explosion {

class Particle {
public:
    double m_x;
    double m_y;

public:
    Particle();
    virtual ~Particle();
};

}

#endif