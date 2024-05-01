//
// Created by tomfr on 01/05/2024.
//

#ifndef RAYTRACER_LAMBERTIAN_HPP
#define RAYTRACER_LAMBERTIAN_HPP
#include "Material.hpp"
#include "Intersection_hit.hpp"

class Lambertian : public Material{
private:
    color fractional_reflexion;
public:
    Lambertian();
    Lambertian(const color& fractional_reflex);
    bool reflexion(const Ray& r,const Intersection_hit& point, color& attenuation,Ray& r_reflect)const override;
};


#endif //RAYTRACER_LAMBERTIAN_HPP
