#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <cmath>

#include <math.h>
#include "Particle.h"

namespace explosion {

Particle::Particle(): m_x(0), m_y(0) {
    m_direction = (2 * M_PI * rand()) / RAND_MAX;
    m_speed = (0.0001 * rand()) / RAND_MAX;
}

Particle::~Particle() {

}

void Particle::update(int interval) {
    double x_speed = m_speed * cos(m_direction);
    double y_speed = m_speed * sin(m_direction);

    m_x += x_speed * interval;
    m_y += y_speed * interval;
}

}