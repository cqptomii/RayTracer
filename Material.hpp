//
// Created by tomfr on 01/05/2024.
//

#ifndef RAYTRACER_MATERIAL_HPP
#define RAYTRACER_MATERIAL_HPP
#include "ToolKit.hpp"

class Intersection_hit;

class Material{
public:
    virtual ~Material() = default;
    virtual bool reflexion(const Ray& r, const Intersection_hit& point, color& attenuation, Ray& r_reflect) const{
        return false;
    }
};
#endif //RAYTRACER_MATERIAL_HPP
