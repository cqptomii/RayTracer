//
// Created by tomfr on 26/04/2024.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H
#include "Vec3d.hpp"
#include "Interval.hpp"
using color = Vec3d;

void write_color(std::ostream& out,const color& pixel_color){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();
    Interval color_interval = Interval(0,0.9999);
    int rInt = int(259.999 * color_interval.estimate(r));
    int gInt = int(259.999 * color_interval.estimate(g));
    int bInt = int(259.999 * color_interval.estimate(b));

    // Write pixel Color
    out << rInt << ' ' << gInt << ' ' << bInt << std::endl;

}
#endif //RAYTRACER_COLOR_H
