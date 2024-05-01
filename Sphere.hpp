//
// Created by tomfr on 28/04/2024.
//

#ifndef RAYTRACER_SPHERE_HPP
#define RAYTRACER_SPHERE_HPP

#include "Ray.hpp"
#include "Hittable.hpp"
#include "ToolKit.hpp"

class Sphere : public Hittable{
private:
    point3d center;
    double radius;
    shared_ptr<Material> mat;
public:
    Sphere(const point3d& center, double radius,const shared_ptr<Material>& mat);
    bool hit(const Ray& r,Interval ray_t, Intersection_hit& point) const override;
};


#endif //RAYTRACER_SPHERE_HPP
