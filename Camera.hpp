//
// Created by tomfr on 29/04/2024.
//

#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

class Camera {
public:
    double aspect_ratio;
    double image_width ;
    void render(const Hittable_List& world);
    Camera();
private:
    double image_height;
    point3d camera_center;
    point3d first_pixel_location;
    Vec3d delta_u;
    Vec3d delta_v;
    void initialize();
    static Vec3d ray_color(Ray& r, const Hittable& world) ;
};


#endif //RAYTRACER_CAMERA_HPP
