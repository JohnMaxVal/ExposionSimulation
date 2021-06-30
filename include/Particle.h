#ifndef _PARTICLE_H_
#define _PARTICLE_H_

namespace explosion {

class Particle {
public:
    double m_x;
    double m_y;

    double m_speed;
    double m_direction;

public:
    Particle();
    virtual ~Particle();
    void update(int interval);
};

}

#endif