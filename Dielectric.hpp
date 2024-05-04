//
// Created by tomfr on 04/05/2024.
//

#ifndef RAYTRACER_DIELECTRIC_HPP
#define RAYTRACER_DIELECTRIC_HPP
#include "Material.hpp"

class Dielectric : public Material {
private:
    double reflective_index;
    static double schlick_approximation(double cosi, double refract_index);
public:
    Dielectric(double index): reflective_index(index){}
    bool reflexion(const Ray& r, const Intersection_hit& point, color& attenuation, Ray& r_reflect) const override;
};


#endif //RAYTRACER_DIELECTRIC_HPP
