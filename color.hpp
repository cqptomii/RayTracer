//
// Created by tomfr on 26/04/2024.
//

#ifndef RAYTRACER_COLOR_HPP
#define RAYTRACER_COLOR_HPP
#include "Vec3d.hpp"
#include "Interval.hpp"
using color = Vec3d;
double linear_to_gamma(double linear_value);
void write_color(std::ostream& out,const color& pixel_color);
#endif //RAYTRACER_COLOR_HPP
