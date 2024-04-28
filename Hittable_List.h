//
// Created by tomfr on 28/04/2024.
//

#ifndef RAYTRACER_HITTABLE_LIST_H
#define RAYTRACER_HITTABLE_LIST_H

#include "Hittable.hpp"
#include "ToolKit.hpp"
#include <vector>

class Hittable_List : public Hittable{
public:
    std::vector<shared_ptr<Hittable>> objects;
    Hittable_List(){}
    explicit Hittable_List(const shared_ptr<Hittable>& object) {
        add(object);
    }
    void clear() {
        this->objects.clear();
    }
    void add(const shared_ptr<Hittable>& object) {
        objects.push_back(object);
    }

    bool hit(const Ray& r, double t_min, double t_max, Intersection_hit& point) const override{
        Intersection_hit point_record;
        bool hit_something = false;
        auto t_far = t_max;
        for( const auto& object : objects){
            if( object->hit(r,t_min,t_far,point_record)){
                hit_something = true;
                t_far = point_record.t;
                point = point_record;
            }
        }

        return hit_something;
    }
};


#endif //RAYTRACER_HITTABLE_LIST_H
