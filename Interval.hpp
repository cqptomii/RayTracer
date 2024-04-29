//
// Created by tomfr on 28/04/2024.
//

#ifndef RAYTRACER_INTERVAL_HPP
#define RAYTRACER_INTERVAL_HPP

#include "ToolKit.hpp"
class Interval {
public:
    double min;
    double max;
    Interval();
    Interval(double min, double max);
    double size() const;
    bool between(double value) const;
    bool surround(double value) const;

    static const Interval univers_R;
};


#endif //RAYTRACER_INTERVAL_HPP
