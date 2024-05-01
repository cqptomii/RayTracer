//
// Created by tomfr on 01/05/2024.
//

#ifndef RAYTRACER_METAL_HPP
#define RAYTRACER_METAL_HPP
#include "Material.hpp"

class Metal : public Material{
private:
    color fractional_reflection;
public:
     Metal(const color& fractional_reflex);
    bool reflexion(const Ray& r, const Intersection_hit& point, color& attenuation, Ray& r_reflect) const override;
};


#endif //RAYTRACER_METAL_HPP
