//
// Created by tomfr on 28/04/2024.
//

#ifndef RAYTRACER_INTERSECTION_HIT_HPP
#define RAYTRACER_INTERSECTION_HIT_HPP
#include "Material.hpp"

class Intersection_hit {
public:
    point3d position;
    Vec3d normal;
    shared_ptr<Material> mat;
    double t;
    bool front_face;

    Intersection_hit();
    void set_normal_face(const Ray& r, Vec3d& intersection_normal);
};


#endif //RAYTRACER_INTERSECTION_HIT_HPP
