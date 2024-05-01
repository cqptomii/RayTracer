//
// Created by tomfr on 28/04/2024.
//

#ifndef RAYTRACER_TOOLKIT_HPP
#define RAYTRACER_TOOLKIT_HPP
#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <cstdlib>

#include "Interval.hpp"
#include "Ray.hpp"
#include "Vec3d.hpp"
#include "color.hpp"
using std::fabs;
using std::make_shared;
using std::shared_ptr;
using std::sqrt;

const double pi = M_PI;
const double infinity = std::numeric_limits<double>::infinity();

inline double degree_to_radian(double degree){
    return degree * pi /180.0;
}
inline double random_number(){
    return rand() / (RAND_MAX + 1.0);
}
inline double random_number(double min, double max){
    return min + (max-min)*random_number();
}

#endif //RAYTRACER_TOOLKIT_HPP
