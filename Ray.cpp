//
// Created by tomfr on 26/04/2024.
//

#include "Ray.hpp"

Ray::Ray() : origin(Vec3d(0,0,0)),direction(Vec3d(1,1,1)){}

Ray::Ray(point3d origin, Vec3d direction) : origin(origin), direction(direction){}

void Ray::setOrigin(point3d orig) {
    this->origin = orig;
}

void Ray::setDirection(Vec3d dir) {
    this->direction = dir;
}

point3d Ray::getOrigin() const{
    return this->origin;
}

Vec3d Ray::getDirection() const {
    return this->direction;
}

point3d Ray::position(double t) const{
    return this->origin +this->direction*t;
}
