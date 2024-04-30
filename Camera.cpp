//
// Created by tomfr on 29/04/2024.
//
#include "ToolKit.hpp"
#include "Hittable_List.h"
#include "color.h"
#include "Camera.hpp"

void Camera::render(const Hittable_List &world) {
    // generated the camera
    initialize();

    std::cout << "P3\n" << image_width << " " << image_height << " \n255\n" << std::endl;
    for(int j = 0; j < image_height; j++){
        std::clog << "Scanline Done: " << j << " / " << image_height << std::endl;
        for(int i = 0; i < image_width; i++){
            /**
                auto current_pixel = first_pixel_location + (i*delta_u) + (j*delta_v);
                auto ray_direction = current_pixel - camera_center;
                Ray r = Ray(camera_center,ray_direction);

                auto pixel_color = ray_color(r,world);
             **/
            color pixel_color(0,0,0);
            for(int sample = 1; sample <= sample_number; sample++){
                Ray r = get_ray(i,j,sample);
                pixel_color = pixel_color + ray_color(r,world);
            }
            write_color(std::cout,scale_factor_sampling * pixel_color);
        }
        std::clog << "Finished" << std::endl;
    }
}
Camera::Camera() : image_width(400),aspect_ratio(16.0/9.0), image_height(1), sample_number(4){}
void Camera::initialize() {
    // Set up image size
    this->image_height = int(image_width/aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;
    this->scale_factor_sampling = 1.0 / sample_number;
    this->camera_center = Vec3d(0,0,0);

    // Set up viewport
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);

    auto viewport_u = Vec3d(viewport_width,0,0);
    auto viewport_v = Vec3d(0,-viewport_height,0);

    this->delta_u = viewport_u / image_width;
    this->delta_v = viewport_v / image_height;

    auto viewport_top_corner = camera_center + Vec3d(0,0,focal_length) - viewport_u/2 - viewport_v/2;
    this->first_pixel_location = viewport_top_corner + delta_u/2 + delta_v/2;

}

Vec3d Camera::ray_color(Ray &r, const Hittable &world) {
        Intersection_hit point;

        if(world.hit(r,Interval(0,infinity),point)){
            return 0.5 * (point.normal + color (1,1,1));
        }

        Vec3d unit_direction = unit_vector(r.getDirection());
        auto a = 0.5*(unit_direction.y() + 1.0);

        return (1.0 - a)*Vec3d(1.0,1.0,1.0) + a*Vec3d(0.5,0.7,1.0);
}
// compute a ray from the camera to a precise sample in pixel {i,j}
Ray Camera::get_ray(int pixel_u_index, int pixel_v_index, int sample_index){
    auto pixel_ij = first_pixel_location + (delta_u * (pixel_u_index)) + (delta_v*(pixel_v_index ));
    if(sample_index > 4){
        auto random_sample = random_sample_square();
        pixel_ij += random_sample.x()*delta_u + random_sample_square().y()*delta_v;
    }else{
        if( sample_index == 1){
            pixel_ij += msaa4_top_left();
        }
        if(sample_index == 2){
            pixel_ij += msaa4_top_right();
        }
        if(sample_index == 3){
            pixel_ij += msaa4_bottom_left();
        }
        if (sample_index == 4){
            pixel_ij += msaa4_bottom_right();
        }
    }
    auto ray_direction = pixel_ij - camera_center;
    return {camera_center,ray_direction};
}

Vec3d Camera::random_sample_square() {
    // return random point between (-0.5,-0.5) - (0.5,0.5)
    return {random_number()-0.5,random_number()-0.5,0};
}
Vec3d Camera::msaa4_top_left() {
    return -0.4*delta_v-0.1*delta_u;
}
Vec3d Camera::msaa4_top_right() {
    return -0.1*delta_v + 0.4*delta_u;
}
Vec3d Camera::msaa4_bottom_left() {
    return 0.4*delta_v + 0.1*delta_u;
}
Vec3d Camera::msaa4_bottom_right() {
    return 0.1*delta_v - 0.4*delta_u;
}
