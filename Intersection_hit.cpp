//
// Created by tomfr on 28/04/2024.
//

#include "Intersection_hit.hpp"

Intersection_hit::Intersection_hit(): position(Vec3d(0,0,0)), normal(Vec3d(0,0,0)), t(0),front_face(false){}

void Intersection_hit::set_normal_face(const Ray &r,Vec3d &intersection_normal) {
    this->front_face = dot(r.getDirection(), intersection_normal) < 0;
    normal = front_face ? intersection_normal : - intersection_normal;
}
