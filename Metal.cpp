//
// Created by tomfr on 01/05/2024.
//

#include "Metal.hpp"
#include "Intersection_hit.hpp"
Metal::Metal(const color& fractional_reflex) :fractional_reflection(fractional_reflex){}

bool Metal::reflexion(const Ray &r, const Intersection_hit &point, color &attenuation, Ray& r_reflect) const{
    auto reflect_direction = mirror_reflect(point.position,point.normal);

    r_reflect = Ray(point.position,reflect_direction);
    attenuation = fractional_reflection;
    return true;
}
