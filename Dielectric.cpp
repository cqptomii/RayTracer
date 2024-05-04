//
// Created by tomfr on 04/05/2024.
//
#include "Dielectric.hpp"
#include "Intersection_hit.hpp"

bool Dielectric::reflexion(const Ray &r, const Intersection_hit& point, color &attenuation, Ray &r_reflect) const {

    attenuation = color(1, 1, 1);
    double index = point.front_face ? (1.0/ reflective_index) : reflective_index;

    Vec3d unit_direction = unit_vector(r.getDirection());
    double cos_theta = fmin(dot(-unit_direction, point.normal), 1.0);
    double sin_theta = sqrt(1.0 - cos_theta*cos_theta);

    Vec3d direction;

    if (index * sin_theta > 1.0 || schlick_approximation(cos_theta,index) > random_number()){
        direction = mirror_reflect(unit_direction, point.normal);
    }
    else {
        direction = refraction(unit_direction, point.normal, index);
    }
    r_reflect = Ray(point.position, direction);
    return true;
}

double Dielectric::schlick_approximation(double cosi, double refract_index) {
    auto refract = (1-refract_index) / (1+ refract_index);
    refract = refract *refract;
    return refract + (1-refract)* pow((1-cosi),5);
}