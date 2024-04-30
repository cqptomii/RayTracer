//
// Created by tomfr on 29/04/2024.
//

#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

class Camera {
public:
    double aspect_ratio;
    double image_width;
    int sample_number;
    void render(const Hittable_List& world);
    Camera();
private:
    double image_height;
    double scale_factor_sampling; // scale factor in addition of number of samples
    point3d camera_center;
    point3d first_pixel_location;
    Vec3d delta_u;
    Vec3d delta_v;
    void initialize();
    static Vec3d ray_color(Ray& r, const Hittable& world) ;

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
