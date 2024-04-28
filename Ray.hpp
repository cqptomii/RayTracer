//
// Created by tomfr on 26/04/2024.
//

#ifndef RAYTRACER_RAY_HPP
#define RAYTRACER_RAY_HPP
#include "Vec3d.hpp"

class Ray {
    private:
        point3d origin;
        Vec3d direction;
    public:
        Ray();
        Ray(point3d origin, Vec3d direction);
        void setOrigin(point3d orig);
        void setDirection(Vec3d dir);
        point3d getOrigin() const;
        Vec3d getDirection() const;
        point3d position(double t) const;
};


#endif //RAYTRACER_RAY_HPP
