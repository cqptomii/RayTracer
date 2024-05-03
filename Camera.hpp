//
// Created by tomfr on 29/04/2024.
//

#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

class Camera {
public:
    void render(const Hittable_List& world);
    Camera();
    Camera(int width,Vec3d& center, Vec3d& look_at, double angle, int sampling_number, int amount_diffuse_reflect);
    void set_fov(double angle);
    void set_scale_factor(double factor);
    void set_origin(point3d& center);
    void set_direction(Vec3d& look_at);
    void set_image_width(int width);
    void set_aspect_ratio(double ratio);
    void set_sample_amount(int number);
    void set_diffuse_reflection_amount(int number);
    void move_camera(Vec3d translate,Vec3d rotate);
    void toString();
private:
        // Image properties
    double image_height;
    double aspect_ratio;
    double image_width;

        // Camera properties
    point3d camera_center;
    double fov;
    Vec3d view_origin;
    Vec3d view_direction;
    Vec3d vector_up;
    Vec3d base_u,base_v,base_w;
    double scale_factor_sampling; // scale factor in addition of number of samples
    int sample_number;
    int diffuse_reflection_amount;

        // Viewport properties
    double h;
    point3d first_pixel_location;
    Vec3d delta_u;
    Vec3d delta_v;


    void initialize();
    static Vec3d ray_color(const Ray& r, int depth,const Hittable& world) ;

    Ray get_ray(int pixel_u_index, int pixel_v_index,int sample_index);
    // Utility Function for Aliasing
    static Vec3d random_sample_square();

    // Utility Function For MSAA4 AntiAliasing
    Vec3d msaa4_top_left();
    Vec3d msaa4_top_right();
    Vec3d msaa4_bottom_left();
    Vec3d msaa4_bottom_right();
};


#endif //RAYTRACER_CAMERA_HPP
