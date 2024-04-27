#include <iostream>
#include "color.h"
#include "Ray.hpp"

using namespace std;
Vec3d ray_color(Ray r){
    Vec3d unit_direction = unit_vector(r.getDirection());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0 - a)*Vec3d(1.0,1.0,1.0) + a*Vec3d(0.5,0.7,1.0);
}
int main() {

    // Image Rendered properties
    auto image_ratio = 16.0 / 9.0;
    int image_width = 400;

    int image_height = int(image_width / image_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    auto focal_length = 1.0;
    Vec3d camera_position = Vec3d(0,0,0);

    // Viewport left
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);
        // Viewport Vector
    auto viewport_u = Vec3d(viewport_width, 0, 0);
    auto viewport_v = Vec3d(0, -viewport_height, 0);
        // Calculate delta u / v
    auto delta_u = viewport_u / image_width;
    auto delta_v = viewport_v / image_height;
        // Get Top left corner of our viewport
    auto viewport_tp_corner = camera_position + Vec3d(0,0,focal_length) - (viewport_u/2) - (viewport_v/2);
    auto viewport_first_pixel = viewport_tp_corner + (delta_u/2) + (delta_v/2);

    // Render
    cout << "P3\n" << image_width << " " << image_height << " \n255\n" <<endl;
    for(int j = 0; j < image_height; j++){
        clog << "Scanline Done: " << j << " / " << image_height << endl;
        for(int i = 0; i < image_width; i++){
            auto current_pixel = viewport_first_pixel + (i*delta_u) + (j*delta_v);
            auto ray_direction = current_pixel - camera_position;
            Ray r = Ray(camera_position,ray_direction);

            auto pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
        clog << "Finished" << endl;
    }
    return 0;
}
