//
// Created by tomfr on 28/04/2024.
//

#ifndef RAYTRACER_HITTABLE_HPP
#define RAYTRACER_HITTABLE_HPP

#include "Intersection_hit.hpp"
#include "ToolKit.hpp"
class Hittable {
public:
    virtual ~Hittable() = default;

    virtual bool hit(const Ray& r, Interval ray_t, Intersection_hit& point) const = 0;
};


#endif //RAYTRACER_HITTABLE_HPP
