//
// Created by tomfr on 28/04/2024.
//

#include "Sphere.hpp"
#include "cmath"
Sphere::Sphere(const point3d &center, double radius) : center(center){
    if(radius > 0){
        this->radius = radius;
    }else{
        this->radius = 0;
    }
}

bool Sphere::hit(Ray& r, double t_min, double t_max, Intersection_hit &point) {
    Vec3d so = r.getOrigin() - center;
    auto a = r.getDirection().lengthSquare();
    auto b = 2*dot(so,r.getDirection());
    auto c = so.lengthSquare() - radius * radius;
    auto delta = b*b - 4*a*c;

    // Analyze intersection
    if(delta < 0 ){
        return false;
    }
    auto sqrt_delta = sqrt(delta);
    auto nearest_root = (-b - sqrt_delta)/(2*a);
    if(nearest_root <= t_min || nearest_root >= t_max){
        nearest_root = (-b + sqrt_delta)/(2*a);
        if(nearest_root <= t_min || nearest_root >= t_max){
            return false;
        }
    }

    // Store Intersection
    point.t = nearest_root;
    point.position = r.position(point.t);
    point.normal = (point.position - center) / radius;

    return true;
}


