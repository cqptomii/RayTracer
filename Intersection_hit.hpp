//
// Created by tomfr on 28/04/2024.
//

#ifndef RAYTRACER_INTERSECTION_HIT_HPP
#define RAYTRACER_INTERSECTION_HIT_HPP

#include "Ray.hpp"
class Intersection_hit {
public:
    point3d position;
    Vec3d normal;
    double t;
    Intersection_hit();
};


#endif //RAYTRACER_INTERSECTION_HIT_HPP
