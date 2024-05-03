//
// Created by tomfr on 29/04/2024.
//
#include "Hittable_List.h"
#include "Camera.hpp"
#include "Material.hpp"

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
                pixel_color = pixel_color + ray_color(r,diffuse_reflection_amount,world);
            }
            write_color(std::cout,scale_factor_sampling * pixel_color);
        }
        std::clog << "Finished" << std::endl;
    }
}
Camera::Camera() : image_width(400),aspect_ratio(16.0/9.0), image_height(1), sample_number(20), diffuse_reflection_amount(10), fov(120),vector_up(Vec3d(0,1,0)){}
Camera::Camera(int width, Vec3d &center, Vec3d &look_at, double angle, int sampling_number,int amount_diffuse_reflect) : camera_center(center), view_direction(look_at), fov(angle),sample_number(sampling_number),diffuse_reflection_amount(amount_diffuse_reflect), aspect_ratio(16.0/9.0){
    if(width < 1){
        this->image_width = 1;
    }else{
        this->image_width = width;
    }
}
void Camera::set_fov(double angle){
    this->fov = fabs(angle);
}
void Camera::set_scale_factor(double factor) {
    this->aspect_ratio = fabs(factor);
}
void Camera::set_origin(point3d &center) {
    this->camera_center = center;
}
void Camera::set_direction(Vec3d& look_at) {
    this->view_direction = look_at;
}
void Camera::set_image_width(int width) {
    if(width < 1){
        this->image_width = 1;
    }else{
        this->image_width = width;
    }
}
void Camera::set_aspect_ratio(double ratio){
    this->aspect_ratio = ratio;
}
void Camera::set_sample_amount(int number){
    if(number < 1){
        this->sample_number = 1;
    }else{
        this->sample_number = number;
    }
}
void Camera::set_diffuse_reflection_amount(int number){
    if(number < 0){
        this->diffuse_reflection_amount = 0;
    }else{
        this->diffuse_reflection_amount = number;
    }
}
void Camera::toString() {
    std::cout << "--- Camera Settings ---" << std::endl;
    camera_center.toString("Camera center :");
    view_direction.toString("Camera direction : ");
    std::cout << "Sample amount :" << sample_number << std::endl;
    std:: cout << "image width :" << image_width << "  , image height: " << image_height << std::endl;
}
void Camera::move_camera(Vec3d translate, Vec3d rotate) {
    // Translation
    auto position = camera_center + translate;
    camera_center = position;
    view_origin = position;

    // Rotation
}
void Camera::initialize() {
        // Set up image size
    this->image_height = int(image_width/aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;
        // Sampling Setup
    this->scale_factor_sampling = 1.0 / sample_number;

        // Camera Setup
    this->view_origin = camera_center;
    auto focal_length = (view_direction - view_origin).length();
    auto theta = degree_to_radian(fov);
    this->h = tan(theta/2);
        // Camera Coordinate system
    this->base_w = unit_vector(view_direction - view_origin);
    this->base_u = unit_vector(cross(vector_up,base_w));
    this->base_v = cross(base_w,base_u);

    // Set up viewport
    auto viewport_height = 2.0*h*focal_length;
    auto viewport_width = viewport_height * (double(image_width)/image_height);

    auto viewport_u = viewport_width * base_u ;
    auto viewport_v = viewport_height * -base_v;

    this->delta_u = viewport_u / image_width;
    this->delta_v = viewport_v / image_height;

    auto viewport_top_corner = camera_center + (focal_length*base_w) - viewport_u/2 - viewport_v/2;
    this->first_pixel_location = viewport_top_corner + delta_u/2 + delta_v/2;

}

Vec3d Camera::ray_color(const Ray &r, int depth, const Hittable &world) {
        if(depth <= 0)
            return {0,0,0};
        Intersection_hit point;

        if(world.hit(r,Interval(0.001,infinity),point)){
            Ray reflect_ray;
            color attenuation;
            if(point.mat->reflexion(r,point,attenuation,reflect_ray)){
                return attenuation * (ray_color(reflect_ray,depth-1,world));
            }
            return {0,0,0};
        }

        Vec3d unit_direction = unit_vector(r.getDirection());
        auto a = 0.5*(unit_direction.y() + 1.0);

        return (1.0 - a)*Vec3d(1.0,1.0,1.0) + a*Vec3d(0.5,0.7,1.0);
}
// compute a ray from the camera to a precise sample in pixel {i,j}
Ray Camera::get_ray(int pixel_u_index, int pixel_v_index, int sample_index){
    Vec3d random_sample;
    if(sample_index > 4){
        random_sample = random_sample_square();
    }else{
        if( sample_index == 1){
             random_sample = msaa4_top_left();
        }
        if(sample_index == 2){
             random_sample = msaa4_top_right();
        }
        if(sample_index == 3){
             random_sample = msaa4_bottom_left();
        }
        if (sample_index == 4){
             random_sample = msaa4_bottom_right();
        }
    }
    auto pixel_ij = first_pixel_location + (delta_u * (pixel_u_index + random_sample.x())) + (delta_v*(pixel_v_index + random_sample.y()));
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

