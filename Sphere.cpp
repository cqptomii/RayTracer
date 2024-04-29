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

bool Sphere::hit(const Ray& r, Interval ray_t, Intersection_hit &point) const{
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
    if(!ray_t.surround(nearest_root)){
        nearest_root = (-b + sqrt_delta)/(2*a);
        if(!ray_t.surround(nearest_root)){
            return false;
        }
    }

    // Store Intersection
    point.t = nearest_root;
    point.position = r.position(point.t);
    Vec3d outward_normal = (point.position - center) / radius;
    point.set_normal_face(r,outward_normal);
    return true;
}


