//
// Created by tomfr on 01/05/2024.
//

#include "Metal.hpp"
#include "Intersection_hit.hpp"
Metal::Metal(const color& fractional_reflex, double fuzz) :fractional_reflection(fractional_reflex),fuzzy_reflection(fuzz < 1 ? fuzz : 1){}

bool Metal::reflexion(const Ray &r, const Intersection_hit &point, color &attenuation, Ray& r_reflect) const{
    auto reflect_direction = mirror_reflect(r.getDirection(),point.normal);
    reflect_direction = unit_vector(reflect_direction) + (fuzzy_reflection * random_vector_in_unit_sphere());
    r_reflect = Ray(point.position,reflect_direction);
    attenuation = fractional_reflection;
    return (dot(point.normal,r_reflect.getDirection()) > 0);
}
