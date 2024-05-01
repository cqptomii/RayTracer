//
// Created by tomfr on 01/05/2024.
//

#include "Lambertian.hpp"
Lambertian::Lambertian() : fractional_reflexion(Vec3d(0,0,0)){}

Lambertian::Lambertian(const color &fractional_reflex) : fractional_reflexion(fractional_reflex){}

bool Lambertian::reflexion(const Ray &r,const Intersection_hit& point, color &attenuation, Ray& r_reflect) const {
    auto reflect_direction = random_lambertian_reflection(point.normal);

    if(reflect_direction.near_zero()){
        reflect_direction = point.normal;
    }
    r_reflect = Ray(point.position,reflect_direction);
    attenuation = fractional_reflexion;
    return true;
}