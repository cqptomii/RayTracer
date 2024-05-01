//
// Created by tomfr on 01/05/2024.
//
#include "color.hpp"
double linear_to_gamma(double linear_value){
    auto gamma = 2.2;

    return pow(linear_value,1/gamma);
}
void write_color(std::ostream& out,const color& pixel_color){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    Interval color_interval = Interval(0,0.9999);
    int rInt = int(259.999 * color_interval.estimate(r));
    int gInt = int(259.999 * color_interval.estimate(g));
    int bInt = int(259.999 * color_interval.estimate(b));

    // Write pixel Color
    out << rInt << ' ' << gInt << ' ' << bInt << std::endl;

}