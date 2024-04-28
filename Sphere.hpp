//
// Created by tomfr on 28/04/2024.
//

#ifndef RAYTRACER_SPHERE_HPP
#define RAYTRACER_SPHERE_HPP

#include "Ray.hpp"
#include "Hittable.hpp"

class Sphere : public Hittable{
private:
    point3d center;
    double radius;
public:
    Sphere(const point3d& center, double radius);
    bool hit(Ray& r, double t_min, double t_max, Intersection_hit& point);
};


#endif //RAYTRACER_SPHERE_HPP
