//
// Created by tomfr on 28/04/2024.
//

#include "Interval.hpp"

Interval::Interval() : min(+infinity), max(-infinity){}
Interval::Interval(double min, double max) : min(min), max(max){}

double Interval::size() const {
    return max-min;
}

bool Interval::between(double value) const {
    return (value >= min && value <= max);
}
bool  Interval::surround(double value) const {
    return  (value > min && value < max);
}
double Interval::estimate(double x) const {
    if(x < min )
        return min;
    if(x>max)
        return max;
    return x;
}
const Interval Interval::univers_R = Interval(-infinity,+infinity);

